#include <stdio.h> //Biblioteca de Comunicação Com o Usuário
#include <stdlib.h> //Biblioteca de Alocação de Espaço em Memoria
#include <locale.h> //Biblioteca de Alocações de Texto por Região
#include <string.h> //Biblioteca Responsável Por Cuidar das String

int registro() //Função Responsável por Cadastrar os Usuários no Sistema
{
    //Inicio da Criação De Variaveis/Strings
	char arquivo[40]; 
    char cpf[40];   
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Final da Criação De Variaveis/Strings
    
    printf("Digite o CPF a Ser Cadastrado: "); //coletando Informação do Usuário
    scanf("%s" , cpf); //%s refere-se a String
    
    strcpy(arquivo , cpf);  //Responsavel Por Copiar os Valores das String
    
    FILE *file;  //Cria O Arquivo
    file = fopen(arquivo,  "w"); //Cria O Arquivo
    fprintf(file,cpf);  //Salvo o Valor da Variavel
    fclose(file);  //Fecha o Arquivo
    
    file = fopen(arquivo , "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o Nome A Ser Cadastrado: ");
    scanf("%s" ,nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);

    file = fopen(arquivo , "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o Sobrenome a Ser Cadastrado: ");
    scanf("%s" ,sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo , "a");
    fprintf(file, ",");
    fclose(file);
     
	printf("Digite o Cargo a Ser Cadastrado: ");     
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
    
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF A Ser Consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
{
    printf("Não Foi Possivel Abrir o Arquivo, Não Localizado!.\n");
}    
    
    while(fgets(conteudo, 200, file) != NULL)
{
    printf("\nEssas São As Informações do Usuário: ");
    printf("%s",conteudo);
    printf("\n\n");
}
   
    system("pause");
   
   
   
}

int deletar()
{
    char cpf [40];
	
	printf("Digite o CPF do Usuario A Ser Deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
   
    FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
    {
	printf("O Usuario Não se Encontra no Sistema!.\n ");
	system("pause");
	}
	
	   
}


int main()
    {
	int opcao=0; //Definindo Variáveis
	int laco=1;	

	for(laco=1;laco=1;)
	{
	
	system("cls");
	

    setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
    
    printf("### Cartorio da EBAC ###\n\n"); //Inicio do Menu
    printf("Escolha A Opção Desejada do Menu\n\n");
    printf("\t1 - Registrar Nomes\n");
    printf("\t2 - Consultar Nomes\n");
    printf("\t3 - Deletar Nomes \n\n");
    printf("Opção: ");//Fim do Menu
    
    scanf("%d", &opcao); //Armazenamento a Escolha do Usuario
    
    system("cls"); //Responsavel por limpar a Tela
    
    switch(opcao) //Inicip da Seleção do Menu
  {
	case 1: //Chamada De Funções
	registro();
	break;
	
	case 2: 
	consulta();
	break;
	
	case 3:
	deletar();
	break;
	
	default:
	printf("Essa Opção Não Está Disponivel!\n");
	system("pause");
	break;
	
	
  }

    
    
    
    
    
   
	
	
	
}
}
