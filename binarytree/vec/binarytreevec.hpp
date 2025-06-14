#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : virtual public MutableBinaryTree<Data>,
                      virtual protected Vector<Data> {

protected:

  using Vector<Data>::size;
  using Vector<Data>::elements;

public:

  using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;

protected:

  struct NodeVec : virtual MutableNode {

    BinaryTreeVec* Tree = nullptr;

    NodeVec() = default;
    virtual ~NodeVec() = default;

    inline const Data& Element() const noexcept override;
    inline Data& Element() noexcept override;

    inline bool IsLeaf() const noexcept override;
    inline bool HasLeftChild() const noexcept override;
    inline bool HasRightChild() const noexcept override;

    const Node& LeftChild() const override;
    const Node& RightChild() const override;
    MutableNode& LeftChild() override;
    MutableNode& RightChild() override;

  protected:

    [[nodiscard]] virtual ulong Index() const noexcept;

  };

  NodeVec* Nodes = nullptr;

public:

  BinaryTreeVec() = default;
  BinaryTreeVec(const TraversableContainer<Data>&);
  BinaryTreeVec(MappableContainer<Data>&&);

  BinaryTreeVec(const BinaryTreeVec&);
  BinaryTreeVec(BinaryTreeVec&&) noexcept;

  ~BinaryTreeVec() override;

  BinaryTreeVec& operator=(const BinaryTreeVec&);
  BinaryTreeVec& operator=(BinaryTreeVec&&) noexcept;

  using BinaryTree<Data>::operator==;
  inline bool operator==(const BinaryTreeVec&) const noexcept;
  using BinaryTree<Data>::operator!=;
  inline bool operator!=(const BinaryTreeVec&) const noexcept;

  const Node& Root() const override;
  MutableNode& Root() override;

  void Clear() override;

  using typename TraversableContainer<Data>::TraverseFun;
  inline void Traverse(TraverseFun) const override;
  inline void PreOrderTraverse(TraverseFun) const override;
  inline void PostOrderTraverse(TraverseFun) const override;
  inline void BreadthTraverse(TraverseFun) const override;

  using typename MappableContainer<Data>::MapFun;
  inline void Map(MapFun) override;
  inline void PreOrderMap(MapFun) override;
  inline void PostOrderMap(MapFun) override;
  inline void BreadthMap(MapFun) override;

protected:

  virtual void NewNodeArray();
  virtual void SwapNodeArrays(BinaryTreeVec &&) noexcept;

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
