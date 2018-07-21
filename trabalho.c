#include<stdio.h>//trabalho de ed1. 11/12/2013
#include<stdlib.h>
#include<time.h>//para funcao sugestoes
#include<string.h>
#define NOME 50
#define E_MAIL 50
#define NUMERO_TELEFONE 8
#define RG 15
typedef struct no {
	int numero_telefone,rg[RG];
	char e_mail[E_MAIL],nome[NOME];
	struct no *di;
	struct no *es;
	} no;
no *grandepatriarca = NULL;
void sugestoes() {
    int i;
    srand(time(NULL));
    printf("Sugestoes:\n"); 	
    for(i=1 ; i <= 3 ; i++) {
    	printf("3%d\n",rand()%10000000);
	printf("8%d\n",rand()%10000000);
	printf("9%d\n",rand()%10000000);
	}
}
void preordem(no *n) {
	if(n != NULL) {
		printf("======================================\n");
		printf("Nome: %s",n->nome);
		printf("E-Mail: %s\n",n->e_mail);
		printf("RG: %d\n",n->rg);
		printf("Numero telefone: %d\n",n->numero_telefone);
		printf("======================================\n");		
		if (n->es != NULL)
			preordem(n->es);
		if (n->di != NULL)
			preordem(n->di);
	}
	else if(n == NULL) {
		printf("nenhum dado encontrado");
	}
}
void posordem(no *n) {
	if(n != NULL) {
		if (n->es != NULL)
			posordem(n->es);
		if(n->di != NULL)
			posordem(n->di);
		printf("======================================\n");
		printf("Nome: %s",n->nome);
		printf("E-Mail: %s\n",n->e_mail);
		printf("RG: %d\n",n->rg);
		printf("Numero telefone: %d\n",n->numero_telefone);
		printf("======================================\n");
		}
	else if(n == NULL) {
		printf("nenhum dado encontrado");
		}
}
void simet(no *n) {
	if(n != NULL) {
		if (n->es != NULL)
			posordem(n->es);
			printf("======================================\n");
			printf("Nome: %s",n->nome);
			printf("E-Mail: %s\n",n->e_mail);
			printf("RG: %d\n",n->rg);
			printf("Numero telefone: %d\n",n->numero_telefone);
			printf("======================================\n");
		if(n->di != NULL)
			posordem(n->di);
	}
	else if(n == NULL) {
		printf("Nenhum dado encontrado");
		}
}
int pesquisar(int numero_telefone, no *n) {
	if(n == NULL){
		printf("Numero nao encontrado");
		return 1;
		}
	else if(n->numero_telefone == numero_telefone) {
		printf("======================================\n");
		printf("Nome: %s",n->nome);
		printf("E-Mail: %s\n",n->e_mail);
		printf("RG: %d\n",n->rg);
		printf("======================================\n");
			}	
		else 
			if(numero_telefone < n->numero_telefone)
				pesquisar(numero_telefone, n->es);
			else
				pesquisar(numero_telefone, n->di);
					
}
void inserir(no **praiz,int i) {
	if(*praiz == NULL) {
		*praiz = (no*) malloc(sizeof(no));
		(*praiz)->es = NULL;
		(*praiz)->di = NULL;
		(*praiz)->numero_telefone = i;
		printf("\nNome a ser cadastrado: ");
		fgets((*praiz)->nome,NOME,stdin);
		__fpurge(stdin);
		printf("\nE-Mail a ser cadastrado: ");
		scanf("%s",(*praiz)->e_mail);
		__fpurge(stdin);
		printf("\nRG a ser cadastrado: ");
		scanf("%d",(*praiz)->rg);
		printf("======================================\n");
		printf("Cadastro realizado com sucesso");
							
		}
	else {
		if((*praiz)->numero_telefone == i) {
			printf("Esse valor existe\n");
			sugestoes();
		}
		else {
		if(i < (*praiz)->numero_telefone)
			inserir(&(*praiz)->es,i);
		if(i > (*praiz)->numero_telefone)
			inserir(&(*praiz)->di,i);
	}
   }
}

