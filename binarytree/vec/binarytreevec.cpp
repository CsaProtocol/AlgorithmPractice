namespace lasd {

template <typename Data>
inline Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept {
  return Tree->elements[Index()];
}

template <typename Data>
inline const Data& BinaryTreeVec<Data>::NodeVec::Element() const noexcept {
  return Tree->elements[Index()];
}

template <typename Data>
inline bool BinaryTreeVec<Data>::NodeVec::IsLeaf() const noexcept {
  return (2 * Index() + 1 >= Tree->size);
}

template <typename Data>
inline bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept {
  return (2 * Index() + 1 < Tree->size);
}

template <typename Data>
inline bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
  return (2 * Index() + 2 < Tree->size);
}

template <typename Data>
inline const typename BinaryTreeVec<Data>::Node& BinaryTreeVec<Data>::NodeVec::LeftChild() const {
  ulong child = 2 * Index() + 1;
  if (child < Tree->size) {
    return Tree->Nodes[child];
  } else {
    throw std::out_of_range("Left child does not exists.");
  }
}

template <typename Data>
inline const typename BinaryTreeVec<Data>::Node& BinaryTreeVec<Data>::NodeVec::RightChild() const {
  ulong child = 2 * Index() + 2;
  if (child < Tree->size) {
    return Tree->Nodes[child];
  } else {
    throw std::out_of_range("Right child does not exists.");
  }
}

template <typename Data>
inline typename BinaryTreeVec<Data>::MutableNode& BinaryTreeVec<Data>::NodeVec::LeftChild() {
  ulong child = 2 * Index() + 1;
  if (child < Tree->size) {
    return Tree->Nodes[child];
  } else {
    throw std::out_of_range("Left child does not exists.");
  }
}

template <typename Data>
inline typename BinaryTreeVec<Data>::MutableNode& BinaryTreeVec<Data>::NodeVec::RightChild() {
  ulong child = 2 * Index() + 2;
  if (child < Tree->size) {
    return Tree->Nodes[child];
  } else {
    throw std::out_of_range("Right child does not exists.");
  }
}


template <typename Data>
inline ulong BinaryTreeVec<Data>::NodeVec::Index() const noexcept {
  return (this - Tree->Nodes);
}

template<typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const TraversableContainer<Data>& con) : Vector<Data>(con) {
  BinaryTreeVec::NewNodeArray();
}

template<typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(MappableContainer<Data>&& con) : Vector<Data>(std::move(con)) {
  BinaryTreeVec::NewNodeArray();
}

template<typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec& btv) : Vector<Data>(btv) {
  BinaryTreeVec::NewNodeArray();
}

template<typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec&& btv) noexcept : Vector<Data>(std::move(btv)) {
  BinaryTreeVec::SwapNodeArrays(std::move(btv));
}

template<typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec() {
  delete[] Nodes;
}

template<typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec& btv) {
  Vector<Data>::operator=(btv);
  NewNodeArray();
  return *this;
}

template<typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec&& btv) noexcept {
  Vector<Data>::operator=(std::move(btv));
  SwapNodeArrays(std::move(btv));
  return *this;
}

template<typename Data>
inline bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec & btv) const noexcept {
  return Vector<Data>::operator==(btv);
}

template<typename Data>
inline bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec & btv) const noexcept {
  return Vector<Data>::operator!=(btv);
}

template<typename Data>
const typename BinaryTreeVec<Data>::Node& BinaryTreeVec<Data>::Root() const {
  if (size != 0) {
    return Nodes[0];
  } else {
    throw std::length_error("Access to an empty tree.");
  }
}

template<typename Data>
typename BinaryTreeVec<Data>::MutableNode& BinaryTreeVec<Data>::Root() {
  if (size != 0) {
    return Nodes[0];
  } else {
    throw std::length_error("Access to an empty tree.");
  }
}

template<typename Data>
void BinaryTreeVec<Data>::Clear() {
  Vector<Data>::Clear();
  delete[] Nodes;
  Nodes = nullptr;
}

template<typename Data>
inline void BinaryTreeVec<Data>::Traverse(TraverseFun fun) const {
  BinaryTree<Data>::Traverse(fun);
}

template<typename Data>
inline void BinaryTreeVec<Data>::PreOrderTraverse(TraverseFun fun) const {
  BinaryTree<Data>::PreOrderTraverse(fun);
}

template<typename Data>
inline void BinaryTreeVec<Data>::PostOrderTraverse(TraverseFun fun) const {
  BinaryTree<Data>::PostOrderTraverse(fun);
}

template<typename Data>
inline void BinaryTreeVec<Data>::BreadthTraverse(TraverseFun fun) const {
  Vector<Data>::PreOrderTraverse(fun);
}

template<typename Data>
inline void BinaryTreeVec<Data>::Map(MapFun fun) {
  MutableBinaryTree<Data>::Map(fun);
}

template<typename Data>
inline void BinaryTreeVec<Data>::PreOrderMap(MapFun fun) {
  MutableBinaryTree<Data>::PreOrderMap(fun);
}

template<typename Data>
inline void BinaryTreeVec<Data>::PostOrderMap(MapFun fun) {
  MutableBinaryTree<Data>::PostOrderMap(fun);
}

template<typename Data>
inline void BinaryTreeVec<Data>::BreadthMap(MapFun fun) {
  Vector<Data>::PreOrderMap(fun);
}

template<typename Data>
inline void BinaryTreeVec<Data>::NewNodeArray() {
  delete[] Nodes;
  Nodes = new NodeVec[size] {};
  for (ulong index = 0; index < size; ++index) {
    Nodes[index].Tree = this;
  }
}

template<typename Data>
inline void BinaryTreeVec<Data>::SwapNodeArrays(BinaryTreeVec && btv) noexcept {
  std::swap(Nodes, btv.Nodes);
  for (ulong index = 0; index < size; ++index) {
    Nodes[index].Tree = this;
  }
  for (ulong index = 0; index < btv.size; ++index) {
    btv.Nodes[index].Tree = &btv;
  }
}

/* ************************************************************************** */

}
