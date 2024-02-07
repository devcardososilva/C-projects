#include "loading.h"
#include "menu.h"
#include "cadastro.h"
#include "crud.h"
#include "investimento.h"
#include "adicionar.h"


#include <math.h> // Usabilidade de funçoes matemática
#include <stdio.h> // Entrada e saída padrão
#include <stdlib.h> // Biblioteca padrão
#include <time.h> // Pocibilita usar funções relacionadas a tempo e data
#include <locale.h> // Configurar aspectos regionais
#include <string.h> // Manipulação de strings
#include <unistd.h> // Usada para funções relacionadas à interação com o sistema operacional

/*
Autores: Daniel Cândido, Miguel Santos, João Tenório, Nicolas Matheus Alves

Data de Criação: 20/10/2023

Descrição: Projeto desenvolvido por alunos do SENAI PE, com a orientação do professor Iago Bayesiano, com fins de avaliação.

Contato: dev.candidosilva@gmail.com | matheusnicolas895@gmail.com | joaolucasptenorio@gmail.com | miguel31419@outlook.com

Funções dos Autores:

João Tenório: Responsável pela criação e administração da função de investimento e questões financeiras.
Miguel Santos: Responsável pelo aspecto criativo do projeto, criação da função de menu e assistência na resolução de bugs.
Daniel Cândido: Responsável pela criação e manipulação do código e desenvolvimento da lógica do projeto.
Nicolas Matheus: Responsável pela documentação do código e estética do projeto.
*/

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

int main(void) {
    
    struct Cliente cliente;

    char mes[20];
    char continuar;

    setlocale(LC_TIME, "pt_BR.utf8"); // Define o ambiente local para português
    time_t t;
    struct tm *data;
    
    FILE *pont_arq; // Ponteiro para arquivo

    pont_arq = fopen("informacao", "a+"); // Abre ou cria o arquivo em modo de leitura e escrita

    t = time(NULL); // Obtém o tempo atual em segundos
    data = localtime(&t); // Transforma a função "t" de segundos em estrutura de data e hora 
    strftime(mes, sizeof(mes), "%B", data); // Formata a data para o formato especificado

    // Função preventiva de erros ao abrir o arquivo
    if (pont_arq == NULL) { 
        printf("Erro ao abrir arquivo\n"); 
        return 1;
    } 

    do { 
        
        int duracao = 1; // Duração do carregamento em segundos
        loading(duracao);
        
        menuPrincipal();
        scanf("%d", &cliente.escolha);

        switch (cliente.escolha) {
            
            case 1:
                adicionarCliente(mes);
                break;
            
            case 2:
                consultarCliente(mes, pont_arq);
                break;
            
            case 3:
                adicionar(mes, pont_arq);
                break;
            
            case 4:
                deletarInformacoes();
                break;
            
            case 5:                 
                atualizar(pont_arq);                 
                break;
            
            case 6:
                investimento();
                break;
            
            case 7:
                sobre();
                break;

            
            case 8:
                exit(2);
            default:
                printf("Escolha inválida. Por favor, escolha alguma das opções acima.\n");
        }
            // Realiza escolha apos as funções
        printf("\nDeseja realizar outra operação? (s/n): ");
        scanf(" %c", &continuar);
    } 

    while (continuar == 's' || continuar == 'S'); // Verifica se o cliente digitou sim

    fclose(pont_arq); // Fechar o arquivo
    
    
    return 0;
}
 
