#pragma once

#define MAXSIZE 100

#define LOWER_MIN 97
#define LOWER_MAX 122

#define UPPER_MIN 65
#define UPPER_MAX 90

void get_key(int* const key);

void get_text(char* input);

void to_upper(char* const text);

void to_lower(char* const text);

void caesar_encrypt(int const key, char const* const plaintext, char* const ciphertext);

void caesar_decrypt(int const key, char* const plaintext, char const* const ciphertext);

void trf_encrypt(char* const text);

void encryption();

void decryption();
