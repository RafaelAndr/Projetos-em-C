#include <stdio.h>
#include <stdlib.h>
typedef struct reg {
	int chave;
    int conteudo;
    struct reg *pai;
    struct reg *esq;
    struct reg *dir;
}noh;

typedef noh* arvore;

// A seguinte funcao recebe um noh "n"
// e um inteiro "c" e retorna
// o noh n com o inteiro c inserido.
noh *insere (noh *n, int c) {
    n = malloc (sizeof(noh));
    n->chave = c;
    n->esq = NULL;
    n->dir = NULL;
    n->pai = NULL;
    return n;
}
//A seguinte funcao recebe
// um inteiro "c" e retorna
// um noh com chave "c"
noh *insere2 ( int c) {
    noh * n = malloc (sizeof(noh));
    n->chave = c;
    n->conteudo = c;
    n->esq = NULL;
    n->dir = NULL;
    n->pai = NULL;
    return n;
}



// A fun��o recebe uma �rvore de busca r
// e uma folha avulsa novo e insere a folha
// na �rvore de modo que a �rvore continue
// sendo de busca. A fun��o devolve a raiz 
// da �rvore resultante.
arvore insereBusc (arvore raiz, noh *novo) {  
    if (raiz == NULL) return novo;
    if (raiz->chave > novo->chave) 
       raiz->esq = insereBusc (raiz->esq, novo);
    else 
       raiz->dir = insereBusc (raiz->dir, novo);
    return raiz;
}

// A fun��o recebe uma recebe uma raiz
// e um inteiro chave, insere a chave em um 
// novo noh e depois insere o noh na raiz,
// e retorna a raiz.
arvore insereAuto (arvore raiz, int chave, int mod) {
	if (mod == 0) {	
		raiz = insere(raiz, chave);
		return raiz;
	}
	else {
		noh *novo = NULL;
		novo = insere(novo, chave);
		raiz = insereBusc(raiz, novo);
		return raiz;
	}
}
// Recebe uma arvore, uma chave e 
// retorna o nivel em que aquela chave est�;

int nivel(arvore raiz, int chave, int niv){
		arvore aux = raiz;
		if(aux == NULL)
			return -1;
		if(aux->chave < chave)
			return nivel(aux->dir, chave, niv+1);
		if(aux->chave > chave)
			return nivel(aux->esq, chave, niv+1);
		if(aux->chave == chave)
			return niv;
		return niv;
}

// A funcao recebe como argumento a raiz
// e um noh novo a ser inserido
// faz a inser��o de forma iterativa 
// e retorna a raiz

arvore insereIt (arvore raiz, arvore novo, int nivel) {
	arvore aux = raiz;
	arvore ant;
	if(aux == NULL)
		return novo;

	while(aux != NULL) {
		ant = aux;
		if(aux->chave < novo->chave)
			aux = aux->dir;
		else
			aux = aux->esq;
	}
	if(novo->chave > ant->chave) ant->dir = novo;
	
	else ant->esq = novo;
	return raiz;
}
// A funcao recebe como argumento a raiz
// e um noh novo a ser inserido
// faz a inser��o de forma recursiva
// e retorna a raiz

arvore insereItR(arvore raiz, arvore novo){
	if (raiz == NULL){
		return novo;
	}
	else{
		if(novo->chave > raiz->chave){
			raiz->dir = insereItR(raiz->dir, novo);
		}
		if(novo->chave == raiz->chave){
			return raiz;
		}
		if(novo->chave < raiz->chave){
			raiz->esq = insereItR(raiz->esq, novo);
		}
	}
	return raiz;
}
// A seguite funcao recebe dois valores inteiros que
// representam, o inicio de um array (crescente) 
// passado tambem como parametro e o final do mesmo, 
// a fun�ao tambem recebe uma arvore. A funcao divide 
// o array haje de forma recursiva sempre subdividindo
// o array e adicionando os elementos do meio na arvore
// de modo qe a mesma fique balanceada.
arvore divide (int inicio, int final, arvore raiz, int *arr, int cont) 
{
	if (inicio < final) {
		int meio = (inicio+final)/2;
		raiz = insereAuto(raiz, arr[meio], cont++);
		divide(inicio, meio, raiz, arr, cont);
		divide(meio+1, final, raiz, arr, cont);
	}
	return raiz;
}

// Recebe a raiz r de uma �rvore bin�ria
// e imprime os conte�dos dos seus n�s
// em ordem r-e-d.
void red (arvore raiz) {
   if (raiz != NULL) {
	  printf("%d\n", raiz->chave);
      red (raiz->esq);
      red (raiz->dir);
   }
}

// Recebe a raiz r de uma �rvore bin�ria e
// insere-os ordenadamente em um vetor vec.

