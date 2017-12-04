#include <stdio.h>
#include <stdlib.h>
#include <string.h>     // para poder comparar as variaveis do tipo CHAR //
#define SIZE 200		// Uma definição para uso nos Vetores//

    float salariopesquisa=1000;
 	int op;
    struct cadastro_funcionarios  // estrutura//
{
    char nome[SIZE][50];
    char email[SIZE][50];
    int cpf[SIZE];
    int salario[SIZE];
};
    struct cadastro_funcionarios funcionario[SIZE];  /* Aqui criei um vetor funcionairo do tipo 
    														cadastro_funcionarios */

    void cadastroF();				/* Aqui foi declarado duas funçoes para ser chamadas na função principal*/
    void pesquisaF();
int main()
{
    int n;
      printf("\t==================CADASTRO DE FUNCIONARIOS===============\n\n\n");
      printf("\t\tOpcoes\n\n\t==> 1 Para cadastro\n\t==> 2 Para Pesquisar cadastros\n\t==> 3 Para Sair\n\n");
        scanf("%d", &n);
        if (n==1){
            cadastroF();							// Aqui fica as Funções que foram criadas e chamadas na funções principal a função MAIN//
        } if (n==2){
            pesquisaF();
        } if (n==3){
        exit(0);}




return 0;
}
 void cadastroF(){
													/* Aqui foi criado o cadastro usando as
													 variaveis do tipo funcionario */
    do{
     int static linha;

        printf("Digite o Nome:\n");
        fflush(stdin);
        fgets(funcionario[linha].nome[linha], 50, stdin);

        printf ("Digite o Email: \n");
        fflush(stdin);
        fgets(funcionario[linha].email[linha], 50, stdin );

        printf("Digite o CPF :\n");
        scanf("%d", &funcionario[linha].cpf[linha]);

        printf("Digite o Salario do Funcionario\n");
        scanf("%d", &funcionario[linha].salario[linha]);

        printf("\n\t Cadastro do Funcionario Numero %d Feito com sucesso\n\n\t==>Digite [1] para continuar\n\n\tPara ir para pesquisa Digite [2]\n\n\tDigite ou outro valor para sair!! :\n",linha+1);
        scanf("%i", &op);
        if (op==2){
            pesquisaF();
        }
        linha++;

    }while(op==1);


 }

 void pesquisaF(){
     int Opcaopesquisa, cpfpesquisa, i; 				/* Aqui foi feito a pesquisa de E-mail, CPF e nome
     															como so fui ter acesso ao livro dias antes de terminar
     															fiz a pesquisa por CPF no Lugar de matricula 
     															mas se usa o mesmo pensamento   */
     char emailpesquisa[50], nomepesquisa[50];

     op=0;
     do{
     printf("\tOpcao de Pesquisa\n");
     printf("\t=> 1 CPF :\n\t=> 2 Email :\n\t=> 3 Nome :\n\t=> 4 Qual ganha Mais de 1000\n");
     scanf("%d", &Opcaopesquisa);

        switch(Opcaopesquisa){
        case 1:
            printf("====>Digite o CPF para pesquisa<=====\n");
            fflush(stdin);
            scanf("%d", &cpfpesquisa);
            for(i=0;i<SIZE;i++){
                if(funcionario[i].cpf[i]==cpfpesquisa){
                    printf("Cpf= %d\n\nEmail= %s\nNome= %s\nSalario %d\n\n", funcionario[i].cpf[i], funcionario[i].email[i], funcionario[i].nome[i], funcionario[i].salario[i]);
                }
            }
            break;

        case 2:
            printf("=====>Digite o Email para pesquisa<=====\n");
            fflush(stdin);
                fgets(emailpesquisa, 50, stdin);
                for(i=0;i<SIZE;i++){
                    if(strcmp(funcionario[i].email[i], emailpesquisa)==0){
                      printf ("Cpf= %d\n\nEmail= %s\nNome= %s\nSalario %d\n\n", funcionario[i].cpf[i], funcionario[i].email[i], funcionario[i].nome[i], funcionario[i].salario[i]);
                    }
                }
            break;

        case 3:
            printf("=====>Digite o Nome para pesquisa<=====\n");
            fflush(stdin);
            fgets(nomepesquisa, 50, stdin);
            for(i=0;i<SIZE;i++){
                if(strcmp(funcionario[i].nome[i], nomepesquisa)==0){
                  printf("Cpf= %d\n\nEmail= %s\nNome= %s\nSalario %d\n\n", funcionario[i].cpf[i], funcionario[i].email[i], funcionario[i].nome[i], funcionario[i].salario[i]);
                }
            }
            break;

        case 4:
            printf("=====>Funcionarios Com salario Maior ou igual a 1000 eh:<=====\n");
            for(i=0;i<SIZE;i++){
                    if(funcionario[i].salario[i] >= salariopesquisa){
            printf("Cpf= %d\n\nEmail= %s\nNome= %s\nSalario %d\n\n\n============================================\n", funcionario[i].cpf[i], funcionario[i].email[i], funcionario[i].nome[i], funcionario[i].salario[i]);
                }
            } if (funcionario[i].cpf[i]!=0){ printf("\t========Sem Fucionarios com Esse Salario=========\n\n"); }
            break;

        default:
            printf("=========>>>Opcao invalida<<<=========");
            break;
        }
        printf("\t***Para Continuar Pesquisando digite 1\t\n****Digite qualquer valor para ir Para o Inicio do Programa\n\n");
        scanf("%d", &op);


     }while(op==1);
    main();
 }

