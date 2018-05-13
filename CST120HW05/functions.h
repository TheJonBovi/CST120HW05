#pragma once

#define MAXSIZE 100

void get_key(int* input);

void get_text(char* input);

void encryption(int key);

void decryption(int key);

void caesar_encrypt(int const key, char const* const plaintext, char* const ciphertext);

void rail_fence_encrypt(char const* const text);
