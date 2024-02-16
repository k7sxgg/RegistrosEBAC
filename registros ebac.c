#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //bibioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //bibioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o responsavel oir cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/string
	char arquivo[100];
	char cpf[100];
	char nome[100];
	char sobrenome[100];
	char cargo[100];
	//inicio da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file;	//cria arquivo
	file = fopen(arquivo, "w"); //cria aquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); // fecho o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[100];
	char conteudo[2000];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("CPF n�o cadastrado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nInforma��es do usu�rio: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[100];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf ("Usu�rio deletado com sucesso!\n ");
		system("pause");
	}
	
}

int main()
	{
	int opcao=0; //Definindo Vari�veis
	int x=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Registros EBAC ###\n\n");
	printf("Login de administrador!\n\n Digite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
	
	
		for(x=1;x=1;)
		{
	
			system("cls");
		
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
			printf("### Registros EBAC ###\n\n"); //Inicio do Menu
			printf("Selecione a op��o desejada no menu:\n\n");
			printf("\t1 - Registrar CPF\n");
			printf("\t2 - Consultar CPF\n");
			printf("\t3 - Deletar CPF\n\n");
			printf("Digite a op��o desejada:"); //Fim do menu
	
			scanf("%d", &opcao); //Armazenando a escolha do Usu�rio
	
			system("cls"); //Responsavel por limpar a tela 
		
			switch(opcao) //inicio dele��o do menu
			{	
				case 1:
				registro();
				break;
				
				case 2:
				consulta();
				break;
				
				case 3:
				deletar();
				break;
				
				default:
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				break;
				
			} //Fim da sele��o 	
		}	 
	}

	else
		printf("Senha incorreta!");

}

