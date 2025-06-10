
#include "../../zlasdtest/list/list.hpp"

namespace lasd {

/* ************************************************************************** */

template<typename Data>
QueueLst<Data>::QueueLst(const TraversableContainer<Data>& toCopy) {
	auto functor = [this] (const Data& value) {
		Enqueue(value);
	};
	toCopy.Traverse(functor);
}

template<typename Data>
QueueLst<Data>::QueueLst(MappableContainer<Data>&& toMove) noexcept {
	auto functor = [this] (Data&& value) {
		Enqueue(std::move(value));
	};
	toMove.MapPreOrder(functor);
}

template<typename Data>
QueueLst<Data>::QueueLst(const QueueLst& queue) : List<Data>::List(queue) {}

template<typename Data>
QueueLst<Data>::QueueLst(QueueLst&& queue) noexcept {
	std::swap(queue.head, this->head);
	std::swap(queue.size, this->size);
	std::swap(queue.tail, this->tail);
}

template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst& toCopy) {
	if(this != &toCopy) {
		List<Data>::operator=(toCopy);
	}
	return *this;
}

template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(QueueLst&& toMove) noexcept {
	if(this != &toMove) {
		List<Data>::operator=(std::move(toMove));
	}
	return *this;
}

template<typename Data>
bool QueueLst<Data>::operator==(const QueueLst& toCompare) const noexcept {
	if(this->size != toCompare.size)
		return false;
	return *(head) == *(toCompare.head);
}

template<typename Data>
bool QueueLst<Data>::operator!=(const QueueLst& toCompare) const noexcept {
	return !(*this == toCompare);
}

template<typename Data>
const Data& QueueLst<Data>::Head() const {
	if (this->Empty())
		throw std::length_error("Error: Cannot access head of an empty queue");
	return this->head->value;
}

template<typename Data>
Data& QueueLst<Data>::Head() {
	if (this->Empty())
		throw std::length_error("Error: Cannot access head of an empty queue");
	return this->head->value;
}

template<typename Data>
void QueueLst<Data>::Dequeue() {
	if(this->Empty())
		throw std::length_error("Error: Cannot dequeue from an empty queue");
	this->RemoveFromFront();
}

template<typename Data>
Data QueueLst<Data>::HeadNDequeue() {
	if(this->Empty())
		throw std::length_error("Error: Cannot dequeue from an empty queue");
	return this->FrontNRemove();
}

template<typename Data>
void QueueLst<Data>::Enqueue(const Data& value) {
	this->InsertAtBack(value);
}

template<typename Data>
void QueueLst<Data>::Enqueue(Data&& value) noexcept {
	this->InsertAtBack(std::move(value));
}

/* ************************************************************************** */

}
