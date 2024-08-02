#include <stdio.h>
#include <cs50.h>

int main(void){
    int height = 0;

    do {
        height = get_int("Height: ");
    } while (height < 1);

    int total = (height*2) + 2;
    char pyramid[total];
    pyramid[total] = 0;

    for (int i = 0; i < total; i++) pyramid[i] = ' ';

    int first = height - 1;
    int last = height + 2;

    do {
        pyramid[first--] = '#';
        pyramid[last++] = '#';
        pyramid[last] = 0;

        printf("%s\n", pyramid);
    } while (first >= 0);
}
