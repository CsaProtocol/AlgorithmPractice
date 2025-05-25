
#ifndef LINEAR_HPP
#define LINEAR_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class LinearContainer : public virtual PreOrderTraversableContainer<Data>,
                        public virtual PostOrderTraversableContainer<Data> {

public:

  LinearContainer() = default;
  ~LinearContainer() override = default;

  LinearContainer& operator=(const LinearContainer&) = delete;
  LinearContainer& operator=(LinearContainer&&) noexcept = delete;

  bool operator==(const LinearContainer&) const noexcept;
  inline bool operator!=(const LinearContainer&) const noexcept;

  virtual const Data& operator[](unsigned long) const = 0;
  inline virtual const Data& Front() const;
  inline virtual const Data& Back() const;

  using typename TraversableContainer<Data>::TraverseFun;
  inline void Traverse(TraverseFun) const override;
  void PreOrderTraverse(TraverseFun) const override;
  void PostOrderTraverse(TraverseFun) const override;

};

/* ************************************************************************** */

template <typename Data>
class MutableLinearContainer : public virtual LinearContainer<Data>,
                               public virtual PreOrderMappableContainer<Data>,
                               public virtual PostOrderMappableContainer<Data> {

public:

  MutableLinearContainer() = default;
  ~MutableLinearContainer() override = default;

  MutableLinearContainer& operator=(const MutableLinearContainer&) = delete;
  MutableLinearContainer& operator=(MutableLinearContainer&&) noexcept = delete;

  using LinearContainer<Data>::operator[];
  using LinearContainer<Data>::Front;
  using LinearContainer<Data>::Back;

  virtual Data& operator[](unsigned long) = 0;
  inline virtual Data& Front();
  inline virtual Data& Back();

  using typename MappableContainer<Data>::MapFun;
  inline void Map(MapFun) override;
  void PreOrderMap(MapFun) override;
  void PostOrderMap(MapFun) override;

};

template <typename Data>
class SortableLinearContainer : public virtual MutableLinearContainer<Data> {

public:

  SortableLinearContainer() = default;
  ~SortableLinearContainer() override = default;

  SortableLinearContainer& operator=(const SortableLinearContainer&) = delete;
  SortableLinearContainer& operator=(SortableLinearContainer&&) = delete;

  virtual void Sort() noexcept;

protected:

  //void InsertionSort();
  void SelectionSort();
  //void MergeSort() noexcept;
  //void QuickSort(unsigned long, unsigned long);

};

/* ************************************************************************** */

}

#include "linear.cpp"

#endif
