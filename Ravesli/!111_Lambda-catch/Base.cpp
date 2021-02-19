#include <array>
#include <vector>
#include <iostream>
#include <string_view>
#include <algorithm>
#include <functional>

        // Лямбда-захваты («capture clause»)
// Лямбды могут получить доступ только к определенным видам идентификаторов: глобальные идентификаторы, объекты, известные во время компиляции и со статической продолжительностью жизни. 

struct Car
{
    std::string make{};
    std::string model{};
};

// Функция возвращает лямбду
auto makeWalrus(const std::string &name)
{
    // Захват переменной name по ссылке и возврат лямбды
    return [&]() {
        std::cout << "I am a walrus, my name is " << name << '\n'; // неопределенное поведение
    };
}

void invoke(const std::function<void(void)> &fn)
{
    fn();
}

int getValue()
{
    return 0;
}

int main(int argc, char *argv[])
{
    {           // Захват по значению

        std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

        // Просим пользователя ввести объект для поиска
        std::cout << "search for: ";
        std::string search{};
        std::cin >> search;

        // Ошибка:
        auto found{ std::find_if(arr.begin(), arr.end(), [](std::string_view str) {
            // Ищем значение переменной search, вместо подстроки "nut"
            return (str.find(search) != std::string_view::npos); // ошибка: Переменная search недоступна в данной области видимости
          }) };

        // Верно: Захват переменной search
        auto found{ std::find_if(arr.begin(), arr.end(), 
            [search](std::string_view str) 
            {
                return (str.find(search) != std::string_view::npos);
            }) 
        };


        if (found == arr.end())
        {
            std::cout << "Not found\n";
        }
        else
        {
            std::cout << "Found " << *found << '\n';
        }
    
    }


    {       // Захват по значению, без const
        
        int ammo{ 10 };

        // Ошибка: 
        auto shoot{
              [ammo]() {
                    // Запрещено, так как переменная ammo была захвачена в виде константной копии
                    --ammo;

                    std::cout << "Pew! " << ammo << " shot(s) left.\n";
              }
        };

        // Верно:
        auto shoot{
            // Добавляем ключевое слово mutable после списка параметров, оно убирает спецификатор const
              [ammo]() mutable {
                    // Теперь нам разрешено изменять значение переменной ammo
                    --ammo;

                    std::cout << "Pew! " << ammo << " shot(s) left.\n";
              }
        };

        // Вызов лямбды
        shoot();    // 9
        shoot();    // 8
        // изменяется копия ammo, которая хранится в переменной shoot

        std::cout << ammo << " shot(s) left\n"; // 10
    }


    {       // Захват по ссылке

        int ammo{ 10 };

        auto shoot{
            // Ключевое слово mutable теперь нам не потребуется
            [&ammo]() { // переменные, которые захватываются по ссылке, не являются константными
              // Изменения текущей переменной ammo приведут к изменению переменной ammo из блока main()
              --ammo;

              std::cout << "Pew! " << ammo << " shot(s) left.\n";
            }
        };

        shoot(); // 9

        std::cout << ammo << " shot(s) left\n"; // 9
    }

    { // воспользуемся захватом по ссылке, чтобы подсчитать, сколько сравнений делает алгоритм std::sort() при сортировке массива

        std::array<Car, 3> cars{ { { "Volkswagen", "Golf" },
                             { "Toyota", "Corolla" },
                             { "Honda", "Civic" } } };

        int comparisons{ 0 };

        std::sort(cars.begin(), cars.end(),
            // Захват переменной comparisons по ссылке
            [&comparisons](const auto& a, const auto& b) {
                // Мы захватили переменную comparisons по ссылке, а это означает, что мы можем изменять её без использования спецификатора mutable
                ++comparisons;

                // Сортировка машин по марке
                return (a.make < b.make);
            });

        std::cout << "Comparisons: " << comparisons << '\n'; // 2

        for (const auto& car : cars)
            std::cout << car.make << ' ' << car.model << '\n';
    }

    {   // Захват нескольких переменных

        int health{ 33 };
        int armor{ 100 };
        std::vector<std::string> enemies{};

        // Захватываем переменные health и armor по значению, а enemies – по ссылке
        [health, armor, &enemies]() {};
    }

    {   // Захват по умолчанию захватывает все переменные, упомянутые в лямбде

        std::array areas{ 100, 25, 121, 40, 56 };

        int width{};
        int height{};

        std::cout << "Enter width and height: ";
        std::cin >> width >> height;

        auto found{ std::find_if(areas.begin(), areas.end(),
                                 [=](int knownArea) { // выполняется захват по умолчанию по значению переменных width и height
                                   return (width * height == knownArea); // потому что они здесь упомянуты
                                 }) };  // захват происходит по значению

        if (found == areas.end())
            std::cout << "I don't know this area :(\n";
        else
            std::cout << "Area found :)\n";
    }

    {   // Захваты по умолчанию могут быть смешаны с обычными захватами

        int health{ 33 };
        int armor{ 100 };
        std::vector<std::string> enemies{};

        // Захватываем переменные health и armor по значению, а enemies – по ссылке
        [health, armor, &enemies]() {};

        // Захватываем переменную enemies по ссылке, а все остальные – по значению
        [=, &enemies]() {};

        // Захватываем переменную armor по значению, а все остальные – по ссылке
        [&, armor]() {};

        // Запрещено, так как мы уже определили захват по ссылке для всех переменных
        [&, &armor]() {};

        // Запрещено, так как мы уже определили захват по значению для всех переменных
        [=, armor]() {};

        // Запрещено, так как переменная armor используется дважды
        [armor, &health, &armor]() {};

        // Запрещено, так как захват по умолчанию должен быть первым элементом в списке захвата
        [armor, &]() {};
    }

    {   // Определение новых переменных в лямбда-захвате

        std::array areas{ 100, 25, 121, 40, 56 };

        int width{};
        int height{};

        std::cout << "Enter width and height: ";
        std::cin >> width >> height;

        // Мы храним переменную areas, но пользователь ввел width и height.
        // Прежде, чем выполнить операцию поиска, мы должны вычислить значение площади (area)
        auto found{ std::find_if(areas.begin(), areas.end(),
            // Объявляем новую переменную, которая видима только для лямбды.
            // Тип переменной userArea автоматически выведен как тип int
            [userArea{ width * height }](int knownArea) {
                return (userArea == knownArea);
            }) };
    }
    
    {       // Висячие захваченные переменные

        // Создаем новый объект с именем Roofus.
        // sayName является лямбдой, возвращаемой функцией makeWalrus()
        // строка уничтожается при выполнении возврата makeWalrus(), но при этом лямбда все еще ссылается на нее
        auto sayName{ makeWalrus("Roofus") };

        // Вызов лямбды, которую возвращает функция makeWalrus()
        sayName(); // происходит попытка доступа к висячей ссылке, что чревато неопределенными результатами
    }

    {       // Непреднамеренные копии лямбд

        int i{ 0 };

        // Создаем новую лямбду с именем count
        auto count{ [i]() mutable {
          std::cout << ++i << '\n';
        } };

        count(); // обращаемся к count - 1

        auto otherCount{ count }; // создаем копию count

        // Обращаемся к count и к копии count
        count();    // 2
        otherCount();   // 2
            // Создавая объект otherCount, как копию объекта count, мы копируем его текущее состояние
    }
    
    {       // Непреднамеренные копии лямбд v2

        int i{ 0 };

        // Выполняем инкремент и выводим на экран локальную копию переменной i
        auto count{ [i]() mutable {
          std::cout << ++i << '\n';
        } };

        invoke(count); // 1
        invoke(count); // 1
        invoke(count); // 1
            // std::function внутри себя создает копию лямбда-объекта

        // std::ref(count) гарантирует, что count рассматривается, как ссылка.
        // Таким образом, всё, что пытается скопировать count, фактически является ссылкой,
        // гарантируя тем самым существование только одного объекта count
        invoke(std::ref(count)); // 1
        invoke(std::ref(count)); // 2
        invoke(std::ref(count)); // 3
    }

    {
        int a{};
        constexpr int b{};
        static int c{};
        static constexpr int d{};
        const int e{};
        const int f{ getValue() };
        static const int g{};
        static const int h{ getValue() };

        []() {
            // Попробуйте использовать переменные без их явного захвата
            a;  // Нет. Переменная a имеет автоматическую продолжительность жизни.
            b;  // Да. Переменная b используется в константном выражении.
            c;  // Да. Переменная c имеет статическую продолжительность жизни.
            d;  // Да.
            e;  // Да. Переменная e используется в константном выражении.
            f;  // Нет. Значение переменной f зависит от getValue(), что может потребовать запуска программы.
            g;  // Да.
            h;  // Да. Переменная h имеет статическую продолжительность жизни
            i;  // Да. Переменная i является глобальной переменной.
            j;  // Да. Переменная j доступна в целом файле.
        }();

    }
}
