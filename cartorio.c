#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()//Função reponsavel por cadastrar os usuários no sistema
{
	//inicio criação de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaves
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuario
	scanf("%s",cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf);// responsável por copiar os valores das strings
	
	FILE *file;//cria o arquivo
	file = fopen(arquivo, "w");//cria o arquivo e o "w" siginifica escrever
	fprintf(file,cpf);//salva o valor da variavel
	fclose(file);//fecho o arquivo
	
	file = fopen(arquivo, "a");//cria o arquivo
	fprintf(file, ",");//coloca virgula no arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coletando informão do usuario
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

int consulta()//função responsavel por consultar nomes no sistema
{
	setlocale(LC_ALL, "portuguese");
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;//cria o arquivo
    file = fopen(cpf,"r");//cria o arquivo e "r" significa ler
    
    if(file == NULL)// quando o arquivo não existir
    {
    	printf("Não foi possível abir o arquivo, não localizado!.\n");
	}

    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssas são as informações do usuário: ");
    	printf("%s", conteudo);
    	printf("\n\n");
	}

    system("pause");
}

int deletar()//função responsavel por deletar usuarios do sistema
{
	char cpf[40];
	
	printf("Digite o cpf do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);//deleta o arquivo
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
	



}


int main()
    {
	int opcao=0;//definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");//responsavel por limpar a tela
		
	
	    setlocale(LC_ALL, "portuguese");//definindo a linguagem
	
	    printf("### cartório da EBAC ###\n\n");//início do menu
     	printf("Escolha a opção desejada do menu:\n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
    	printf("Opção: ");//fim do menu

	    scanf("%d", &opcao);//armazenando a escolha do usuário
	
	    system("cls");
	    
	    switch(opcao)// inicio da seleção do menu
	    { 
	        case 1:
	        registro();//chamada de funções
	        break;
	        
	        case 2:
	        consulta();
	        break;
	        
	        case 3:
	        deletar();
	        break;
	        
	        default:
	        printf("Essa opção não está disponivel!\n");
	        system("pause");
	        break;
	        //fim da seleção
		}
		
	
   } 
       
}
    

    
