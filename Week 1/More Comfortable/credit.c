// American Express  15 digits - starts with 34 or 37
// MasterCard - 16 digits - starts with 51-55
// Visa - 13 and 16 digits - starts with 4

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    string str = get_string("Number: ");
    int length = strlen(str);
    bool incorrect = true;
    while(incorrect) {
        bool wrong = false;
        for(int i = 0; i < strlen(str); i++) {
            if(length != 0) {
                if(str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9') {
                    wrong = false;
                } else {
                    wrong = true;
                    break;
                }
            } else {
                wrong = true;
                break;
            }
        }
        if(wrong) {
            str = get_string("Number: ");
            length = strlen(str);
        } else {
            incorrect = false;
        }
    }
    int temp_num = 0; // stores the temporary number here
    for(int i = 0; i < strlen(str); i+=2) {
        if(str[i] - '0' >= 5) {
            if (str[i] - '0' == 5) {
                temp_num += 1 + 0;
            } else if (str[i] - '0' == 6) {
                temp_num += 1 + 2;
            } else if (str[i] - '0' == 7) {
                temp_num += 1 + 4;
            } else if (str[i] - '0' == 8) {
                temp_num += 1 + 6;
            } else if (str[i] - '0' == 9) {
                temp_num += 1 + 8;
            }
        } else {
            temp_num += (str[i] - '0') * 2;
        }
    }
    int checksum = temp_num; // gets the sum for the checksum
    if(length % 2 == 0) {
        for(int i = length - 1; i >= 1; i-=2) {
            checksum += str[i] - '0';
        }
    } else {
        for(int i = length - 2; i >= 1; i-=2) {
            checksum += str[i] - '0';
        }
    }
    if(checksum % 10 == 0) { // determine the type of card if card number is valid
        if(length  == 15) {
            if(str[0] == '3') {
                if(str[1] == '4' || str[1] == '7') {
                    printf("AMEX\n");
                } else {
                    printf("INVALID\n");
                }
            } else {
                printf("INVALID\n");
            }
        } else if(length == 16) {
            if(str[0] == '4') {
                printf("VISA\n");
            } else if(str[0] == '5') {
                if(str[1] == '1' || str[1] == '2' || str[1] == '3' || str[1] == '4' || str[1] == '5') {
                    printf("MASTERCARD\n");
                } else {
                    printf("INVALID\n");
                }
            } else {
                printf("INVALID\n");
            }
        } else if(length == 13) {
            if(str[0] == '4') {
                printf("VISA\n");
            } else {
                printf("INVALID\n");
            }
        } else {
            printf("INVALID\n");
        }
    } else {
        printf("INVALID\n");
    }
    
    return 0;
}