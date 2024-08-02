#include <stdio.h>
#include <cs50.h>

int main(void){
    int coin[4];

    coin[0] = 25;
    coin[1] = 10;
    coin[2] = 5;
    coin[3] = 1;

    int cents = 0;

    do {
        cents = get_int("Change owed: ");
    } while (cents < 0);

    int total = 0;
    int index = 0;

    while (cents > 0){
        if (cents - coin[index] >= 0 ) {
            cents -= coin[index];
            total++;
        }
        else index++;
    }

    printf("%d\n", total);

    return 0;
}
