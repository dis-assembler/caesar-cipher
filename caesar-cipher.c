#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

void encryptText(const char plainText[], char encryptedText[], int shift) {

	int lenght = strlen(plainText);

	for (int i = 0; i < lenght; i++) {
	
		if (isalpha(plainText[i])) {
		
			if (isupper(plainText[i])) {
			
				encryptedText[i] = ((plainText[i] - 'A' + shift ) % 26 ) + 'A';  
			
			}
			else {
			
				encryptedText[i] = ((plainText[i] - 'a' + shift ) % 26 ) + 'a';
			
			}
		
		
		}
		else {
		
			encryptedText[i] = plainText[i];
		
		}	
	}
		
	encryptedText[lenght] = '\0';
}

void decryptText(const char encryptedText[], char decryptedText[], int shift) {
	
	int lenght = strlen(encryptedText);
	
	for (int i = 0; i < lenght; i++){
	
		if (isalpha(encryptedText[i])) {
		
			if (isupper(encryptedText[i])){
			
				decryptedText[i] = ((encryptedText[i] - 'A' - shift + 26) % 26) + 'A';
			
			}
			else{
			
				
				decryptedText[i] = ((encryptedText[i] - 'a' - shift + 26) % 26) + 'a';
			
			
			}
		
		}
		else {
		
			decryptedText[i] = encryptedText[i];
		
		}
	
	
	
	}



	decryptedText[lenght] = '\0';
}

int main() {

	int shift, chooser;
	
	char plainText[SIZE], encryptedText[SIZE], decryptedText[SIZE], outputText[SIZE];
	
	FILE *TEXT;
	
 		printf("CHOOSE AN OPTION:\n");
 		printf("1. ENCRYPT\n2. DECRYPT\n");
			scanf("%d", &chooser);
			getchar();
		
			switch (chooser) {
			
				case 0:
			
					 printf("hello\n");
			
				case 1: 
					printf("INSERT TEXT TO ENCRYPT:\n");
						fgets(plainText, SIZE, stdin);
			
					printf("INSERT SHIFT OPERATOR:\n");
						scanf("%d", &shift);
			
					encryptText(plainText, encryptedText, shift);
					strcpy(outputText, encryptedText);	
				
					break;
					
				case 2:
				
				
					printf("INSERT TEXT TO DECRYPT:\n");
						fgets(encryptedText, SIZE, stdin);
			
					printf("INSERT SHIFT OPERATOR:\n");
						scanf("%d", &shift);
			
		
					decryptText(encryptedText, decryptedText, shift);
					strcpy(outputText, decryptedText);
				
					break;
		}
			
		
		
		printf("CHOOSE OUTPUT:\n");
		printf("1. CONSOLE\n2. TEXT FILE\n");
			scanf("%d", &chooser);
			getchar();
			
			
			switch (chooser) {
			
				case 1: 
					printf("%s\n", outputText);
						break;
		
				case 2:
					TEXT = fopen ("ccoutput.txt", "w");	
					fprintf(TEXT, "%s\n", outputText);
					printf("SUCCESS.");			
						break;
			
			
				default:
			
					printf("WRONG CHOICE.\n");
						break;		
			}
				




}
