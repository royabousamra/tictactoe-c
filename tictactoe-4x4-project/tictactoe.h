#ifndef TICTACTOE_H
#define TICTACTOE_H

#ifdef __cplusplus
extern "C" {
#endif

int checkForWin(char *board) {
    // 0 for draw; 1 for player 1 (X); 2 for player 2 (O); -1 for no win yet

    if (board[0] == board[1] && board[1] == board[2] && board[2] == board[3] && board[3] == 'X') return 1;
    else if (board[0] == board[1] && board[1] == board[2] && board[2] == board[3] && board[3] == 'O') return 2;

    else if (board[4] == board[5] && board[5] == board[6] && board[6] == board[7] && board[7] == 'X') return 1;
    else if (board[4] == board[5] && board[5] == board[6] && board[6] == board[7] && board[7] == 'O') return 2;

    else if (board[8] == board[9] && board[9] == board[10] && board[10] == board[11] && board[11] == 'X') return 1;
    else if (board[8] == board[9] && board[9] == board[10] && board[10] == board[11] && board[11] == 'O') return 2;

    else if (board[12] == board[13] && board[13] == board[14] && board[14] == board[15] && board[15] == 'X') return 1;
    else if (board[12] == board[13] && board[13] == board[14] && board[14] == board[15] && board[15] == 'O') return 2;
    
    else if (board[0] == board[4] && board[4] == board[8] && board[8] == board[12] && board[12] == 'X') return 1;
    else if (board[0] == board[4] && board[4] == board[8] && board[8] == board[12] && board[12] == 'O') return 2;

    else if (board[1] == board[5] && board[5] == board[9] && board[9] == board[13] && board[13] == 'X') return 1;
    else if (board[1] == board[5] && board[5] == board[9] && board[9] == board[13] && board[13] == 'O') return 2;
    
    else if (board[2] == board[6] && board[6] == board[10] && board[10] == board[14] && board[14] == 'X') return 1;
    else if (board[2] == board[6] && board[6] == board[10] && board[10] == board[14] && board[14] == 'O') return 2;
    
    else if (board[3] == board[7] && board[7] == board[11] && board[11] == board[15] && board[15] == 'X') return 1;
    else if (board[3] == board[7] && board[7] == board[11] && board[11] == board[15] && board[15] == 'O') return 2;

    else if (board[0] == board[5] && board[5] == board[10] && board[10] == board[14] && board[14] == 'X') return 1;
    else if (board[0] == board[5] && board[5] == board[10] && board[10] == board[14] && board[14] == 'O') return 2;

    else if (board[3] == board[6] && board[6] == board[9] && board[9] == board[12] && board[12] == 'X') return 1;
    else if (board[3] == board[6] && board[6] == board[9] && board[9] == board[12] && board[12] == 'O') return 2;

    else if (board[0] != 'a' && board[1] != 'b' && board[2] != 'c' &&
            board[3] != 'd' && board[4] != 'e' && board[5] != 'f' && board[6]
            != 'g' && board[7] != 'h' && board[8] != 'i' && board[9] != 'j' && board[10] != 'k' && board[11] != 'l'
             && board[12] != 'm' && board[13] != 'n' && board[14] != 'o' && board[15] != 'p') return 0; 

    return -1;
}

void printBoard(char *board) {
    printf("\n  %c |  %c |  %c |  %c ", board[0], board[1], board[2], board[3]);
    printf("\n____|____|____|____");
    printf("\n  %c |  %c |  %c |  %c ", board[4], board[5], board[6], board[7]);
    printf("\n____|____|____|____");
    printf("\n  %c |  %c |  %c |  %c ", board[8], board[9], board[10], board[11]);
    printf("\n____|____|____|____");
    printf("\n  %c |  %c |  %c |  %c ", board[12], board[13], board[14], board[15]);
    printf("\n    |    |    |    ");
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

