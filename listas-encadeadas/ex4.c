#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 40

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct funcionario {
    int id;
    char nome[TAM_NOME+1];
    double salario;
    Data nascimento;
    struct funcionario *proximo;
    struct funcionario *anterior;
} Funcionario;

// Imprime a lista a partir do primeiro
void imprime_lista_primeiro(Funcionario *primeiro) {
    Funcionario *aux;
    printf("\nImprime a lista começando do primeiro: \n");
    if (primeiro == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    for (aux=primeiro; aux != NULL; aux=aux->proximo) {
        printf("Registro:\n\t id: %d, \n\t nome: %s, \n\t nasc: %d/%d/%d, \n\t salario: %lf\n\n",
                aux->id, aux->nome, aux->nascimento.dia,
                aux->nascimento.mes, aux->nascimento.ano, aux->salario);
    }
}

// Imprime a lista a partir do ultimo
void imprime_lista_ultimo(Funcionario *ultimo) {
    Funcionario *aux;
    printf("\nImprime a lista começando do ultimo: \n");
    if (ultimo == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    for (aux=ultimo; aux != NULL; aux=aux->proximo) {
        printf("Registro:\n\t id: %d, \n\t nome: %s, \n\t nasc: %d/%d/%d, \n\t salario: %lf\n\n",
                aux->id, aux->nome, aux->nascimento.dia,
                aux->nascimento.mes, aux->nascimento.ano, aux->salario);
    }
}

Funcionario* deleta_elemento(Funcionario *primeiro, Funcionario *ultimo, int key) {
    Funcionario *aux, *anterior;
    for (aux=primeiro; aux !=NULL; aux=aux->proximo) {
        if (aux->id == key) {
            if (aux == primeiro) {
                primeiro = primeiro->proximo;
                if (primeiro == NULL) { // se isso acontecer é porq a lista ficou vazia, ela só tinha um elemento e esse foi excluido. Então retorn null;
                    free(ultimo);
                    ultimo = NULL;
                    return NULL;
                }
                primeiro->anterior = NULL; // faz o anterior do novo primeiro ser null;
            }
            else if (aux ==  ultimo) {
                ultimo = ultimo->anterior;
                ultimo-> proximo = NULL;
            }
            else {
                anterior = aux->anterior;
                anterior->proximo = aux->proximo;
                aux->proximo->anterior = anterior;
            }
            free(aux);
        }
    }
    return primeiro;
}

void limpa_toda_lista(Funcionario *primeiro) {
    Funcionario *aux;
    while (primeiro != NULL) {
        aux = primeiro;
        primeiro = primeiro->proximo;
        free(aux);
    }
}

int main() {
    Funcionario *primeiro = NULL, *ultimo, *aux;
    int i, n;

    printf("Digite o número de valores: ");
    scanf("%d", &n);

    for (i=0; i<n; i++) {
        aux = malloc(sizeof(Funcionario));
        printf("\nDigite o id: \n");
        scanf("%d%*c", &aux->id); //o %*c representa ler um caractere mas não gravar, só outra forma de eliminar o '\n', pois ele atrapalha o fgets
		
        printf("\nDigite o nome: ");
        fgets(aux->nome, sizeof(aux->nome), stdin);
		aux->nome[strcspn(aux->nome, "\n")] = '\0';
        
        printf("\nDigite a data nascimento (formato dd/mm/yyyy): ");
        scanf("%d/%d/%d", &aux->nascimento.dia, &aux->nascimento.mes, &aux->nascimento.ano);
        
        printf("\nDigite o salario: ");
        scanf("%lf", &aux->salario);

        aux->proximo = NULL;
        aux->anterior = NULL;

        if (primeiro == NULL) { // ELe éo primeiro
            primeiro = aux;
            ultimo = aux;
        }
        else { // Faz o encadeamento inserindo o elemento ao final da lista
            aux-> anterior = ultimo;
            ultimo->proximo = aux;
            ultimo = aux;
        }
    }

    imprime_lista_primeiro(primeiro);

    imprime_lista_ultimo(ultimo);

    printf("\nExcluindo elemento com id 2\n");
	primeiro = deleta_elemento(primeiro, ultimo, 2); //deletando o 2, poderia fazer um scanf para pedir o elemento a ser excluido.
	/*Perceba que agora passamos o primeiro e o último elemento da lista, retornamos o primeiro, e o ultimo também será atualizado caso necessário já que é passado por referência.*/

	printf("\nImprimindo a lista após a exclusao: \n");
	/*Imprimindo a lista depois do delete*/
	imprime_lista_primeiro(primeiro);

	/*Antes de acabar o programa podemos limpar nossa lista.*/
	limpa_toda_lista(primeiro);

	printf("\nTerminamos!\n");


	return 0;
}

