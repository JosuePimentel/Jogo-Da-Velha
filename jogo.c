#include <stdio.h>
#include <stdlib.h>
#define lin 3
#define col 3

void escreverJogo(int jogo[][col]) {
    system("cls");

    int x, y;

    printf("\n\n");
    for( x = 0 ; x < lin ; x++ ) {
        if(x == 0) {
            for( y = 0 ; y < col ; y++){
                if(!y) printf("    %i ", y+1);
                else printf("  %i ", y+1);
            }
            printf("\n");
        }
        for( y = 0 ; y < col ; y++ ) {
            if(!y) printf("%i  ", x+1);

            if(jogo[x][y] == 0) printf("   ");
            else if(jogo[x][y] == 1) printf("\033[31m X \033[0m"); 
            else if(jogo[x][y] == 2) printf("\033[32m O \033[0m");

            if(y != col-1) printf("|");
        }
        printf("\n");
        for( y = 0 ; y < col ; y++){
            if(!y && x != lin-1) printf("  ----");
            else if(x != lin-1) printf("----");
        }
        printf("\n");
    }
}

int verGanhador(int jogo[][col], int game) {
    if(((jogo[0][0] == jogo[1][0] && jogo[1][0] == jogo[2][0]) && (jogo[0][0] != 0 && jogo[1][0] != 0 && jogo[2][0] != 0)) || ((jogo[0][1] == jogo[1][1] && jogo[1][1] == jogo[2][1]) && (jogo[0][1] != 0 && jogo[1][1] != 0 && jogo[2][1] != 0)) || ((jogo[0][2] == jogo[1][2] && jogo[1][2] == jogo[2][2]) && (jogo[0][2] != 0 && jogo[1][2] != 0 && jogo[2][2] != 0)) || ((jogo[0][0] == jogo[1][1] && jogo[1][1] == jogo[2][2]) && (jogo[0][0] != 0 && jogo[1][1] != 0 && jogo[2][2] != 0)) || ((jogo[0][2] == jogo[1][1] && jogo[1][1] == jogo[2][0]) && (jogo[0][2] != 0 && jogo[1][1] != 0 && jogo[2][0] != 0)) || ((jogo[0][0] == jogo[0][1] && jogo[0][1] == jogo[0][2]) && (jogo[0][0] != 0 && jogo[0][1] != 0 && jogo[0][2] != 0)) || ((jogo[1][0] == jogo[1][1] && jogo[1][1] == jogo[1][2]) && (jogo[1][0] != 0 && jogo[1][1] != 0 && jogo[1][2] != 0)) || ((jogo[2][0] == jogo[2][1] && jogo[2][1] == jogo[2][2]) && (jogo[2][0] != 0 && jogo[2][1] != 0 && jogo[2][2] != 0))) {
        game--;
    }

    return game;
}

int main() {
    int jogo[lin][col] = {0, 0, 0,
                          0, 0, 0,
                          0, 0, 0};


    int l,c, vez = 1, game = 1;

    // 1 -> X 
    // 2 -> O
    
    while(game){
        int player = vez%2;

        escreverJogo(jogo);

        printf("\nPlayer of the time:");
        if(player == 0) printf(" O\n");
        else if(player != 0) printf(" X.\n");

        printf("\nWrite a position ( line | Column ):\n");
        scanf("%i %i", &l, &c);

        if(player == 0 && jogo[l-1][c-1] == 0 && !(jogo[l-1][c-1] == 1)) {
            jogo[l-1][c-1] = 2;
            vez++;   
            escreverJogo(jogo);

            game = verGanhador(jogo, game);
        } else if(jogo[l-1][c-1] == 0 && !(jogo[l-1][c-1] == 2)) {
            jogo[l-1][c-1] = 1;
            vez++;   
            escreverJogo(jogo);

            game = verGanhador(jogo, game);
        }
    }
    printf("\nThe games over!\n");

    return 0;
}

