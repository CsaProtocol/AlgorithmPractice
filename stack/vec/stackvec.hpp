
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec : virtual public Stack<Data> {

protected:
	using Container::size;
  Vector<Data>* vec = nullptr;

  static constexpr unsigned long defaultStackVecSize = 16;

public:

  StackVec();

  StackVec(const TraversableContainer<Data>&);
  StackVec(MappableContainer<Data>&&) noexcept;

  StackVec(const StackVec&);
  StackVec(StackVec&&) noexcept;

  ~StackVec() override;

  StackVec& operator=(const StackVec&);
  StackVec& operator=(StackVec&&) noexcept;

  bool operator==(const StackVec&) const noexcept;
  bool operator!=(const StackVec&) const noexcept;

  const Data& Top() const override;
  Data& Top() override;
  void Pop() override;
  Data TopNPop() override;
  void Push(const Data&) override;
  void Push(Data&&) noexcept override;

  using Container::Size;
  using Container::Empty;

  void Clear() override;

};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif
