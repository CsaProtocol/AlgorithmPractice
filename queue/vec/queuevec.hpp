
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec : virtual public Queue<Data> {

protected:
	using Container::size;

  Vector<Data>* vec = nullptr;
  unsigned long head = 0;
  static constexpr unsigned long defaultQueueVecSize = 5;

public:
  QueueVec();

  QueueVec(const TraversableContainer<Data>&);
  QueueVec(MappableContainer<Data>&&) noexcept;

  QueueVec(const QueueVec&);
  QueueVec(QueueVec&&) noexcept;

  ~QueueVec() override = default;

  QueueVec& operator=(const QueueVec&);
  QueueVec& operator=(QueueVec&&) noexcept;

  bool operator==(const QueueVec&) const noexcept;
  bool operator!=(const QueueVec&) const noexcept;

  const Data& Head() const override;
  Data& Head() override;
  void Dequeue() override;
  Data HeadNDequeue() override;
  void Enqueue(const Data&) override;
  void Enqueue(Data&&) noexcept override;

  using Container::Empty;
  using Container::Size;
  void Clear() override;

protected:
  void DequeueAux() noexcept;
  [[nodiscard]] unsigned long physicalIndex(const unsigned long logicalIndex) const {
    return (head + logicalIndex) % vec->Size();
  }
  void Resize(unsigned long newSize);

};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
