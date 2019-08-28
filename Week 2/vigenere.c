#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    bool wrongUsage = false;
    if (argc == 2) {
        for(int i = 0; i < strlen(argv[1]); i++) {
            if ((argv[1][i] >= 65 && argv[1][i] <= 90) || (argv[1][i] >= 97 && argv[1][i] <= 122)) {
                wrongUsage = false;
            } else {
                wrongUsage = true;
                break;
            }
        }
    } else {
        wrongUsage = true;
    }
    if (wrongUsage) {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    } else {
        int keyIndex = 0;
        int keyLength = strlen(argv[1]);
        char key[keyLength];
        for (int i = 0; i < keyLength; i++) {
            char convert;
            if (argv[1][i] <= 90) {
                key[i] = argv[1][i] + 32;
            } else {
                key[i] = argv[1][i];
            }
        }
        string plaintext = get_string("plaintext: ");
        char ciphertext[strlen(plaintext) + 1];
        for (int i = 0; i < strlen(plaintext); i++) {
            if (plaintext[i] >= 65 && plaintext[i] <= 90) {
                if (plaintext[i] + (key[keyIndex] - 97) > 90) {
                    ciphertext[i] = (char) (64 + ((plaintext[i] + (key[keyIndex] - 97)) - 90));
                } else {
                    ciphertext[i] = (char) ((plaintext[i] + (key[keyIndex] - 97)));
                }
                if (keyIndex + 1 == keyLength) {
                    keyIndex = 0;
                } else {
                    keyIndex++;
                }
            } else if (plaintext[i] >= 97 && plaintext[i] <= 122) {
                if (plaintext[i] + (key[keyIndex] - 97) > 122) {
                    ciphertext[i] = (char) (96 + ((plaintext[i] + (key[keyIndex] - 97)) - 122));
                } else {
                    ciphertext[i] = (char) (plaintext[i] + (key[keyIndex] - 97));
                }
                if (keyIndex + 1 == keyLength) {
                    keyIndex = 0;
                } else {
                    keyIndex++;
                }
            } else {
                ciphertext[i] = plaintext[i];
            }
        } 
        ciphertext[strlen(plaintext)] = '\0';
        
        printf("ciphertext: %s\n", ciphertext);
    }
}
