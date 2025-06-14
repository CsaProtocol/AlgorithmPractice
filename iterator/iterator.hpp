
#ifndef ITERATOR_HPP
#define ITERATOR_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Iterator {

public:

  Iterator() = default;
  virtual ~Iterator() = default;

  Iterator & operator=(const Iterator &) = delete;
  Iterator & operator=(Iterator &&) noexcept = delete;

  bool operator==(const Iterator &) const noexcept = delete;
  bool operator!=(const Iterator &) const noexcept = delete;

  virtual const Data& operator*() const = 0;
  inline virtual const Data* operator->() const {
    return (&(operator*()));
  }

  virtual bool Terminated() const noexcept = 0;

};

/* ************************************************************************** */

template <typename Data>
class MutableIterator : virtual public Iterator<Data> {

public:

  MutableIterator() = default;
  ~MutableIterator() override = default;

  MutableIterator& operator=(const MutableIterator&) = delete;
  MutableIterator& operator=(MutableIterator&&) noexcept = delete;

  bool operator==(const MutableIterator&) const noexcept = delete;
  bool operator!=(const MutableIterator&) const noexcept = delete;

  using Iterator<Data>::operator*;
  virtual Data& operator*() = 0;

  using Iterator<Data>::operator->;
  inline virtual Data * operator->() {
    return (&(operator*()));
  }

};

/* ************************************************************************** */

template <typename Data>
class ForwardIterator : virtual public Iterator<Data> {

public:

  ForwardIterator() = default;
  ~ForwardIterator() override = default;

  ForwardIterator& operator=(const ForwardIterator &) = delete;
  ForwardIterator& operator=(ForwardIterator &&) noexcept = delete;

  bool operator==(const ForwardIterator &) const noexcept = delete;
  bool operator!=(const ForwardIterator &) const noexcept = delete;

  virtual ForwardIterator& operator++() = 0;

};

/* ************************************************************************** */

template <typename Data>
class ResettableIterator : virtual public Iterator<Data> {

public:

  ResettableIterator() = default;
  ~ResettableIterator() override = default;

  ResettableIterator & operator=(const ResettableIterator &) = delete;
  ResettableIterator & operator=(ResettableIterator &&) noexcept = delete;

  bool operator==(const ResettableIterator &) const noexcept = delete;
  bool operator!=(const ResettableIterator &) const noexcept = delete;

  virtual void Reset() noexcept = 0;

};

/* ************************************************************************** */

}

#endif
