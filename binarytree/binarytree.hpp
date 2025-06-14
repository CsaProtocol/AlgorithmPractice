#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/mappable.hpp"

#include "../iterator/iterator.hpp"

#include "../stack/vec/stackvec.hpp"
#include "../queue/vec/queuevec.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree : virtual public ClearableContainer,
                   virtual public PreOrderTraversableContainer<Data>,
                   virtual public PostOrderTraversableContainer<Data>,
                   virtual public InOrderTraversableContainer<Data>,
                   virtual public BreadthTraversableContainer<Data> {

protected:

  using Container::size;

public:

  struct Node {

  protected:

    bool operator==(const Node&) const noexcept;
    inline bool operator!=(const Node&) const noexcept;

  public:

    friend class BinaryTree;

    Node() = default;
    virtual ~Node() = default;

    Node& operator=(const Node&) = delete;
    Node& operator=(Node&&) noexcept = delete;

    virtual const Data& Element() const noexcept = 0;

    inline virtual bool IsLeaf() const noexcept;
    virtual bool HasLeftChild() const noexcept = 0;
    virtual bool HasRightChild() const noexcept = 0;

    virtual const Node& LeftChild() const = 0;
    virtual const Node& RightChild() const = 0;

  };

  BinaryTree() = default;
  ~BinaryTree() override = default;

  BinaryTree& operator=(const BinaryTree &) = delete;
  BinaryTree& operator=(BinaryTree &&) noexcept = delete;

  inline virtual bool operator==(const BinaryTree &) const noexcept;
  inline virtual bool operator!=(const BinaryTree &) const noexcept;

  virtual const Node& Root() const = 0;

  using typename TraversableContainer<Data>::TraverseFun;
  inline void Traverse(TraverseFun) const override;
  inline void PreOrderTraverse(TraverseFun) const override;
  inline void PostOrderTraverse(TraverseFun) const override;
  inline void InOrderTraverse(TraverseFun) const override;
  inline void BreadthTraverse(TraverseFun) const override;

protected:

  virtual void PreOrderTraverse(TraverseFun, const Node&) const;
  virtual void PostOrderTraverse(TraverseFun, const Node&) const;
  virtual void InOrderTraverse(TraverseFun, const Node&) const;
  virtual void BreadthTraverse(TraverseFun, const Node&) const;

};

/* ************************************************************************** */

