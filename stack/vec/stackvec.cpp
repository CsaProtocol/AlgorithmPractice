
namespace lasd {

/* ************************************************************************** */

template<typename Data>
StackVec<Data>::StackVec() {
	vec = new Vector<Data>(defaultStackVecSize);
}

template<typename Data>
StackVec<Data>::StackVec(const TraversableContainer<Data>& toCopy) : StackVec() {
	auto functor = [this] (const Data& value) {
		this->Push(value);
	};
	toCopy.Traverse(functor);
}

template<typename Data>
StackVec<Data>::StackVec(MappableContainer<Data>&& toMove) noexcept : StackVec() {
	auto functor = [this] (Data& value) {
		this->Push(std::move(value));
	};
	toMove.Map(functor);
}

template<typename Data>
StackVec<Data>::StackVec(const StackVec& toCopy) {
	if(toCopy.vec == nullptr) {
		vec = new Vector<Data>(defaultStackVecSize);
	} else {
		vec = new Vector<Data>(*(toCopy.vec));
	}
	size = toCopy.size;
}

template<typename Data>
StackVec<Data>::StackVec(StackVec&& toMove) noexcept {
	std::swap(vec, toMove.vec);
	std::swap(size, toMove.size);
}

template<typename Data>
StackVec<Data>::~StackVec() {
	delete vec;
	vec = nullptr;
}

template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec& toCopy) {
	if(this != &toCopy) {
		delete vec;
		vec = new Vector<Data>(*(toCopy.vec));
		size = toCopy.size;
	}
	return *this;
}

template<typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec&& toMove) noexcept {
	if(this != &toMove) {
		std::swap(vec, toMove.vec);
		std::swap(size, toMove.size);
	}
	return *this;
}

template<typename Data>
bool StackVec<Data>::operator==(const StackVec& toCompare) const noexcept {
	if(size != toCompare.size) {
		return false;
	}
	for(unsigned long i = 0; i < size; ++i) {
		if(vec->operator[](i) != toCompare.vec->operator[](i)) {
			return false;
		}
	}
	return true;
}

template<typename Data>
bool StackVec<Data>::operator!=(const StackVec& toCompare) const noexcept {
	return !(*this == toCompare);
}

template<typename Data>
const Data& StackVec<Data>::Top() const {
	if(Empty()) {
		throw std::length_error("Stack is empty");
	}
	return vec->operator[](size - 1);
}

template<typename Data>
Data& StackVec<Data>::Top() {
	if(Empty()) {
		throw std::length_error("Stack is empty");
	}
	return vec->operator[](size - 1);
}

template<typename Data>
void StackVec<Data>::Pop() {
	if(Empty()) {
		throw std::length_error("Stack is empty");
	}
	--this->size;
}

template<typename Data>
Data StackVec<Data>::TopNPop() {
	if(Empty()) {
		throw std::length_error("Stack is empty");
	}
	Data topValue = vec->operator[](size - 1);
	--this->size;
	return topValue;
}

template<typename Data>
void StackVec<Data>::Push(const Data& value) {
	if(size == vec->Size()) {
		vec->Resize(vec->Size() * 2);
	}
	vec->operator[](size) = value;
	++this->size;
}

template<typename Data>
void StackVec<Data>::Push(Data&& value) noexcept {
	if(size == vec->Size()) {
		vec->Resize(vec->Size() * 2);
	}
	std::swap(vec->operator[](size), value);
	++this->size;
}

template<typename Data>
void StackVec<Data>::Clear() {
	delete vec;
	vec = new Vector<Data>(defaultStackVecSize);
	size = 0;
}

/* ************************************************************************** */

}
