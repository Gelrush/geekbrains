#include <iostream>

template<typename T, typename U>
class Pair
{
private:
    T p_first;
    U p_second;
public:
    Pair(T first, U second)
        : p_first(first), p_second(second)
    {   }
    
    T first() const  { return p_first; }
    U second() const { return p_second; }
};

int main(int argc, const char * argv[])
{
    Pair<int, double> p1(6, 7.8);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair<double, int> p2(3.4, 5);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    
    return 0;
}
