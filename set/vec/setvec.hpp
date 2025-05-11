
#ifndef SETVEC_HPP
#define SETVEC_HPP

/* ************************************************************************** */

#include "../set.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class SetVec : virtual public Set<Data>,
               virtual public ResizableContainer {

protected:

  using Container::size;

  Vector<Data>* vec = nullptr;
  unsigned long head = 0;

public:

  using Container::Size;
  using Container::Empty;

  SetVec();

  SetVec(const TraversableContainer<Data>&);
  SetVec(MappableContainer<Data>&&) noexcept;

  SetVec(const SetVec&);
  SetVec(SetVec&&) noexcept;

  ~SetVec() override;

  SetVec& operator=(const SetVec&);
  SetVec& operator=(SetVec&&) noexcept;

  virtual bool operator==(const SetVec&) const noexcept;
  inline virtual bool operator!=(const SetVec&) const noexcept;

  const Data& Min() const override;
  Data MinNRemove() override;
  void RemoveMin() override;

  const Data& Max() const override;
  Data MaxNRemove() override;
  void RemoveMax() override;

  const Data& Predecessor(const Data&) const override;
  Data PredecessorNRemove(const Data&) override;
  void RemovePredecessor(const Data&) override;

  const Data& Successor(const Data&) const override;
  Data SuccessorNRemove(const Data&) override;
  void RemoveSuccessor(const Data&) override;

  bool Insert(const Data&) noexcept override;
  bool Insert(Data&&) noexcept override;
  bool Remove(const Data&) noexcept override;

  const Data& operator[](unsigned long) const override;

  bool Exists(const Data&) const noexcept override;

  void Clear() override;
  void Resize(unsigned long) override;

protected:

  void InsertAt(unsigned long, const Data&) noexcept;
  void InsertAt(unsigned long, Data&&) noexcept;
  void RemoveAt(unsigned long) noexcept;

  [[nodiscard]] unsigned long physicalIndex(const unsigned long logicalIndex) const {
    return (head + logicalIndex) % vec->Size();
  }

};

/* ************************************************************************** */

}

#include "setvec.cpp"

#endif
