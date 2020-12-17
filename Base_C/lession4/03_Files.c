#include <stdio.h>
/*		r - открытие файла для чтения. Ошибка если файла нет
 *		w - создать фаил для записи. Стирание данных, если фаил есть
 *		a - открыть фаил для записи, либо создать
 */
FILE *f;

int main(int argc, char const *argv[])
{
	f = fopen("Hello.txt", "w");
	if (f == NULL)					// завершение программы если указатель не создался
		return 1;

	fprintf(f, "Hello, file! %s", "We actually did it!");
	fclose(f);

	char word[256];
	f = fopen("Hello.txt", "r");
	while (!feof(f)) {				// возвращает 0 если конец файла не достигнут
		fscanf(f, "%s", word);		// считывание из файла
		printf("%s ", word);
	}
	fclose(f);

	return 0;
}