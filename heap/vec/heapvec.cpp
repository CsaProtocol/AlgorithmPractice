
namespace lasd {

/* ************************************************************************** */

template<typename Data>
    requires std::totally_ordered<Data>
HeapVec<Data>::HeapVec(const TraversableContainer<Data>& container) {
    vec = new SortableVector<Data>(container);
    size = container.Size();
    HeapVec::Heapify();
}

template<typename Data>
    requires std::totally_ordered<Data>
HeapVec<Data>::HeapVec(MappableContainer<Data>&& container) noexcept {
    vec = new SortableVector<Data>(std::move(container));
    size = container.Size();
    HeapVec::Heapify();
}

template<typename Data>
    requires std::totally_ordered<Data>
HeapVec<Data>::HeapVec(const HeapVec& other) {
    vec = new SortableVector<Data>(*(other.vec));
    size = other.size;
}

template<typename Data>
    requires std::totally_ordered<Data>
HeapVec<Data>::HeapVec(HeapVec&& other) noexcept {
    std::swap(vec, other.vec);
    std::swap(size, other.size);
}

template<typename Data>
    requires std::totally_ordered<Data>
HeapVec<Data>::~HeapVec() {
    delete vec;
}

template<typename Data>
    requires std::totally_ordered<Data>
HeapVec<Data>& HeapVec<Data>::operator=(const HeapVec& other) {
    if (this != &other) {
        delete vec;
        vec = new SortableVector<Data>(*(other.vec));
        size = other.size;
    }
    return *this;
}

template<typename Data>
    requires std::totally_ordered<Data>
HeapVec<Data>& HeapVec<Data>::operator=(HeapVec&& other) noexcept {
    if (this != &other) {
        std::swap(vec, other.vec);
        std::swap(size, other.size);
    }
    return *this;
}

template<typename Data>
    requires std::totally_ordered<Data>
bool HeapVec<Data>::operator==(const HeapVec& other) const noexcept {
    if(this->size != other.size) {
        return false;
    }
    for(unsigned long i = 0; i < size; ++i) {
        if(vec->operator[](i) != other.vec->operator[](i)) {
            return false;
        }
    } return true;
}

template<typename Data>
    requires std::totally_ordered<Data>
bool HeapVec<Data>::operator!=(const HeapVec& other) const noexcept {
    return !(*this == other);
}

template<typename Data>
    requires std::totally_ordered<Data>
void HeapVec<Data>::Clear() {
    delete vec;
    vec = new SortableVector<Data>(defaultHeapVecSize);
    size = 0;
}

template<typename Data>
    requires std::totally_ordered<Data>
const Data& HeapVec<Data>::operator[](unsigned long index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return vec->operator[](index);
}

template<typename Data>
    requires std::totally_ordered<Data>
Data& HeapVec<Data>::operator[](unsigned long index) {
    return const_cast<Data&>(static_cast<const HeapVec&>(*this)[index]);
}

template<typename Data>
    requires std::totally_ordered<Data>
bool HeapVec<Data>::IsHeap() const noexcept {
    for(unsigned long i = 0; i < size; ++i) {
        if (unsigned long left = leftChild(i); left < size && vec->operator[](i) < vec->operator[](left)) {
            return false;
        }
        if (unsigned long right = rightChild(i); right < size && vec->operator[](i) < vec->operator[](right)) {
            return false;
        }
    }
    return true;
}

template<typename Data>
    requires std::totally_ordered<Data>
void HeapVec<Data>::Heapify() {
    for(long long i = (size / 2) - 1; i >= 0; --i) {
        HeapifyDown(i);
    }
}

template<typename Data>
    requires std::totally_ordered<Data>
void HeapVec<Data>::Sort() noexcept {
    HeapSort();
}

/***************************************** AUXILIARY FUNCTIONS **********************************/

template<typename Data>
    requires std::totally_ordered<Data>
void HeapVec<Data>::HeapifyDown(unsigned long index) noexcept {
    while(true) {
        unsigned long maxIndex = index;
        unsigned long left = leftChild(index);
        unsigned long right = rightChild(index);

        if(left < size && vec->operator[](left) > vec->operator[](maxIndex)) {
            maxIndex = left;
        }
        if(right < size && vec->operator[](right) > vec->operator[](maxIndex)) {
            maxIndex = right;
        }
        if(maxIndex == index) {
            break;
        }
        std::swap(vec->operator[](index), vec->operator[](maxIndex));
        index = maxIndex;
    }
}

//Recursive version of HeapifyDown
/*template<typename Data>
    requires std::totally_ordered<Data>
void HeapVec<Data>::HeapifyDown(unsigned long index) noexcept {
    unsigned long maxIndex = index;
    unsigned long left = leftChild(index);
    unsigned long right = rightChild(index);

    if(left < size && vec->operator[](left) > vec->operator[](maxIndex)) {
        maxIndex = left;
    }
    if(right < size && vec->operator[](right) > vec->operator[](maxIndex)) {
        maxIndex = right;
    }
    if(maxIndex != index) {
        std::swap(vec->operator[](index), vec->operator[](maxIndex));
        HeapifyDown(maxIndex);
    }
}*/

template<typename Data>
    requires std::totally_ordered<Data>
void HeapVec<Data>::HeapifyUp(unsigned long index) noexcept {
    while(index > 0 && vec->operator[](index) > vec->operator[](parent(index))) {
        std::swap(vec->operator[](index), vec->operator[](parent(index)));
        index = parent(index);
    }
}


template<typename Data>
    requires std::totally_ordered<Data>
void HeapVec<Data>::HeapSort() {
    const unsigned long sizeToSave = size;
    for (long long i = size - 1; i > 0; --i) {
        std::swap(vec->operator[](0), vec->operator[](i));
        --size;
        HeapifyDown(0);
    }
    size = sizeToSave;
}

/* ************************************************************************** */

}
