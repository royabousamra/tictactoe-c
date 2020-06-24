#ifndef TICTACTOE_H
#define TICTACTOE_H

#ifdef __cplusplus
extern "C" {
#endif

int checkForWin(char *board) {
    // 0 for draw; 1 for player 1 (X); 2 for player 2 (O); -1 for no win yet

    if (board[0] == board[1] && board[1] == board[2] && board[2] == 'X') return 1;
    if (board[0] == board[1] && board[1] == board[2] && board[2] == 'O') return 2;

    else if (board[3] == board[4] && board[4] == board[5] && board[5] == 'X') return 1;
    else if (board[3] == board[4] && board[4] == board[5] && board[5] == 'O') return 2;

    else if (board[6] == board[7] && board[7] == board[8] && board[8] == 'X') return 1;
    else if (board[6] == board[7] && board[7] == board[8] && board[8] == 'O') return 2;

    else if (board[0] == board[3] && board[3] == board[6] && board[6] == 'X') return 1;
    else if (board[0] == board[3] && board[3] == board[6] && board[6] == 'O') return 2;

    else if (board[1] == board[4] && board[4] == board[7] && board[7] == 'X') return 1;
    else if (board[1] == board[4] && board[4] == board[7] && board[7] == 'O') return 2;

    else if (board[2] == board[5] && board[5] == board[8] && board[8] == 'X') return 1;
    else if (board[2] == board[5] && board[5] == board[8] && board[8] == 'O') return 2;

    else if (board[0] == board[4] && board[4] == board[8] && board[8] == 'X') return 1;
    else if (board[0] == board[4] && board[4] == board[8] && board[8] == 'O') return 2;

    else if (board[2] == board[4] && board[4] == board[6] && board[6] == 'X') return 1;
    else if (board[2] == board[4] && board[4] == board[6] && board[6] == 'O') return 2;

    else if (board[0] != '1' && board[1] != '2' && board[2] != '3' &&
            board[3] != '4' && board[4] != '5' && board[5] != '6' && board[6]
            != '7' && board[7] != '8' && board[8] != '9') return 0; 

    return -1;
}

void printBoard(char *board) {
    printf("\n  %c |  %c |  %c ", board[0], board[1], board[2]);
    printf("\n____|____|____");
    printf("\n  %c |  %c |  %c ", board[3], board[4], board[5]);
    printf("\n____|____|____");
    printf("\n  %c |  %c |  %c ", board[6], board[7], board[8]);
    printf("\n    |    |    ");
    printf("\n");
}

void trimwhitespace(char* str) { // adapted fully from stackoverflow to clean the lines read from scoreboard to making scanning easier
  int i, x;
  for(i=x=0; str[i]; ++i)
    if(!isspace(str[i]) || (i > 0 && !isspace(str[i-1])))
      str[x++] = str[i];
  str[x] = '\0';
}

#ifdef __cplusplus
}
#endif

#endif /* TICTACTOE_H */

