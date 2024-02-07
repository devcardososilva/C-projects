#include "menu.h"
#include <stdio.h> // Entrada e saída padrão
#include <stdlib.h> // Biblioteca padrão
#include <time.h> // Pocibilita usar funções relacionadas a tempo e data
#include <locale.h> // Configurar aspectos regionais
#include <string.h> // Manipulação de strings
#include <unistd.h> // Usada para funções relacionadas à interação com o sistema operacional

void sobre() {

    printf("Apresentamos o Sistema de Gestão Financeira, a solução inteligente e eficaz\n");
    printf("para simplificar o controle financeiro de sua empresa. Desenvolvido com tecnologia de ponta\n");
    printf("e pensado para atender às necessidades de negócios de todos os tamanhos, nosso sistema é a ferramenta essencial\n");
    printf("para garantir a saúde financeira de sua organização.\nAqui você poderá realizar o acompanhamento detalhado de\n");
    printf("suas finanças até o controle de receita.\n");
}

void menuPrincipal() {
    
    system("clear");
    
    printf("Bem-vindo ao Sistema Financeiro.\nAqui estão as opções do programa:\n");
    printf(" _____________________________\n");
    printf("|                             |\n");
    printf("|   1 - Cadastrar-se          |\n"); // Primeira entrada de um cliente
    printf("|   2 - Consultar cadastros   |\n"); // Quando um cliente já tem um cadastro
    printf("|   3 - Adicionar informações |\n"); // Adicionar novas informações ao sistema
    printf("|   4 - Deletar informações   |\n");    // Sobre o software
    printf("|   5 - Atualizar             |\n"); // Atualizar informações
    printf("|   6 - Investimentos         |\n"); 
    printf("|   7 - Sobre o sistema       |\n"); // Deletar
    printf("|   8 - Sair                  |\n"); // Sair do software
    printf("|_____________________________|\n");
    printf("\nPor favor digite o número de alguma das operações do sistema: \n");

}