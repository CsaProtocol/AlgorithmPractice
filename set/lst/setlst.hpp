
#ifndef SETLST_HPP
#define SETLST_HPP

/* ************************************************************************** */

#include "../set.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class SetLst : virtual public Set<Data>,
               virtual protected List<Data> {

protected:

  using Container::size;

  using List<Data>::head;
  using List<Data>::tail;
  using List<Data>::operator[];

public:

  using List<Data>::Node;
  using Container::Size;
  using Container::Empty;

  SetLst() = default;

  SetLst(const TraversableContainer<Data>&);
  SetLst(MappableContainer<Data>&&) noexcept;

  SetLst(const SetLst&);
  SetLst(SetLst&&) noexcept;

  ~SetLst() override;

  SetLst& operator=(const SetLst&);
  SetLst& operator=(SetLst&&) noexcept;

  bool operator==(const SetLst&) const noexcept;
  inline bool operator!=(const SetLst&) const noexcept;

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

protected:

  void DetachAndDelete(typename List<Data>::Node*, typename List<Data>::Node*) noexcept;
  void InsertBetween(typename List<Data>::Node*, const Data&, typename List<Data>::Node*) noexcept;
  void InsertBetween(typename List<Data>::Node*, Data&&, typename List<Data>::Node*) noexcept;

};

/* ************************************************************************** */

}

#include "setlst.cpp"

#endif
