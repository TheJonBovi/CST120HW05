#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


void get_key(int* const input);
void get_text(char* const input);
void caesar_encrypt(char const * const plaintext);
void rail_fence_encrypt(char const * const plain, char* const cipher);

void main(void)
{
	int program_run = 1;
	int key_flag = 0;
	int key = 0;
	char plaintext[100];
	char ciphertext[100];
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
		case 1:
			get_key(&key);
			key_flag = 1;
			break;

		case 2:
			if (key_flag)
			{
				get_text(plaintext);
			}
			else
			{
				printf("Enter a key first!\n\n");
			}
			break;

		case 3:
			if (key_flag)
			{
				// TODO: Stuff
			}
			else
			{
				printf("Enter a key first!\n\n");
			}
			break;

		case 4:
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

void get_key(int* const input)
{
	int temp_key;
	printf("Enter a positive integer for a key: ");

	scanf("%d", &temp_key);

	while( temp_key < 0 )
	{
		printf( "Error! Enter a positive integer: ");

		scanf("%d", &temp_key);
	}

	temp_key %= 25;

	*input = temp_key;
	printf("\n");
}

void get_text(char* const input)
{
	char temp_text[100];
	int input_good = 0;


	while (!input_good)
	{
		printf("Enter plaintext as lowercase characters: ");
		scanf(" %s", temp_text);

		size_t const temp_text_size = strlen(temp_text);
		input_good = 1;

		for (size_t i = 0; i < temp_text_size; i++)
		{
			if(temp_text[i] < 97 || temp_text[i] > 122)
			{
				printf("Bad input, try again!\n");
				input_good = 0;
				break;
			}
		}
	}
	strcpy(input, temp_text);
	printf("\n");
}

void caesar_encrypt(char const * const plaintext)
{
	
}