#include <stdio.h>
#include <cs50.h>

int compute_score(string word, int points[]);

int main(void){
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    if (compute_score(player1, points) > compute_score(player2, points)) printf("Player 1 wins!\n");
    else if (compute_score(player1, points) < compute_score(player2, points)) printf("Player 2 wins!\n");
    else printf("Tie!\n");
}

int compute_score(string word, int points[]){
    int index = 0;
    int score = 0;

    do {
        if (word[index] >= 65 && word[index] <= 90) score += points[word[index] - 'A'];
        else if (word[index] >= 97 && word[index] <= 122) score += points[word[index] - 'a'];

        index++;
    } while (word[index]);

    return score;
}
