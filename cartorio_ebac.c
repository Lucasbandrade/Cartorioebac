#include <stdio.h>	//biblioteca de comunicação com o usuário
#include <stdlib.h>	//biblioteca de alocação de espaço em memória
#include <locale.h>	//biblioteca de alocações de texto por região
#include <string.h>	//biblioteca responsável por cuidar das strings

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//inicio criação variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40]; 
	char sobrenome[40];
	char cargo[40];
	//inicio criação variáveis/string

	printf("digite CPF a ser cadastrado: "); //coletando inf do usuário
	scanf("%s", cpf); //scanf: armazena o valor na variavel. %s refere-se a string.
		
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings 
	
	FILE *file; //cria o arquivo 
	
	file = fopen(arquivo,"w"); //cria o arquivo (w é para escrever)
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo, "a"); //"a" é de atualização
	fprintf(file,",");
	fclose(file);
	
	printf("digite nome a ser cadastrado: "); //coletando inf do usuário
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
	setlocale(LC_ALL, "Portuguese"); // permite as acentuações do idioma selecionado. 
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	printf("\n");
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
		printf("\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
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
	
	printf("usuário deletado! \n");
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL);
	{
		printf("o usuário não se encontra no sistema!. \n");
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
	
		printf("### cartório da EBAC ###\n\n"); //inicio menu
		printf("escolha a opção desejada:\n\n");
		printf("\t1 - registrar nomes\n");
		printf("\t2 - consultar nomes\n");
		printf("\t3 - deletar nomes\n"); 
		printf("opção:"); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuario
	
		system("cls"); //responsavel por limpar a tela
		
		switch(opcao) //inicio da seleção do menu 
		{
			case 1:
			registro(); //chamda de funções
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
						
			default:
			printf("essa opção não está disponivel!\n");
			system("pause");	
			
				
		}
			
	}
	
}



