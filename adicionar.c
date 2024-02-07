#include "adicionar.h"

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

void adicionar(char mes[], FILE *pont_arq) {

    system("clear");

    char nome[100];

    printf("Informe o nome do cliente a ser adicionado: \n");
    scanf(" %[^\n]", nome);

    FILE *arquivo = fopen(nome, "rb+"); // Abre o arquivo no modo de leitura e escrita

    if (arquivo == NULL) {
        printf("Cliente não encontrado.\n");
        return;
    }

    struct Cliente cliente;
    int encontrado = 0; // Flag para verificar se o cliente foi encontrado

    // Procure pelo cliente no arquivo
    while (fread(&cliente, sizeof(struct Cliente), 1, arquivo)) {
        if (strcmp(cliente.nome, nome) == 0) {
            encontrado = 1; // O cliente foi encontrado
            break;
        }
    }

    if (!encontrado) {
        printf("Cliente não encontrado.\n");
        fclose(arquivo);
        return;
    }

    // Exibe as informações atuais do cliente
        system("clear");
    
    printf("Informações atuais do cliente:\n");
  
    printf("\nMês de acesso: %s\n\n", cliente.mes);
        
    printf("Nome: %s\n", cliente.nome);
    printf("Renda mensal: %.2f\n", cliente.renda);
    printf("Gastos com contas de casa: %.2f\n", cliente.gastos);
    printf("Gastos com internet: %.2f\n", cliente.internet);
    printf("Alimentação: %.2f\n", cliente.alimento);    
    if (cliente.planoVar == 1) {
        printf("Saúde: %.2f\n", cliente.saude);
    } 
    else {
        printf("Saúde: Não possui plano de saúde\n");
    }
    printf("Meta de gastos: %.2f\n", cliente.meta);

    printf("\nPor favor digite 1 para continuar, ou 2 para sair:\n");
    scanf("%d", &cliente.escolha);
  
       system("clear");
    if (cliente.escolha == 1){
    
    printf("Informe as novas informações do cliente:\n");
        
    printf("\nQual a renda mensal? \n");
    scanf("%f", &cliente.renda);

        system("clear");

    printf("Qual o valor de gastos com contas de casa? \n");
    scanf("%f", &cliente.gastos);

        system("clear");

    printf("Qual o valor de gastos com internet? \n");
    scanf("%f", &cliente.internet);

        system("clear");

    printf("Você possui vale refeição ou ticket alimentação? (Digite 1 para sim e 2 para não): \n");
    scanf("%d", &cliente.planoVar);

    if (cliente.planoVar == 1) {
        printf("Informe a nova taxa mensal paga: \n");
        scanf("%f", &cliente.alimento);
    } 
    else {
        printf("Informe o novo custo mensal de alimentação: \n");
        scanf("%f", &cliente.alimento);
    }

        system("clear");

        printf("Você possui plano de saúde? (Digite 1 para sim e 2 para não): \n");
        scanf("%d", &cliente.planoVar);

    if (cliente.planoVar == 1) {
        printf("Informe o novo valor da mensalidade do plano de saúde: \n");
        scanf("%f", &cliente.saude);
    }
    
        system("clear");
    printf("Você deseja modificar a sua meta de gastos? Digite 1 pra sim e 2 pra não.\n");
    scanf("%d", &cliente.escolha);
    
    if (cliente.escolha == 1) {
    
    printf("Informe a sua meta de gastos para esse mês: \n");
    scanf("%f", &cliente.meta);

    }

    fseek(arquivo, -sizeof(struct Cliente), SEEK_CUR);
    fwrite(&cliente, sizeof(struct Cliente), 1, arquivo);

    fclose(arquivo);

    printf("Informações do cliente adicionadas com sucesso!\n");
    }
}