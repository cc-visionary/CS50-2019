#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if(argc < 2 || argc > 2) {
        printf("Usage: ./caesar key\n");
    } else {
        if(strlen(argv[1]) > 2) {
            printf("Usage: ./caesar key\n");
        } else {
            int key = atoi(argv[1]);
            string plain = get_string("plaintext: ");
            char decoded[100] = {};
            for(int i = 0; i < strlen(plain); i++) {
                int current = plain[i];
                if(current >= 65 && current <= 90) {
                    decoded[i] = (char) current + key;
                } else if(current >= 97 && current <= 122) {
                    if(current + key >= 122) {
                        decoded[i] = (char) 97 + (122 - (current + key));
                    } else {
                        decoded[i] = (char) current + key;
                    }
                } else {
                    decoded[i] = plain[i];
                }
            }
            printf("ciphertext: %s\n", decoded);
        }
    }
}
