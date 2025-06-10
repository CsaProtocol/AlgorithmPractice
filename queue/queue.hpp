
#ifndef QUEUE_HPP
#define QUEUE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Queue : virtual public ClearableContainer {

public:

  Queue() = default;
  ~Queue() override = default;

  Queue& operator=(const Queue&) = delete;
  Queue& operator=(Queue&&) noexcept = delete;

  bool operator==(const Queue&) const noexcept = delete;
  bool operator!=(const Queue&) const noexcept = delete;

  virtual const Data& Head() const = 0;
  virtual Data& Head() = 0;
  virtual void Dequeue() = 0;
  virtual Data HeadNDequeue() = 0;
  virtual void Enqueue(const Data&) = 0;
  virtual void Enqueue(Data&&) noexcept = 0;

};

/* ************************************************************************** */

}

#endif
