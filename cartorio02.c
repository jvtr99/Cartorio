#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaços em memória 
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável pelas strings

// Se colaca ";" no final quando estamos chamando a função. Se estiver criando, o ";" não é utilizado

int registro()
{
	char arquivo[50]; //[50] é a quantidade máxima de caracteres permitidas na string
	char cpf[50];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf );	//salva a variável dentro de uma string - neste caso, ele vai salvar até 50 caracteres em CPF
	
	strcpy(arquivo, cpf); //responsável por copiar/igualar as strings - neste caso, copiar o valor da string cpf para a string arquivo
	
	FILE *file; //comando para criar o arquivo no banco de dados (computador)
	file = fopen(arquivo, "w"); //cria o arquivo na pasta ("w" - write ---> escrever/criar)
	fprintf(file, cpf); //salvar o valor da variável cpf dentro do arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abrir e incluir mais informações no arquivo - "a"TUALIZAR
	fprintf(file, ","); //salvar a acrescentar a vígula
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome); //salvar o conteúdo da variável nome dentro do arquivo
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ","); 
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome); //salvar o conteúdo da variável sobrenome dentro do arquivo
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ","); 
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Poutuguese");
	
	char cpf[50];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //abrir e ler arquivo cpf ("r" ---> "r"EAD)
	
	if(file == NULL)
	{
		printf("Arquivo NÃO localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //salvando a variável na string, os 200 caracteres que estão dentro do arquivo; só para quando for nulo
	{
		printf("\nEssas são as informaçãoes do usuário: ");
		printf("%s", conteudo);
		printf("\n\n"); //pular linhas	
	}
	
	fclose(file);
	system("pause");
	
}

int deletar()
{
	char cpf[50];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); //Essa função vai acessar a pasta e irá apagar o arquivo
	
	FILE *file; //Validar a presença do CPF no sistema
	file == fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usuário não cadastrado no sistema!.\n\n"); // o sistema entendo a "\" como um comando, não como parte do texto!
		system("pause");
	}
	
	if(file != NULL)
	{
		printf("Usuário deletado com sucesso!\n\n");
		remove(cpf);
		system("pause");
	}
	
}

int main() //Sempre será executado primeiro
	{
		int opcao=0; //Definindo variáveis
		int laco=1;
		
		for(laco=1;laco=1;) // Laço de repetição
		{
			system("cls"); //Limpar a tela
		
			setlocale(LC_ALL, "Poutuguese"); // Definindo a linguagem
		
			printf("### Cartório EBAC ###\n\n"); //Início do menu
			printf("Escolha a opcao desejada do menu\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("Opção: "); // Fim do menu
		
			scanf("%d", &opcao); //armazenando a escolha do usuário - armazena a variável
		
			system("cls");
			
			switch(opcao)
			{
				case 1: // ":" no switch case funciona com se fosse "{"
				registro();
				break; // funciona como se fosse "}"
				
				case 2:
				consulta();
				break;
				
				case 3:
				deletar();
				break;
				
				default: // nenhuma opção acima
				printf("Opção indisponível!");
				system("pause");
				break;
			}
		}
	}
	