
#ifndef TRAVERSABLE_HPP
#define TRAVERSABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "testable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class TraversableContainer : virtual public TestableContainer<Data> {

public:

  TraversableContainer() = default;

  ~TraversableContainer() override = default;

  TraversableContainer& operator=(const TraversableContainer&) = delete;
  TraversableContainer& operator=(TraversableContainer&&) noexcept = delete;

  bool operator==(const TraversableContainer&) const noexcept = delete;
  inline bool operator!=(const TraversableContainer&) const noexcept = delete;

  using TraverseFun = std::function<void(const Data &)>;
  virtual void Traverse(TraverseFun) const = 0;

  template <typename Accumulator>
  using FoldFun = std::function<Accumulator(const Data &, const Accumulator &)>;

  template <typename Accumulator>
  Accumulator Fold(FoldFun<Accumulator>, Accumulator) const;

  bool Exists(const Data& toFind) const noexcept override;

};

/* ************************************************************************** */

template <typename Data>
class PreOrderTraversableContainer : virtual public TraversableContainer<Data> {

public:

  PreOrderTraversableContainer() = default;
  ~PreOrderTraversableContainer() override = default;

  PreOrderTraversableContainer& operator=(const PreOrderTraversableContainer&) = delete;
  PreOrderTraversableContainer& operator=(PreOrderTraversableContainer&&) noexcept = delete;

  bool operator==(const PreOrderTraversableContainer&) const noexcept = delete;
  inline bool operator!=(const PreOrderTraversableContainer&) const noexcept = delete;

  using typename TraversableContainer<Data>::TraverseFun;
  virtual void PreOrderTraverse(TraverseFun) const = 0;

  template<typename Accumulator>
  using FoldFun = typename TraversableContainer<Data>::template FoldFun<Accumulator>;

  template <typename Accumulator>
  Accumulator PreOrderFold(FoldFun<Accumulator>, Accumulator) const;

  inline void Traverse(TraverseFun fun) const override {
    PreOrderTraverse(fun);
  }

};

/* ************************************************************************** */

template <typename Data>
class PostOrderTraversableContainer : virtual public TraversableContainer<Data> {

public:

  PostOrderTraversableContainer() = default;
  ~PostOrderTraversableContainer() override = default;

  PostOrderTraversableContainer& operator=(const PostOrderTraversableContainer&) = delete;
  PostOrderTraversableContainer& operator=(PostOrderTraversableContainer&&) noexcept = delete;

  bool operator==(const PostOrderTraversableContainer&) const noexcept = delete;
  inline bool operator!=(const PostOrderTraversableContainer&) const noexcept = delete;

  using typename TraversableContainer<Data>::TraverseFun;
  virtual void PostOrderTraverse(TraverseFun) const = 0;

  template <typename Accumulator>
  using FoldFun = typename TraversableContainer<Data>::template FoldFun<Accumulator>;

  template <typename Accumulator>
  Accumulator PostOrderFold(FoldFun<Accumulator>, Accumulator) const;

  inline void Traverse(TraverseFun fun) const override {
    PostOrderTraverse(fun);
  }

};

/* ************************************************************************** */

template <typename Data>
class InOrderTraversableContainer : virtual public TraversableContainer<Data> {

public:

  InOrderTraversableContainer() = default;
  ~InOrderTraversableContainer() override = default;

  InOrderTraversableContainer& operator=(const InOrderTraversableContainer&) = delete;
  InOrderTraversableContainer& operator=(InOrderTraversableContainer&&) noexcept = delete;

  bool operator==(const InOrderTraversableContainer&) const noexcept = delete;
  bool operator!=(const InOrderTraversableContainer&) const noexcept = delete;

  using typename TraversableContainer<Data>::TraverseFun;
  virtual void InOrderTraverse(TraverseFun) const = 0;

  template <typename Accumulator>
  using FoldFun = typename TraversableContainer<Data>::template FoldFun<Accumulator>;

  template <typename Accumulator>
  Accumulator InOrderFold(FoldFun<Accumulator>, Accumulator) const;

  inline void Traverse(TraverseFun fun) const override {
    InOrderTraverse(fun);
  }

};

/* ************************************************************************** */

template <typename Data>
class BreadthTraversableContainer : virtual public TraversableContainer<Data> {
public:

  BreadthTraversableContainer() = default;
  ~BreadthTraversableContainer() override = default;

  BreadthTraversableContainer& operator=(const BreadthTraversableContainer&) = delete;
  BreadthTraversableContainer& operator=(BreadthTraversableContainer&&) noexcept = delete;

  bool operator==(const BreadthTraversableContainer&) const noexcept = delete;
  bool operator!=(const BreadthTraversableContainer&) const noexcept = delete;

  using typename TraversableContainer<Data>::TraverseFun;
  virtual void BreadthTraverse(TraverseFun) const = 0;

  template <typename Accumulator>
  using FoldFun = typename TraversableContainer<Data>::template FoldFun<Accumulator>;

  template <typename Accumulator>
  Accumulator BreadthFold(FoldFun<Accumulator>, Accumulator) const;

  inline void Traverse(TraverseFun fun) const override {
    BreadthTraverse(fun);
  }

};

/* ************************************************************************** */

}

#include "traversable.cpp"

#endif
