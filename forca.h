#ifndef FORCA_H
#define FORCA_H

extern char palpite[16];
extern int chutes[26];


void imprimir_boneco (int a);
int verificar_letra (char a[], char b);
void lista_de_chute(int chutes[],int tam);
void validar(char b);
int jogo( );
typedef struct Palavra {
char letras[16];
int identificador;
} termo;
extern termo palavras[250];
#endif
