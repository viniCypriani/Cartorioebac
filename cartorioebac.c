#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocações de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblikoteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//início da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //responsável por copiar os valores das string
	scanf("%s" , cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo 
	fprintf(file, ","); //representa a "," que ficará entre o nome/sobrenome...
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo "a"
	fprintf(file,nome);
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo "a"
	fprintf(file, ","); //representa a "," que ficará entre o nome/sobrenome...
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //abre o arquivo "a"
	fprintf(file,sobrenome);
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo "a"
	fprintf(file, ","); //representa a "," que ficará entre o nome/sobrenome...
	fclose(file); //fercha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");  //abre o arquivo "a"
	fprintf(file,cargo);
	fclose(file); //fecha o arquivo
	
	system("pause"); //evita que retorne de imediato para tela inicial, fazendo um "freeze" na última tela utilizada
	
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
		printf("Não foi possível abrir o arquivo, não localizado!.\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //evita que retorne de imediato para tela inicial, fazendo um "freeze" na última tela utilizada
}
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); //comando para remoção de arquivos
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause"); //evita que retorne de imediato para tela inicial, fazendo um "freeze" na última tela utilizada
	
	}
	
}

int main()
{
	int opcao=0;//Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");  //Responsável por limpar a tela
	
	 	setlocale(LC_ALL, "Portuguese");//Definindo linguagem
	 
	 
	 	printf("### Cartório da EBAC ###\n\n");//Início do menu
	 	printf("Escolha a  opção desejada do menu\n\n");
	 	printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
	 	printf("\t3 - Deletar nomes\n\n");
		printf("Opção: ");//Fim do menu                    
	 
	 	scanf("%d" , &opcao);//Armazenando escolha do User
	 
		 system("cls"); //Responsável por limpar a tela
		 
		 switch(opcao) //Inicio da seleção
		 {
		 	case 1:
			registro(); //Chamada de funções
	 		break;
	 		
	 		case 2:
	 		consulta();
	 		break;
	 		
	 		case 3:
	 		deletar();
	 		break;
	 		
	 		default:
	 		printf("Essa opção não está disponível!\n");
	 		system("pause"); //evita que retorne de imediato para tela inicial, fazendo um "freeze" na última tela utilizada
			break; //Fim da seleção
				
		 }
	
	}
}
