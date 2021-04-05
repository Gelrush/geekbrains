#include <iostream>

/*struct Custom_manip {} endll;
std::ostream& operator<<(std::ostream& os, Custom_manip)
{
    os << "\n\n";
    os.flush();
    return os;
}*/

std::ostream& endll(std::ostream& os) {
    os << "\n\n";
    os.flush();
    return os;
}

int main(int argc, char const* argv[])
{
    std::cout << "Enter a int value: " << endll;

    return 0;
}
