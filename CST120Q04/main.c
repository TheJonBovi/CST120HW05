#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void main(void)
{
	char run_program = 'y';

	while (run_program == 'y' || run_program == 'Y')
	{
		char input;
		int key;
		printf("Enter a character between a-z: ");

		scanf(" %c", &input);

		while ((int)input < 97 || (int)input > 122)
		{
			printf( "Do it again, a-z only: " );

			scanf(" %c", &input);
		}

		printf("Enter a key, 0-25: ");

		scanf(" %d", &key);

		while (key < 0 || key > 25)
		{
			printf( "Do it again, 0-25 only: " );

			scanf(" %d", &key);
		}

		input = input - 97;

		auto const encrypted = (char)((((int)input + key) % 26) + 65);

		printf("Encrypted character is: %c", encrypted);

		printf("\nEnter Y or y to run again: ");
		scanf(" %c", &run_program);
	}
}