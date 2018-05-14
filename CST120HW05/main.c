// This program will encode a string of chars via ceasar then rail fence.
// Program is NOT safe for inputs larger than 100 characters!!!
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  // NOLINT
#include "functions.h"


enum Options {k_encrypt = 1, k_decrypt, k_exit};

void main(void)
{
	int program_run = 1;
	int choice;

	while (program_run)
	{
		printf("*************Main Menu*************\n\n");
		printf(" 1 - Encryption \n");
		printf(" 2 - Decryption \n");
		printf(" 3 - Exit\n\n");

		printf("Enter your choice and press return: ");

		scanf("%d", &choice);
		printf("\n");

		switch (choice)
		{
		case k_encrypt:
			encryption();
			break;

		case k_decrypt:
			decryption();
			break;

		case k_exit:
			printf("End of program.\n\n");
			program_run = 0;
			break;

		default:
			printf("Not a valid choice, choose again.\n\n");
			printf("Enter your choice and press return: ");

			scanf("%d", &choice);
			break;
		}
	}

	// Below prevents console window from closing after program completion
	while (getchar() != '\n');
	printf("press enter to continue...\n");
	getchar();
}

