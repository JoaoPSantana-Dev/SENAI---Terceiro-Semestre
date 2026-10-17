#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

#define  true  1      /* apoio para uso nas fun  es */ 
#define  false 0      /* apoio para uso nas fun  es */ 

typedef  int   bool;  /* apoio para uso nas fun  es */ 

/* Definindo o REGISTRO */
typedef struct   
{         
   int		  chave; 
   /* campos do registro */        
   char       NOME[100+1];
   char       DATANASC [10+1];
   char       CPF [14+1];
 
} 
REGISTRO;

typedef struct
{
  char nome[50];
  char dataNascimento[11];
  char cpf[15];	
} Pessoa;

typedef struct aux
{  
   REGISTRO 	reg;
   struct 	    aux * PROX;  /* prox APONTA para o endere o de mem ria  */
}                            /* de um elemento com essa mesma estrutura */
ELEMENTO;

/* Definindo a fila */
typedef ELEMENTO  *PONT;

typedef struct 
{
   PONT inicio;    /* inicio APONTA para o endere o do primeiro ELEMENTO da fila */
   PONT fim;       /* fim APONTA para o endere o do  ltimo ELEMENTO da fila */
} 
fila;

Pessoa pessoas[10] = {
        {"Freddie Mercury", "1946/09/05", "123.456.789-01"},
        {"Jimi Hendrix",    "1942/11/27", "234.567.890-12"},
        {"Janis Joplin",    "1943/01/19", "345.678.901-23"},
        {"John Lennon",     "1940/10/09", "456.789.012-34"},
        {"Elvis Presley",   "1935/01/08", "567.890.123-45"},
        {"David Bowie",     "1947/01/08", "678.901.234-56"},
        {"Kurt Cobain",     "1967/02/20", "789.012.345-67"},
        {"Robert Plant",    "1948/08/20", "890.123.456-78"},
        {"Mick Jagger",     "1943/07/26", "901.234.567-89"},
        {"Joan Jett",       "1958/09/22", "012.345.678-90"}
 };

void insertion_sort_fila(fila *f)
{
    PONT ordenada = NULL;
    PONT atual, proximo, p;

    atual = f->inicio;

    while (atual != NULL)
    {
        proximo = atual->PROX;

        if (ordenada == NULL ||
            strcmp(atual->reg.DATANASC,
                   ordenada->reg.DATANASC) < 0)
        {
            atual->PROX = ordenada;
            ordenada = atual;
        }
        else
        {
            p = ordenada;

            while (p->PROX != NULL &&
                   strcmp(p->PROX->reg.DATANASC,
                          atual->reg.DATANASC) <= 0)
            {
                p = p->PROX;
            }

            atual->PROX = p->PROX;
            p->PROX = atual;
        }

        atual = proximo;
    }

    f->inicio = ordenada;
    f->fim = ordenada;

    while (f->fim != NULL && f->fim->PROX != NULL)
        f->fim = f->fim->PROX;
}

/* Definindo o ELEMENTO */


/* Prot tipos de fun  es */
void 	inicializarfila 	(fila * f);
int 	tamanho 			(fila * f);
void 	exibirfila 			(fila * f);
bool 	estaVazia			(fila * f);
bool 	inserirNaFila 		(fila * f);
bool    insereElemFila      (fila * f, REGISTRO  reg);
bool 	excluirDaFila		(fila * f, REGISTRO *reg);
void 	reinicializarFila	(fila * f);

REGISTRO oqueInserir (void);
void     msgErro	 (void);
void cadastraDefault (fila * f); 

/* 
Para inicializar uma fila j  criada pelo usu rio,  precisamos acertar o valor do campo inicio e do campo fim.
J  que o inicio conter  o endere o do elemento que ser  o primeiro da fila e a fila est  vazia, iniciaremos esse campo com valor NULL. 
J  que o fim conter  o endere o do elemento que ser  o  ltimo da fila e a fila est  vazia, iniciaremos esse campo com o valor NULL.
*/
void inicializarfila (fila * f)
{
  f->inicio = NULL;
  f->fim    = NULL;
}

/* J  que n o temos um campo com o n mero de elementos na fila, precisaremos percorrer todos os elementos para contar quantos s o.
*/
int tamanho (fila * f) 
{  
	PONT    end = f->inicio;  
	int     tam = 0;
	while (end != NULL) 
	{  
  		tam++;
  		end = end->PROX;
	}
	return tam;
}

/* Para exibir os elementos da estrutura precisaremos  percorrer os elementos 
   (iniciando pelo elemento do in cio da fila) e, por exemplo, imprimir suas chaves. */
void exibirfila (fila* f) 
{  	
   PONT end = f->inicio;  
   system ("cls"); system ("mode 110, 12");
   printf("fila:\n");  
   while (end != NULL) 
   {
	printf("[%i-%s-%s-%s]", end->reg.chave, end->reg.NOME, end->reg.DATANASC, end->reg.CPF);
	printf("\n"); 
	end = end->PROX;
   }
}

/* Se in cio est   armazenando o endere o NULL, significa que a fila est  vazia. */
bool estaVazia(fila* f) 
{
   if (f->inicio == NULL) 
      return true;  
   return false;
}

