#include <iostream>
#include <algorithm> // для std::swap. В C++11 используйте заголовок <utility>
					 // для std::sort()

int main()
{   
    const int length = 5;
    int array[length] = { 30, 50, 20, 10, 40 };

	// Сортировка массивов методом выбора
	for (int startIndex = 0; startIndex < length - 1; ++startIndex)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			if (array[currentIndex] < array[smallestIndex])
				smallestIndex = currentIndex;
		}
		std::swap(array[startIndex], array[smallestIndex]);
	}

	for (int index = 0; index < length; ++index)
		std::cout << array[index] << ' ';

	// Функция сортировки std::sort() находится в заголовочном файле algorithm
	int array2[length] = { 30, 50, 20, 10, 40 };
	std::sort(array2, array2 + length); // Принимает первый и последний элементы массива

	for (int i = 0; i < length; ++i)
		std::cout << array2[i] << ' ';

    return 0;
}
