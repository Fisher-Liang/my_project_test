#include <iostream>
#include <cstdio>
#include <vector>
#include "hashtable.h"

using namespace std;

class Foo
{
public:
    typedef int bar_type;
};

template <typename T>
class Bar
{
    typename T::bar_type bar;
};

// template<> class Bar<int>
// {
//     int bar;
// };
// template<class T>
// class Compare
// {
// public:
//     static bool IsEqual(const T& lh, const T& rh)
//     {
//         std::cout <<"in the general class..." <<std::endl;
//         return lh == rh;
//     }
// };

// specialize for float
// template<>
// class Compare<float>
// {
// public:
//     static bool IsEqual(const float& lh, const float& rh)
//     {
//         std::cout <<"in the float special class..." <<std::endl;

//         return std::abs(lh - rh) < 10e-3;
//     }
// };


int main()
{
    Bar<Foo> b;
    return 0;
}