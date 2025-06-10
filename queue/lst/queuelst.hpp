
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst : virtual public List<Data>,
                 virtual public Queue<Data> {

protected:
  using List<Data>::head;
  using List<Data>::tail;
  using List<Data>::Node;

public:

  QueueLst() = default;

  QueueLst(const TraversableContainer<Data>&);
  QueueLst(MappableContainer<Data>&&) noexcept;

  QueueLst(const QueueLst&);
  QueueLst(QueueLst&&) noexcept;

  ~QueueLst() override = default;

  QueueLst& operator=(const QueueLst&);
  QueueLst& operator=(QueueLst&&) noexcept;

  bool operator==(const QueueLst&) const noexcept;
  bool operator!=(const QueueLst&) const noexcept;

  const Data& Head() const override;
  Data& Head() override;
  void Dequeue() override;
  Data HeadNDequeue() override;
  void Enqueue(const Data&) override;
  void Enqueue(Data&&) noexcept override;

  using List<Data>::Empty;
  using List<Data>::Size;
  using List<Data>::Clear;

};

/* ************************************************************************** */

}

#include "queuelst.cpp"

#endif
