#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "forca.h"





int main() {
    setlocale(LC_ALL, "Portuguese");
    int menu= 's';
    while(menu!='X') {
        system("cls");
        puts("Bem-vindo ao Jogo da Forca!\n Selecione a opção teclando os simbolos indicados no teclado");
        printf("JOGAR(!)\nCOMO JOGAR(?)\nSAIR(X)\n\n Opção: ");
        scanf(" %c", &menu);
        if(menu=='!') {
            while(jogo());
            }
        else if(menu=='?') {
            system("cls");
            printf("\033[1;33m"
"=== BEM-VINDO AO JOGO DA FORCA ===\n"
"COMO JOGAR:\n"
"Uma palavra secreta será sorteada e você deve descobri-la letra por letra.\n"
"A cada rodada, uma DICA com o tema da palavra aparecerá na tela.\n"
"Digite uma letra por vez e tente adivinhar a palavra completa. Por motivos de limitação técnica não há acentuação ou cedilha\n\n"
"ATENÇÃO AOS ERROS:\n"
"A cada letra errada, uma parte do boneco é desenhada na forca.\n"
"O boneco tem 6 partes: cabeça, tronco, braço esquerdo,\n"
"braço direito, perna esquerda e perna direita.\n"
"Se o boneco ficar completo, você perde!\n\n"
"TEMAS POSSÍVEIS:\n"
"As 250 palavras do jogo estão divididas em 5 temas.\n"
"O tema da palavra sorteada aparecerá como DICA no início de cada rodada.\n"
"Use o tema a seu favor para tentar adivinhar mais rápido!\n\n"
"RESUMINDO:\n"
"- Adivinhe a palavra letra por letra\n"
"- Você tem 6 tentativas antes do enforcamento\n"
"- Use a DICA do tema para ajudar\n"
"- Boa sorte!\n"
"\033[0m");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            puts("Pressione ENTER para voltar ao menu...");
            getchar();
        }

    }


    return 0;
}
