
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List : virtual public MutableLinearContainer<Data>,
             virtual public ClearableContainer {

protected:

  using Container::size;

  struct Node {
    Data value;
    Node* next;

    inline Node() : value(), next(nullptr) {}
    inline Node(const Data& toInsert) : value(toInsert), next(nullptr) {}
    inline Node(Data&& toInsert) noexcept : next(nullptr) {
      std::swap(value, toInsert);
    }

    inline Node(const Data& toInsert, Node* toInsertNext) : value(toInsert), next(toInsertNext) {}

    Node(const Node&) = delete;
    Node(Node&& toMove) noexcept = delete;
    ~Node() = default;

    bool operator==(const Node& toCompare) const noexcept;
    inline bool operator!=(const Node& toCompare) const noexcept;

  };

  Node* head = nullptr;
  Node* tail = nullptr;

public:

  using Container::Size;
  using Container::Empty;

  List() = default;
  List(const TraversableContainer<Data>&);
  List(MappableContainer<Data>&&) noexcept;

  List(const List&);
  List(List&&) noexcept;

  ~List() noexcept override;

  List& operator=(const List&);
  List& operator=(List&&) noexcept;

  bool operator==(const List&) const noexcept;
  inline bool operator!=(const List&) const noexcept;

  virtual void InsertAtFront(const Data&);
  virtual void InsertAtFront(Data&&);
  virtual void RemoveFromFront();
  virtual Data FrontNRemove();

  virtual void InsertAtBack(const Data&);
  virtual void InsertAtBack(Data&&);
  virtual void RemoveFromBack();
  virtual Data BackNRemove();

  Data& operator[](unsigned long) override;
  Data& Front() override;
  Data& Back() override;

  const Data& operator[](unsigned long) const override;
  const Data& Front() const override;
  const Data& Back() const override;

  using typename MappableContainer<Data>::MapFun;
  void Map(MapFun) override;
  void PreOrderMap(MapFun) override;
  void PostOrderMap(MapFun) override;

  using typename TraversableContainer<Data>::TraverseFun;
  void Traverse(TraverseFun) const override;
  void PreOrderTraverse(TraverseFun) const override;
  void PostOrderTraverse(TraverseFun) const override;

  void Clear() override;

protected:

  void PostOrderTraverseAux(Node*, TraverseFun) const;
  void PostOrderMapAux(Node*, MapFun);

};

/* ************************************************************************** */

}

#include "list.cpp"

#endif
