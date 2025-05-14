
namespace lasd {
    /* ************************************************************************** */

template<typename Data>
bool List<Data>::Node::operator==(const Node& toCompare) const noexcept {
    return this->value == toCompare.value &&
        ((next == nullptr && toCompare.next == nullptr) ||
            (next != nullptr && toCompare.next != nullptr &&
                *next == *toCompare.next));
}

template <typename Data>
bool List<Data>::Node::operator!=(const Node& toCompare) const noexcept {
    return !(*this == toCompare);
}


// LIST

template<typename Data>
List<Data>::List(const TraversableContainer<Data>& toCopy) {
    toCopy.Traverse([this](const Data& value) {
        this->InsertAtBack(value);
    });
}

template<typename Data>
List<Data>::List(MappableContainer<Data>&& toMove) noexcept {
    toMove.Map([this](Data& value) {
        this->InsertAtBack(std::move(value));
    });
}

template<typename Data>
List<Data>::List(const List& toCopy) {
    Node* traverse = toCopy.head;
    while (traverse) {
        InsertAtBack(traverse->value);
        traverse = traverse->next;
    }
}

template<typename Data>
List<Data>::List(List&& toMove) noexcept {
    std::swap(toMove.head, this->head);
    std::swap(toMove.tail, this->tail);
    std::swap(toMove.size, this->size);
}

template <typename Data>
List<Data>::~List() noexcept {
    Node* traverse = this->head;
    while (traverse) {
        Node* next = traverse->next;
        delete traverse;
        traverse = next;
    }
    size = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

template<typename Data>
List<Data>& List<Data>::operator=(const List& toCopy) {
    Node* traverse = toCopy.head;
    this->Clear();
    while(traverse) {
        InsertAtBack(traverse->value);
        traverse = traverse->next;
    } return *this;
}

template<typename Data>
List<Data>& List<Data>::operator=(List&& toMove) noexcept {
    std::swap(this->head, toMove.head);
    std::swap(this->tail, toMove.tail);
    std::swap(this->size, toMove.size);
    return *this;
}

template<typename Data>
bool List<Data>::operator==(const List& toCompare) const noexcept {
    if(this->size != toCompare.size)
        return false;
    return *(head) == *(toCompare.head);
}

template<typename Data>
bool List<Data>::operator!=(const List& toCompare) const noexcept {
    return !(*this == toCompare);
}

template<typename Data>
void List<Data>::InsertAtFront(const Data& toInsert) {
    Node* newNode = new Node(toInsert);
    newNode->next = this->head;
    this->head = newNode;
    if(this->tail == nullptr) {
        this->tail = newNode;
    }
    ++this->size;
}

template<typename Data>
void List<Data>::InsertAtFront(Data&& toMove) {
    Node* newNode = new Node(std::move(toMove));
    newNode->next = this->head;
    this->head = newNode;
    if(this->tail == nullptr) {
        this->tail = newNode;
    }
    ++this->size;
}

template<typename Data>
void List<Data>::RemoveFromFront() {
    if(Empty())
        throw std::out_of_range("List is empty");
    Node* toDelete = this->head;
    this->head = toDelete->next;
    delete toDelete;
    --this->size;
    if(this->head == nullptr) {
        this->tail = nullptr;
    }
}

template<typename Data>
Data List<Data>::FrontNRemove() {
    if(Empty())
        throw std::out_of_range("List is empty");
    Node* toDelete = this->head;
    this->head = toDelete->next;
    Data toReturn = toDelete->value;
    delete toDelete;
    --this->size;
    if(this->head == nullptr) {
        this->tail = nullptr;
    }
    return toReturn;
}

template<typename Data>
void List<Data>::InsertAtBack(const Data& toInsert) {
    Node* newNode = new Node(toInsert);
    if(head == nullptr) {
        this->head = newNode;
        this->tail = newNode;
        ++this->size;
        return;
    }
    this->tail->next = newNode;
    this->tail = newNode;
    ++this->size;
}

template <typename Data>
void List<Data>::InsertAtBack(Data&& toMove) {
    Node* newNode = new Node(std::move(toMove));
    if(head == nullptr) {
        this->head = newNode;
        this->tail = newNode;
        ++this->size;
        return;
    }
    this->tail->next = newNode;
    this->tail = newNode;
    ++this->size;
}

template <typename Data>
void List<Data>::RemoveFromBack() {
    if(Empty())
        throw std::out_of_range("List is empty");
    if(size == 1) {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
        size = 0;
        return;
    }
    Node* previous = nullptr;
    Node* traverse = this->head;
    while(traverse->next) {
        previous = traverse;
        traverse = traverse->next;
    }
    delete traverse;
    tail = previous;
    previous->next = nullptr;
    --this->size;
}

template <typename Data>
Data List<Data>::BackNRemove() {
    if(Empty())
        throw std::out_of_range("List is empty");
    if(size == 1) {
        Data toReturn = this->head->value;
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
        size = 0;
        return toReturn;
    }
    Node* previous = nullptr;
    Node* traverse = this->head;
    while(traverse->next) {
        previous = traverse;
        traverse = traverse->next;
    }
    Data toReturn = traverse->value;
    delete traverse;
    tail = previous;
    previous->next = nullptr;
    --this->size;
    return toReturn;
}

template<typename Data>
Data& List<Data>::operator[](unsigned long index) {
    if(index >= this->size)
        throw std::out_of_range("Index is out of range");
    Node* temp = this->head;
    for(unsigned long i = 0; i < index; ++i) {
        temp = temp->next;
    }
    return temp->value;
}

template<typename Data>
Data& List<Data>::Front() {
    if(this->size == 0)
        throw std::length_error("List is empty");
    return this->head->value;
}

template<typename Data>
Data& List<Data>::Back() {
    if(this->size == 0)
        throw std::length_error("List is empty");
    return this->tail->value;
}

template<typename Data>
const Data& List<Data>::operator[](unsigned long index) const {
    if(index >= this->size)
        throw std::out_of_range("Index is out of range");
    Node* temp = this->head;
    for(unsigned long i = 0; i < index; ++i) {
        temp = temp->next;
    } return temp->value;
}

template<typename Data>
const Data& List<Data>::Front() const {
    if(this->size == 0)
        throw std::length_error("List is empty");
    return this->head->value;
}

template<typename Data>
const Data& List<Data>::Back() const {
    if(this->size == 0)
        throw std::length_error("List is empty");
    return this->tail->value;
}

template<typename Data>
void List<Data>::Map(MapFun fun) {
    PreOrderMap(fun);
}

template<typename Data>
void List<Data>::PreOrderMap(MapFun fun) {
    if(this->Empty())
        return;
    for(Node* temp = head; temp != nullptr; temp = temp->next)
        fun(temp->value);
}

template<typename Data>
void List<Data>::PostOrderMap(MapFun fun) {
    if(this->Empty())
        return;
    PostOrderMapAux(head, fun);
}

template<typename Data>
void List<Data>::Traverse(TraverseFun fun) const {
    PreOrderTraverse(fun);
}

template<typename Data>
void List<Data>::PreOrderTraverse(TraverseFun fun) const {
    if(this->Empty())
        return;
    for(Node* temp = head; temp != nullptr; temp = temp->next)
        fun(temp->value);
}

template<typename Data>
void List<Data>::PostOrderTraverse(TraverseFun fun) const {
    if(this->Empty())
        return;
    PostOrderTraverseAux(head, fun);
}

template <typename Data>
void List<Data>::Clear() {
    Node* temp = this->head;
    while(temp) {
        Node* toDelete = temp;
        temp = toDelete->next;
        delete toDelete;
    }
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

template <typename Data>
void List<Data>::PostOrderTraverseAux(Node* current, TraverseFun fun) const {
    if(current == nullptr) {
        return;
    } PostOrderTraverseAux(current->next, fun);
    fun(current->value);
}

template <typename Data>
void List<Data>::PostOrderMapAux(Node* current, MapFun fun) {
    if(current == nullptr) {
        return;
    } PostOrderMapAux(current->next, fun);
    fun(current->value);
}





/* ************************************************************************** */

}
