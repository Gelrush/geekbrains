#include <iostream>

// указатель на указатель (пример: массив структур)

int getSingleIndex(int row, int col, int numberOfColumnsInArray)
{
	return (row * numberOfColumnsInArray) + col;
}

int main() 
{   
    {
		int value = 7;

		int* ptr = &value;
		std::cout << *ptr << std::endl; // разыменовываем указатель, чтобы получить значение типа int

		int** ptrptr = &ptr;
		std::cout << **ptrptr << std::endl;

		int** ptrptr = &(&value); // нельзя: оператор адреса (&) требует l-value, но &value — это r-value.
		int** ptrptr = nullptr; // используйте 0, если не поддерживается C++11
    }
	{
		int **array1 = new int*[20]; // выделяем массив из 20 указателей типа int

		int* arr = new int[5]; // выделение одномерного массива можно
		int **array2 = new int[15][7]; // не будет работать!
			
				// решение:
		int (*array3)[7] = new int[15][7]; // если индекс является константой типа compile-time
		auto array4 = new int[15][7]; // намного проще! но решение не работает, если правый индекс не является константой типа compile-time

		int** array5 = new int* [15]; // выделяем массив из 15 указателей типа int — это наши строки
		for (int i = 0; i < 15; ++i)
			array5[i] = new int[7]; // а это наши столбцы
	}
	{			// мы можем создать массив треугольной формы
		int** array = new int*[15]; // выделяем массив из 15 указателей типа int — это наши строки
		for (int count = 0; count < 15; ++count)
			array[count] = new int[count + 1]; // а это наши столбцы

				// освобождение памяти
		for (int count = 0; count < 15; ++count)
			delete[] array[count];
		delete[] array; // это следует выполнять в конце
	}
	{			// альтернативой можно сдедалть одномерный массив
		const int row = 15;
		const int col = 7;	
			// Вместо следующего :
		int** array1 = new int*[row]; // выделяем массив из 15 указателей типа int — это наши строки
		for (int count = 0; count < row; ++count)
			array1[count] = new int[col]; // а это наши столбцы 

			// Делаем следующее: 
		int* array2 = new int[row * col]; // двумерный массив 15x7 "сплющенный" в одномерный массив
		// Присваиваем array[9,4] значение 3, используя наш "сплющенный" массив
		array2[getSingleIndex(3, 9, row)] = 3;
	}

    return 0;
}
