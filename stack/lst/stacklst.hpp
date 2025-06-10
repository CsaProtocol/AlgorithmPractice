
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst : virtual public Stack<Data>,
                 virtual public List<Data> {

protected:

  using List<Data>::head;
  using List<Data>::tail;
  using List<Data>::size;
  using List<Data>::Node;

public:

  StackLst() = default;

  StackLst(const TraversableContainer<Data>&);
  StackLst(MappableContainer<Data>&&) noexcept;

  StackLst(const StackLst&);
  StackLst(StackLst&&) noexcept;

  ~StackLst() override = default;

  StackLst& operator=(const StackLst&);
  StackLst& operator=(StackLst&&) noexcept;

  bool operator==(const StackLst&) const noexcept;
  bool operator!=(const StackLst&) const noexcept;

  const Data& Top() const override;
  Data& Top() override;
  void Pop() override;
  Data TopNPop() override;
  void Push(const Data&) override;
  void Push(Data&&) noexcept override;

  using List<Data>::Clear;

};

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif


