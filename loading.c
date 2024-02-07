#include "loading.h"

#include <stdio.h> // Entrada e saída padrão
#include <stdlib.h> // Biblioteca padrão
#include <time.h> // Pocibilita usar funções relacionadas a tempo e data
#include <locale.h> // Configurar aspectos regionais
#include <string.h> // Manipulação de strings
#include <unistd.h> // Usada para funções relacionadas à interação com o sistema operacional


void loading(int duracaosegundos) {
    char animacao[] = "|/-\\";
    int i;
    for (i = 0; i < duracaosegundos * 10; i++) {
        printf("\rCarregando... %c", animacao[i % 4]);
        fflush(stdout);
        usleep(100000);  // Espera 100ms 
    }
    printf("\nConcluído!\n");
}