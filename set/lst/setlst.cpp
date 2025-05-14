
namespace lasd {

/* ************************************************************************** */

template<typename Data>
SetLst<Data>::SetLst(const TraversableContainer<Data>& toCopy) {
    auto functor = [&](const Data& data) {
        this->Insert(data);
    };
    toCopy.Traverse(functor);
}

template<typename Data>
SetLst<Data>::SetLst(MappableContainer<Data>&& toMove) noexcept {
    auto functor = [&](const Data& data) {
        this->Insert(std::move(data));
    };
    toMove.Map(functor);
}

template<typename Data>
SetLst<Data>::SetLst(const SetLst& toCopy) : List<Data>(toCopy) {}

template <typename Data>
SetLst<Data>::SetLst(SetLst&& toMove) noexcept {
    std::swap(this->head, toMove.head);
    std::swap(this->tail, toMove.tail);
    std::swap(this->size, toMove.size);
}

template<typename Data>
SetLst<Data>::~SetLst() {
    typename List<Data>::Node* traverse = this->head;
    while (traverse) {
        typename List<Data>::Node* next = traverse->next;
        delete traverse;
        traverse = next;
    }
    size = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

template<typename Data>
SetLst<Data>& SetLst<Data>::operator=(const SetLst& toCopy) {
    if (this != &toCopy) {
        List<Data>::operator=(toCopy);
    }
    return *this;
}

template<typename Data>
SetLst<Data>& SetLst<Data>::operator=(SetLst&& toMove) noexcept {
    if (this != &toMove) {
        std::swap(this->head, toMove.head);
        std::swap(this->tail, toMove.tail);
        std::swap(this->size, toMove.size);
    }
    return *this;
}

template<typename Data>
bool SetLst<Data>::operator==(const SetLst& toCompare) const noexcept {
    if(this->size != toCompare.size) {
        return false;
    }

    typename List<Data>::Node* thisCurrent = this->head;
    typename List<Data>::Node* otherCurrent = toCompare.head;

    while(thisCurrent != nullptr && otherCurrent != nullptr) {
        if(thisCurrent->value != otherCurrent->value) {
            return false;
        }
        thisCurrent = thisCurrent->next;
        otherCurrent = otherCurrent->next;
    }

    return true;
}

template<typename Data>
bool SetLst<Data>::operator!=(const SetLst& toCompare) const noexcept {
    return !(*this == toCompare);
}

template<typename Data>
const Data& SetLst<Data>::Min() const {
    if(Empty()) {
        throw std::length_error("Set is empty");
    }
    return head->value;
}

template<typename Data>
Data SetLst<Data>::MinNRemove() {
    if(Empty()) {
        throw std::length_error("Set is empty");
    }
    return this->FrontNRemove();
}

template<typename Data>
void SetLst<Data>::RemoveMin() {
    if(Empty()) {
        throw std::length_error("Set is empty");
    }
    this->RemoveFromFront();
}

template<typename Data>
const Data& SetLst<Data>::Max() const {
    if(Empty()) {
        throw std::length_error("Set is empty");
    }
    return tail->value;
}

template<typename Data>
Data SetLst<Data>::MaxNRemove() {
    if(Empty()) {
        throw std::length_error("Set is empty");
    }
    return this->BackNRemove();
}

template<typename Data>
void SetLst<Data>::RemoveMax() {
    if(Empty()) {
        throw std::length_error("Set is empty");
    }
    this->RemoveFromBack();
}

template<typename Data>
const Data& SetLst<Data>::Predecessor(const Data& data) const {
    if(Empty()) {
        throw std::length_error("Set is empty");
    }
    typename List<Data>::Node* current = head;
    typename List<Data>::Node* prev = nullptr;
    while(current != nullptr) {
        if(current->value >= data) {
            if(prev == nullptr) {
                throw std::length_error("Predecessor not found");
            }
            return prev->value;
        }
        prev = current;
        current = current->next;
    }
    return tail->value;
}

template<typename Data>
Data SetLst<Data>::PredecessorNRemove(const Data& data) {
    if(Empty()) {
        throw std::length_error("Set is empty");
    }
    typename List<Data>::Node* current = head;
    typename List<Data>::Node* prev = nullptr;
    typename List<Data>::Node* prevPrev = nullptr;
    while(current != nullptr) {
        if(current->value >= data) {
            if(prev == nullptr) {
                throw std::length_error("Predecessor not found");
            }
            Data toReturn = prev->value;
            this->DetachAndDelete(prev, prevPrev);
            size--;
            return toReturn;
        }
        prevPrev = prev;
        prev = current;
        current = current->next;
    }
    Data toReturn = tail->value;
    this->RemoveFromBack();
    return toReturn;
}

template<typename Data>
void SetLst<Data>::RemovePredecessor(const Data& data) {
    if(Empty()) {
        throw std::length_error("Set is empty");
    }
    typename List<Data>::Node* current = head;
    typename List<Data>::Node* prev = nullptr;
    typename List<Data>::Node* prevPrev = nullptr;
    while(current != nullptr) {
        if(current->value >= data) {
            if(prev == nullptr) {
                throw std::length_error("Predecessor not found");
            }
            this->DetachAndDelete(prev, prevPrev);
            size--;
            return;
        }
        prevPrev = prev;
        prev = current;
        current = current->next;
    } this->RemoveFromBack();
}

template<typename Data>
const Data& SetLst<Data>::Successor(const Data& data) const {
    if(Empty()) {
        throw std::length_error("Set is empty");
    }
    typename List<Data>::Node* current = head;
    while(current != nullptr) {
        if(current->value > data) {
            return current->value;
        }
        current = current->next;
    }
    throw std::length_error("Successor not found");
}

template<typename Data>
Data SetLst<Data>::SuccessorNRemove(const Data& data) {
    if(Empty()) {
        throw std::length_error("Set is empty");
    }
    typename List<Data>::Node* current = head;
    typename List<Data>::Node* prev = nullptr;
    while(current != nullptr) {
        if(current->value > data) {
            Data toReturn = current->value;
            this->DetachAndDelete(current, prev);
            size--;
            return toReturn;
        }
        prev = current;
        current = current->next;
    }
    throw std::length_error("Successor not found");
}

template<typename Data>
void SetLst<Data>::RemoveSuccessor(const Data& data) {
    if(Empty()) {
        throw std::length_error("Set is empty");
    }
    typename List<Data>::Node* current = head;
    typename List<Data>::Node* prev = nullptr;
    while(current != nullptr) {
        if(current->value > data) {
            this->DetachAndDelete(current, prev);
            size--;
            return;
        }
        prev = current;
        current = current->next;
    }
    throw std::length_error("Successor not found");
}

template<typename Data>
bool SetLst<Data>::Insert(const Data& data) noexcept {
    if(Empty()) {
        this->InsertAtFront(data);
        return true;
    }
    if(Exists(data)) {
        return false;
    }
    typename List<Data>::Node* current = head;
    typename List<Data>::Node* prev = nullptr;
    while(current != nullptr) {
        if(current->value > data) {
            if(prev == nullptr) {
                this->InsertAtFront(data);
            } else {
                this->InsertBetween(prev, data, current);
            }
            return true;
        }
        prev = current;
        current = current->next;
    }
    this->InsertAtBack(data);
    return true;
}

template<typename Data>
bool SetLst<Data>::Insert(Data&& data) noexcept {
    if(Empty()) {
        this->InsertAtFront(std::move(data));
        return true;
    }
    if(Exists(data)) {
        return false;
    }
    typename List<Data>::Node* current = head;
    typename List<Data>::Node* prev = nullptr;
    while(current != nullptr) {
        if(current->value > data) {
            if(prev == nullptr) {
                this->InsertAtFront(data);
            } else {
                this->InsertBetween(prev, std::move(data), current);
            }
            return true;
        }
        prev = current;
        current = current->next;
    }
    this->InsertAtBack(std::move(data));
    return true;
}

template <typename Data>
bool SetLst<Data>::Remove(const Data& data) noexcept {
    if(Empty()) {
        return false;
    }
    typename List<Data>::Node* current = head;
    typename List<Data>::Node* prev = nullptr;
    while(current != nullptr) {
        if(current->value == data) {
            this->DetachAndDelete(current, prev);
            size--;
            return true;
        } if(current->value > data) {
            return false;
        }
        prev = current;
        current = current->next;
    } return false;
}

template<typename Data>
const Data& SetLst<Data>::operator[](const unsigned long index) const {
    if(index >= size) {
        throw std::out_of_range("Index out of range");
    }
    typename List<Data>::Node* current = head;
    for(unsigned long i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->value;
}

template<typename Data>
bool SetLst<Data>::Exists(const Data& data) const noexcept {
    typename List<Data>::Node* current = head;
    while(current != nullptr) {
        if(current->value == data) {
            return true;
        } if(current->value > data) {
            return false;
        }
        current = current->next;
    } return false;
}

template<typename Data>
void SetLst<Data>::Clear() {
    this->List<Data>::Clear();
}

template <typename Data>
void SetLst<Data>::DetachAndDelete(typename List<Data>::Node* toDelete, typename List<Data>::Node* prev) noexcept {
    if(prev == nullptr) {
        head = toDelete->next;
    } else {
        prev->next = toDelete->next;
    }
    if(toDelete->next == nullptr) {
        tail = prev;
    }
    delete toDelete;
}

template <typename Data>
void SetLst<Data>::InsertBetween(typename List<Data>::Node* prev, const Data& toInsert, typename List<Data>::Node* next) noexcept {
    typename List<Data>::Node* newNode = new typename List<Data>::Node(toInsert);
    newNode->next = next;
    prev->next = newNode;
    size++;
}

template <typename Data>
void SetLst<Data>::InsertBetween(typename List<Data>::Node* prev, Data&& toMove, typename List<Data>::Node* next) noexcept {
    typename List<Data>::Node* newNode = new typename List<Data>::Node(std::move(toMove));
    newNode->next = next;
    prev->next = newNode;
    size++;
}


/* ************************************************************************** */

}
