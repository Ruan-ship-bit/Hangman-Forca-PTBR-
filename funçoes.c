#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "forca.h"
#include <time.h>
int chutes[26] = {0};
char palpite[16] = "_______________";


int jogo ( ) {
for(int i = 0; i < 26; i++) chutes[i] = 0;
srand(time(NULL));
   int tentativa=0, acertou=1;
    char a[16], b;

    //int indice = rand() % 250;
    int indice = 21;
    strcpy(a, palavras[indice].letras);
    int tam = strlen(a);
    for(int i = 0; i < tam; i++) {
        palpite[i] = '_';
    }
    palpite[tam] = '\0';
    char temas[][16] = {"COR", "OBJETO", "ANIMAL", "FRUTA", "LUGAR"};
    int indice_tema = (palavras[indice].identificador - 1) / 50;
    for(int i = 0; i < strlen(a); i++) palpite[i] = '_';
    palpite[strlen(a)] = '\0'; // Finaliza a string corretamente

    while(tentativa<=6){
    system("cls");
    puts("Vamos brincar de Forca?(APENAS LETRAS MAIÚSCULAS)");
    lista_de_chute(chutes, 26);
    printf("\nDICA: %s\n", temas[indice_tema]);
    imprimir_boneco(tentativa);
    for(int i=0; i<strlen(a);i++) {
        if(palpite[i]==95) printf("_ ");
        else {
            printf("%c ", palpite[i]);
        }
    }
    printf("\n\n");
    scanf(" %c", &b);


    acertou = verificar_letra(a, b);

    if(strchr(palpite, '_')== NULL){
        system("cls");
        imprimir_boneco(tentativa);
        printf("\nPALAVRA: %s", palpite); // Mostra a palavra toda preenchida
        puts("\n\n Parabéns! Você ganhou!!");
        printf("Deseja jogar novamente?\n \nSIM(1) \nNÃO(0)\n");
    int res; scanf("%d", &res);
    if(res==1 || res==0) return res;
    }
    if(acertou==0) {
            tentativa++;
            if(tentativa == 6 ) {
                system("cls");
                imprimir_boneco(tentativa);
                printf("Você foi enforcado!\nA palavra era: %s\n", a);
                printf("Deseja jogar novamente?\n \nSIM(1) \nNÃO(0)\n");
                int res; scanf("%d", &res);
                if(res==1 || res==0) return res;
}
    }



   }


return 0;
}


int verificar_letra(char a[], char b) {
    int indice= b-'A', achou=0;
    if (indice>=0 && indice<26) {
        chutes[indice] = 1;

    }

    for(int i=0; a[i]!='\0' && i<15; i++) {
        if(b==a[i]) {
            palpite[i] = b;
            achou = 1;
        }

    }
    return achou;
    }

void imprimir_boneco(int a) {

// Supondo que 'erros' seja a variável que conta quantos palpites errados o usuário deu
switch(a) {
    case 0:
        printf("\n  +---+\n");
        printf("  |   |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
        printf("\n");
        break;

    case 1: // CABEÇA
        printf("\n  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
        printf("\n");
        break;

    case 2: // TRONCO
        printf("\n  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf("  |   |\n");
        printf("      |\n");
        printf("      |\n");
        printf("\n");
        break;

    case 3: // UM BRAÇO
        printf("\n  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|   |\n");
        printf("      |\n");
        printf("      |\n");
        printf("\n");
        break;

    case 4: // OUTRO BRAÇO
        printf("\n  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|\\  |\n"); // Usei \\ para imprimir uma única barra invertida
        printf("      |\n");
        printf("      |\n");
        printf("\n");
        break;

    case 5: // UMA PERNA
        printf("\n  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|\\  |\n");
        printf(" /    |\n");
        printf("      |\n");
        printf("\n");
        break;

    case 6: // OUTRA PERNA (MORREU)
        printf("\n  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|\\  |\n");
        printf(" / \\  |\n");
        printf("      |\n");
        printf("GAME OVER!\n");
        printf("\n");
        break;
}






}

void lista_de_chute(int chutes[], int tam) {
    for(int i=0; i<tam; i++) if(chutes[i]==1) printf(" \033[33m%c\033[0m", i+65);
}







