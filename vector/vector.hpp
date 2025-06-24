
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector : virtual public MutableLinearContainer<Data>,
               virtual public ResizableContainer {

protected:

  using Container::size;

  Data* elements = nullptr;

public:

  using Container::Size;
  using Container::Empty;

  Vector() = default;
  Vector(unsigned long);

  Vector(const TraversableContainer<Data>&);
  Vector(MappableContainer<Data>&&) noexcept;

  Vector(const Vector&);
  Vector(Vector&&) noexcept;

  ~Vector() override;

  Vector& operator=(const Vector&);
  Vector& operator=(Vector&&) noexcept;

  bool operator==(const Vector&) const noexcept;
  inline bool operator!=(const Vector&) const noexcept;

  const Data& operator[](unsigned long) const override;
  inline const Data& Front() const override;
  inline const Data& Back() const override;

  Data& operator[](unsigned long) override;
  inline Data& Front() override;
  inline Data& Back() override;

  void Resize(unsigned long) override;
  void Fill(const Data&);
  void Clear() override;

};

/* ************************************************************************** */

template <typename Data>
  requires std::totally_ordered<Data>
class SortableVector : virtual public Vector<Data>,
                       virtual public SortableLinearContainer<Data> {

protected:

  using Container::size;
  using Vector<Data>::elements;

public:

  using Container::Size;
  using Container::Empty;

  SortableVector() = default;
  SortableVector(unsigned long);
  SortableVector(const TraversableContainer<Data>&);
  SortableVector(MappableContainer<Data>&&) noexcept;

  SortableVector(const SortableVector&);
  SortableVector(SortableVector&&) noexcept;

  ~SortableVector() override;

  SortableVector& operator=(const SortableVector&);
  SortableVector& operator=(SortableVector&&) noexcept;

};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
