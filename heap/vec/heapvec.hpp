#ifndef HEAPVEC_HPP
#define HEAPVEC_HPP

/* ************************************************************************** */

#include "../heap.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
  requires std::totally_ordered<Data>
class HeapVec : virtual public Heap<Data> {

protected:

  using Container::size;
  Vector<Data>* vec = nullptr;

  Data& operator[](unsigned long) override;

public:

  HeapVec() = default;
  HeapVec(const TraversableContainer<Data>&);
  HeapVec(MappableContainer<Data>&&) noexcept;

  HeapVec(const HeapVec&);
  HeapVec(HeapVec&&) noexcept;

  ~HeapVec() override;

  HeapVec& operator=(const HeapVec&);
  HeapVec& operator=(HeapVec&&) noexcept;

  bool operator==(const HeapVec&) const noexcept;
  bool operator!=(const HeapVec&) const noexcept;

  void Clear() override;

  const Data& operator[](unsigned long) const override;

  bool IsHeap() const noexcept override;
  void Heapify() override;

  void Sort() noexcept override;

protected:

  [[nodiscard]] static inline unsigned long parent(const unsigned long index) noexcept {
    return (index - 1) / 2;
  }
  [[nodiscard]] static inline unsigned long leftChild(const unsigned long index) noexcept {
    return 2 * index + 1;
  }
  [[nodiscard]] static inline unsigned long rightChild(const unsigned long index) noexcept {
    return 2 * index + 2;
  }

  void HeapifyDown(unsigned long) noexcept;
  void HeapifyUp(unsigned long) noexcept;

  void HeapSort();

};

/* ************************************************************************** */

}

#include "heapvec.cpp"

#endif
