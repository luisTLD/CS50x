#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float grade = 0.0588 * (((float)letters/(float)words) * 100) - 0.296 * (((float)sentences/(float)words) * 100) - 15.8;
    grade = round(grade);

    if (grade < 1) printf("Before Grade 1\n");
    else if (grade > 16) printf("Grade 16+\n");
    else printf("Grade %d\n", (int)grade);

    return 0;
}

int count_letters(string text){
    int letters = 0;
    int index = 0;
    while (text[index]) {
        if (isalpha(text[index])) letters++;
        index++;
    }

    return letters;
}

int count_words(string text){
    int words = 0;
    int index = 0;
    while (text[index]){
        if(text[index] == ' ') words++;
        index++;
    }

    words++;
    return words;
}

int count_sentences(string text){
    int sentences = 0;
    int index = 0;
    while (text[index]) {
        if(text[index] == '.' || text[index] == '!' || text[index] == '?') sentences++;
        index++;
    }

    return sentences;
}
