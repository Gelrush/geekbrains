#include <array>
#include <iostream>
#include <string_view>
#include <algorithm>
//#include <functional>

struct Student
{
    std::string_view name{};
    int score{};
};

struct Season
{
    std::string_view name{};
    double averageTemperature{};
};

int main(int argc, char *argv[])
{
    {           // task1. best student
        std::array<Student, 8> arr{
        {   { "Albert", 3 },
            { "Ben", 5 },
            { "Christine", 2 },
            { "Dan", 8 },
            { "Enchilada", 4 },
            { "Francis", 1 },
            { "Greg", 3 },
            { "Hagrid", 5 } }
        };

        auto bestStudent{ std::max_element(arr.begin(), arr.end(),
            [](const auto& a, const auto& b)
            {
                return a.score < b.score;
            }) };

        std::cout << bestStudent->name << " is the best student\n";
    }
    {          // task2. sort
        std::array<Season, 4> seasons{
        {   { "Spring", 285.0 },
            { "Summer", 296.0 },
            { "Fall", 288.0 },
            { "Winter", 263.0 } }
        };

        auto isMinTemp{
            [](const auto& a, const auto& b)
            {
                return a.averageTemperature < b.averageTemperature;
            } };
        
        std::sort(seasons.begin(), seasons.end(), isMinTemp);

        for (const auto& season : seasons)
        {
            std::cout << season.name << '\n';
        }
    }
}
