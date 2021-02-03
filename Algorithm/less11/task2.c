#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define ENC '+'
#define DEC '-'


//=====================Supp func=====================
void sortBubble(char* str, const int SZ)
{
	for (int j = 0; j < SZ; ++j)
		for (int i = 0; i < SZ - 1; ++i) 
			if (str[i] > str[i + 1]) {
				char tmp = str[i];
				str[i] = str[i + 1];
				str[i + 1] = tmp;
			}
}

//=====================Task 1=====================
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

char* cipherCaesar(char* str, int shift, char side)
{
	char *out = (char*) malloc((strlen(str) + 1) * sizeof(char));
	strcpy(out, str);
	for (int i = 0; out[i] != 0; ++i) 
		out[i] = shiftChar(out[i], shift, side);
	return out;
}


//=====================Task 2=====================
int* decodWord(char* word)
{
	int len = strlen(word);
	int *arrSh = (int*) malloc((len + 1) * sizeof(int));
	arrSh[0] = len;
	char sortWord[len];
	strcpy(sortWord, word);

	sortBubble(sortWord, len);

	for (int i = 0; i < len; ++i)
		for (int j = 0; j < len; ++j)
			if (word[i] == sortWord[j]) 
				arrSh[i + 1] = j;
				
	return arrSh;
}

char* cipherShuffle(char* str, char* word, char side)
{
	int *arrCode = decodWord(word);
	int countRow = ceil((float) strlen(str) / arrCode[0]);
	char *out = (char*) malloc(countRow * arrCode[0] * sizeof(char));
	for (int i = strlen(str); i < countRow * arrCode[0]; ++i)
		str[i] = rand() % 26 + 96;
	
	
	if (side == ENC) {
		int idx = 0;
		for (int i = 1; i <= arrCode[0]; ++i)
			for (int j = 0; j < countRow; ++j)
				out[idx++] = str[arrCode[i] + j * countRow];
	}
	if (side == DEC) {
		int idx = 0;
		for (int i = 0; i < countRow; ++i)
			for (int j = 1; j <= arrCode[0]; ++j) 
				out[idx++] = str[arrCode[j] * countRow + i];
	}
		
	return out;
}


int main(int argc, char const *argv[])
{
	char *str = (char*) malloc(255 * sizeof (char));
	puts("Enter string:");
	fgets(str, 255, stdin);
	int i = 0;
    while (str[i] != '\0') { 
        if(str[i] == '\n') str[i] = '\0';
        i++;
    }

	const int SHIFT = 4;
	printf("Original message:\n%s\n", str);
	
	printf("\n---Caesar cipher---\n");
	puts("Encrypted message:");
	str = cipherCaesar(str, SHIFT, ENC);
	puts(str);

	puts("Decrypted message:");
	str = cipherCaesar(str, SHIFT, DEC);
	puts(str);

	printf("\n---Shuffle algorithm---\n");
	char* codeWord = "CARTS";
	puts("Encrypted message:");
	str = cipherShuffle(str, codeWord, ENC);
	puts(str);

	puts("Decrypted message:");
	str = cipherShuffle(str, codeWord, DEC);
	puts(str);

	return 0;
}
