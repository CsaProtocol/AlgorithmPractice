
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk : virtual public MutableBinaryTree<Data> {

protected:

  using Container::size;

public:

  using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;

protected:

  struct NodeLnk : virtual MutableNode {

    friend class BinaryTreeLnk;

    NodeLnk * left = nullptr;
    NodeLnk * right = nullptr;
    Data element;

    NodeLnk(const Data& dat) noexcept : element(dat) {};
    NodeLnk(Data&& dat) noexcept;

    NodeLnk(const NodeLnk &);
    NodeLnk(NodeLnk &&) noexcept;

    ~NodeLnk() override;

    NodeLnk& operator=(const NodeLnk &);
    NodeLnk& operator=(NodeLnk &&) noexcept;

    bool operator==(const NodeLnk &) const noexcept;
    inline bool operator!=(const NodeLnk &) const noexcept;

    inline const Data & Element() const noexcept override;
    inline Data & Element() noexcept override;

    inline bool IsLeaf() const noexcept override;
    inline bool HasLeftChild() const noexcept override;
    inline bool HasRightChild() const noexcept override;

    const Node& LeftChild() const override;
    const Node& RightChild() const override;

    MutableNode& LeftChild() override;
    MutableNode& RightChild() override;

  };

public:

  BinaryTreeLnk() = default;

  BinaryTreeLnk(const TraversableContainer<Data>&);
  BinaryTreeLnk(MappableContainer<Data>&&) noexcept;

  BinaryTreeLnk(const BinaryTreeLnk &);

  // Move constructor
  BinaryTreeLnk(BinaryTreeLnk &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTreeLnk();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeLnk & operator=(const BinaryTreeLnk &);

  // Move assignment
  BinaryTreeLnk & operator=(BinaryTreeLnk &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  using BinaryTree<Data>::operator==;
  inline bool operator==(const BinaryTreeLnk &) const noexcept;
  using BinaryTree<Data>::operator!=;
  inline bool operator!=(const BinaryTreeLnk &) const noexcept;

  /* ************************************************************************ */

  // Specific member function (inherited from BinaryTree)

  const Node & Root() const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  MutableNode & Root() override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override;

protected:

  NodeLnk * root = nullptr;

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
