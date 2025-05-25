
namespace lasd {

/* ************************************************************************** */

template<typename Data>
    requires std::totally_ordered<Data>
PQHeap<Data>::PQHeap() {
    vec = new Vector<Data>;
    size = 0;
}

template<typename Data>
    requires std::totally_ordered<Data>
PQHeap<Data>::PQHeap(const TraversableContainer<Data>& toCopy) : HeapVec<Data>(toCopy) {}

template<typename Data>
    requires std::totally_ordered<Data>
PQHeap<Data>::PQHeap(MappableContainer<Data>&& toMove) noexcept : HeapVec<Data>(std::move(toMove)) {}

template<typename Data>
    requires std::totally_ordered<Data>
PQHeap<Data>::PQHeap(const PQHeap& toCopy) : HeapVec<Data>(toCopy) {
    this->Heapify();
}

template<typename Data>
    requires std::totally_ordered<Data>
PQHeap<Data>::PQHeap(PQHeap&& toMove) noexcept : HeapVec<Data>(std::move(toMove)) {
    this->Heapify();
}

template<typename Data>
    requires std::totally_ordered<Data>
PQHeap<Data>& PQHeap<Data>::operator=(const PQHeap& toCopy) {
    if (this != &toCopy) {
        delete vec;
        vec = new Vector<Data>(*(toCopy.vec));
        size = toCopy.size;
    }
    return *this;
}

template<typename Data>
    requires std::totally_ordered<Data>
PQHeap<Data>& PQHeap<Data>::operator=(PQHeap&& toMove) noexcept {
    if (this != &toMove) {
        std::swap(vec, toMove.vec);
        std::swap(size, toMove.size);
    }
    return *this;
}

template<typename Data>
    requires std::totally_ordered<Data>
const Data& PQHeap<Data>::Tip() const {
    if (size == 0) {
        throw std::length_error("Heap is empty");
    }
    return vec->operator[](0);
}

template<typename Data>
    requires std::totally_ordered<Data>
void PQHeap<Data>::RemoveTip() {
    if (size == 0) {
        throw std::length_error("Heap is empty");
    }
    std::swap(vec->operator[](0), vec->operator[](size - 1));
    --size;
    this->HeapifyDown(0);
}

template<typename Data>
    requires std::totally_ordered<Data>
Data PQHeap<Data>::TipNRemove() {
    if(size == 0) {
        throw std::length_error("Heap is empty");
    }
    Data tip = vec->operator[](0);
    std::swap(vec->operator[](0), vec->operator[](size - 1));
    --size;
    this->HeapifyDown(0);
    return tip;
}

template<typename Data>
    requires std::totally_ordered<Data>
void PQHeap<Data>::Insert(const Data& value) noexcept {
    if(size == vec->Size()) {
        vec->Resize(vec->Size() == 0 ? 1 : vec->Size() * 2);
    }
    vec->operator[](this->size) = value;
    ++size;
    this->HeapifyUp(size - 1);
}

template<typename Data>
    requires std::totally_ordered<Data>
void PQHeap<Data>::Insert(Data&& value) noexcept {
    if(size == vec->Size()) {
        vec->Resize(vec->Size() == 0 ? 1 : vec->Size() * 2);
    }
    std::swap(vec->operator[](this->size), value);
    ++size;
    this->HeapifyUp(size - 1);
}

template<typename Data>
    requires std::totally_ordered<Data>
void PQHeap<Data>::Change(unsigned long index, const Data& value) {
    if(index >= size) {
        throw std::out_of_range("Index out of range");
    }
    Data oldValue = vec->operator[](index);
    vec->operator[](index) = value;
    if(value > oldValue) {
        this->HeapifyUp(index);
    } else {
        this->HeapifyDown(index);
    }
}

template<typename Data>
    requires std::totally_ordered<Data>
void PQHeap<Data>::Change(unsigned long index, Data&& value) {
    if(index >= size) {
        throw std::out_of_range("Index out of range");
    }
    Data oldValue = vec->operator[](index);
    std::swap(vec->operator[](index), value);
    if(value > oldValue) {
        this->HeapifyUp(index);
    } else {
        this->HeapifyDown(index);
    }
}





/* ************************************************************************** */

}
