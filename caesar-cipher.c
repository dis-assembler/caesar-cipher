#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

void encryptText(const char plainText[], char cipherText[], int shift) {

	int plainTextLenght = strlen(plainText);

	for(int i=0; i < plainTextLenght; i++) {
		if (isalpha(plainText[i])) {
			if (isupper(plainText[i])) {
				cipherText[i] = ((plainText[i] - 'A' + shift) % 26 ) + 'A';
			}
			else { 
				cipherText[i] = ((plainText[i] - 'a' + shift) % 26 ) + 'a';
			
		}
		}
		else {
	
			cipherText[i] = plainText[i];
	
		}

	

	cipherText[plainTextLenght]='\0';
	
} 

}


int main()
{

	int shift;
	char plainText[MAX_SIZE], cipherText[MAX_SIZE];


	printf("INSERT TEXT TO ENCRYPT/DECRYPT:\n");
		fgets(plainText, MAX_SIZE, stdin);

	printf("INSERT SHIFT VALUE:\n");
		scanf("%d", &shift);

	encryptText(plainText, cipherText, shift);

	printf("%s\n", cipherText);

}
