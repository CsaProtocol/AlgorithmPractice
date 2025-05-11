// ReSharper disable CppUnusedIncludeDirective
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {

protected:

  unsigned long size = 0;
  Container() = default;

public:

  virtual ~Container() = default;

  Container& operator=(const Container&) = delete;
  Container& operator=(Container&&) noexcept = delete;

  virtual bool operator==(const Container&) const noexcept = delete;
  inline virtual bool operator!=(const Container&) const noexcept = delete;

  inline virtual bool Empty() const noexcept { return size == 0; }
  virtual unsigned long Size() const noexcept { return size; }

};

/* ************************************************************************** */

class ClearableContainer : virtual public Container {

public:

  ClearableContainer() = default;

  ~ClearableContainer() override = default;

  ClearableContainer& operator=(const ClearableContainer&) = delete;
  ClearableContainer& operator=(ClearableContainer&&) noexcept = delete;

  virtual bool operator==(const ClearableContainer&) const noexcept = delete;
  inline virtual bool operator!=(const ClearableContainer&) const noexcept = delete;

  virtual void Clear() = 0;

};

/* ************************************************************************** */

class ResizableContainer : virtual public ClearableContainer {

public:

  ResizableContainer() = default;

  ~ResizableContainer() override = default;

  ResizableContainer& operator=(const ResizableContainer&) = delete;
  ResizableContainer& operator=(ResizableContainer&&) noexcept = delete;

  virtual bool operator==(const ResizableContainer&) const noexcept = delete;
  inline virtual bool operator!=(const ResizableContainer&) const noexcept = delete;

  virtual void Resize(unsigned long newSize) = 0;
  inline void Clear() override { Resize(0); }

};

/* ************************************************************************** */

}

#endif
