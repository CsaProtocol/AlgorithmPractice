
#ifndef HEAP_HPP
#define HEAP_HPP

/* ************************************************************************** */

#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
    requires std::totally_ordered<Data>
class Heap : virtual public SortableLinearContainer<Data>,
             virtual public ClearableContainer {

public:

  Heap() = default;
  ~Heap() override = default;

  Heap& operator=(const Heap&) = delete;
  Heap& operator=(Heap&&) noexcept = delete;

  virtual bool IsHeap() const noexcept = 0;
  virtual void Heapify() = 0;

};

/* ************************************************************************** */

}

#endif
