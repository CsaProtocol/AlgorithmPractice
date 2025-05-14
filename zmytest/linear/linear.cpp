#include "linear.hpp"

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../../zlasdtest/list/list.hpp"
#include "../../zlasdtest/vector/vector.hpp"
#include "../../vector/vector.hpp"

#include <iostream>
#include <string>
#include <utility>

namespace zmytest {

void zMyLinearInt(unsigned int& testnum, unsigned int& testerr) {
    lasd::SortableVector<int> vec1;
    Empty(testnum, testerr, vec1, true);

    lasd::SortableVector<int> vec2(5);
    vec1 = vec2;
    Empty(testnum, testerr, vec1, false);
    EqualVector(testnum, testerr, vec1, vec2, true);

    lasd::SortableVector<int> vec3;
    vec2 = vec3;
    Size(testnum, testerr, vec2, true, 0);
    EqualVector(testnum, testerr, vec1, vec2, false);
    EqualVector(testnum, testerr, vec2, vec3, true);

    SetAt(testnum, testerr, vec3, false, 0, 0);
    vec3.Resize(5);
    Size(testnum, testerr, vec3, true, 5);
    SetAt(testnum, testerr, vec3, true, 0, 5);
    SetAt(testnum, testerr, vec3, true, 1, 4);
    SetAt(testnum, testerr, vec3, true, 2, 3);
    SetAt(testnum, testerr, vec3, true, 3, 2);
    SetAt(testnum, testerr, vec3, true, 4, 1);
    SetAt(testnum, testerr, vec3, false, 5, 1);

    Empty(testnum, testerr, vec2, true);
    Size(testnum, testerr, vec2, true, 0);
    vec2 = std::move(vec3);
    Size(testnum, testerr, vec3, true, 0);
    Traverse(testnum, testerr, vec2, true, &TraversePrint<int>);
    GetAt(testnum, testerr, vec2, false, 0, 1);
    GetAt(testnum, testerr, vec2, false, 1, 2);
    GetAt(testnum, testerr, vec2, true, 2, 3);
    GetAt(testnum, testerr, vec2, false, 3, 4);
    GetAt(testnum, testerr, vec2, false, 4, 5);

    Empty(testnum, testerr, vec3, true);
    vec2.Sort();
    Traverse(testnum, testerr, vec2, true, &TraversePrint<int>);
    GetAt(testnum, testerr, vec2, true, 0, 1);
    GetAt(testnum, testerr, vec2, true, 1, 2);
    GetAt(testnum, testerr, vec2, true, 2, 3);
    GetAt(testnum, testerr, vec2, true, 3, 4);
    GetAt(testnum, testerr, vec2, true, 4, 5);

    vec2.Sort();
    Traverse(testnum, testerr, vec2, true, &TraversePrint<int>);
    vec2.Resize(2);
    GetAt(testnum, testerr, vec2, false, 2, 1);

    lasd::SortableVector<int> vec4(vec2);
    lasd::SortableVector<int> vec5(std::move(vec2));
    Empty(testnum, testerr, vec2, true);
    EqualVector(testnum, testerr, vec4, vec5, true);

    lasd::SortableVector<int> vec6;
    EqualVector(testnum, testerr, vec2, vec6, true);
    vec4.Resize(1);
    EqualVector(testnum, testerr, vec4, vec5, false);
    vec4.Resize(2);
    SetAt(testnum, testerr, vec4, true, 1, 2);
    Traverse(testnum, testerr, vec4, true, &TraversePrint<int>);
    Traverse(testnum, testerr, vec5, true, &TraversePrint<int>);
    EqualVector(testnum, testerr, vec4, vec5, true);

    vec4.Resize(10);
    for (int i = 0; i < 10; ++i) SetAt(testnum, testerr, vec4, true, i, 1);
    Traverse(testnum, testerr, vec4, true, &TraversePrint<int>);
    Fold(testnum, testerr, vec4, true, [](const int& data, const int& accum) { return accum + data; }, 0, 10);

    Map(testnum, testerr, vec4, true, [](int& i) { ++i; });
    Traverse(testnum, testerr, vec4, true, &TraversePrint<int>);
    Fold(testnum, testerr, vec4, true, [](const int& data, const int& accum) { return accum + data; }, 0, 20);

    int pos = 0;
    Map(testnum, testerr, vec4, true, [&pos](int& i) { i += pos++; });
    Traverse(testnum, testerr, vec4, true, &TraversePrint<int>);
    Fold(testnum, testerr, vec4, true, [](const int& data, const int& accum) { return (data % 2 == 0) ? accum + 1 : accum - 1; }, 0, 0);

    lasd::List<int> lst(vec4);
    lasd::SortableVector<int> vec7(lst);
    EqualVector(testnum, testerr, vec4, vec7, true);
    Traverse(testnum, testerr, vec7, true, &TraversePrint<int>);

    vec1 = vec5;
    lasd::SortableVector<int> vec8(std::move(lst));
    EqualVector(testnum, testerr, vec7, vec8, true);
    vec5 = std::move(vec7);
    Traverse(testnum, testerr, vec7, true, &TraversePrint<int>);
    EqualVector(testnum, testerr, vec4, vec5, true);
    EqualVector(testnum, testerr, vec4, vec8, true);
    EqualVector(testnum, testerr, vec5, vec8, true);

    Empty(testnum, testerr, lst, false);
    Empty(testnum, testerr, vec7, false);
    EqualVector(testnum, testerr, vec1, vec7, true);
    NonEqualVector(testnum, testerr, vec1, vec7, false);
    Exists(testnum, testerr, vec7, true, 1);
    Exists(testnum, testerr, vec7, false, 12);

    Traverse(testnum, testerr, vec4, true, &TraversePrint<int>);
    pos = 0;
    FoldPreOrder(testnum, testerr, vec4, true, [&pos](const int& i, const double& a) { return pos++ % 2 ? a - i : a + i; }, 0, -5);
    pos = 0;
    FoldPostOrder(testnum, testerr, vec4, true, [&pos](const int& i, const double& a) { return pos++ % 2 ? a - i : a + i; }, 0, 5);

    vec5.Clear();
    Size(testnum, testerr, vec5, true, 0);
    EqualVector(testnum, testerr, vec5, vec7, false);
    NonEqualVector(testnum, testerr, vec5, vec7, true);
    Exists(testnum, testerr, vec5, false, 1);
    GetAt(testnum, testerr, vec5, false, 0, 0);
    SetAt(testnum, testerr, vec5, false, 0, 0);

    lasd::List<int> lst2;
    InsertAtBack(testnum, testerr, lst2, true, 1);
    InsertAtBack(testnum, testerr, lst2, true, 2);
    InsertAtBack(testnum, testerr, lst2, true, 3);
    lasd::List<int> lst3(lst2);
    lasd::SortableVector<int> vec9;
    lst2.Clear();
    Traverse(testnum, testerr, lst2, true, &TraversePrint<int>);
    Traverse(testnum, testerr, lst3, true, &TraversePrint<int>);
    NonEqualList(testnum, testerr, lst2, lst3, true);

    lasd::SortableVector<int> vecDup;
    vecDup.Resize(5);
    SetAt(testnum, testerr, vecDup, true, 0, 3);
    SetAt(testnum, testerr, vecDup, true, 1, 1);
    SetAt(testnum, testerr, vecDup, true, 2, 2);
    SetAt(testnum, testerr, vecDup, true, 3, 2);
    SetAt(testnum, testerr, vecDup, true, 4, 4);
    vecDup.Sort();
    Traverse(testnum, testerr, vecDup, true, &TraversePrint<int>);

    lasd::SortableVector<int> vecEmpty;
    vecEmpty.Sort();
    Empty(testnum, testerr, vecEmpty, true);

    lasd::SortableVector<int> vecSingle(1);
    SetAt(testnum, testerr, vecSingle, true, 0, 5);
    vecSingle.Sort();
    GetAt(testnum, testerr, vecSingle, true, 0, 5);

    vecDup.Resize(0);
    Empty(testnum, testerr, vecDup, true);
    vecDup.Resize(5);
    Size(testnum, testerr, vecDup, true, 5);
    SetAt(testnum, testerr, vecDup, true, 0, 3);
    SetAt(testnum, testerr, vecDup, true, 1, 1);
    SetAt(testnum, testerr, vecDup, true, 2, 2);
    SetAt(testnum, testerr, vecDup, true, 3, 2);
    SetAt(testnum, testerr, vecDup, true, 4, 4);

    Traverse(testnum, testerr, vecDup, true, &TraversePrint<int>);

    vecDup.Resize(5);
    SetAt(testnum, testerr, vecDup, true, 0, 1);
    SetAt(testnum, testerr, vecDup, true, 1, 2);
    SetAt(testnum, testerr, vecDup, true, 2, 3);
    SetAt(testnum, testerr, vecDup, true, 3, 4);
    SetAt(testnum, testerr, vecDup, true, 4, 5);
    vecDup.Map([](int& i) { i *= i; });
    Traverse(testnum, testerr, vecDup, true, &TraversePrint<int>);

    Fold(testnum, testerr, vecDup, true, [](const int& data, const int& accum) { return accum * data; }, 1, 1*4*9*16*25);

    lasd::SortableVector<int> vecExist(5);
    SetAt(testnum, testerr, vecExist, true, 0, 1);
    SetAt(testnum, testerr, vecExist, true, 1, 2);
    SetAt(testnum, testerr, vecExist, true, 2, 3);
    SetAt(testnum, testerr, vecExist, true, 3, 4);
    SetAt(testnum, testerr, vecExist, true, 4, 5);

    Exists(testnum, testerr, vecExist, true, 1);
    Exists(testnum, testerr, vecExist, true, 5);
    Exists(testnum, testerr, vecExist, false, 0);
    Exists(testnum, testerr, vecExist, false, 6);

    vecExist.Resize(3);
    GetAt(testnum, testerr, vecExist, false, 3, 0);

    lasd::SortableVector<int> vecCopy(vecExist);
    EqualVector(testnum, testerr, vecExist, vecCopy, true);
    SetAt(testnum, testerr, vecCopy, true, 0, 10);
    EqualVector(testnum, testerr, vecExist, vecCopy, false);

    lasd::SortableVector<int> vecMove(std::move(vecCopy));
    Empty(testnum, testerr, vecCopy, true);
    vecMove = std::move(vecExist);
    Empty(testnum, testerr, vecExist, false); //Move assignment should swap the contents

    vecMove = vecMove;
    Size(testnum, testerr, vecMove, true, 3);

    lasd::List<int> lst5;
    InsertAtBack(testnum, testerr, lst5, true, 10);
    InsertAtBack(testnum, testerr, lst5, true, 20);
    InsertAtBack(testnum, testerr, lst5, true, 30);
    lasd::SortableVector<int> vecFromList(lst5);
    EqualLinear(testnum, testerr, vecFromList, lst5, true);

    lasd::List<int> lstFromVec(vecFromList);
    EqualLinear(testnum, testerr, lstFromVec, vecFromList, true);

    vecFromList.Clear();
    Empty(testnum, testerr, vecFromList, true);

    vecFromList.Resize(5);
    for (unsigned int i = 0; i < 5; ++i) {
        SetAt(testnum, testerr, vecFromList, true, i, 0);
    }

    pos = 0;
    vecFromList.Map([&pos](int& i) { i = pos++; });
    Traverse(testnum, testerr, vecFromList, true, &TraversePrint<int>); // 0,1,2,3,4

    Fold(testnum, testerr, vecFromList, true, [](const int& data, const int& accum) { return accum + data * data; }, 0, 30);
}

void zMyLinearDouble(unsigned int& testnum, unsigned int& testerr) {
    lasd::SortableVector<double> vec1;
    Empty(testnum, testerr, vec1, true);

    lasd::SortableVector<double> vec2(0);
    vec1.Resize(0);
    Empty(testnum, testerr, vec1, true);
    Empty(testnum, testerr, vec2, true);
    EqualVector(testnum, testerr, vec1, vec2, true);

    lasd::SortableVector<double> vec3;
    vec2 = vec3;
    Size(testnum, testerr, vec2, true, 0);
    EqualVector(testnum, testerr, vec1, vec2, true);
    EqualVector(testnum, testerr, vec2, vec3, true);

    SetAt(testnum, testerr, vec3, false, 0, 0.0);
    vec3.Resize(5);
    Size(testnum, testerr, vec3, true, 5);
    SetAt(testnum, testerr, vec3, true, 0, 5.5);
    SetAt(testnum, testerr, vec3, true, 1, 4.4);
    SetAt(testnum, testerr, vec3, true, 2, 3.3);
    SetAt(testnum, testerr, vec3, true, 3, 2.2);
    SetAt(testnum, testerr, vec3, true, 4, 1.1);
    SetAt(testnum, testerr, vec3, false, 5, 1.0);

    Empty(testnum, testerr, vec2, true);
    Size(testnum, testerr, vec2, true, 0);
    vec2 = std::move(vec3);
    Size(testnum, testerr, vec3, true, 0);
    Traverse(testnum, testerr, vec2, true, &TraversePrint<double>);
    GetAt(testnum, testerr, vec2, false, 0, 1.1);
    GetAt(testnum, testerr, vec2, false, 1, 2.2);
    GetAt(testnum, testerr, vec2, true, 2, 3.3);
    GetAt(testnum, testerr, vec2, false, 3, 4.4);
    GetAt(testnum, testerr, vec2, false, 4, 5.5);

    Empty(testnum, testerr, vec3, true);
    vec2.Sort();
    Traverse(testnum, testerr, vec2, true, &TraversePrint<double>);
    GetAt(testnum, testerr, vec2, true, 0, 1.1);
    GetAt(testnum, testerr, vec2, true, 1, 2.2);
    GetAt(testnum, testerr, vec2, true, 2, 3.3);
    GetAt(testnum, testerr, vec2, true, 3, 4.4);
    GetAt(testnum, testerr, vec2, true, 4, 5.5);

    vec2.Sort();
    Traverse(testnum, testerr, vec2, true, &TraversePrint<double>);
    vec2.Resize(2);
    GetAt(testnum, testerr, vec2, false, 2, 1.0);

    lasd::SortableVector<double> vec4(vec2);
    lasd::SortableVector<double> vec5(std::move(vec2));
    Empty(testnum, testerr, vec2, true);
    EqualVector(testnum, testerr, vec4, vec5, true);

    lasd::SortableVector<double> vec6;
    EqualVector(testnum, testerr, vec2, vec6, true);
    vec4.Resize(1);
    EqualVector(testnum, testerr, vec4, vec5, false);
    vec4.Resize(2);
    SetAt(testnum, testerr, vec4, true, 1, 2.2);
    Traverse(testnum, testerr, vec4, true, &TraversePrint<double>);
    Traverse(testnum, testerr, vec5, true, &TraversePrint<double>);
    EqualVector(testnum, testerr, vec4, vec5, true);

    vec4.Resize(10);
    for (int i = 0; i < 10; ++i) SetAt(testnum, testerr, vec4, true, i, 1.5);
    Traverse(testnum, testerr, vec4, true, &TraversePrint<double>);
    Fold(testnum, testerr, vec4, true, [](const double& data, const double& accum) { return accum + data; }, 0.0, 15.0);

    Map(testnum, testerr, vec4, true, [](double& i) { i += 0.5; });
    Traverse(testnum, testerr, vec4, true, &TraversePrint<double>);
    Fold(testnum, testerr, vec4, true, [](const double& data, const double& accum) { return accum + data; }, 0.0, 20.0);

    double pos = 0;
    Map(testnum, testerr, vec4, true, [&pos](double& i) { i += pos++ * 0.1; });
    Traverse(testnum, testerr, vec4, true, &TraversePrint<double>);
    Fold(testnum, testerr, vec4, true, [](const double& data, const double& accum) {
        return (static_cast<int>(data * 10) % 2 == 0) ? accum + 1.0 : accum - 1.0;
    }, 0.0, 0.0);

    lasd::List<double> lst(vec4);
    lasd::SortableVector<double> vec7(lst);
    EqualVector(testnum, testerr, vec4, vec7, true);
    Traverse(testnum, testerr, vec7, true, &TraversePrint<double>);

    vec1 = vec5;
    lasd::SortableVector<double> vec8(std::move(lst));
    EqualVector(testnum, testerr, vec7, vec8, true);
    vec5 = std::move(vec7);
    Traverse(testnum, testerr, vec7, true, &TraversePrint<double>);
    EqualVector(testnum, testerr, vec4, vec5, true);
    EqualVector(testnum, testerr, vec4, vec8, true);
    EqualVector(testnum, testerr, vec5, vec8, true);

    Empty(testnum, testerr, lst, false);
    Empty(testnum, testerr, vec7, false);
    EqualVector(testnum, testerr, vec1, vec7, true);
    NonEqualVector(testnum, testerr, vec1, vec7, false);
    Exists(testnum, testerr, vec7, true, 1.1);
    Exists(testnum, testerr, vec7, false, 12.0);

    Traverse(testnum, testerr, vec4, true, &TraversePrint<double>);

    vec5.Clear();
    Size(testnum, testerr, vec5, true, 0);
    EqualVector(testnum, testerr, vec5, vec7, false);
    NonEqualVector(testnum, testerr, vec5, vec7, true);
    Exists(testnum, testerr, vec5, false, 1.0);
    GetAt(testnum, testerr, vec5, false, 0, 0.0);
    SetAt(testnum, testerr, vec5, false, 0, 0.0);

    lasd::List<double> lst2;
    InsertAtBack(testnum, testerr, lst2, true, 1.1);
    InsertAtBack(testnum, testerr, lst2, true, 2.2);
    InsertAtBack(testnum, testerr, lst2, true, 3.3);
    lasd::List lst3(lst2);
    lasd::SortableVector vec9(std::move(lst2));
    Traverse(testnum, testerr, lst2, true, &TraversePrint<double>);
    Traverse(testnum, testerr, lst3, true, &TraversePrint<double>);
    NonEqualList(testnum, testerr, lst2, lst3, true);

    lasd::SortableVector<double> vecDup;
    vecDup.Resize(5);
    SetAt(testnum, testerr, vecDup, true, 0, 3.3);
    SetAt(testnum, testerr, vecDup, true, 1, 1.1);
    SetAt(testnum, testerr, vecDup, true, 2, 2.2);
    SetAt(testnum, testerr, vecDup, true, 3, 2.2);
    SetAt(testnum, testerr, vecDup, true, 4, 4.4);
    vecDup.Sort();
    Traverse(testnum, testerr, vecDup, true, &TraversePrint<double>); // Expected: 1.1,2.2,2.2,3.3,4.4

    lasd::SortableVector<double> vecEmpty;
    vecEmpty.Sort();
    Empty(testnum, testerr, vecEmpty, true);

    lasd::SortableVector<double> vecSingle(1);
    SetAt(testnum, testerr, vecSingle, true, 0, 5.5);
    vecSingle.Sort();
    GetAt(testnum, testerr, vecSingle, true, 0, 5.5);

    vecDup.Resize(0);
    Empty(testnum, testerr, vecDup, true);
    vecDup.Resize(5);
    Size(testnum, testerr, vecDup, true, 5);

    vecDup.Map([](double& i) { i = i * i; });
    Traverse(testnum, testerr, vecDup, true, &TraversePrint<double>);

    vecDup.Resize(5);
    SetAt(testnum, testerr, vecDup, true, 0, 1.1);
    SetAt(testnum, testerr, vecDup, true, 1, 2.2);
    SetAt(testnum, testerr, vecDup, true, 2, 3.3);
    SetAt(testnum, testerr, vecDup, true, 3, 4.4);
    SetAt(testnum, testerr, vecDup, true, 4, 5.5);
    vecDup.Map([](double& i) { i *= i; });
    Traverse(testnum, testerr, vecDup, true, &TraversePrint<double>);

    Fold(testnum, testerr, vecDup, true, [](const double& data, const double& accum) { return accum + data; }, 0.0, 66.55);

    lasd::SortableVector<double> vecExist(5);
    SetAt(testnum, testerr, vecExist, true, 0, 1.1);
    SetAt(testnum, testerr, vecExist, true, 1, 2.2);
    SetAt(testnum, testerr, vecExist, true, 2, 3.3);
    SetAt(testnum, testerr, vecExist, true, 3, 4.4);
    SetAt(testnum, testerr, vecExist, true, 4, 5.5);

    Exists(testnum, testerr, vecExist, true, 1.1);
    Exists(testnum, testerr, vecExist, true, 5.5);
    Exists(testnum, testerr, vecExist, false, 0.0);
    Exists(testnum, testerr, vecExist, false, 6.6);
}

void zMyLinearString(unsigned int& testnum, unsigned int& testerr) {
    lasd::SortableVector<std::string> vec1;
    Empty(testnum, testerr, vec1, true);

    lasd::SortableVector<std::string> vec2(5);
    vec1 = vec2;
    Empty(testnum, testerr, vec1, false);
    EqualVector(testnum, testerr, vec1, vec2, true);

    lasd::SortableVector<std::string> vec3;
    vec2 = vec3;
    Size(testnum, testerr, vec2, true, 0);
    EqualVector(testnum, testerr, vec1, vec2, false);
    EqualVector(testnum, testerr, vec2, vec3, true);

    SetAt(testnum, testerr, vec3, false, 0, std::string(""));
    vec3.Resize(5);
    Size(testnum, testerr, vec3, true, 5);
    SetAt(testnum, testerr, vec3, true, 0, std::string("E"));
    SetAt(testnum, testerr, vec3, true, 1, std::string("D"));
    SetAt(testnum, testerr, vec3, true, 2, std::string("C"));
    SetAt(testnum, testerr, vec3, true, 3, std::string("B"));
    SetAt(testnum, testerr, vec3, true, 4, std::string("A"));
    SetAt(testnum, testerr, vec3, false, 5, std::string("Z"));

    Empty(testnum, testerr, vec2, true);
    Size(testnum, testerr, vec2, true, 0);
    vec2 = std::move(vec3);
    Size(testnum, testerr, vec3, true, 0);
    Traverse(testnum, testerr, vec2, true, &TraversePrint<std::string>);
    GetAt(testnum, testerr, vec2, false, 0, std::string("A"));
    GetAt(testnum, testerr, vec2, false, 1, std::string("B"));
    GetAt(testnum, testerr, vec2, true, 2, std::string("C"));
    GetAt(testnum, testerr, vec2, false, 3, std::string("D"));
    GetAt(testnum, testerr, vec2, false, 4, std::string("E"));

    Empty(testnum, testerr, vec3, true);
    vec2.Sort();
    Traverse(testnum, testerr, vec2, true, &TraversePrint<std::string>);
    GetAt(testnum, testerr, vec2, true, 0, std::string("A"));
    GetAt(testnum, testerr, vec2, true, 1, std::string("B"));
    GetAt(testnum, testerr, vec2, true, 2, std::string("C"));
    GetAt(testnum, testerr, vec2, true, 3, std::string("D"));
    GetAt(testnum, testerr, vec2, true, 4, std::string("E"));

    vec2.Sort();
    Traverse(testnum, testerr, vec2, true, &TraversePrint<std::string>);
    vec2.Resize(2);
    GetAt(testnum, testerr, vec2, false, 2, std::string("Z"));

    lasd::SortableVector<std::string> vec4(vec2);
    lasd::SortableVector<std::string> vec5(std::move(vec2));
    Empty(testnum, testerr, vec2, true);
    EqualVector(testnum, testerr, vec4, vec5, true);

    lasd::SortableVector<std::string> vec6;
    EqualVector(testnum, testerr, vec2, vec6, true);
    vec4.Resize(1);
    EqualVector(testnum, testerr, vec4, vec5, false);
    vec4.Resize(2);
    SetAt(testnum, testerr, vec4, true, 1, std::string("B"));
    Traverse(testnum, testerr, vec4, true, &TraversePrint<std::string>);
    Traverse(testnum, testerr, vec5, true, &TraversePrint<std::string>);
    EqualVector(testnum, testerr, vec4, vec5, true);

    vec4.Resize(10);
    for (int i = 0; i < 10; ++i) SetAt(testnum, testerr, vec4, true, i, std::string("X"));
    Traverse(testnum, testerr, vec4, true, &TraversePrint<std::string>);
    Fold(testnum, testerr, vec4, true, [](const std::string& data, const std::string& accum) {
        return accum + data;
    }, std::string(""), std::string("XXXXXXXXXX"));

    Map(testnum, testerr, vec4, true, [](std::string& s) { s += std::string("Y"); });
    Traverse(testnum, testerr, vec4, true, &TraversePrint<std::string>);
    Fold(testnum, testerr, vec4, true, [](const std::string& data, const std::string& accum) {
        return accum + data;
    }, std::string(""), std::string("XYXYXYXYXYXYXYXYXYXY"));

    unsigned long int pos = 0;
    Map(testnum, testerr, vec4, true, [&pos](std::string& s) { s += std::to_string(pos++); });
    Traverse(testnum, testerr, vec4, true, &TraversePrint<std::string>);

    lasd::List lst(vec4);
    lasd::SortableVector vec7(lst);
    EqualVector(testnum, testerr, vec4, vec7, true);
    Traverse(testnum, testerr, vec7, true, &TraversePrint<std::string>);

    vec1 = vec5;
    lasd::SortableVector vec8(std::move(lst));
    EqualVector(testnum, testerr, vec7, vec8, true);
    vec5 = std::move(vec7);
    Traverse(testnum, testerr, vec7, true, &TraversePrint<std::string>);
    EqualVector(testnum, testerr, vec4, vec5, true);
    EqualVector(testnum, testerr, vec4, vec8, true);
    EqualVector(testnum, testerr, vec5, vec8, true);

    Empty(testnum, testerr, lst, false);
    Empty(testnum, testerr, vec7, false);
    EqualVector(testnum, testerr, vec1, vec7, true);
    NonEqualVector(testnum, testerr, vec1, vec7, false);
    Exists(testnum, testerr, vec7, true, std::string("A"));
    Exists(testnum, testerr, vec7, false, std::string("Z"));

    Traverse(testnum, testerr, vec4, true, &TraversePrint<std::string>);
    pos = 0;
    FoldPreOrder(testnum, testerr, vec4, true, FoldStringConcatenate, std::string(""), std::string("XY0XY1XY2XY3XY4XY5XY6XY7XY8XY9"));

    pos = 0;
    FoldPostOrder(testnum, testerr, vec4, true,FoldStringConcatenate, std::string(""), std::string("XY9XY8XY7XY6XY5XY4XY3XY2XY1XY0"));

    vec5.Clear();
    Size(testnum, testerr, vec5, true, 0);
    EqualVector(testnum, testerr, vec5, vec7, false);
    NonEqualVector(testnum, testerr, vec5, vec7, true);
    Exists(testnum, testerr, vec5, false, std::string("A"));
    GetAt(testnum, testerr, vec5, false, 0, std::string(""));
    SetAt(testnum, testerr, vec5, false, 0, std::string(""));

    lasd::List<std::string> lst2;
    InsertAtBack(testnum, testerr, lst2, true, std::string("Alpha"));
    InsertAtBack(testnum, testerr, lst2, true, std::string("Beta"));
    InsertAtBack(testnum, testerr, lst2, true, std::string("Gamma"));
    lasd::List<std::string> lst3(lst2);
    lasd::SortableVector<std::string> vec9(std::move(lst2));
    Traverse(testnum, testerr, lst2, true, &TraversePrint<std::string>);
    Traverse(testnum, testerr, lst3, true, &TraversePrint<std::string>);
    NonEqualList(testnum, testerr, lst2, lst3, true);

    lasd::SortableVector<std::string> vecDup;
    vecDup.Resize(5);
    SetAt(testnum, testerr, vecDup, true, 0, std::string("Charlie"));
    SetAt(testnum, testerr, vecDup, true, 1, std::string("Alpha"));
    SetAt(testnum, testerr, vecDup, true, 2, std::string("Bravo"));
    SetAt(testnum, testerr, vecDup, true, 3, std::string("Bravo"));
    SetAt(testnum, testerr, vecDup, true, 4, std::string("Delta"));
    vecDup.Sort();
    Traverse(testnum, testerr, vecDup, true, &TraversePrint<std::string>); // Alpha,Bravo,Bravo,Charlie,Delta

    lasd::SortableVector<std::string> vecEmpty;
    vecEmpty.Sort();
    Empty(testnum, testerr, vecEmpty, true);

    lasd::SortableVector<std::string> vecSingle(1);
    SetAt(testnum, testerr, vecSingle, true, 0, std::string("Echo"));
    vecSingle.Sort();
    GetAt(testnum, testerr, vecSingle, true, 0, std::string("Echo"));

    vecDup.Resize(0);
    Empty(testnum, testerr, vecDup, true);
    vecDup.Resize(5);
    Size(testnum, testerr, vecDup, true, 5);

    vecDup.Map([](std::string& s) { s = s + s; });
    Traverse(testnum, testerr, vecDup, true, &TraversePrint<std::string>);

    vecDup.Resize(5);
    SetAt(testnum, testerr, vecDup, true, 0, std::string("a"));
    SetAt(testnum, testerr, vecDup, true, 1, std::string("b"));
    SetAt(testnum, testerr, vecDup, true, 2, std::string("c"));
    SetAt(testnum, testerr, vecDup, true, 3, std::string("d"));
    SetAt(testnum, testerr, vecDup, true, 4, std::string("e"));
    vecDup.Map([](std::string& s) { s = s + s; });
    Traverse(testnum, testerr, vecDup, true, &TraversePrint<std::string>); // aa,bb,cc,dd,ee

    Fold(testnum, testerr, vecDup, true, [](const std::string& data, const std::string& accum) {
        return accum + data;
    }, std::string(""), std::string("aabbccddee"));

    lasd::SortableVector<std::string> vecExist(5);
    SetAt(testnum, testerr, vecExist, true, 0, std::string("Alpha"));
    SetAt(testnum, testerr, vecExist, true, 1, std::string("Beta"));
    SetAt(testnum, testerr, vecExist, true, 2, std::string("Gamma"));
    SetAt(testnum, testerr, vecExist, true, 3, std::string("Delta"));
    SetAt(testnum, testerr, vecExist, true, 4, std::string("Epsilon"));

    Exists(testnum, testerr, vecExist, true, std::string("Alpha"));
    Exists(testnum, testerr, vecExist, true, std::string("Epsilon"));
    Exists(testnum, testerr, vecExist, false, std::string(""));
    Exists(testnum, testerr, vecExist, false, std::string("Omega"));

    //TODO - Coverage tests
    lasd::List<std::string> lst4(std::move(vecExist));
    Exists(testnum, testerr, lst4, true, std::string("Alpha"));
    Exists(testnum, testerr, lst4, true, std::string("Epsilon"));
    Exists(testnum, testerr, lst4, false, std::string(""));
    Exists(testnum, testerr, lst4, false, std::string("Omega"));
}

void zMyTestLinear(unsigned int& testnum, unsigned int& testerr) {
    std::cout << "\n~*~#~*~ Test Linear Container ~*~#~*~ " << std::endl;

    std::cout << "\n[Test 1] Testing Linear<int>..." << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    zMyLinearInt(testnum, testerr);
    std::cout << "Integer linear tests completed" << std::endl;

    std::cout << "\n[Test 2] Testing Linear<double>..." << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    zMyLinearDouble(testnum, testerr);
    std::cout << "Double linear tests completed" << std::endl;

    std::cout << "\n[Test 3] Testing Linear<string>..." << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    zMyLinearString(testnum, testerr);
    std::cout << "String linear tests completed" << std::endl;

    std::cout << "\nAll linear tests completed!" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

}