void kth (arvore r,int vec[], int i) {

	if (r != NULL) {
	  kth (r->esq,vec, i++);
      vec[i] = r->conteudo;
      //printf("%d\n", r->conteudo);
      kth (r->dir,vec, i++); 
	}
   
}

/* A fun��o imprime os nos de uma
// arvore junto ao seu pai, pela ordem
// de prioridade r-e-d.
void redPai (arvore raiz) {

	if (raiz != NULL) {
		if (raiz->pai != NULL)
      		printf ("Pai: %d Filho: %d\n",raiz->pai->chave ,raiz->chave);
		else
			printf("Raiz: %d\n", raiz->chave);
		redPai (raiz->esq);
		redPai (raiz->dir); 
   	}
}
*/

// Recebe a raiz r de uma �rvore bin�ria e
// um inteiro cont que controla a profundidade 
// dos nos e imprime os conteudos dos seus nos 
// com suas respectivas distancias dando prioridade 
// a esquerda, sem valor de retorno. 
void imprimeBalanceado (arvore raiz, int cont) {
   if (raiz != NULL) {
       if (cont > 0) {
           int i;
           for (i = 0; i < cont; i++) printf("   ");
       }
       cont++;
       printf("%d\n", raiz->chave);
       if (raiz->esq == NULL) {
           int i;
           for (i = 0; i < cont; i++) 
               printf("   ");
           printf("-\n");
       }
       imprimeBalanceado (raiz->esq, cont);
       imprimeBalanceado (raiz->dir, cont);
       if (raiz->dir == NULL) {
           int i;
           for (i = 0; i < cont; i++)
               printf("   ");
           printf("-\n");
       }
       cont--;
   }
}

// Recebe uma �rvore n�o vazia r.
// Remove a raiz da �rvore e rearranja
// a �rvore de modo que ela continue sendo
// de busca. Devolve o endere�o
// da nova raiz.
arvore removeraiz (arvore r) {
	noh *p, *q;
	if (r->esq == NULL) {
		q = r->dir;
		free (r);
		return q;
	}
	p = r; q = r->esq;
	while (q->dir != NULL) {
		p = q; q = q->dir;
	}

	if (p != r) {
		p->dir = q->esq;
		q->esq = r->esq;
	}
	q->dir = r->dir;
	free (r);
	return q;
}

// Recebe um a raiz de uma arvore
// um inteiro x, e remove o noh
// que a chave e igual x,
// retorna a raiz.
arvore Buscaremove(arvore raiz, int x ) {
	if (raiz != NULL) {
		if (raiz->chave == x) {
			raiz = removeraiz(raiz);
			return raiz;
		}
		else if (x > raiz->chave) {
			raiz->dir = Buscaremove(raiz->dir, x);
		}
		else {
			raiz->esq = Buscaremove(raiz->esq, x);
		}
	}
	return raiz;
}

// Recebe uma arvore r
// e retorna a menor chave
// aquela mais a esquerda da raiz
int minkey (arvore r){
	int resp = -1;
	if(r != NULL) resp = r->chave;
	if(r->esq != NULL) resp = minkey(r->esq);
	return resp;
}

// Recebe uma arvore r
// e retorna a maior chave
// aquela mais a direita da raiz
int maxkey (arvore r) {
	int resp = -1;
	if(r != NULL)
		resp = r->chave;
	if(r->dir != NULL) resp = maxkey (r->dir);
	return resp;
}

// Recebe uma arvore r, um inteiro k
// e retorna a chave do proximo n�
// ao n� de chave K
int next (arvore r, int k, int aux){
	int resp = -1;
	if(r != NULL){
		if (r->chave < k){
			aux = r->chave;
			resp = next(r->dir,k, aux);
		}
		if (r->chave > k) {
			aux = r->chave;
			resp = next(r->esq, k, aux);
		}
		if(r->chave == k){
			if (r->dir == NULL) resp = aux;
			else resp = r->dir->chave;
		}
	}
	return resp;
}

int previous (arvore r, int k, int aux) {
	int resp = -1;
	if(r != NULL){
		if (r->chave < k){
			aux = r->chave;
			resp = next(r->dir,k, aux);
		}
		if (r->chave > k) {
			aux = r->chave;
			resp = next(r->esq, k, aux);
		}
		if(r->chave == k){
			if (r->esq == NULL) resp = aux;
			else resp = r->esq->chave;
		}
	}
	return resp;
}


int next (arvore r, int k) {
	int resp = -1;
	if (r.chave < k)
		resp = next(r->esq, k);
	if (r.chave > k)
		resp = next(r-dir, k);
	if(r.chave == k){
		if(r->dir != NULL) resp = r->dir->chave;
		else resp = r->pai->chave;
	}
   return resp;
}
 * 
 maior que
