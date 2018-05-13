#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  // NOLINT
#include <string.h>  // NOLINT
#include "functions.h"

void get_key(int* const input)
{
	int temp_key;
	printf("Enter a positive integer for a key: ");

	scanf("%d", &temp_key);

	while (temp_key < 0)
	{
		printf("Error! Enter a positive integer: ");

		scanf("%d", &temp_key);
	}

	temp_key %= 25;

	*input = temp_key;
	printf("\n");
}

void get_text(char* const input)
{
	char temp_text[MAXSIZE];
	int input_good = 0;


	while (!input_good)
	{
		printf("Enter plaintext as lowercase characters: ");
		scanf(" %s", temp_text);

		size_t const temp_text_size = strlen(temp_text);
		input_good = 1;

		for (size_t i = 0; i < temp_text_size; i++)
		{
			if (temp_text[i] < 97 || temp_text[i] > 122)
			{
				printf("Bad input, try again using only lowercase letters!\n");
				input_good = 0;
				break;
			}
		}
	}
	strcpy(input, temp_text);
	printf("\n");
}

void encryption(int key)
{
	char plaintext[MAXSIZE];
	char ciphertext[MAXSIZE];

	get_text(plaintext);

	caesar_encrypt(key, plaintext, ciphertext);

	rail_fence_encrypt(ciphertext);

	printf("The ciphertext is: %s\n\n", ciphertext);
}

void decryption(int key)
{

}

void caesar_encrypt(int const key, char const* const plaintext, char* const ciphertext)
{
	char temp_text[MAXSIZE];
	strcpy(temp_text, plaintext);

	size_t const temp_text_size = strlen(temp_text);

	for (size_t i = 0; i < temp_text_size; i++)
	{
		temp_text[i] = ((temp_text[i] - 97) + key) % 25 + 65;
	}

	strcpy(ciphertext, temp_text);
}

void rail_fence_encrypt(char* const text)
{
	char temp_text[MAXSIZE];
	strcpy(temp_text, text);

	char rail1[MAXSIZE / 3];
	char rail2[MAXSIZE / 3];
	char rail3[MAXSIZE / 3];

	size_t temp_text_size = strlen(temp_text);

	// Make sure length is divisible by 3
	while (temp_text_size % 3)
	{
		temp_text[temp_text_size] = 'X';
		temp_text[temp_text_size + 1] = '\0';
		temp_text_size = strlen(temp_text);
	}

	for (size_t i = 0; i < temp_text_size / 3; i++)
	{
		rail1[i] = temp_text[3 * i];
		rail1[i + 1] = '\0';
		rail2[i] = temp_text[3 * i + 1];
		rail2[i + 1] = '\0';
		rail3[i] = temp_text[3 * i + 2];
		rail3[i + 1] = '\0';
	}

	for (size_t i = 0; i < strlen(rail1); i++)
	{
		temp_text[i] = rail1[i];
		temp_text[i + strlen(rail1)] = rail2[i];
		temp_text[i + strlen(rail1) + strlen(rail3)] = rail3[i];
	}

	strcpy(text, temp_text);
}
