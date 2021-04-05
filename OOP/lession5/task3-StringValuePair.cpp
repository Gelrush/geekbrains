#include <iostream>
#include <string>

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

template<typename T>
class StringValuePair : public Pair<std::string, T>
{
public:
    StringValuePair(std::string first, T second)
        : Pair<std::string, T>(first, second)
    {   }
};

int main(int argc, const char * argv[])
{
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    
    return 0;
}
