#include <stdio.h>
#include <cs50.h>

int main(void){

    long credit = 0;
    do {
        credit = get_long("Number: ");
    } while (credit < 0);

    long copy = credit;
    int verify = 0;
    int aux = 0;
    int totalNum = 0;

    do {
        verify += copy % 10;
        copy /= 10;
        totalNum++;

        aux = (copy % 10)*2;
        if (aux < 10) verify += aux;
        else {
            do {
                verify += (aux % 10);
                aux /= 10;
            } while (aux > 0);
        }

        if (copy > 0) totalNum++;
        copy /= 10;
    } while (copy > 0);

    copy = credit;
    int numbers[totalNum];
    for (int i = 0; i < totalNum; i++){
        numbers[i] = credit % 10;
        credit /= 10;
    }

    if (!(verify % 10) && totalNum == 15 && (numbers[totalNum - 1] == 3 && (numbers[totalNum - 2] == 4 || numbers[totalNum - 2] == 7))) {
        printf("AMEX\n");
    } else if (!(verify % 10) && totalNum == 16 && (numbers[totalNum - 1] == 5 && (numbers[totalNum - 2] >= 1 && numbers[totalNum - 2] <= 5 ))){
        printf("MASTERCARD\n");
    } else if (!(verify % 10) && (totalNum == 16 || totalNum == 13) && numbers[totalNum - 1] == 4){
        printf("VISA\n");
    } else {
        printf("INVALID\n");
    }
}

