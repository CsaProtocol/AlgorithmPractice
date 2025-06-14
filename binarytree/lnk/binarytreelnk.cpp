
#include "../../queue/vec/queuevec.hpp"

namespace lasd {

template<typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data && dat) noexcept {
  std::swap(element, dat);
}

template<typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const NodeLnk & nod) {
  element = nod.element;
  if (nod.left != nullptr) {
    left = new NodeLnk(*nod.left);
  }
  if (nod.right != nullptr) {
    right = new NodeLnk(*nod.right);
  }
}

template<typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(NodeLnk && nod) noexcept {
  std::swap(left, nod.left);
  std::swap(right, nod.right);
  std::swap(element, nod.element);
}

template<typename Data>
BinaryTreeLnk<Data>::NodeLnk::~NodeLnk() {
  delete left;
  delete right;
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk & BinaryTreeLnk<Data>::NodeLnk::operator=(const NodeLnk & nod) {
  element = nod.element;
  if (left == nullptr) {
    if (nod.left != nullptr) {
      left = new NodeLnk(*nod.left);
    }
  } else {
    if (nod.left != nullptr) {
      *left = *nod.left;
    } else {
      delete left;
      left = nullptr;
    }
  }
  if (right == nullptr) {
    if (nod.right != nullptr) {
      right = new NodeLnk(*nod.right);
    }
  } else {
    if (nod.right != nullptr) {
      *right = *nod.right;
    } else {
      delete right;
      right = nullptr;
    }
  }
  return *this;
}

template<typename Data>
inline typename BinaryTreeLnk<Data>::NodeLnk & BinaryTreeLnk<Data>::NodeLnk::operator=(NodeLnk && nod) noexcept {
  std::swap(element, nod.element);
  std::swap(left, nod.left);
  std::swap(right, nod.right);
  return *this;
}

template<typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::operator==(const NodeLnk & nod) const noexcept {
  return (element == nod.element) \
    && ((left == nullptr && nod.left == nullptr) || (left != nullptr && nod.left != nullptr) && (*left == *nod.left)) \
    && ((right == nullptr && nod.right == nullptr) || (right != nullptr && nod.right != nullptr) && (*right == *nod.right));
}

template<typename Data>
inline bool BinaryTreeLnk<Data>::NodeLnk::operator!=(const NodeLnk & nod) const noexcept {
  return !(*this == nod);
}

template <typename Data>
inline const Data & BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept {
  return element;
}

template <typename Data>
inline Data & BinaryTreeLnk<Data>::NodeLnk::Element() noexcept {
  return element;
}

template <typename Data>
inline bool BinaryTreeLnk<Data>::NodeLnk::IsLeaf() const noexcept {
  return ((left == nullptr) && (right == nullptr));
}

template <typename Data>
inline bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept {
  return (left != nullptr);
}

template <typename Data>
inline bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept {
  return (right != nullptr);
}

template <typename Data>
inline const typename BinaryTreeLnk<Data>::Node& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const {
  if (left != nullptr) {
    return *left;
  } else {
    throw std::out_of_range("Left child does not exists.");
  }
}

template <typename Data>
inline const typename BinaryTreeLnk<Data>::Node& BinaryTreeLnk<Data>::NodeLnk::RightChild() const {
  if (right != nullptr) {
    return *right;
  } else {
    throw std::out_of_range("Right child does not exists.");
  }
}

template <typename Data>
inline typename BinaryTreeLnk<Data>::MutableNode& BinaryTreeLnk<Data>::NodeLnk::LeftChild() {
  if (left != nullptr) {
    return *left;
  } else {
    throw std::out_of_range("Left child does not exists.");
  }
}

template <typename Data>
inline typename BinaryTreeLnk<Data>::MutableNode& BinaryTreeLnk<Data>::NodeLnk::RightChild() {
  if (right != nullptr) {
    return *right;
  } else {
    throw std::out_of_range("Right child does not exists.");
  }
}

template<typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const TraversableContainer<Data>& con) {
  size = con.Size();
  QueueVec<NodeLnk **> Queue;
  Queue.Enqueue(&root);
  con.Traverse(
    [&Queue](const Data & dat) {
      NodeLnk *& cur = *Queue.HeadNDequeue();
      cur = new NodeLnk(dat);
      Queue.Enqueue(&cur->left);
      Queue.Enqueue(&cur->right);
    }
  );
};

template<typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(MappableContainer<Data>&& con) noexcept {
  size = con.Size();
  QueueVec<NodeLnk **> Queue;
  Queue.Enqueue(&root);
  con.Map(
    [&Queue](const Data & dat) {
      NodeLnk *& cur = *Queue.HeadNDequeue();
      cur = new NodeLnk(std::move(dat));
      Queue.Enqueue(&cur->left);
      Queue.Enqueue(&cur->right);
    }
  );
}

template<typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk & btl) {
  if (btl.root != nullptr) {
    root = new NodeLnk(*btl.root);
    size = btl.size;
  }
}

template<typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk && btl) noexcept {
  std::swap(root, btl.root);
  std::swap(size, btl.size);
}

template<typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk() {
  delete root;
}

template<typename Data>
BinaryTreeLnk<Data> & BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk<Data> & btl) {
  if (root == nullptr) {
    if (btl.root != nullptr) {
      root = new NodeLnk(*btl.root);
    }
  } else {
    if (btl.root == nullptr) {
      delete root;
      root = nullptr;
    } else {
      *root = *btl.root;
    }
  }
  size = btl.size;
  return *this;
}

template<typename Data>
BinaryTreeLnk<Data> & BinaryTreeLnk<Data>::operator=(BinaryTreeLnk<Data> && btl) noexcept {
  std::swap(root, btl.root);
  std::swap(size, btl.size);
  return *this;
}

template<typename Data>
bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk<Data> & btl) const noexcept {
  return (size == btl.size) && ((root == nullptr && btl.root == nullptr) || (root != nullptr && btl.root != nullptr) && (*root == *btl.root));
}

template<typename Data>
inline bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk<Data> & btl) const noexcept {
  return !(*this == btl);
}

template<typename Data>
const typename BinaryTreeLnk<Data>::Node & BinaryTreeLnk<Data>::Root() const {
  if (root != nullptr) {
    return *root;
  } else {
    throw std::length_error("Access to an empty tree.");
  }
}

template<typename Data>
typename BinaryTreeLnk<Data>::MutableNode & BinaryTreeLnk<Data>::Root() {
  if (root != nullptr) {
    return *root;
  } else {
    throw std::length_error("Access to an empty tree.");
  }
}

template<typename Data>
void BinaryTreeLnk<Data>::Clear() {
  delete root;
  root = nullptr;
  size = 0;
}

/* ************************************************************************** */

}