bool inserirNaFila (fila * f)
{
   REGISTRO	elem;
   PONT novo = (PONT) malloc(sizeof(ELEMENTO));  
   if ( novo == NULL )
   {  
      printf ("\nErro ao alocar novo registro.");
      getch();
      return false;
   }
   elem  = oqueInserir();
   novo->reg = elem;
   novo->PROX = NULL;
   if (f->inicio==NULL) 
      f->inicio = novo;  
   else 
      f->fim->PROX = novo;
   f->fim = novo;
   system ("cls"); system ("mode 110, 12");
   printf ("\nChave [%i-%s-%s-%s] inserida com sucesso.", 
   elem.chave, elem.NOME, elem.DATANASC, elem.CPF);
   insertion_sort_fila(f);
   return true;
}

/* 
O usu rio solicita a exclus o do elemento do in cio da fila. 
Se a fila n o estiver vazia, 
  iremos copiar esse elemento para um local indicado pelo usu rio;
  acertar o valor do campo inicio;
  eventualmente acertar o valor do campo fim.
*/
bool atenderCliente(fila * f, REGISTRO *reg) 
{  	
   if (f->inicio==NULL) 
   	  return false;
   insertion_sort_fila(f);	  
   *reg = f->inicio->reg;  
   PONT apagar = f->inicio;
   f->inicio = f->inicio->PROX;  
   free(apagar);
   if (f->inicio == NULL) 
      f->fim = NULL;  
   return true;
}

/* 
Para reinicializar a fila, precisamos excluirtodos os  seus elementos 
e colocar NULL nos campos inicio e fim
*/
void reinicializarFila(fila * f) 
{  
   PONT end = f->inicio;
   PONT apagar;
   while (end != NULL) 
   {  
      apagar = end;  
	  end = end->PROX;  
	  free(apagar);
   }
   f->inicio = NULL;  
   f->fim = NULL;
}

REGISTRO oqueInserir (void)
{	REGISTRO r;
    system ("cls"); system ("mode 110, 12");
	printf ("\nTIPOCHAVE          : "); fflush (stdin); scanf("%i", &r.chave);
	printf ("\nNOME               : "); fflush (stdin); gets(r.NOME);
	printf("\nDATA DE NASCIMENTO (AAAA/MM/DD): ");fflush(stdin); gets(r.DATANASC);
	printf ("\nCPF                : "); fflush (stdin); gets(r.CPF);
	return r;
}

void     msgErro	 (void)
{
	system ("cls");
	printf ("\nOp  o inv lida!");
	getch();
}

bool    insereElemFila      (fila * f, REGISTRO reg)
{
   PONT novo = (PONT) malloc(sizeof(ELEMENTO));  
   novo->reg = reg;
   novo->PROX = NULL;
   if (f->inicio==NULL) 
      f->inicio = novo;  
   else 
      f->fim->PROX = novo;
   f->fim = novo;
   system ("cls"); system ("mode 110, 12");
   printf ("\nChave [%i-%s-%s] inserida com sucesso.", 
   reg.chave, reg.NOME, reg.DATANASC );
   insertion_sort_fila(f);
   return true;
}

void cadastraDefault  (fila * f) 
{
	int i;
	REGISTRO r[10];

	for(i=0;i<10;i++){
		r[i].chave = i+1;
		strcpy(r[i].NOME, pessoas[i].nome);
		strcpy(r[i].DATANASC,pessoas[i].dataNascimento);			
		strcpy(r[i].CPF,pessoas[i].cpf);
	}	
	
	reinicializarFila(f);
	for (i=0 ; i<10; i++)
	   if (insereElemFila(f, r[i]) == false) 
	   {
	   	printf ("\nErro no cadastro default.");
        getch();	   	
	   }
	exibirfila(f);
}

/* CORPO DO PROGRAMA */
int main ()
{
  fila  	* F;
  REGISTRO 	r;
  char      opc;
	
  setlocale (LC_ALL, "");
  
  F = (fila *) malloc (sizeof (fila)); // aloca uma fila
  if (F == NULL)
  {
    printf ("malloc devolveu NULL!\n");
    getch();
    exit (EXIT_FAILURE);
  }        

  inicializarfila (F);
	
  while (opc != 's')
  {
  	system ("cls"); system ("mode 36,12");
  	printf ("\n=============================");
  	printf ("\n    TESTE COM FILA           ");
  	printf ("\n=============================");
  	printf ("\n d = cadastro default        ");
  	printf ("\n i = incluir      		    ");
  	printf ("\n a = atender cliente 	    ");
  	printf ("\n m = mostrar fila   		    ");
  	printf ("\n t = mostrar tamanho da fila ");
  	printf ("\n r = reinicializar fila      ");
  	printf ("\n s = sair         	  	    ");
  	printf ("\n=============================");
  	printf ("\n Escolha: "); fflush (stdin); opc = getche(); opc = tolower(opc);
  	system ("cls");
   	switch (opc) 
	{
      	case 'i' : 	inserirNaFila(F);			break;
      	case 'a' : 	
		  system ("cls"); system ("mode 110, 12");
		  if (atenderCliente(F, &r)==true)
      		printf ("\nCliente atendido: [%i-%s-%s-%s]", 
			r.chave, r.NOME, r.DATANASC, r.CPF);
      	  else
      	  	printf ("\nNao ha clientes para ser atendidos.");
		break;
   		case 'm' : exibirfila(F);				break;
   		case 't' : if ( estaVazia(F) == false )
	                    printf ("\n\nTamanho da fila = %d", tamanho(F));
	               else printf ("\n\nFILA VAZIA!");
	    break;
   		case 'r' : reinicializarFila(F);		
   				   printf ("\n\nFILA REINICIALIZADA!");
		break;
   		case 'd' : cadastraDefault(F);			break;
     	case 's' : exit(0); 					break;
		default  : msgErro();					break;
    }
	getch();
  }	
  return (0);
}
