#include <stdio.h>
#include <stdlib.h>
#include "tictactoe.h"
#include <string.h>
#include <ctype.h>

typedef struct {
    char fname[50];
    char lname[50];
    int wins, losses, plays;
    int score;
} players;

int main(int argc, char** argv) {
    players player[50];

    int boxNumber = 0, err;
    char name[100], boxLetter;
    char tempFName[50], tempLName[50];

    int j, k, count = 0, nbOfPlayers = 0;
    char line[100];

    FILE * prev_scores = fopen("scores.txt", "r");
    if (prev_scores == NULL) goto JUMP;

    while (!feof(prev_scores)) {
        count++;
        fgets(line, 100, prev_scores);

        if (count >= 3) {
            trimwhitespace(line);
            sscanf(line, "%s %s %d %d %d %d", player[nbOfPlayers].fname, player[nbOfPlayers].lname, &player[nbOfPlayers].plays, &player[nbOfPlayers].wins, &player[nbOfPlayers].losses, &player[nbOfPlayers].score);
            nbOfPlayers++;
        }
    }


JUMP:

    do {
        //  initialize board 
        char board[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{'};

        int res1 = 1, res2 = 1;

        printf("\nWhat is the full name of the first player who will play with X? ");
        scanf(" %49[^\n]", name);
        sscanf(name, "%s %s", tempFName, tempLName);

        for (j = 0; j < 50; j++) {
            if ((strcmp(tempFName, player[j].fname) == 0) && (strcmp(tempLName, player[j].lname)) == 0) {
                res1 = 0;
                (player[j].plays)++;
                break;
            }
        }
        if (res1 != 0) {
            j = nbOfPlayers;
            strcpy(player[j].fname, tempFName);
            strcpy(player[j].lname, tempLName);
            player[j].plays = 0;
            player[j].wins = 0;
            player[j].losses = 0;
            player[j].score = 0;
            (player[j].plays)++;
            nbOfPlayers++;
        }

        printf("\nWhat is the full name of the second player who will play with O? ");
        scanf(" %49[^\n]", name);
        sscanf(name, "%s %s", tempFName, tempLName);

        for (k = 0; k < 50; k++) {
            if ((strcmp(tempFName, player[k].fname) == 0) && (strcmp(tempLName, player[k].lname)) == 0) {
                res2 = 0;
                (player[k].plays)++;
                break;
            }
        }
        if (res2 != 0) {
            k = nbOfPlayers;
            strcpy(player[k].fname, tempFName);
            strcpy(player[k].lname, tempLName);
            player[k].plays = 0;
            player[k].wins = 0;
            player[k].losses = 0;
            player[k].score = 0;
            (player[k].plays)++;
            nbOfPlayers++;
        }

        //clear the output screen, code from stackoverflow
        printf("\e[1;1H\e[2J");

        for (int i = 0; i < 27; i++) {
            printBoard(board);
            printf("\nTurn %d", i + 1);
            if (i % 2 == 0) {

REPEAT1:
                printf("\nIt is %s %s's turn", player[j].fname, player[j].lname);
                scanf("%*[^\n]");
                printf("\nBox symbol: ");
                err = scanf("%s", &boxLetter);

                while (err != 1 || err == EOF || boxLetter < 'a' || boxLetter > '{') {
                    scanf("%*[^\n]");
                    printf("\nWrong input.");
                    printf("\nBox symbol: ");
                    err = scanf("%s", &boxLetter);
                }
                boxNumber = boxLetter - 96;

                if (board[boxNumber - 1] == (boxLetter)) { // help from stackoverflow for the '0' trick
                    board[boxNumber - 1] = 'X';
                } else {
                    printf("\nERROR: Box has already been filled.\n");
                    goto REPEAT1;
                }
            } else {
REPEAT2:
                printf("\nIt is %s %s's turn", player[k].fname, player[k].lname);

                scanf("%*[^\n]");
                printf("\nBox symbol: ");
                err = scanf("%s", &boxLetter);

                while (err != 1 || err == EOF || boxLetter < 'a' || boxLetter > '{') {
                    scanf("%*[^\n]");
                    printf("\nWrong input.");
                    printf("\nBox symbol: ");
                    err = scanf("%s", &boxLetter);
                }
                boxNumber = boxLetter - 96;
                if (board[boxNumber - 1] == (boxLetter)) {
                    board[boxNumber - 1] = 'O';
                } else {
                    printf("\nERROR: Box has already been filled.\n");
                    goto REPEAT2;
                }
            }

            //clear the output screen, code from stackoverflow
            printf("\e[1;1H\e[2J");
            if (i >= 2) {
                int res = checkForWin(board);

                if (res == 1) {
                    printBoard(board);
                    printf("\n%s %s has won.", player[j].fname, player[j].lname);
                    (player[j].wins)++;
                    (player[k].losses)++;
                    break;
                }

                if (res == 2) {
                    printBoard(board);
                    printf("\n%s %s has won.", player[k].fname, player[k].lname);
                    (player[k].wins)++;
                    (player[j].losses)++;
                    break;
                }

                if (res == 0) {
                    printBoard(board);
                    printf("\nNo one wins the game.");
                    break;
                }
            }

        }
        player[j].score = player[j].wins - player[j].losses;
        player[k].score = player[k].wins - player[k].losses;
        char ans[3];
        scanf("%*[^\n]"); 
        printf("\nDo you want to play again (yes/no)? ");
        scanf("%s", ans);
        if (strcmp(ans, "no") == 0) break;
        printf("\e[1;1H\e[2J");
    } while (1);

    FILE * scores = fopen("scores.txt", "w");
    fprintf(scores, "%17s        %s          %s         %s           %s", "Name", "Played", "Won", "Lost", "Score");
    fprintf(scores, "\n-----------------------------------------------------------------------------");

    for (int f = 0; f < nbOfPlayers; f++) {
        fprintf(scores, "\n%7s %10s        %03d            %03d          %03d            %03d", player[f].fname, player[f].lname, player[f].plays, player[f].wins, player[f].losses, player[f].score);
    }
    fclose(scores);
    fclose(prev_scores);

    return (EXIT_SUCCESS);
}

