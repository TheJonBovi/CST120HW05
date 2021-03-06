#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  // NOLINT
#include <string.h>  // NOLINT
#include "functions.h"

void get_key(int* const key)
{
	double temp_key = -1;
	char input[MAXSIZE];
	printf("Enter a positive integer for a key: ");
	getchar();

	while (temp_key == -1)
	{
		char* cp = fgets(input, sizeof(input), stdin);
		if (cp == input)
		{
			char badc; // badc is for detecting extraneous chars in the input
			int const n = sscanf(input, "%lf %c", &temp_key, &badc);
			printf("\n");

			if (n != 1 || temp_key < 0) // if badc captured an extraneous char
			{
				printf("Error! Enter a positive integer: ");
				temp_key = -1;
			}
		}
	}

	*key = (int)temp_key % 26;
}

void get_text(char* const input)
{
	char temp_text[MAXSIZE];
	int input_good = 0;

	while (!input_good)
	{
		printf("Enter text: ");
		scanf(" %s", temp_text);

		size_t const temp_text_size = strlen(temp_text);
		input_good = 1;

		for (size_t i = 0; i < temp_text_size; i++)
		{
			if (!(temp_text[i] >= LOWER_MIN && temp_text[i] <= LOWER_MAX)
				&& !(temp_text[i] >= UPPER_MIN && temp_text[i] <= UPPER_MAX))
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

void to_upper(char* const text)
{
	char temp_text[MAXSIZE];
	strcpy(temp_text, text);

	// If a character is lowercase, subtract difference to get uppercase
	for (size_t i = 0; i < strlen(text); i++)
	{
		if (temp_text[i] >= LOWER_MIN && temp_text[i] <= LOWER_MAX)
		{
			temp_text[i] -= (LOWER_MIN - UPPER_MIN);
		}
	}

	strcpy(text, temp_text);
}

void to_lower(char* const text)
{
	char temp_text[MAXSIZE];
	strcpy(temp_text, text);

	// If a character is uppercase, add difference to value to get lowercase
	for (size_t i = 0; i < strlen(text); i++)
	{
		if (temp_text[i] >= UPPER_MIN && temp_text[i] <= UPPER_MAX)
		{
			temp_text[i] += (LOWER_MIN - UPPER_MIN);
		}
	}

	strcpy(text, temp_text);
}

void caesar_encrypt(int const key, char const* const plaintext, char* const ciphertext)
{
	char temp_text[MAXSIZE];
	strcpy(temp_text, plaintext);
	to_lower(temp_text);

	size_t const temp_text_size = strlen(temp_text);

	for (size_t i = 0; i < temp_text_size; i++)
	{
		temp_text[i] = ((temp_text[i] - LOWER_MIN + key) % 26 + 26) % 26 + UPPER_MIN;
	}

	strcpy(ciphertext, temp_text);
}

void caesar_decrypt(int const key, char* const plaintext, char const* const ciphertext)
{
	caesar_encrypt(-key, ciphertext, plaintext);
	to_lower(plaintext);
}

void trf_encrypt(char* const text)
{
	char temp_text[MAXSIZE];
	strcpy(temp_text, text);

	size_t temp_text_size = strlen(temp_text);

	// Make sure length is divisible by 3 by adding X's
	while (temp_text_size % 3)
	{
		temp_text[temp_text_size] = 'X';
		temp_text[temp_text_size + 1] = '\0';
		temp_text_size = strlen(temp_text);
	}

	// Make new copy to switch characters to
	char final_text[MAXSIZE];
	strcpy(final_text, temp_text);

	size_t const rail_size = strlen(final_text) / 3;

	for (size_t i = 0; i < rail_size; i++)
	{
		final_text[i] = temp_text[3 * i];
		final_text[i + rail_size] = temp_text[3 * i + 1];
		final_text[i + 2 * rail_size] = temp_text[3 * i + 2];
	}

	// Stick it back into input parameter
	strcpy(text, final_text);
}

void trf_decrypt(char* const text)
{
	char temp_text[MAXSIZE];
	strcpy(temp_text, text);

	size_t const temp_text_size = strlen(temp_text);
	// TODO: What if this has remainder? IE: what if input not even divisible by 3!!
	size_t const rail_size = strlen(temp_text) / 3;

	// Unwind similar to inverse of trf_encrypt
	for (size_t i = 0; i < rail_size; i++)
	{
		temp_text[3 * i] = text[i];
		temp_text[3 * i + 1] = text[i + rail_size];
		temp_text[3 * i + 2] = text[i + 2 * rail_size];
	}

	// Stick it back into input parameter
	strcpy(text, temp_text);
}

void encryption()
{
	char plaintext[MAXSIZE];
	char ciphertext[MAXSIZE];
	int key;

	get_key(&key);
	get_text(plaintext);

	caesar_encrypt(key, plaintext, ciphertext);
	trf_encrypt(ciphertext);

	printf("The ciphertext is: %s\n\n", ciphertext);
}

void decryption()
{
	char plaintext[MAXSIZE];
	char ciphertext[MAXSIZE];
	int key;

	get_key(&key);
	get_text(ciphertext);

	trf_decrypt(ciphertext);
	caesar_decrypt(key, plaintext, ciphertext);

	printf("The plaintext is: %s\n\n", plaintext);
}