template <typename Data>
class MutableBinaryTree : virtual public BinaryTree<Data>,
                          virtual public PreOrderMappableContainer<Data>,
                          virtual public PostOrderMappableContainer<Data>,
                          virtual public InOrderMappableContainer<Data>,
                          virtual public BreadthMappableContainer<Data> {

protected:

  using Container::size;
  using typename BinaryTree<Data>::Node;

public:

  struct MutableNode : Node {

    MutableNode() = default;
    virtual ~MutableNode() = default;

    MutableNode& operator=(const MutableNode&) = delete;
    MutableNode& operator=(MutableNode&&) noexcept = delete;

    using Node::Element;
    virtual Data& Element() noexcept = 0;

    using Node::LeftChild;
    virtual MutableNode& LeftChild() = 0;

    using Node::RightChild;
    virtual MutableNode& RightChild() = 0;

  };

  MutableBinaryTree() = default;
  ~MutableBinaryTree() override = default;

  MutableBinaryTree& operator=(const MutableBinaryTree&) = delete;
  MutableBinaryTree& operator=(MutableBinaryTree&&) noexcept = delete;

  using BinaryTree<Data>::Root;
  virtual MutableNode& Root() = 0;

  using typename MappableContainer<Data>::MapFun;
  inline void Map(MapFun) override;
  inline void PreOrderMap(MapFun) override;
  inline void PostOrderMap(MapFun) override;
  inline void InOrderMap(MapFun) override;
  inline void BreadthMap(MapFun) override;

protected:

  virtual void PreOrderMap(MapFun, MutableNode&);
  virtual void PostOrderMap(MapFun, MutableNode&);
  virtual void InOrderMap(MapFun, MutableNode&);
  virtual void BreadthMap(MapFun, MutableNode&);

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator : virtual public ForwardIterator<Data>,
                           virtual public ResettableIterator<Data> {

protected:

  const typename BinaryTree<Data>::Node* root = nullptr;
  StackVec<const typename BinaryTree<Data>::Node*> stk;

public:

  BTPreOrderIterator(const BinaryTree<Data> & bt) {
    if (bt.Size() != 0) {
      stk.Push(root = &bt.Root());
    }
  }

  BTPreOrderIterator(const BTPreOrderIterator& toCopy) : root(toCopy.root), stk(toCopy.stk) {}
  BTPreOrderIterator(BTPreOrderIterator && toMove) noexcept {
    std::swap(root, toMove.root);
    std::swap(stk, toMove.stk);
  }

  ~BTPreOrderIterator() override = default;

  BTPreOrderIterator& operator=(const BTPreOrderIterator& toCopy) {
    root = toCopy.root;
    stk = toCopy.stk;
    return *this;
  }
  BTPreOrderIterator& operator=(BTPreOrderIterator&& toMove) noexcept {
    std::swap(root, toMove.root);
    std::swap(stk, toMove.stk);
    return *this;
  }

  inline bool operator==(const BTPreOrderIterator& toCompare) const noexcept {
    return (root == toCompare.root) && (stk == toCompare.stk);
  }
  inline bool operator!=(const BTPreOrderIterator& toCompare) const noexcept {
    return !(*this == toCompare);
  }

  const Data& operator*() const override {
    if(stk.Empty()) {
      throw std::out_of_range("Iterator has reached termination point.");
    } return stk.Top()->Element();
  }

  bool Terminated() const noexcept override {
    return stk.Empty();
  }

  ForwardIterator<Data>& operator++() override {
    const typename BinaryTree<Data>::Node& curr = *stk.TopNPop();
    if(curr.HasRightChild()) {
      stk.Push(&curr.RightChild());
    }
    if(curr.HasLeftChild()) {
      stk.Push(&curr.LeftChild());
    }
    return *this;
  };

  void Reset() noexcept override {
    if(root != nullptr) {
      stk.Clear();
      stk.Push(root);
    }
  }

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderMutableIterator : virtual public MutableIterator<Data>,
                                  virtual public BTPreOrderIterator<Data> {
protected:

  using BTPreOrderIterator<Data>::stk;

public:

  BTPreOrderMutableIterator(MutableBinaryTree<Data> & bt) : BTPreOrderIterator<Data>(bt) {};

  BTPreOrderMutableIterator(const BTPreOrderMutableIterator& itr) : BTPreOrderIterator<Data>(itr) {};
  BTPreOrderMutableIterator(BTPreOrderMutableIterator&& itr) noexcept : BTPreOrderIterator<Data>(std::move(itr)) {};

  ~BTPreOrderMutableIterator() override = default;

  BTPreOrderMutableIterator& operator=(const BTPreOrderMutableIterator& itr) {
    BTPreOrderIterator<Data>::operator=(itr);
    return *this;
  }
  BTPreOrderMutableIterator& operator=(BTPreOrderMutableIterator&& itr) noexcept {
    BTPreOrderIterator<Data>::operator=(std::move(itr));
    return *this;
  }

  Data & operator*() override {
    if(stk.Empty()) {
      throw std::out_of_range("Iterator has reached termination point.");
    } return const_cast<Data&>(stk.Top()->Element());
  }

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator : virtual public ForwardIterator<Data>,
                            virtual public ResettableIterator<Data> {

protected:

  const typename BinaryTree<Data>::Node * root = nullptr;
  StackVec<const typename BinaryTree<Data>::Node *> stk;

public:

  BTPostOrderIterator(const BinaryTree<Data> & bt) {
    if (bt.Size() != 0) {
      stk.Push(root = &bt.Root());
      SearchLeftMostLeaf();
    }
  }

  BTPostOrderIterator(const BTPostOrderIterator& toCopy) : root(toCopy.root), stk(toCopy.stk) {}
  BTPostOrderIterator(BTPostOrderIterator&& toMove) noexcept {
    std::swap(root, toMove.root);
    std::swap(stk, toMove.stk);
  }

  ~BTPostOrderIterator() override = default;

  BTPostOrderIterator& operator=(const BTPostOrderIterator& toCopy) {
    root = toCopy.root;
    stk = toCopy.stk;
    return *this;
  }
  BTPostOrderIterator& operator=(BTPostOrderIterator&& toMove) noexcept {
    std::swap(root, toMove.root);
    std::swap(stk, toMove.stk);
    return *this;
  }

  inline bool operator==(const BTPostOrderIterator& toCompare) const noexcept {
    return (root == toCompare.root) && (stk == toCompare.stk);
  }
  inline bool operator!=(const BTPostOrderIterator& toCompare) const noexcept {
    return !(*this == toCompare);
  }

  const Data& operator*() const override {
    if(stk.Empty()) {
      throw std::out_of_range("Iterator has reached termination point.");
    } return stk.Top()->Element();
  }

  bool Terminated() const noexcept override {
    return stk.Empty();
  }

  ForwardIterator<Data>& operator++() override {
    const typename BinaryTree<Data>::Node* last = stk.TopNPop();
    if (!stk.Empty()) {
      const typename BinaryTree<Data>::Node& top = *stk.Top();
      if (top.HasRightChild() && (last != &top.RightChild())) {
        stk.Push(&top.RightChild());
        SearchLeftMostLeaf();
      }
    };
    return *this;
  }

  void Reset() noexcept override {
    if (root != nullptr) {
      stk.Clear();
      stk.Push(root);
      SearchLeftMostLeaf();
    }
  };

protected:

  void SearchLeftMostLeaf() {
    const typename BinaryTree<Data>::Node * curr;
    while (true) {
      while ((curr = stk.Top())->HasLeftChild()) {
        stk.Push(&curr->LeftChild());
      }
      if (curr->HasRightChild()) {
        stk.Push(&curr->RightChild());
      } else {
        break;
      }
    }
  }

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderMutableIterator : virtual public MutableIterator<Data>,
                                   virtual public BTPostOrderIterator<Data> {
protected:

  using BTPostOrderIterator<Data>::stk;

public:

  BTPostOrderMutableIterator(MutableBinaryTree<Data>& bt) : BTPostOrderIterator<Data>(bt) {};

  BTPostOrderMutableIterator(const BTPostOrderMutableIterator& itr) : BTPostOrderIterator<Data>(itr) {};
  BTPostOrderMutableIterator(BTPostOrderMutableIterator&& itr) noexcept : BTPostOrderIterator<Data>(std::move(itr)) {};

  ~BTPostOrderMutableIterator() override = default;

  BTPostOrderMutableIterator& operator=(const BTPostOrderMutableIterator & itr) {
    BTPostOrderIterator<Data>::operator=(itr);
    return *this;
  }
  BTPostOrderMutableIterator & operator=(BTPostOrderMutableIterator && itr) noexcept {
    BTPostOrderIterator<Data>::operator=(std::move(itr));
    return *this;
  }

  Data& operator*() override {
    if(stk.Empty()) {
      throw std::out_of_range("Iterator has reached termination point.");
    } return const_cast<Data&>(stk.Top()->Element());
  }

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator : virtual public ForwardIterator<Data>,
                          virtual public ResettableIterator<Data> {

protected:

  const typename BinaryTree<Data>::Node * root = nullptr;
  StackVec<const typename BinaryTree<Data>::Node *> stk;

public:

  BTInOrderIterator(const BinaryTree<Data>& bt) {
    if (bt.Size() != 0) {
      stk.Push(root = &bt.Root());
      SearchLeftMostNode();
    }
  }

  BTInOrderIterator(const BTInOrderIterator& toCopy) : root(toCopy.root), stk(toCopy.stk) {}
  BTInOrderIterator(BTInOrderIterator&& toMove) noexcept {
    std::swap(root, toMove.root);
    std::swap(stk, toMove.stk);
  }

  ~BTInOrderIterator() override = default;

  BTInOrderIterator& operator=(const BTInOrderIterator& toCopy) {
    root = toCopy.root;
    stk = toCopy.stk;
    return *this;
  }
  BTInOrderIterator& operator=(BTInOrderIterator&& toMove) noexcept {
    std::swap(root, toMove.root);
    std::swap(stk, toMove.stk);
    return *this;
  }

  inline bool operator==(const BTInOrderIterator& toCompare) const noexcept {
    return (root == toCompare.root) && (stk == toCompare.stk);
  }
  inline bool operator!=(const BTInOrderIterator& toCompare) const noexcept {
    return !(*this == toCompare);
  }

  const Data& operator*() const override {
    if(stk.Empty()) {
      throw std::out_of_range("Iterator has reached termination point.");
    } return stk.Top()->Element();
  }

  bool Terminated() const noexcept override {
    return stk.Empty();
  }

  ForwardIterator<Data>& operator++() override {
    if(const typename BinaryTree<Data>::Node& curr = *stk.TopNPop(); curr.HasRightChild()) {
      stk.Push(&curr.RightChild());
      SearchLeftMostNode();
    }
    return *this;
  }

  void Reset() noexcept override {
    if (root != nullptr) {
      stk.Clear();
      stk.Push(root);
      SearchLeftMostNode();
    }
  };

protected:

  void SearchLeftMostNode() {
    const typename BinaryTree<Data>::Node* curr = stk.Top();
    if(!curr->HasLeftChild()) return;

    do {
      curr = &curr->LeftChild();
      stk.Push(curr);
    } while(curr->HasLeftChild());
  }

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderMutableIterator : virtual public MutableIterator<Data>,
                                 virtual public BTInOrderIterator<Data> {

protected:

  using BTInOrderIterator<Data>::stk;

public:

  BTInOrderMutableIterator(MutableBinaryTree<Data>& bt) : BTInOrderIterator<Data>(bt) {};

  BTInOrderMutableIterator(const BTInOrderMutableIterator& itr) : BTInOrderIterator<Data>(itr) {};
  BTInOrderMutableIterator(BTInOrderMutableIterator&& itr) noexcept : BTInOrderIterator<Data>(std::move(itr)) {};

  ~BTInOrderMutableIterator() override = default;

  BTInOrderMutableIterator& operator=(const BTInOrderMutableIterator& itr) {
    BTInOrderIterator<Data>::operator=(itr);
    return *this;
  }
  BTInOrderMutableIterator& operator=(BTInOrderMutableIterator&& itr) noexcept {
    BTInOrderIterator<Data>::operator=(std::move(itr));
    return *this;
  }

  Data& operator*() override {
    if(stk.Empty()) {
      throw std::out_of_range("Iterator has reached termination point.");
    } return const_cast<Data&>(stk.Top()->Element());
  }

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthIterator : virtual public ForwardIterator<Data>,
                          virtual public ResettableIterator<Data> {

protected:

  const typename BinaryTree<Data>::Node* root = nullptr;
  QueueVec<const typename BinaryTree<Data>::Node*> que;

public:

  BTBreadthIterator(const BinaryTree<Data>& bt) {
    if(bt.Size() != 0) {
      que.Enqueue(root = &bt.Root());
    }
  }

  BTBreadthIterator(const BTBreadthIterator& toCopy) : root(toCopy.root), que(toCopy.que) {}
  BTBreadthIterator(BTBreadthIterator&& toMove) noexcept {
    std::swap(root, toMove.root);
    std::swap(que, toMove.que);
  }

  ~BTBreadthIterator() override = default;

  BTBreadthIterator& operator=(const BTBreadthIterator& toCopy) {
    root = toCopy.root;
    que = toCopy.que;
    return *this;
  }
  BTBreadthIterator& operator=(BTBreadthIterator&& toMove) noexcept {
    std::swap(root, toMove.root);
    std::swap(que, toMove.que);
    return *this;
  }

  inline bool operator==(const BTBreadthIterator & toCompare) const noexcept {
    return (root == toCompare.root) && (que == toCompare.que);
  }
  inline bool operator!=(const BTBreadthIterator & toCompare) const noexcept {
    return !(*this == toCompare);
  }

  const Data& operator*() const override {
    if(que.Empty()) {
      throw std::out_of_range("Iterator has reached termination point.");
    } return que.Head()->Element();
  }

  bool Terminated() const noexcept override {
    return que.Empty();
  }

  ForwardIterator<Data>& operator++() override {
    const typename BinaryTree<Data>::Node& curr = *que.HeadNDequeue();
    if (curr.HasLeftChild()) {
      que.Enqueue(&curr.LeftChild());
    }
    if (curr.HasRightChild()) {
      que.Enqueue(&curr.RightChild());
    }
    return *this;
  }

  void Reset() noexcept override {
    if (root != nullptr) {
      que.Clear();
      que.Enqueue(root);
    }
  };

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthMutableIterator : virtual public MutableIterator<Data>,
                                 virtual public BTBreadthIterator<Data> {

protected:

  using BTBreadthIterator<Data>::que;

public:

  BTBreadthMutableIterator(MutableBinaryTree<Data>& bt) : BTBreadthIterator<Data>(bt) {};

  BTBreadthMutableIterator(const BTBreadthMutableIterator& toCopy) : BTBreadthIterator<Data>(toCopy) {};
  BTBreadthMutableIterator(BTBreadthMutableIterator&& toMove) noexcept : BTBreadthIterator<Data>(std::move(toMove)) {};

  ~BTBreadthMutableIterator() override = default;

  BTBreadthMutableIterator& operator=(const BTBreadthMutableIterator& toCopy) {
    BTBreadthIterator<Data>::operator=(toCopy);
    return *this;
  }
  BTBreadthMutableIterator& operator=(BTBreadthMutableIterator&& toMove) noexcept {
    BTBreadthIterator<Data>::operator=(std::move(toMove));
    return *this;
  }

  Data& operator*() override {
    if(que.Empty()) {
      throw std::out_of_range("Iterator has reached termination point.");
    } return const_cast<Data&>(que.Head()->Element());
  }

};

/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
