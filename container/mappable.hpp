
#ifndef MAPPABLE_HPP
#define MAPPABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "traversable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class MappableContainer : virtual public TraversableContainer<Data> {

public:

  MappableContainer() = default;

  ~MappableContainer() override = default;

  MappableContainer& operator=(const MappableContainer&) = delete;
  MappableContainer& operator=(MappableContainer&&) noexcept = delete;

  virtual bool operator==(const MappableContainer&) const noexcept = delete;
  inline virtual bool operator!=(const MappableContainer&) const noexcept = delete;

  using MapFun = std::function<void(Data &)>;
  virtual void Map(MapFun) = 0;

};

/* ************************************************************************** */

template <typename Data>
class PreOrderMappableContainer : virtual public MappableContainer<Data>,
                                  virtual public PreOrderTraversableContainer<Data> {

public:

  PreOrderMappableContainer() = default;

  ~PreOrderMappableContainer() override  = default;

  PreOrderMappableContainer& operator=(const PreOrderMappableContainer&) = delete;
  PreOrderMappableContainer& operator=(PreOrderMappableContainer&&) noexcept = delete;

  virtual bool operator==(const PreOrderMappableContainer&) const noexcept = delete;
  inline virtual bool operator!=(const PreOrderMappableContainer&) const noexcept = delete;

  using typename MappableContainer<Data>::MapFun;
  virtual void PreOrderMap(MapFun) = 0;

  inline void Map(MapFun fun) override {
    PreOrderMap(fun);
  }

};

/* ************************************************************************** */

template <typename Data>
class PostOrderMappableContainer : virtual public MappableContainer<Data>,
                                   virtual public PostOrderTraversableContainer<Data> {

public:

  PostOrderMappableContainer() = default;

  ~PostOrderMappableContainer() override = default;

  PostOrderMappableContainer& operator=(const PostOrderMappableContainer&) = delete;
  PostOrderMappableContainer& operator=(PostOrderMappableContainer&&) noexcept = delete;

  virtual bool operator==(const PostOrderMappableContainer&) const noexcept = delete;
  inline virtual bool operator!=(const PostOrderMappableContainer&) const noexcept = delete;

  using typename MappableContainer<Data>::MapFun;
  virtual void PostOrderMap(MapFun) = 0;

  void Map(MapFun fun) override {
    PostOrderMap(fun);
  }

};

/* ************************************************************************** */

}

#include "mappable.cpp"

#endif
