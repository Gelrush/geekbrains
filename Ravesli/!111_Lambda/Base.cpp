#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
#include <functional>

// Лямбда-выражение в программировании позволяет определить анонимную функцию внутри другой функции.
// Лямбды являются особым типом объектов, который называется функтором. 
// Функторы — это объекты, содержащие перегруженный operator(), который и делает их вызываемыми подобно обычным функциям.
// [captureClause] (параметры) -> возвращаемыйТип {	стейтменты;	}

static bool containsNut(std::string_view str) // static в данном контексте означает внутреннее связывание
{
	// Функция std::string_view::find() возвращает std::string_view::npos, если она не нашла подстроку.
	// В противном случае, она возвращает индекс, где происходит вхождение подстроки в строку str
	return (str.find("nut") != std::string_view::npos);
}

// Мы не знаем, чем будет fn. std::function работает с обычными функциями и лямбдами
void repeat(int repetitions, const std::function<void(int)>& fn)
{
	for (int i{ 0 }; i < repetitions; ++i)
	{
		fn(i);
	}
}

int main(int argc, char *argv[])
{
	{
		[]() {}; // определяем лямбда-выражение без captureClause, параметров и возвращаемого типа
	}
	
	{		// std::find_if() возвращает первый элемент подходящий под условие
		std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

		// Решение без лямбда. std::find_if() принимает указатель на функцию. 
		auto found{ std::find_if(arr.begin(), arr.end(), containsNut) };

		// Решение с лямбда. Определяем функцию непосредственно в том месте, где собираемся её использовать
		auto foundJl{ std::find_if(arr.begin(), arr.end(),
						   [](std::string_view str) // вот наша лямбда, без поля captureClause
						   {
							 return (str.find("nut") != std::string_view::npos);
						   }) };		// но данное решение плохо читается

		if (found == arr.end())
		{
			std::cout << "No nuts\n";
		}
		else
		{
			std::cout << "Found " << *found << '\n';
		}
	}
	{		// std::all_of() проверяет каждый элемент на совпа
		std::array array{ 2, 4, 6, 8, 10, 12, 14, 16 };

		// std::all_of() проверяет, являются ли ВСЕ элементы массива чётными
		auto check1 = std::all_of(array.begin(), array.end(), [](int i) { return ((i % 2) == 0); }); // Плохо читаемо

			// Хорошо: Мы можем хранить лямбду в именованной переменной и передавать её в функцию в качестве параметра
		auto isEven {  // Запись лямбда в переменную. auto обязателен, так как у лямбда нету типа данных
			[](int i)
				{
					return ((i % 2) == 0);
				}
		};
		auto check2 = std::all_of(array.begin(), array.end(), isEven);
	}

				// Хранение лямбда-выражений
	{
		// Обычный указатель на функцию. Лямбда не может ничего захватить
		double (*addNumbers1)(double, double) {
			[](double a, double b) {
				return (a + b);
			}
		};
		addNumbers1(1, 2);
	}
	{
		// Используем std::function. Лямбда может захватывать переменные. Затратно по раходу памяти.
		std::function addNumbers2{ // примечание: Если у вас не поддерживается C++17, используйте std::function<double(double, double)> 
		  [](double a, double b) {
			return (a + b);
		  }
		};
		addNumbers2(3, 4);
	}
	{
		// Используем auto. Храним лямбду с её реальным типом
		auto addNumbers3{
		  [](double a, double b) {
			return (a + b);
		  }
		};
		addNumbers3(5, 6);
	}
	{
		repeat(3, [](int i) { // если передаем лямбду в функцию в качестве параметра, нельзя использовать auto (если в функции нет шаблона)
			std::cout << i << '\n'; // std::function работает с обычными функциями и лямбдами
			});
	}

	// Лямбды с одним или несколькими параметрами типа auto называются общими («generic lambdas») лямбдами.
	{
		std::array months{
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
		};

		// Поиск двух последовательных элементов, которые совпадают с условием
		auto sameLetter{ std::adjacent_find(months.begin(), months.end(),
											[](const auto& a, const auto& b) {
											  return (a[0] == b[0]);
											}) };

		// Убеждаемся, что эти два месяца были найдены
		if (sameLetter != months.end())
		{
			std::cout << *sameLetter << " and " << *std::next(sameLetter)
				<< " start with the same letter\n";
		} // June and July start with the same letter

		// Подсчитываем количество месяцев с названиями в 5 букв
		auto fiveLetterMonths{ std::count_if(months.begin(), months.end(),
											 [](std::string_view str) { // лучше использовать string_view, так как функционал больше
											   return (str.length() == 5);
											 }) };
		std::cout << "There are " << fiveLetterMonths << " months with 5 letters\n";
	}
	{
		// Выводим значение и подсчитываем, сколько раз будет вызван print
		auto print{
		  [](auto value) {
			static int callCount{ 0 };
			std::cout << callCount++ << ": " << value << '\n';
		  }
		};
					// first lambda func
		print("hello"); // 0: hello 
		print("world"); // 1: world

					// second lambda func
		print(1); // 0: 1 
		print(2); // 1: 2

					// first lambda func
		print("ding dong"); // 2: ding dong
	}
	{		// Вывод возвращаемого типа
		auto divide{ [](int x, int y, bool bInteger) { // примечание: Не указан тип возвращаемого значения
			if (bInteger)
				return x / y;
			else
				return static_cast<double>(x) / y; // ОШИБКА: Тип возвращаемого значения не совпадает с предыдущим возвращаемым типом
			} };

		std::cout << divide(3, 2, true) << '\n';
		std::cout << divide(3, 2, false) << '\n';
	}
	{		// Возвращаемые типы trailing
		// Примечание: Явно указываем тип double для возвращаемого значения
		auto divide{ [](int x, int y, bool bInteger) -> double {
		  if (bInteger)
			return x / y; // выполнится неявное преобразование в тип double
		  else
			return static_cast<double>(x) / y;
		} };

		std::cout << divide(3, 2, true) << '\n';
		std::cout << divide(3, 2, false) << '\n';
	}


	{		// Функциональные объекты Стандартной библиотеки С++
		std::array arr{ 13, 90, 99, 5, 40, 80 };

		// Передаем std::greater в качестве параметра в std::sort()
		std::sort(arr.begin(), arr.end(), std::greater{}); // примечание: Требуются фигурные скобки для создания объекта

		for (int i : arr)
			std::cout << i << ' ';
		std::cout << '\n';
	}
}