void deletar(no **praiz,int i) {
	if(*praiz == NULL)
		printf("Valor nao existe");
	else if((*praiz)->numero_telefone == i) {
		if((*praiz)->es == NULL)
			(*praiz) = (*praiz)->di;
		else 
		if((*praiz)->di == NULL)
			(*praiz) = (*praiz)->es;
		else {
			no *aux = (*praiz)->di;
			while(aux->es != NULL)
				aux = aux->es;
			(*praiz) = aux;
		}
	}
	else
	if(i > (*praiz)->numero_telefone)
		deletar(&(*praiz)->di,i);
	else
		deletar(&(*praiz)->es,i);
}
void menu_deletar() {
	int op,num;
	char nume[NUMERO_TELEFONE];
	printf("======================================\n");
	printf("Digite o Numero que deseja deletar: ");
	scanf("%s",nume);
	__fpurge(stdin);
	if((strlen(nume) != 8) || ((nume[0] != '9') && (nume[0] != '8') && (nume[0] != '3'))) {
		printf("Opcao invalida\n");
		printf("Para a remoçao ser realizada com sucesso, o numero a ser removido deve possuir 8 digitos iniciando-se com 3, 8 ou 9.\n");
	}
	else {
		num = atoi(nume);
		if(pesquisar(num,grandepatriarca)==1) {} 
		else {
			printf("Desejas realmente excluir?\n");
			printf("1. Sim\n");
			printf("Para cancelar e voltar ao menu pressione qualquer tecla\n");
			printf("Escolha: "); 
			scanf("%d",&op);
			printf("======================================\n");
			switch(op) {
				case 1:
					deletar(&grandepatriarca,num);
					printf("\t\tExclusao realizada com sucesso\n");
					printf("\t\t===============================\n");
					break;
						
				default:
					break;
				}
	     	 } 
      }
    
}
void menu_listar() {
	int op2;
	printf("\t\tSelecione a ordem de visualizacao.\n");
	printf("1) Percurso em pre-ordem.\n");
	printf("2) Percurso em ordem simetrica.\n");
	printf("3) Percurso em pos-ordem.\n");
	printf("Escolha: ");
	scanf("%d", &op2);
	switch(op2) {
	case 1: 
		printf("Pre-ordem: \n");
		preordem(grandepatriarca);
		break;

	 case 2: 
		printf("Ordem simetrica: \n");
		simet(grandepatriarca);
		break;	               
	case 3: 
		printf("Pos-ordem: \n");
		posordem(grandepatriarca);
		break;
		               
	default: 
		printf("Opcao invalida");
		break;	                        
	}
}
void menu_inserir() {
	int num;
	char nume[NUMERO_TELEFONE];
	printf("Para o cadastro ser realizado com sucesso, o numero a ser cadastrado deve possuir 8 digitos iniciando-se com 3, 8 ou 9. escolha opcao 5 para mais informacoes.\n\n"); 
	printf("Digite o Numero que deseja cadastrar: ");
	scanf("%s",nume);
	__fpurge(stdin);
	if((strlen(nume) != 8) || ((nume[0] != '9') && (nume[0] != '8') && (nume[0] != '3'))) {
		printf("Opcao invalida\n");
		printf("Para o cadastro ser realizado com sucesso, o numero a ser cadastrado deve possuir 8 digitos iniciando-se com 3, 8 ou 9.");
				}
	else {
		num = atoi(nume);
		inserir(&grandepatriarca,num);
	     }
}
void menu_pesquisar() {
	int num;
	char nume[NUMERO_TELEFONE];
	printf("Digite o Numero que deseja pesquisar: ");
	scanf("%s",nume);
	if((strlen(nume) != 8) || ((nume[0] != '9') && (nume[0] != '8') && (nume[0] != '3'))) {
		printf("Opcao invalida\n");
		printf("Para a pesquisa ser realizada com sucesso, o numero a ser pesquisado deve possuir 8 digitos iniciando-se com 3, 8 ou 9.");
	}
	else {
		num = atoi(nume);
		pesquisar(num,grandepatriarca);
	   }
}
void informacoes() {
	printf("\t\tInformacoes imprescindiveis\n1- O numero de cadastro deve possuir 8 digitos iniciando-se com 3, 8 ou 9 para quaisquer acoes que  envolvem-o.\n");
	printf("2- Nomes e e-mails nao devem exceder 50 caracteres.\n");
	printf("3- O RG possui no maximo 15 digitos. Somente numeros devem ser inseridos, senao erros serao computados.\n");
}	            	
main() {
	char op[2];
	int ch;
	do {
		printf("\n======================================\n");
		printf("1. Cadastrar Numero\n");
		printf("2. Pesquisar Numero\n");
		printf("3. Remover Numero\n");
		printf("4. Listar Cadastros\n");
		printf("5. Informacoes\n");
		printf("6. Sair\n");
		printf("======================================\n");
		printf("Escolha: ");
		scanf("%s",op);
		ch = atoi(op);
		switch(ch) {
           	 	case 1:
				menu_inserir();
                    		break;

           	 	case 2:
		            	menu_pesquisar();
                   		break;

            		case 3: 
				menu_deletar();
                    		break;

           	 	case 4:
				menu_listar();
                   		break;
			case 5:
				informacoes();
				break;
			case 6:
				break;

            		default: 
				printf("Opcao invalida");
				break;
            }
    }while(ch!=6);

}
