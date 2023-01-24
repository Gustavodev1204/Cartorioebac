#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()//Fun��o reponsavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaves
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usuario
	scanf("%s",cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf);// respons�vel por copiar os valores das strings
	
	FILE *file;//cria o arquivo
	file = fopen(arquivo, "w");//cria o arquivo e o "w" siginifica escrever
	fprintf(file,cpf);//salva o valor da variavel
	fclose(file);//fecho o arquivo
	
	file = fopen(arquivo, "a");//cria o arquivo
	fprintf(file, ",");//coloca virgula no arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coletando inform�o do usuario
	scanf("%s",nome);//%s refere-se a strings
	
	file = fopen(arquivo, "a");//cria o arquivo
	fprintf(file,nome);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()//fun��o responsavel por consultar nomes no sistema
{
	setlocale(LC_ALL, "portuguese");
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;//cria o arquivo
    file = fopen(cpf,"r");//cria o arquivo e "r" significa ler
    
    if(file == NULL)// quando o arquivo n�o existir
    {
    	printf("N�o foi poss�vel abir o arquivo, n�o localizado!.\n");
	}

    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssas s�o as informa��es do usu�rio: ");
    	printf("%s", conteudo);
    	printf("\n\n");
	}

    system("pause");
}

int deletar()//fun��o responsavel por deletar usuarios do sistema
{
	char cpf[40];
	
	printf("Digite o cpf do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);//deleta o arquivo
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
	



}


int main()
    {
	int opcao=0;//definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");//responsavel por limpar a tela
		
	
	    setlocale(LC_ALL, "portuguese");//definindo a linguagem
	
	    printf("### cart�rio da EBAC ###\n\n");//in�cio do menu
     	printf("Escolha a op��o desejada do menu:\n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("\t4 - Sair do sistema\n\n");
    	printf("Op��o: ");//fim do menu

	    scanf("%d", &opcao);//armazenando a escolha do usu�rio
	
	    system("cls");
	    
	    switch(opcao)// inicio da sele��o do menu
	    { 
	        case 1:
	        registro();//chamada de fun��es
	        break;
	        
	        case 2:
	        consulta();
	        break;
	        
	        case 3:
	        deletar();
	        break;
	        
	        case 4:
	        printf("Obrigado por utilizar o sistema!\n");
	        return 0;
	        break;
	        
	        default:
	        printf("Essa op��o n�o est� disponivel!\n");
	        system("pause");
	        break;
	        //fim da sele��o
		}
		
	
   } 
       
}
    

    
