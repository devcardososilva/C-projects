#include "cadastro.h"

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

void adicionarCliente(char mes[]) {
    
    struct Cliente cliente;

        system("clear");

    printf("Informe o seu nome: \n");
    scanf(" %[^\n]", cliente.nome);

        system("clear");
    
    printf("Qual é sua renda mensal? \n");
    scanf("%f", &cliente.renda);

        system("clear");

    printf("Quanto você gasta com contas de casa? Leve em consideração gastos com água e luz: \n");
    scanf("%f", &cliente.gastos);

        system("clear");

    printf("Quanto você gasta com internet? \n");
    scanf("%f", &cliente.internet);

        system("clear");

    printf("Você possui vale refeição ou ticket alimentação? (Digite 1 para sim e 2 para não): \n");
    scanf("%d", &cliente.planoVar);

    if (cliente.planoVar == 1) {
        printf("Qual é a taxa mensal paga? \n");
        scanf("%f", &cliente.alimento);
    } 
    else {
        printf("Qual é o seu custo mensal de alimentação? \n");
        scanf("%f", &cliente.alimento);
    }

        system("clear");

    printf("Você tem plano de saúde? (Digite 1 para sim e 2 para não): \n");
    scanf("%d", &cliente.planoVar);

    if (cliente.planoVar == 1) {
        printf("Qual é o valor da mensalidade do plano de saúde? \n");
        scanf("%f",&cliente.saude);
    }

      system("clear");
    printf("Você deseja adicionar uma meta para seus gastos? Digite 1 pra sim e 2 pra não.\n");
    scanf("%d", &cliente.escolha);
    
    if (cliente.escolha == 1) {
    
    printf("Informe a sua meta de gastos para esse mês: \n");
    scanf("%f", &cliente.meta);

    }

        system("clear");

    strcpy(cliente.mes, mes);

    FILE *arquivo = fopen(cliente.nome, "wb");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo para o cliente.\n");
        return;
    }

    fwrite(&cliente, sizeof(struct Cliente), 1, arquivo);
    fclose(arquivo);

    printf("Cliente cadastrado com sucesso!\n");

}
