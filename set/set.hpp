
#ifndef SET_HPP
#define SET_HPP

/* ************************************************************************** */

#include "../container/dictionary.hpp"
#include "../container/linear.hpp"
#include "../container/traversable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Set : virtual public OrderedDictionaryContainer<Data>,
            virtual public LinearContainer<Data>,
            virtual public ClearableContainer {

public:

    Set() = default;
    ~Set() override = default;

    Set& operator=(const Set&) = delete;
    Set& operator=(Set&&) noexcept = delete;

};

/* ************************************************************************** */

}

#endif