int Busc(arvore r, int key) {
	int resp = -1;
	if(r != NULL ) {
		if(r->chave > key) resp = Busc(r->esq, key);	
		if (r->chave < key) resp = Busc (r->dir, key);
		if(r->chave == key) {
					if(r->dir != NULL) resp = minkey(r->dir);
					else resp = r->pai->chave;
				}
		}
	return resp;
}


// Recebe uma arvore "raiz", um vetor de int
// e um inteiro "i" e insere os conteudos da arvore
// no vetor de forma crescente, a fun��o retorna um inteiro
// que controla as posi��es do vetor.
int arvVec (arvore raiz, int vec[], int i) {
	if (raiz != NULL) {
		i = arvVec (raiz->esq, vec, i);
		vec[i++] = raiz->chave;
		i = arvVec (raiz->dir, vec, i);
	}
	return i;
}

// Essa fun��o recebe uma arvore T
// e imprime de forma balanceada
// usando parenteses para indicar os niveis 
void print_brackets(arvore T){
    if(T != NULL){
        printf(" %d  (",T->chave);
        print_brackets(T->esq);
        printf(")  (");
        print_brackets(T->dir);
        printf(") ");
    }
}
// recebe uma arvore "raiz" e um inteiro "x" e retorna
// quantos n�meros s�o maiores que seu inteiro "x".

int maiores(arvore raiz, int x, int aux2){
	arvore aux = raiz;
	while(aux != NULL){
		if(x == aux->chave){
			return maiores(aux->dir, x, aux2);
			return maiores(aux->esq, x, aux2);
		}
		if(x > aux->chave){
			return maiores(aux->dir, x, aux2);
			return maiores(aux->esq, x, aux2);
		}
		if(x < aux->chave){
			return maiores(aux->dir, x, aux2+1);
			return maiores(aux->esq, x, aux2+1);
		}
	}
	return aux2;
	
}	

int main (void) {
	int i;
	//int aux[12];
	arvore raiz = NULL;
	//arvore new = NULL;
	for (i = 0; i < 5; i++){
		int vec;
		scanf("%d", &vec);
		arvore aux = insere2(vec);
		raiz = insereItR(raiz,aux);
		print_brackets(raiz);
		printf("\n");
	}
	//raiz = divide(0, 12, raiz, vec, 0);
	imprimeBalanceado (raiz, 0);
	putchar('\n');
	printf ("%d\n", next(raiz, 50, 0));
	printf ("%d\n", previous(raiz, 50, 0)); 
	putchar('\n');
	printf ("Depois da remomover o noh com chave 2\n");
	raiz = Buscaremove(raiz, 2);
	imprimeBalanceado (raiz, 0);
	print_brackets(raiz);
	//print_brackets(raiz);
	//putchar('\n');
	//printf("%d\n", minkey(raiz));
	//rintf("%d\n", maxkey(raiz));
	//printf("%d\n", Busc(raiz, 40));
	//x = arvVec(raiz, aux, 0);
	//for(i = 0; i < 12; i++) printf ("%d ", aux[i]);
	//putchar ('\n');
	//printf ("%d\n", x);
	//putchar('\n');
	//new = divide(0,12, new, aux, 0);
	//imprimeBalanceado(new, 0);
    return 0;
}

int main(){
	
	int T, N, C, X;
	int i = 0, j = 0;
	scanf("%d", &T);
	
	for(i = 0; i<T; i++){
		arvore raiz = NULL;
		int quant = 0;
		
		scanf("%d", &N);
		
		for(j = 0; j < N; j++){
			scanf("%d %d", &C, &X);
			if(C == 1){ //Insere
				arvore aux = insere2(X);
				raiz = insereItR(raiz, aux);
				printf("%d\n", nivel(raiz, X, 0));
				quant++;
			}
			if(C == 2){ //Remove
				printf("%d\n", nivel(raiz, X, 0));
				if(nivel(raiz, X, 0) != -1){
					raiz = Buscaremove(raiz, X);
					quant--;
				}
			}
			if(C == 3){ //Maiores
				int mai = maiores(raiz, X, 0);
				printf("%d\n", mai);
			}
			if(C == 4){ // K-�simo n�mero
				int vec[quant];
				vec[0] = minkey(raiz);
				kth (raiz,vec, 0);
				//int l = 0;
				//for(l = 0; l < quant; l++){
				//	printf("vec[%d] : %d\n", l, vec[l]);
				//}
				printf("%d\n", vec[X-1]);

			}
		}
		printf("\n");
		//imprimeBalanceado (raiz, 0);
	}

	return 0;
}


