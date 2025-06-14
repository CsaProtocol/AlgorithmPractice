
#include "../queue/lst/queuelst.hpp"

namespace lasd {

/* ************************************************************************** */

template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& nod) const noexcept {
  if (Element() != nod.Element())
    return false;

  if (HasLeftChild() != nod.HasLeftChild())
    return false;
  if (HasLeftChild() && !(LeftChild() == nod.LeftChild()))
    return false;

  if (HasRightChild() != nod.HasRightChild())
    return false;
  if (HasRightChild() && !(RightChild() == nod.RightChild()))
    return false;

  return true;
}

template <typename Data>
inline bool BinaryTree<Data>::Node::operator!=(const Node & nod) const noexcept {
  return !(*this == nod);
}

template <typename Data>
inline bool BinaryTree<Data>::Node::IsLeaf() const noexcept {
  return !(HasLeftChild() || HasRightChild());
}

template<typename Data>
inline bool BinaryTree<Data>::operator==(const BinaryTree<Data> & bt) const noexcept {
  if (size != bt.size) return false;
  if (size == 0) return true;
  return Root() == bt.Root();
}

template<typename Data>
inline bool BinaryTree<Data>::operator!=(const BinaryTree<Data> & bt) const noexcept {
  return !(*this == bt);
}

template<typename Data>
inline void BinaryTree<Data>::Traverse(TraverseFun fun) const {
  PreOrderTraverse(fun);
}

template<typename Data>
inline void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun) const {
  if (size > 0) {
    PreOrderTraverse(fun, Root());
  }
}

template<typename Data>
inline void BinaryTree<Data>::PostOrderTraverse(TraverseFun fun) const {
  if (size > 0) {
    PostOrderTraverse(fun, Root());
  }
}

template<typename Data>
inline void BinaryTree<Data>::InOrderTraverse(TraverseFun fun) const {
  if (size > 0) {
    InOrderTraverse(fun, Root());
  }
}

template<typename Data>
inline void BinaryTree<Data>::BreadthTraverse(TraverseFun fun) const {
  if (size > 0) {
    BreadthTraverse(fun, Root());
  }
}

template<typename Data>
void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun, const Node & nod) const {
  fun(nod.Element());
  if (nod.HasLeftChild()) {
    PreOrderTraverse(fun, nod.LeftChild());
  }
  if (nod.HasRightChild()) {
    PreOrderTraverse(fun, nod.RightChild());
  }
}

template<typename Data>
void BinaryTree<Data>::PostOrderTraverse(TraverseFun fun, const Node & nod) const {
  if (nod.HasLeftChild()) {
    PostOrderTraverse(fun, nod.LeftChild());
  }
  if (nod.HasRightChild()) {
    PostOrderTraverse(fun, nod.RightChild());
  }
  fun(nod.Element());
}

template<typename Data>
void BinaryTree<Data>::InOrderTraverse(TraverseFun fun, const Node & nod) const {
  if (nod.HasLeftChild()) {
    InOrderTraverse(fun, nod.LeftChild());
  }
  fun(nod.Element());
  if (nod.HasRightChild()) {
    InOrderTraverse(fun, nod.RightChild());
  }
}

template<typename Data>
void BinaryTree<Data>::BreadthTraverse(TraverseFun fun, const Node & nod) const {
  QueueVec<const Node *> Queue;
  Queue.Enqueue(&nod);
  while (!Queue.Empty()) {
    const Node & cur = *Queue.HeadNDequeue();
    fun(cur.Element());
    if (cur.HasLeftChild()) {
      Queue.Enqueue(&cur.LeftChild());
    }
    if (cur.HasRightChild()) {
      Queue.Enqueue(&cur.RightChild());
    }
  }
}

template<typename Data>
inline void MutableBinaryTree<Data>::Map(MapFun fun) {
  PreOrderMap(fun);
}

template<typename Data>
inline void MutableBinaryTree<Data>::PreOrderMap(MapFun fun) {
  if (size > 0) {
    PreOrderMap(fun, Root());
  }
}

template<typename Data>
inline void MutableBinaryTree<Data>::PostOrderMap(MapFun fun) {
  if (size > 0) {
    PostOrderMap(fun, Root());
  }
}

template<typename Data>
inline void MutableBinaryTree<Data>::InOrderMap(MapFun fun) {
  if (size > 0) {
    InOrderMap(fun, Root());
  }
}

template<typename Data>
inline void MutableBinaryTree<Data>::BreadthMap(MapFun fun) {
  if (size > 0) {
    BreadthMap(fun, Root());
  }
}

template<typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MapFun fun, MutableNode & nod) {
  fun(nod.Element());
  if (nod.HasLeftChild()) {
    PreOrderMap(fun, nod.LeftChild());
  }
  if (nod.HasRightChild()) {
    PreOrderMap(fun, nod.RightChild());
  }
}

template<typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MapFun fun, MutableNode & nod) {
  if (nod.HasLeftChild()) {
    PostOrderMap(fun, nod.LeftChild());
  }
  if (nod.HasRightChild()) {
    PostOrderMap(fun, nod.RightChild());
  }
  fun(nod.Element());
}

template<typename Data>
void MutableBinaryTree<Data>::InOrderMap(MapFun fun, MutableNode & nod) {
  if (nod.HasLeftChild()) {
    InOrderMap(fun, nod.LeftChild());
  }
  fun(nod.Element());
  if (nod.HasRightChild()) {
    InOrderMap(fun, nod.RightChild());
  }
}

template<typename Data>
void MutableBinaryTree<Data>::BreadthMap(MapFun fun, MutableNode & nod) {
  QueueLst<MutableNode *> Queue;
  Queue.Enqueue(&nod);
  while (!Queue.Empty()) {
    MutableNode & cur = *Queue.HeadNDequeue();
    fun(cur.Element());
    if (cur.HasLeftChild()) {
      Queue.Enqueue(&cur.LeftChild());
    }
    if (cur.HasRightChild()) {
      Queue.Enqueue(&cur.RightChild());
    }
  }
}

/* ************************************************************************** */

}
