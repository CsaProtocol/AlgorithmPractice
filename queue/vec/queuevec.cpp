namespace lasd {

/* ************************************************************************** */

template<typename Data>
QueueVec<Data>::QueueVec() {
	vec = new Vector<Data>(defaultQueueVecSize);
	head = 0;
}

template<typename Data>
QueueVec<Data>::QueueVec(const TraversableContainer<Data>& toCopy) : QueueVec() {
	auto functor = [this] (const Data& value) {
		Enqueue(value);
	};
	toCopy.Traverse(functor);
}

template<typename Data>
QueueVec<Data>::QueueVec(MappableContainer<Data>&& toMove) noexcept : QueueVec() {
	auto functor = [this] (Data& value) {
		this->Enqueue(std::move(value));
	};
	toMove.Map(functor);
}

template<typename Data>
QueueVec<Data>::QueueVec(const QueueVec& toCopy) {
	delete vec;
	if(toCopy.vec == nullptr) {
		vec = new Vector<Data>(defaultQueueVecSize);
	} else {
		vec = new Vector<Data>(*(toCopy.vec));
	}
	head = toCopy.head;
	size = toCopy.size;
}

template<typename Data>
QueueVec<Data>::QueueVec(QueueVec&& toMove) noexcept {
	std::swap(vec, toMove.vec);
	std::swap(head, toMove.head);
	std::swap(size, toMove.size);
}

template<typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec& toCopy) {
	if (this != &toCopy) {
		delete vec;
		vec = new Vector<Data>(*(toCopy.vec));
		head = toCopy.head;
		size = toCopy.size;
	} return *this;
}

template<typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec&& toMove) noexcept {
	if (this != &toMove) {
		std::swap(vec, toMove.vec);
		std::swap(head, toMove.head);
		std::swap(size, toMove.size);
	} return *this;
}

template<typename Data>
bool QueueVec<Data>::operator==(const QueueVec& toCompare) const noexcept {
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
bool QueueVec<Data>::operator!=(const QueueVec& queue) const noexcept {
    return !this->operator==(queue);
}

template<typename Data>
const Data& QueueVec<Data>::Head() const {
    if(this->Empty())
    	throw std::length_error("Error: Cannot access head of an empty queue");
    return vec->operator[](physicalIndex(0));
}

template<typename Data>
Data& QueueVec<Data>::Head() {
    if(this->Empty())
    	throw std::length_error("Error: Cannot access head of an empty queue");
    return vec->operator[](physicalIndex(0));
}

template<typename Data>
void QueueVec<Data>::Dequeue() {
    if(this->Empty())
        throw std::length_error("Error: Cannot dequeue from an empty queue");
    this->DequeueAux();
}

template<typename Data>
Data QueueVec<Data>::HeadNDequeue() {
    if(this->Empty())
    	throw std::length_error("Error: Cannot access and dequeue from an empty queue");
    Data value = vec->operator[](physicalIndex(0));
	this->DequeueAux();
    return value;
}

template <typename Data>
void QueueVec<Data>::Enqueue(const Data& value) {
	if(size == vec->Size()) {
		this->Resize(size * 2);
	}
	vec->operator[](physicalIndex(size)) = value;
	size++;
}

template <typename Data>
void QueueVec<Data>::Enqueue(Data&& value) noexcept {
    if(size == vec->Size()) {
		this->Resize(size * 2);
	}
	std::swap(value, vec->operator[](physicalIndex(size)));
	size++;
}

template <typename Data>
void QueueVec<Data>::Clear() {
	delete vec;
	vec = new Vector<Data>(defaultQueueVecSize);
	head = 0;
	size = 0;
}

template<typename Data>
void QueueVec<Data>::DequeueAux() noexcept {
	head = (head + 1) % vec->Size();
	size--;
	if(size < vec->Size() / 4 && vec->Size() > defaultQueueVecSize) {
		this->Resize(std::max(defaultQueueVecSize, vec->Size() / 2));
	}
}

template<typename Data>
void QueueVec<Data>::Resize(unsigned long newSize) {
	Vector<Data>* newVec = new Vector<Data>(newSize);
	const unsigned long maxloop = std::min(newSize, size);
	for(unsigned long i = 0; i < maxloop; i++) {
		newVec->operator[](i) = vec->operator[](physicalIndex(i));
	}
	delete vec;
	vec = newVec;
	head = 0;
	size = maxloop;
}

/* ************************************************************************** */

}
