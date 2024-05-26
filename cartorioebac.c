#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��es de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblikoteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //respons�vel por copiar os valores das string
	scanf("%s" , cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo 
	fprintf(file, ","); //representa a "," que ficar� entre o nome/sobrenome...
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo "a"
	fprintf(file,nome);
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo "a"
	fprintf(file, ","); //representa a "," que ficar� entre o nome/sobrenome...
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //abre o arquivo "a"
	fprintf(file,sobrenome);
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo "a"
	fprintf(file, ","); //representa a "," que ficar� entre o nome/sobrenome...
	fclose(file); //fercha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");  //abre o arquivo "a"
	fprintf(file,cargo);
	fclose(file); //fecha o arquivo
	
	system("pause"); //evita que retorne de imediato para tela inicial, fazendo um "freeze" na �ltima tela utilizada
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //evita que retorne de imediato para tela inicial, fazendo um "freeze" na �ltima tela utilizada
}
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); //comando para remo��o de arquivos
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause"); //evita que retorne de imediato para tela inicial, fazendo um "freeze" na �ltima tela utilizada
	
	}
	
}

int main()
{
	int opcao=0;//Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");  //Respons�vel por limpar a tela
	
	 	setlocale(LC_ALL, "Portuguese");//Definindo linguagem
	 
	 
	 	printf("### Cart�rio da EBAC ###\n\n");//In�cio do menu
	 	printf("Escolha a  op��o desejada do menu\n\n");
	 	printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
	 	printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: ");//Fim do menu                    
	 
	 	scanf("%d" , &opcao);//Armazenando escolha do User
	 
		 system("cls"); //Respons�vel por limpar a tela
		 
		 switch(opcao) //Inicio da sele��o
		 {
		 	case 1:
			registro(); //Chamada de fun��es
	 		break;
	 		
	 		case 2:
	 		consulta();
	 		break;
	 		
	 		case 3:
	 		deletar();
	 		break;
	 		
	 		default:
	 		printf("Essa op��o n�o est� dispon�vel!\n");
	 		system("pause"); //evita que retorne de imediato para tela inicial, fazendo um "freeze" na �ltima tela utilizada
			break; //Fim da sele��o
				
		 }
	
	}
}
