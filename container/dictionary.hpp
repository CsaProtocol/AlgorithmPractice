
#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

/* ************************************************************************** */

#include "testable.hpp"
#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class DictionaryContainer : virtual public TestableContainer<Data> {

public:

  DictionaryContainer() = default;

  ~DictionaryContainer() override = default;

  DictionaryContainer& operator=(const DictionaryContainer&) = delete;
  DictionaryContainer& operator=(DictionaryContainer&&) = delete;

  virtual bool operator==(const DictionaryContainer&) const noexcept = delete;
  inline virtual bool operator!=(const DictionaryContainer&) const noexcept = delete;

  virtual bool Insert(const Data&) noexcept = 0;
  virtual bool Insert(Data&&) noexcept = 0;
  virtual bool Remove(const Data&) noexcept = 0;

  virtual bool InsertAll(const TraversableContainer<Data>&) noexcept;
  virtual bool InsertAll(MappableContainer<Data>&&) noexcept;
  virtual bool RemoveAll(const TraversableContainer<Data>&) noexcept;

  virtual bool InsertSome(const TraversableContainer<Data>&) noexcept;
  virtual bool InsertSome(MappableContainer<Data>&&) noexcept;
  virtual bool RemoveSome(const TraversableContainer<Data>&) noexcept;

};

/* ************************************************************************** */

template <typename Data>
class OrderedDictionaryContainer : virtual public DictionaryContainer<Data> {

public:

  OrderedDictionaryContainer() = default;

  ~OrderedDictionaryContainer() override = default;

  OrderedDictionaryContainer& operator=(const OrderedDictionaryContainer&) = delete;
  OrderedDictionaryContainer& operator=(OrderedDictionaryContainer&&) = delete;

  virtual bool operator==(const OrderedDictionaryContainer&) const noexcept = delete;
  inline virtual bool operator!=(const OrderedDictionaryContainer&) const noexcept = delete;

  virtual const Data& Min() const = 0;
  virtual Data MinNRemove() = 0;
  virtual void RemoveMin() = 0;

  virtual const Data& Max() const = 0;
  virtual Data MaxNRemove() = 0;
  virtual void RemoveMax() = 0;

  virtual const Data& Predecessor(const Data&) const = 0;
  virtual Data PredecessorNRemove(const Data&) = 0;
  virtual void RemovePredecessor(const Data&) = 0;

  virtual const Data& Successor(const Data&) const = 0;
  virtual Data SuccessorNRemove(const Data&) = 0;
  virtual void RemoveSuccessor(const Data&) = 0;

};

/* ************************************************************************** */

}

#include "dictionary.cpp"

#endif
