#include <stdio.h>
#include <cs50.h>

int main(void){
    int height = 0;

    do {
        height = get_int("Height: ");
    } while (height < 1);

    char pyramid[height];
    pyramid[height] = 0;

    for (int i = 0; i < height; i++) pyramid[i] = ' ';

    int loop = height - 1;
    for (int i = loop; i >= 0; i--){
        pyramid[i] = '#';
        printf("%s\n", pyramid);
    }
}
