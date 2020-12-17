#include <stdio.h>
#include <string.h>								// работа со строками
#include <stdlib.h>								// обработка символов
#include <ctype.h>								// классификация и преобразование символов

void helloFunction(char *out, char *name) {
	char welcome[50] = "Hello, ";
	name[0] = tolower(name[0]);					// в нижний регистр

	if (strcmp(name, "denis") == 0)				// compare: сравнивание строк -  
		strcpy(name, "Overlord");				// (-1: 1<2; 0: 1==2; 1: 1>2)
	
	name[0] = toupper(name[0]);					// в верхний регистр

	strcat(welcome, name);						// объединение строк (конкатенация)
	strcpy(out, welcome);						// copy: копирование в строку (dest <- src)
}


int main(int argc, char const *argv[])
{
	char string1[50] = "This is a string";		// строка
	char *string2 = "This is a literal";		// строковый литерал (не изменяемый)

	char name[256];
	char result[256];
	gets(name);									// считать из конмоли строку (только)
	puts(name);									// вывести в консоль строку (только)

	helloFunction(result, name);
	printf("%s\n", result);


	return 0;
}