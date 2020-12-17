#include <stdio.h>


struct fraction {						// структура данных (новый тип данных)
	int integer;
	int divisible;
	int divider;
};
typedef struct fraction Fraction; 		// описание нового типа данных, для сокращения записи

void frPrint(Fraction f) {				// функция вывода на экран Fraction
	if (f.divisible != 0)				// работает через копиросание значения
		if (f.integer == 0)
			printf("%d/%d", f.divisible, f.divider);
		else printf("%d|%d/%d", f.integer, f.divisible, f.divider);
	else printf("%d", f.integer);
}

void frDesint(Fraction *f) {
	int sign = (f->integer < 0) ? -1 : 1;
		if (f->integer < 0)
			f->integer = -f->integer;
		f->divisible = f->divisible + (f->integer * f->divider);
		f->divisible *= sign;
		f->integer = 0;
}


void frMul(Fraction f1, Fraction f2, Fraction *r) {
	frDesint(&f1);
	frDesint(&f2);
	r->divisible = f1.divisible * f2.divisible;
	r->divider = f1.divider * f2.divider;
}


int main(int argc, char const *argv[])
{
	Fraction f1, f2, result = {0, 0, 0};

	f1.integer = -1;
	f1.divisible = 1;		// -1|1/5
	f1.divider = 5;

	f2.integer = 1;
	f2.divisible = 1;		// 1|1/5
	f2.divider = 5;

	frPrint(f1);
	puts("");							// аналог \n
	frPrint(f2);

	frMul(f1, f2, &result);
	puts("");
	frPrint(result);

	return 0;
}





