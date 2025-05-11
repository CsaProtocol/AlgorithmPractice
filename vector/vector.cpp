
namespace lasd {

/* ************************************************************************** */

template<typename Data>
Vector<Data>::Vector(const unsigned long newSize) {
    elements = new Data[newSize];
    size = newSize;
}

template<typename Data>
Vector<Data>::Vector(const TraversableContainer<Data>& toCopy) : Vector(toCopy.Size()) {
    this->size = toCopy.Size();
    unsigned long i = 0;
    toCopy.Traverse([this, &i](const Data& value){
            (this->elements)[i] = value; i++;
    });
}

template<typename Data>
Vector<Data>::Vector(MappableContainer<Data>&& toMove) noexcept : Vector(toMove.Size()) {
    this->size = toMove.Size();
    unsigned long i = 0;
    toMove.Map([this, &i](Data& value){
        std::swap(this->elements[i], value);
        i++;
    });
}

template<typename Data>
Vector<Data>::Vector(const Vector& toCopy) {
    this->size = toCopy.Size();
    this->elements = new Data[toCopy.Size()];
    for(unsigned long i = 0; i < toCopy.Size(); i++) {
        this->elements[i] = toCopy.elements[i];
    }
}

template<typename Data>
Vector<Data>::Vector(Vector&& toMove) noexcept {
    std::swap(this->size, toMove.size);
    std::swap(this->elements, toMove.elements);
}

template<typename Data>
Vector<Data>::~Vector() {
    delete[] elements;
    elements = nullptr;
}

template<typename Data>
Vector<Data>& Vector<Data>::operator=(const Vector& toCopy) {
    this->Resize(toCopy.Size());
    for(unsigned long i = 0; i < toCopy.Size(); i++) {
        this->elements[i] = toCopy.elements[i];
    }
    return *this;
}

template<typename Data>
Vector<Data>& Vector<Data>::operator=(Vector&& toMove) noexcept {
    this->Clear();
    std::swap(this->size, toMove.size);
    std::swap(this->elements, toMove.elements);
    return *this;
}

template<typename Data>
bool Vector<Data>::operator==(const Vector& toCompare) const noexcept {
    if(this->size != toCompare.Size())
        return false;
    if(this->Empty() && toCompare.Empty())
        return true;
    for(unsigned long i = 0; i < this->Size(); i++) {
        if(this->elements[i] != toCompare.elements[i])
            return false;
    } return true;
}

template<typename Data>
bool Vector<Data>::operator!=(const Vector& toCompare) const noexcept {
    return !(*this == toCompare);
}

template<typename Data>
Data& Vector<Data>::operator[](unsigned long index) {
    if(index >= this->Size())
        throw std::out_of_range("Index greater than Size.");
    return this->elements[index];
}

template<typename Data>
Data& Vector<Data>::Front() {
    if(this->Empty())
        throw std::length_error("Vector is empty.");
    return this->elements[0];
}

template<typename Data>
Data& Vector<Data>::Back() {
    if(this->Empty())
        throw std::length_error("Vector is empty.");
    return this->elements[this->Size() - 1];
}

template <typename Data>
const Data& Vector<Data>::operator[](unsigned long index) const {
    if(index >= this->Size())
        throw std::out_of_range("Index greater than Size.");
    return this->elements[index];
}

template<typename Data>
const Data& Vector<Data>::Front() const {
    if(this->Empty())
        throw std::length_error("Vector is empty.");
    return this->elements[0];
}

template<typename Data>
const Data& Vector<Data>::Back() const {
    if(this->Empty())
        throw std::length_error("Vector is empty.");
    return this->elements[this->Size() - 1];
}

template <typename Data>
void Vector<Data>::Resize(unsigned long newSize) {
    Data* newElements = new Data[newSize];
    const unsigned long minSize = std::min(this->size, newSize);
    std::copy(elements, elements + minSize, newElements);
    delete[] elements;
    std::swap(elements, newElements);
    this->size = newSize;
}

template<typename Data>
void Vector<Data>::Clear() {
    delete[] elements;
    elements = nullptr;
    this->size = 0;
}

// SortableVector

template<typename Data>
SortableVector<Data>::SortableVector(const unsigned long newSize) : Vector<Data>(newSize) {}

template<typename Data>
SortableVector<Data>::SortableVector(const TraversableContainer<Data>& toCopy) : Vector<Data>(toCopy) {}

template<typename Data>
SortableVector<Data>::SortableVector(MappableContainer<Data>&& toMove) noexcept : Vector<Data>(std::move(toMove)) {}

template<typename Data>
SortableVector<Data>::SortableVector(const SortableVector& toCopy) : Vector<Data>(toCopy) {}

template<typename Data>
SortableVector<Data>::SortableVector(SortableVector&& toMove) noexcept {
    std::swap(this->size, toMove.size);
    std::swap(this->elements, toMove.elements);
}

template <typename Data>
SortableVector<Data>::~SortableVector() {
    delete[] this->elements;
    this->elements = nullptr;
}

template<typename Data>
SortableVector<Data>& SortableVector<Data>::operator=(const SortableVector& toCopy) {
    this->Resize(toCopy.Size());
    for(unsigned long i = 0; i < toCopy.Size(); i++) {
        this->elements[i] = toCopy.elements[i];
    }
    return *this;
}

template <typename Data>
SortableVector<Data>& SortableVector<Data>::operator=(SortableVector&& toMove) noexcept {
    std::swap(this->size, toMove.size);
    std::swap(this->elements, toMove.elements);
    return *this;
}




/* ************************************************************************** */

}
