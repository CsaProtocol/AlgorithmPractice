
namespace lasd {

/* ************************************************************************** */

template<typename Data>
bool DictionaryContainer<Data>::InsertAll(const TraversableContainer<Data>& toInsert) noexcept {
    bool all_inserted = true;
    auto functor = [&all_inserted, this] (const Data& value) {
        all_inserted &= Insert(value);
    };
    toInsert.Traverse(functor);
    return all_inserted;
}

template <typename Data>
bool DictionaryContainer<Data>::InsertAll(MappableContainer<Data>&& toInsert) noexcept {
    bool all_inserted = true;
    auto functor = [&all_inserted, this] (Data& value) {
        all_inserted &= Insert(std::move(value));
    };
    toInsert.Map(functor);
    return all_inserted;
}

template<typename Data>
bool DictionaryContainer<Data>::RemoveAll(const TraversableContainer<Data>& toRemove) noexcept {
    bool all_removed = true;
    auto functor = [&all_removed, this] (const Data& value) {
        all_removed &= Remove(value);
    };
    toRemove.Traverse(functor);
    return all_removed;
}

template<typename Data>
bool DictionaryContainer<Data>::InsertSome(const TraversableContainer<Data>& toInsert) noexcept {
    bool some_inserted = false;
    auto functor = [&some_inserted, this] (const Data& value) {
        some_inserted |= Insert(value);
    };
    toInsert.Traverse(functor);
    return some_inserted;
}

template<typename Data>
bool DictionaryContainer<Data>::InsertSome(MappableContainer<Data>&& toInsert) noexcept {
    bool some_inserted = false;
    auto functor = [&some_inserted, this] (Data& value) {
        some_inserted |= Insert(std::move(value));
    };
    toInsert.Map(functor);
    return some_inserted;
}

template<typename Data>
bool DictionaryContainer<Data>::RemoveSome(const TraversableContainer<Data>& toRemove) noexcept {
    bool some_removed = false;
    auto functor = [&some_removed, this] (const Data& value) {
        some_removed |= Remove(value);
    };
    toRemove.Traverse(functor);
    return some_removed;
}

/* ************************************************************************** */

}
