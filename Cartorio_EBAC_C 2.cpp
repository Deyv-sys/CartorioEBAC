#include <stdio.h> //Biblioteca de Comunica��o Com o Usu�rio
#include <stdlib.h> //Biblioteca de Aloca��o de Espa�o em Memoria
#include <locale.h> //Biblioteca de Aloca��es de Texto por Regi�o
#include <string.h> //Biblioteca Respons�vel Por Cuidar das String

int registro() //Fun��o Respons�vel por Cadastrar os Usu�rios no Sistema
{
    //Inicio da Cria��o De Variaveis/Strings
	char arquivo[40]; 
    char cpf[40];   
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Final da Cria��o De Variaveis/Strings
    
    printf("Digite o CPF a Ser Cadastrado: "); //coletando Informa��o do Usu�rio
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
    printf("N�o Foi Possivel Abrir o Arquivo, N�o Localizado!.\n");
}    
    
    while(fgets(conteudo, 200, file) != NULL)
{
    printf("\nEssas S�o As Informa��es do Usu�rio: ");
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
	printf("O Usuario N�o se Encontra no Sistema!.\n ");
	system("pause");
	}
	
	   
}


int main()
    {
	int opcao=0; //Definindo Vari�veis
	int laco=1;	

	for(laco=1;laco=1;)
	{
	
	system("cls");
	

    setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
    
    printf("### Cartorio da EBAC ###\n\n"); //Inicio do Menu
    printf("Escolha A Op��o Desejada do Menu\n\n");
    printf("\t1 - Registrar Nomes\n");
    printf("\t2 - Consultar Nomes\n");
    printf("\t3 - Deletar Nomes \n\n");
    printf("Op��o: ");//Fim do Menu
    
    scanf("%d", &opcao); //Armazenamento a Escolha do Usuario
    
    system("cls"); //Responsavel por limpar a Tela
    
    switch(opcao) //Inicip da Sele��o do Menu
  {
	case 1: //Chamada De Fun��es
	registro();
	break;
	
	case 2: 
	consulta();
	break;
	
	case 3:
	deletar();
	break;
	
	default:
	printf("Essa Op��o N�o Est� Disponivel!\n");
	system("pause");
	break;
	
	
  }

    
    
    
    
    
   
	
	
	
}
}
