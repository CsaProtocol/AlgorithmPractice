
namespace lasd {

/* ************************************************************************** */

template<typename Data>
StackLst<Data>::StackLst(const TraversableContainer<Data>& toCopy) : List<Data>(toCopy) {}

template<typename Data>
StackLst<Data>::StackLst(MappableContainer<Data>&& toMove) noexcept : List<Data>(std::move(toMove)) {}

template<typename Data>
StackLst<Data>::StackLst(const StackLst& toCopy) : List<Data>(toCopy) {}

template<typename Data>
StackLst<Data>::StackLst(StackLst&& toMove) noexcept : List<Data>(std::move(toMove)) {}

template<typename Data>
StackLst<Data>& StackLst<Data>::operator=(const StackLst& toCopy) {
	List<Data>::operator=(toCopy);
	return *this;
}

template<typename Data>
StackLst<Data>& StackLst<Data>::operator=(StackLst&& toMove) noexcept {
    List<Data>::operator=(std::move(toMove));
    return *this;
}

template<typename Data>
bool StackLst<Data>::operator==(const StackLst& toCompare) const noexcept {
    return List<Data>::operator==(toCompare);
}

template<typename Data>
bool StackLst<Data>::operator!=(const StackLst& toCompare) const noexcept {
	return List<Data>::operator!=(toCompare);
}

template<typename Data>
const Data& StackLst<Data>::Top() const {
    if (this->Empty()) {
        throw std::length_error("Stack is empty");
    }
    return List<Data>::Front();
}

template<typename Data>
Data& StackLst<Data>::Top() {
    if (this->Empty()) {
        throw std::length_error("Stack is empty");
    }
    return List<Data>::Front();
}

template<typename Data>
void StackLst<Data>::Pop() {
    if (this->Empty()) {
        throw std::length_error("Stack is empty");
    }
    List<Data>::RemoveFromFront();
}

template<typename Data>
Data StackLst<Data>::TopNPop() {
    if (this->Empty()) {
        throw std::length_error("Stack is empty");
    }
    return List<Data>::FrontNRemove();
}

template<typename Data>
void StackLst<Data>::Push(const Data& value) {
    List<Data>::InsertAtFront(value);
}

template<typename Data>
void StackLst<Data>::Push(Data&& value) noexcept {
    List<Data>::InsertAtFront(std::move(value));
}

/* ************************************************************************** */

}
