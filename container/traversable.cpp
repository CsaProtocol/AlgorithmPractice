
namespace lasd {

/* ************************************************************************** */

template<typename Data>
template<typename Accumulator>
Accumulator TraversableContainer<Data>::Fold(FoldFun<Accumulator> foldfun, Accumulator folded) const {
    Accumulator accumulator = folded;
    auto traversefunctor = [&accumulator, &foldfun] (const Data& data) {
        accumulator = foldfun(data, accumulator);
    };
    Traverse(traversefunctor);
    return accumulator;
}

template<typename Data>
bool TraversableContainer<Data>::Exists(const Data& toFind) const noexcept {
    bool exists = false;
    auto existsFunctor = [&exists, toFind] (const Data& data) {
        exists |= (data == toFind);
    };
    Traverse(existsFunctor);
    return exists;
}

template<typename Data>
template<typename Accumulator>
Accumulator PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun<Accumulator> foldfun, Accumulator folded) const {
    Accumulator accumulator = folded;
    auto traversefunctor = [&accumulator, &foldfun] (const Data& data) {
        accumulator = foldfun(data, accumulator);
    };
    PreOrderTraverse(traversefunctor);
    return accumulator;
}

template<typename Data>
template<typename Accumulator>
Accumulator PostOrderTraversableContainer<Data>::PostOrderFold(FoldFun<Accumulator> foldfun, Accumulator folded) const {
    Accumulator accumulator = folded;
    auto traversefunctor = [&accumulator, &foldfun] (const Data& data) {
        accumulator = foldfun(data, accumulator);
    };
    PostOrderTraverse(traversefunctor);
    return accumulator;
}

template<typename Data>
template<typename Accumulator>
Accumulator InOrderTraversableContainer<Data>::InOrderFold(FoldFun<Accumulator> foldfun, Accumulator folded) const {
    Accumulator accumulator = folded;
    auto traversefunctor = [&accumulator, &foldfun] (const Data& data) {
        accumulator = foldfun(data, accumulator);
    };
    InOrderTraverse(traversefunctor);
    return accumulator;
}

template<typename Data>
template<typename Accumulator>
Accumulator BreadthTraversableContainer<Data>::BreadthFold(FoldFun<Accumulator> foldfun, Accumulator folded) const {
    Accumulator accumulator = folded;
    auto traversefunctor = [&accumulator, &foldfun] (const Data& data) {
        accumulator = foldfun(data, accumulator);
    };
    BreadthTraverse(traversefunctor);
    return accumulator;
}


/* ************************************************************************** */

}
