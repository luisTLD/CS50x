#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string s);

int main(int argc, string argv[]){
    if (argc != 2 || !only_digits(argv[1])){
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);
    char input[80];

    printf("plain text: ");
    scanf(" %[^\n]", input);

    int index = 0;
    do {
       if (isalpha(input[index])) {
            char c = islower(input[index]) ? 'a' : 'A';
            input[index] = (input[index] - c + key) % 26 + c;
        }
       index++;
    } while (input[index]);

    printf("ciphertext: %s\n", input);
    
    return 0;
}

bool only_digits(string s){
    bool verify = true;

    int index = 0;
    do {
        if (!isdigit(s[index])) verify = false;
        index++;
    } while (s[index] && verify);

    return verify;
}
