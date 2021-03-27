#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int uniqueCust(std::vector<int> arr)
{
    std::set<int> unq;

    for (const auto& elem : arr)
        unq.insert(elem);

    return unq.size();
}

int uniqueStd(std::vector<int> arr)
{
    std::sort(arr.begin(), arr.end());
    auto last{ std::unique(arr.begin(), arr.end()) };
    arr.erase(last, arr.end());

    return arr.size();
}

int main(int argc, char *argv[])
{
    std::vector<int> arr{ 1, 2, 3, 4, 25, 1, 2, 3, 8 };

    std::cout << "Custom function result: " << uniqueCust(arr) << std::endl;
    std::cout << "Std::algorithm result: " << uniqueStd(arr) << std::endl;

    return 0;
}
