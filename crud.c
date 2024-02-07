#include "crud.h" // Create, Read, Update, Delete

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

void deletarInformacoes() {
        system("clear");

    char nome[100];

    printf("Informe o nome do cliente a ser deletado: \n");
    scanf(" %[^\n]", nome);

    // Verifique se o arquivo do cliente existe
    if (remove(nome) == 0) {
        printf("As informações do cliente foram deletadas com sucesso.\n");
    } else {
        printf("Erro ao deletar as informações do cliente ou cliente não encontrado.\n");
    }
}

void atualizar(FILE *pont_arq) {
    
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
    
        system("clear");

    printf("Informe a informação que deseja modificar:\n");
    
        printf("\n");

    printf("Escolha a informação que deseja modificar:\n");
    printf("1 - Nome\n");
    printf("2 - Renda Mensal\n");
    printf("3 - Gastos com contas de casa\n");
    printf("4 - Gastos com internet\n");
    printf("5 - Vale refeição ou ticket alimentação\n");
    printf("6 - Custo mensal de alimentação\n");
    printf("7 - Plano de saúde\n");
    printf("8 - Meta de gastos\n");


    int escolha;
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            printf("Informe o novo nome: \n");
            scanf(" %[^\n]", cliente.nome);
            break;
        case 2:
            printf("Informe a renda mensal: \n");
            scanf("%f", &cliente.renda);
            break;
        case 3:
            printf("Informe o valor de gastos com contas de casa: \n");
            scanf("%f", &cliente.gastos);
            break;
        case 4:
            printf("Informe o valor de gastos com internet: \n");
            scanf("%f", &cliente.internet);
            break;
        case 5:
            printf("Você possui vale refeição ou ticket alimentação? (Digite 1 para sim e 2 para não): \n");
            scanf("%d", &cliente.planoVar);
            if (cliente.planoVar == 1) {
                printf("Informe a taxa mensal paga: \n");
                scanf("%f", &cliente.alimento);
            } else {
                printf("Informe o custo mensal de alimentação: \n");
                scanf("%f", &cliente.alimento);
            }
            break;
        case 6:
            printf("Informe o custo mensal de alimentação: \n");
            scanf("%f", &cliente.alimento);
            break;
        case 7:
            printf("Você possui plano de saúde? (Digite 1 para sim e 2 para não): \n");
            scanf("%d", &cliente.planoVar);
            
            if (cliente.planoVar == 1) {
                printf("Informe o valor da mensalidade do plano de saúde: \n");
                scanf("%f", &cliente.saude);
            }
            break;
        case 8:
            printf("Informe o valor da meta gastos: \n");
            scanf("%f", &cliente.meta);
            break;
        default:
            printf("Opção inválida.\n");
            return;
    }
        system("clear");

    // Volte ao início do registro do cliente e atualize as informações
    fseek(arquivo, -sizeof(struct Cliente), SEEK_CUR);
    fwrite(&cliente, sizeof(struct Cliente), 1, arquivo);

    fclose(arquivo);

    printf("Informações do cliente atualizadas com sucesso!\n");


}

void consultarCliente(char mes[], FILE *pont_arq) {
    char continuar;
    char nome[100];

        system("clear");

    printf("Informe o nome do cliente a ser consultado: \n");
    scanf(" %[^\n]", nome);

    FILE *arquivo = fopen(nome, "rb+"); // Abri o arquivo no modo de leitura

    if (arquivo == NULL) {
        printf("Cliente não encontrado.\n");
        return;
    }

    struct Cliente cliente;
    fread(&cliente, sizeof(struct Cliente), 1, arquivo);
    fclose(arquivo);

        system("clear");
    
    printf("Informações atuais do cliente:\n\n");

  printf("Mês de acesso: %s\n\n", cliente.mes);

    printf("Nome: %s\n", cliente.nome);
    printf("Renda mensal: R$ %.2f reais.\n", cliente.renda);
    printf("Gastos com contas de casa: R$ %.2f reais.\n", cliente.gastos);
    printf("Gastos com internet: R$ %.2f reais.\n", cliente.internet);
    printf("Alimentação: R$ %.2f reais.\n", cliente.alimento);
    
    if (cliente.planoVar == 1) {
        printf("Saúde: R$ %.2f reais.\n", cliente.saude);
    } else {
        printf("Saúde: Não possui plano de saúde\n");
    }
        printf("\n");

    
    float totalGastos, saldo, porcentagem, porAlimento, porSaude, porInternet, porGastos, porMeta;

        totalGastos = cliente.alimento + cliente.saude + cliente.gastos + cliente.internet;
        saldo = cliente.renda - totalGastos;

        porcentagem = (totalGastos / cliente.renda) * 100; 
        porAlimento = (cliente.alimento / cliente.renda) * 100;
        porGastos = (cliente.gastos / cliente.renda) * 100;
        porInternet = (cliente.internet / cliente.renda) * 100;
        porSaude = (cliente.saude / cliente.renda) * 100;
        
        printf("Você quer saber qual o seu balanço mensal? Informe 1 para sim e 2 para não: \n");
        scanf("%d", &cliente.escolha);

         if (cliente.escolha == 1){

        system("clear");

        printf("Informações monetárias: \n");

        printf("Gastos de %s: R$ %.2f reais.\n\n", cliente.mes, totalGastos);
        printf("Porcentagem de gastos sobre a renda: %.2f%\n", porcentagem);
        printf("Saldo: R$ %.2f reais\n", saldo);
        
          if (totalGastos > cliente.meta) {
                   printf("Você excedeu a sua meta de R$ %.2f reais\n", cliente.meta);
          }

          else {
                   printf("Você não excedeu a sua meta de R$ %.2f reais\n", cliente.meta);
               }         
           
        printf("\nPorcentagem de gastos:\n\n");
        
        printf("Gastos com contas de casa: %.2f%\n", porGastos);
        printf("Gastos com internet: %.2f%\n", porInternet);
        printf("Alimentação: %.2f%\n", porAlimento);
        printf("Saúde: %.2f%\n", porSaude);

    }

}