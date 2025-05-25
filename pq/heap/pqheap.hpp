#ifndef PQHEAP_HPP
#define PQHEAP_HPP

/* ************************************************************************** */

#include "../pq.hpp"
#include "../../heap/vec/heapvec.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
  requires std::totally_ordered<Data>
class PQHeap : virtual public PQ<Data>,
               virtual public HeapVec<Data> {

protected:

  using Container::size;
  using HeapVec<Data>::vec;

public:

  PQHeap();

  PQHeap(const TraversableContainer<Data>&);
  PQHeap(MappableContainer<Data>&&) noexcept;

  PQHeap(const PQHeap&);
  PQHeap(PQHeap&&) noexcept;

  ~PQHeap() override = default;

  PQHeap& operator=(const PQHeap&);
  PQHeap& operator=(PQHeap&&) noexcept;

  const Data& Tip() const override;
  void RemoveTip() override;
  Data TipNRemove() override;

  void Insert(const Data&) noexcept override;
  void Insert(Data&&) noexcept override;

  void Change(unsigned long, const Data&) override;
  void Change(unsigned long, Data&&) override;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "pqheap.cpp"

#endif
