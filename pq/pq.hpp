
#ifndef PQ_HPP
#define PQ_HPP

/* ************************************************************************** */

#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
  requires std::totally_ordered<Data>
class PQ : virtual public LinearContainer<Data>,
           virtual public ClearableContainer {

public:

  PQ() = default;

  ~PQ() override = default;

  PQ& operator=(const PQ&) = delete;
  PQ& operator=(PQ&&) = delete;

  virtual const Data& Tip() const = 0;
  virtual void RemoveTip() = 0;
  virtual Data TipNRemove() = 0;

  virtual void Insert(const Data&) noexcept = 0;
  virtual void Insert(Data&&) noexcept = 0;

  virtual void Change(unsigned long, const Data&) = 0;
  virtual void Change(unsigned long, Data&&) = 0;

};

/* ************************************************************************** */

}

#endif

