
namespace lasd {

/* ************************************************************************** */

template<typename Data>
bool LinearContainer<Data>::operator==(const LinearContainer& toCompare) const noexcept {
    if(this == &toCompare) {
        return true;
    }
    if(this->Size() != toCompare.Size()) {
        return false;
    }
    for(unsigned long i = 0; i < this->Size(); i++) {
        if ((*this)[i] != toCompare[i]) {
            return false;
        }
    }
    return true;
}

template<typename Data>
bool LinearContainer<Data>::operator!=(const LinearContainer& toCompare) const noexcept {
    return !(*this == toCompare);
}

template<typename Data>
const Data& LinearContainer<Data>::Front() const {
    if(this->Size() == 0) {
        throw std::length_error("Empty container");
    }
    return (*this)[0];
}

template<typename Data>
const Data& LinearContainer<Data>::Back() const {
    if(this->Size() == 0) {
        throw std::length_error("Empty container");
    }
    return (*this)[this->Size() - 1];
}

template<typename Data>
void LinearContainer<Data>::Traverse(TraverseFun fun) const {
    PreOrderTraverse(fun);
}

template<typename Data>
void LinearContainer<Data>::PreOrderTraverse(TraverseFun fun) const {
    for(unsigned long i = 0; i < this->Size(); i++) {
        fun((*this)[i]);
    }
}

template<typename Data>
void LinearContainer<Data>::PostOrderTraverse(TraverseFun fun) const {
    for(unsigned long i = this->Size(); i > 0; --i) {
        fun((*this)[i - 1]);
    }
}


// MutableLinearContainer

template<typename Data>
Data& MutableLinearContainer<Data>::Front() {
    if(this->Size() == 0) {
        throw std::length_error("Empty container");
    }
    return (*this)[0];
}

template<typename Data>
Data& MutableLinearContainer<Data>::Back() {
    if(this->Size() == 0) {
        throw std::length_error("Empty container");
    }
    return (*this)[this->Size() - 1];
}

template<typename Data>
void MutableLinearContainer<Data>::Map(MapFun functor) {
    PreOrderMap(functor);
}

template<typename Data>
void MutableLinearContainer<Data>::PreOrderMap(MapFun functor) {
    for(unsigned long i = 0; i < this->Size(); i++) {
        functor((*this)[i]);
    }
}

template<typename Data>
void MutableLinearContainer<Data>::PostOrderMap(MapFun functor){
    for(unsigned long i = this->Size(); i > 0; --i) {
        functor((*this)[i - 1]);
    }
}

// SortableLinearContainer

template<typename Data>
    requires std::totally_ordered<Data>
void SortableLinearContainer<Data>::Sort() noexcept {
    if(this->Empty()) {
        return;
    }
    SelectionSort();
}

template<typename Data>
    requires std::totally_ordered<Data>
void SortableLinearContainer<Data>::SelectionSort() {
    for(unsigned long current = 0; current < this->size - 1; current++) {
        int minIndex = current;
        for(unsigned long i = current + 1; i < this->size; i++) {
            if(this->operator[](i) < this->operator[](minIndex)) {
                minIndex = i;
            }
        }
        std::swap(this->operator[](current), this->operator[](minIndex));
    }
}

/* ************************************************************************** */

}
