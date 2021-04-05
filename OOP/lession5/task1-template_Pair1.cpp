#include <iostream>

template<typename T>
class Pair1
{
private:
    T p_first;
    T p_second;
public:
    Pair1(T first, T second)
        : p_first(first), p_second(second)
    {   }
    
    T first() const  { return p_first; }
    T second() const { return p_second; }
};

int main(int argc, const char * argv[])
{
    Pair1<int> p1(6, 9);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
    
    const Pair1<double> p2(3.4, 7.8);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
    
    return 0;
}
