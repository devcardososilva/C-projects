#include "investimento.h"

#include <math.h> // Usabilidade de funçoes matemática
#include <stdio.h> // Entrada e saída padrão
#include <stdlib.h> // Biblioteca padrão
#include <time.h> // Pocibilita usar funções relacionadas a tempo e data
#include <locale.h> // Configurar aspectos regionais
#include <string.h> // Manipulação de strings
#include <unistd.h> // Usada para funções relacionadas à interação com o sistema operacional

struct Cliente {
    char nome[100];
    char mes[20];
    char resposta;
    float renda;
    float gastos;
    float saude;
    float internet;
    float alimento;
    int escolha;
    int planoVar;
    float meta;
};

void investimento() {
    double montante, investiInicial, juros, aporte; 
    int anos, meses;

    system("clear");

    printf("Digite o valor do investimento inicial: \n");
    scanf("%lf", &investiInicial);

    system("clear");

    printf("Digite a taxa de juros anual (em decimal): \n");
    scanf("%lf", &juros);

    system("clear");

    printf("Digite o tempo de investimento (em anos): \n");
    scanf("%d", &anos);

    montante = investiInicial * pow(1 + juros, anos); // Realiza o calculo de investimento, com as informações dadas pelo cliente

      system("clear");
  
    printf("\nInvestimento inicial: R$ %.2lf reais\n", investiInicial);
    printf("Taxa de juros anual: %.2lf%%\n", juros * 100); // Transformar de decimal para porcentagem
    printf("Tempo de investimento: %d anos\n", anos);
    printf("O valor futuro do investimento é: R$ %.2lf reais\n", montante);
}
