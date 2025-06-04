
#include <cstring>

namespace lasd {

unsigned long constexpr defaultSetVecSize = 5;

/* ************************************************************************** */

template <typename Data>
SetVec<Data>::SetVec() {
    vec = new Vector<Data>(defaultSetVecSize);
    head = 0;
    size = 0;
}

template <typename Data>
SetVec<Data>::SetVec(const TraversableContainer<Data>& toCopy) : SetVec() {
    auto functor = [this](const Data& data) {
        Insert(data);
    };
    toCopy.Traverse(functor);
}

template<typename Data>
SetVec<Data>::SetVec(MappableContainer<Data>&& toMove) noexcept : SetVec() {
    auto functor = [this](Data& data) {
        Insert(std::move(data));
    };
    toMove.Map(functor);
}

template<typename Data>
SetVec<Data>::SetVec(const SetVec& toCopy) {
    vec = new Vector<Data>(*(toCopy.vec));
    head = toCopy.head;
    size = toCopy.size;
}

template<typename Data>
SetVec<Data>::SetVec(SetVec&& toMove) noexcept {
    std::swap(vec, toMove.vec);
    std::swap(head, toMove.head);
    std::swap(size, toMove.size);
}

template<typename Data>
SetVec<Data>::~SetVec() {
    delete vec;
    vec = nullptr;
}

template<typename Data>
SetVec<Data>& SetVec<Data>::operator=(const SetVec& toCopy) {
    if(this != &toCopy) {
        delete vec;
        vec = new Vector<Data>(*(toCopy.vec));
        head = toCopy.head;
        size = toCopy.size;
    }
    return *this;
}

template<typename Data>
SetVec<Data>& SetVec<Data>::operator=(SetVec&& toMove) noexcept {
    if(this != &toMove) {
        std::swap(vec, toMove.vec);
        std::swap(head, toMove.head);
        std::swap(size, toMove.size);
    }
    return *this;
}

template<typename Data>
bool SetVec<Data>::operator==(const SetVec& toCompare) const noexcept {
    if(size != toCompare.size) {
        return false;
    }
    for(unsigned long i = 0; i < size; i++) {
        if(vec->operator[](physicalIndex(i)) != toCompare.vec->operator[](toCompare.physicalIndex(i))) {
            return false;
        }
    } return true;
}

template<typename Data>
bool SetVec<Data>::operator!=(const SetVec& toCompare) const noexcept {
    return !(*this == toCompare);
}

template<typename Data>
const Data& SetVec<Data>::Min() const {
    if(Empty()) {
        throw std::length_error("Set is empty");
    }
    return this->operator[](0);
}

template<typename Data>
Data SetVec<Data>::MinNRemove() {
    if(Empty()) {
        throw std::length_error("Set is empty");
    }
    const unsigned long pIndex = physicalIndex(0);
    Data min = vec->operator[](pIndex);
    this->RemoveAt(pIndex);
    return min;
}

template<typename Data>
void SetVec<Data>::RemoveMin() {
    if(Empty()) {
        throw std::length_error("Set is empty");
    }
    this->RemoveAt(physicalIndex(0));
}

template<typename Data>
const Data& SetVec<Data>::Max() const {
    if(Empty())
        throw std::length_error("Set is empty");
    return this->operator[](this->size - 1);
}

template<typename Data>
Data SetVec<Data>::MaxNRemove() {
    if(Empty())
        throw std::length_error("Set is empty");
    const unsigned long pIndex = physicalIndex(this->size - 1);
    Data max = vec->operator[](pIndex);
    this->RemoveAt(pIndex);
    return max;
}

template<typename Data>
void SetVec<Data>::RemoveMax() {
    if(Empty())
        throw std::length_error("Set is empty");
    this->RemoveAt(physicalIndex(this->size - 1));
}

template<typename Data>
const Data& SetVec<Data>::Predecessor(const Data& value) const {
    if(Empty())
        throw std::length_error("Set is empty");

    BSearchResult result = BSearch(value);
    const unsigned long predPos = result.pos - 1;

    if(result.pos == 0)
        throw std::length_error("Predecessor not found");

    return vec->operator[](physicalIndex(predPos));
}

template<typename Data>
Data SetVec<Data>::PredecessorNRemove(const Data& value) {
    if(Empty())
        throw std::length_error("Set is empty");

    BSearchResult result = BSearch(value);
    const unsigned long predPos = result.pos - 1;

    if(result.pos == 0)
        throw std::length_error("Predecessor not found");

    Data predecessor = vec->operator[](physicalIndex(predPos));
    this->RemoveAt(physicalIndex(predPos));
    return predecessor;
}

template<typename Data>
void SetVec<Data>::RemovePredecessor(const Data& value) {
    if(Empty())
        throw std::length_error("Set is empty");

    BSearchResult result = BSearch(value);
    const unsigned long predPos = result.pos - 1;

    if(result.pos == 0)
        throw std::length_error("Predecessor not found");

    this->RemoveAt(physicalIndex(predPos));
}

template<typename Data>
const Data& SetVec<Data>::Successor(const Data& value) const {
    if(Empty())
        throw std::length_error("Set is empty");

    BSearchResult result = BSearch(value);
    const unsigned long succPos = result.found ? result.pos + 1 : result.pos;

    if(succPos >= size)
        throw std::length_error("Successor not found");

    return vec->operator[](physicalIndex(succPos));
}

template<typename Data>
Data SetVec<Data>::SuccessorNRemove(const Data& value) {
    if(Empty())
        throw std::length_error("Set is empty");

    BSearchResult result = BSearch(value);
    const unsigned long succPos = result.found ? result.pos + 1 : result.pos;

    if(succPos >= size)
        throw std::length_error("Successor not found");

    Data successor = vec->operator[](physicalIndex(succPos));
    RemoveAt(physicalIndex(succPos));
    return successor;
}

template<typename Data>
void SetVec<Data>::RemoveSuccessor(const Data& value) {
    if(Empty())
        throw std::length_error("Set is empty");

    BSearchResult result = BSearch(value);
    const unsigned long succPos = result.found ? result.pos + 1 : result.pos;

    if(succPos >= size)
        throw std::length_error("Successor not found");

    RemoveAt(physicalIndex(succPos));
}

template<typename Data>
bool SetVec<Data>::Insert(const Data& value) noexcept {
    if(size == 0) {
        InsertAt(0, value);
        return true;
    }
    BSearchResult result = BSearch(value);
    if(result.found == true) {
        return false;
    }
    if(result.pos == size) {
        InsertAt(result.pos, value);
        return true;
    }
    InsertAt(physicalIndex(result.pos), value);
    return true;
}

template<typename Data>
bool SetVec<Data>::Insert(Data&& value) noexcept {
    if(size == 0) {
        InsertAt(0, std::move(value));
        return true;
    }
    BSearchResult result = BSearch(value);
    if(result.found == true) {
        return false;
    }
    if(result.pos == size) {
        InsertAt(result.pos, std::move(value));
        return true;
    }
    InsertAt(result.pos, std::move(value));
    return true;
}

template<typename Data>
bool SetVec<Data>::Remove(const Data& value) noexcept {
    if(Empty()) {
        return false;
    }
    if(BSearchResult result = BSearch(value); result.found) {
        RemoveAt(physicalIndex(result.pos));
        return true;
    } return false;
}

template<typename Data>
bool SetVec<Data>::Exists(const Data& value) const noexcept {
    if(Empty())
        return false;

    if(BSearchResult result = BSearch(value); result.found) {
        return true;
    } return false;
}

template<typename Data>
void SetVec<Data>::Clear() {
    delete vec;
    vec = new Vector<Data>(defaultSetVecSize);
    head = 0;
    size = 0;
}

template<typename Data>
void SetVec<Data>::Resize(unsigned long newSize) {
    Vector<Data>* newVec = new Vector<Data>(newSize);
    unsigned long maxloop = std::min(newSize, size);
    for(unsigned long i = 0; i < maxloop; i++) {
        newVec->operator[](i) = vec->operator[](physicalIndex(i));
    }
    delete vec;
    vec = newVec;
    head = 0;
    size = maxloop;
}

template<typename Data>
const Data& SetVec<Data>::operator[](const unsigned long logicalIndex) const {
    if(logicalIndex >= size) {
        throw std::out_of_range("Index out of range");
    }
    return vec->operator[](physicalIndex(logicalIndex));
}

/***************************************** AUXILIARY FUNCTIONS **********************************/

template <typename Data>
void SetVec<Data>::InsertAt(unsigned long physicalindexvalue, const Data& value) noexcept {
    if(size == vec->Size()) {
        vec->Resize(size * 2);
    }
    for(unsigned long i = size; i > physicalindexvalue; i--) {
        vec->operator[](physicalIndex(i)) = vec->operator[](physicalIndex(i - 1));
    }
    vec->operator[](physicalindexvalue) = value;
    size++;
}

template <typename Data>
void SetVec<Data>::InsertAt(unsigned long physicalindexvalue, Data&& value) noexcept {
    if(size == vec->Size()) {
        vec->Resize(size * 2);
    }
    for(unsigned long i = size; i > physicalindexvalue; i--) {
        vec->operator[](physicalIndex(i)) = vec->operator[](physicalIndex(i - 1));
    }
    std::swap(value, vec->operator[](physicalindexvalue));
    size++;
}

template<typename Data>
void SetVec<Data>::RemoveAt(unsigned long physicalindexvalue) noexcept {
    for(unsigned long i = physicalindexvalue; i < size; i++) {
        vec->operator[](physicalIndex(i)) = vec->operator[](physicalIndex(i + 1));
    }
    size--;
    if(size < vec->Size() / 4 && vec->Size() > defaultSetVecSize) {
        vec->Resize(std::max(defaultSetVecSize, vec->Size() / 2));
    }
}

template<typename Data>
typename SetVec<Data>::BSearchResult SetVec<Data>::BSearch(const Data& value) const noexcept {
    long low = 0;
    long high = size - 1;

    while (low <= high) {
        const long mid = low + (high - low) / 2;
        const Data& midVal = vec->operator[](physicalIndex(mid));

        if (midVal == value) {
            return {true, static_cast<unsigned long>(mid)};
        }
        if (midVal < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return {false, static_cast<unsigned long>(low)};
}


}
