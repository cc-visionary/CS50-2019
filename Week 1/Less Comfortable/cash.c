#include <cs50.h>
#include <stdio.h>

int main(void) {
    float change = get_float("Change owed: ");
    while(change <= 0) {
        change = get_float("Change owed: ");
    }
    change *= 100;
    int coins = 0;
    if(change >= 25) {
        int current_coin = change / 25;
        coins += current_coin;
        change -= current_coin * 25;
    }
    if(change >= 10) {
        int current_coin = change / 10;
        coins += current_coin;
        change -= current_coin * 10;
    }
    if(change >= 5) {
        int current_coin = change / 5;
        coins += current_coin;
        change -= current_coin * 5;
    }
    if(change >= 1) {
        int current_coin = change / 1;
        coins += current_coin;
        change -= current_coin * 1;
    }
    printf("%d\n", coins);
}
