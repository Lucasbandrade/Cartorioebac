#include <stdio.h>	//biblioteca de comunica��o com o usu�rio
#include <stdlib.h>	//biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>	//biblioteca de aloca��es de texto por regi�o
#include <string.h>	//biblioteca respons�vel por cuidar das strings

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40]; 
	char sobrenome[40];
	char cargo[40];
	//inicio cria��o vari�veis/string

	printf("digite CPF a ser cadastrado: "); //coletando inf do usu�rio
	scanf("%s", cpf); //scanf: armazena o valor na variavel. %s refere-se a string.
		
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings 
	
	FILE *file; //cria o arquivo 
	
	file = fopen(arquivo,"w"); //cria o arquivo (w � para escrever)
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo, "a"); //"a" � de atualiza��o
	fprintf(file,",");
	fclose(file);
	
	printf("digite nome a ser cadastrado: "); //coletando inf do usu�rio
	scanf("%s",nome); //scanf: armazena o valor na variavel. %s refere-se a string.
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");	
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	

}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); // permite as acentua��es do idioma selecionado. 
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	printf("\n");
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
		printf("\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");


}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	printf("usu�rio deletado! \n");
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL);
	{
		printf("o usu�rio n�o se encontra no sistema!. \n");
		system("pause");
	}
}




int main()
{
	int opcao=0; //definindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");	
	
    	setlocale(LC_ALL, "Portuguese"); //definindo a liguagem
	
		printf("### cart�rio da EBAC ###\n\n"); //inicio menu
		printf("escolha a op��o desejada:\n\n");
		printf("\t1 - registrar nomes\n");
		printf("\t2 - consultar nomes\n");
		printf("\t3 - deletar nomes\n"); 
		printf("op��o:"); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuario
	
		system("cls"); //responsavel por limpar a tela
		
		switch(opcao) //inicio da sele��o do menu 
		{
			case 1:
			registro(); //chamda de fun��es
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
						
			default:
			printf("essa op��o n�o est� disponivel!\n");
			system("pause");	
			
				
		}
			
	}
	
}



