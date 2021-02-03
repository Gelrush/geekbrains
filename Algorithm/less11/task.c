#include <stdio.h>



#define ENC '+'
#define DEC '-'

char shiftChar(char sym, int shift, char side)
{
	if (side == DEC) 
		shift = -shift;

	if (sym > 64 && sym < 91) 
		return ((sym + shift - 65 + 26) % 26) + 65;
	if (sym > 96 && sym < 123) 
		return ((sym + shift - 97 + 26) % 26) + 97;
	if (sym > 47 && sym < 58)
		return ((sym + shift - 48 + 10) % 10) + 48;

	return sym;
}

void cipherCaesar(char* str, int shift, char side)
{
	for (int i = 0; str[i] != 0; ++i) 
		str[i] = shiftChar(str[i], shift, side);
}

int main(int argc, char const *argv[])
{
	char* str;
	puts("Enter string:");
	gets(str);

	const int SHIFT = 4;
	
	puts("Encrypted message:");
	cipherCaesar(str, SHIFT, ENC);
	puts(str);

	puts("Decrypted message:");
	cipherCaesar(str, SHIFT, DEC);
	puts(str);


	return 0;
}