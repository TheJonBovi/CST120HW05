// This program will encode a string of chars via ceasar then rail fence.
// Program is NOT safe for inputs larger than 100 characters!!!
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  // NOLINT
#include "functions.h"


enum Options {k_get_key = 1, k_encrypt, k_decrypt, k_exit};

void main(void)
{
	int program_run = 1;
	int key_flag = 0;
	int key = 0;
	int choice;

	while (program_run)
	{
		printf("*************Main Menu*************\n\n");
		printf(" 1 - Enter a Key\n");
		printf(" 2 - Encryption \n");
		printf(" 3 - Decryption \n");
		printf(" 4 - Exit\n\n");

		printf("Enter your choice and press return: ");

		scanf("%d", &choice);
		printf("\n");

		switch (choice)
		{
		case k_get_key:
			get_key(&key);
			key_flag = 1;
			break;

		case k_encrypt:
			if (key_flag)
			{
				encryption(key);
			}
			else
			{
				printf("Enter a key first!\n\n");
			}
			break;

		case k_decrypt:
			if (key_flag)
			{
				decryption(key);
			}
			else
			{
				printf("Enter a key first!\n\n");
			}
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

