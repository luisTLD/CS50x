#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

bool only_chars(string s, int argc);

int main(int argc, string argv[]){
    if (!only_chars(argv[1], argc)){
        return 1;
    }

    string input = get_string("plaintext: ");

    int index = 0;
    printf("ciphertext: ");
    do {
        if (isalpha(input[index])){
            if (islower(input[index])) printf("%c", tolower(argv[1][input[index] - 'a']));
            else printf("%c", toupper(argv[1][input[index] - 'A']));
        }
        else printf("%c", input[index]);

        index++;
    } while (input[index]);

    printf("\n");
    return 0;
}

bool only_chars(string s, int argc){
    bool verify = true;
    if (argc != 2) verify = false;

    int repeat[26];
    int index = 0;
    while (verify && s[index]){
        if (!isalpha(s[index])) verify = false;
        else {
            char c = tolower(s[index]);
            repeat[c - 'a']++;
        }
        index++;
    }

    for (int i = 0; i < 26; i++){
        if (repeat[i] != 1) verify = false;
        i = 26;
    }

    if (!verify) printf("Usage: ./caesar key\n");
    else if (index != 26){
        printf("Key must cointains 26 characters\n");
        verify = false;
    }


    return verify;
}
