
#ifndef TESTABLE_HPP
#define TESTABLE_HPP

/* ************************************************************************** */

#include "container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class TestableContainer : virtual public Container {

public:

  TestableContainer() = default;

  ~TestableContainer() override = default;

  TestableContainer& operator=(const TestableContainer&) = delete;
  TestableContainer& operator=(TestableContainer&&) noexcept = delete;

  virtual bool operator==(const TestableContainer&) const noexcept = delete;
  virtual bool operator!=(const TestableContainer&) const noexcept = delete;

  virtual bool Exists(const Data&) const noexcept = 0;

};

/* ************************************************************************** */

}

#endif
