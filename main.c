#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_PILHA 5
int pilha[TAMANHO_PILHA];
int topo = -1;

void inserir(int valor) {
    if (topo == TAMANHO_PILHA - 1) {
        printf("\nA pilha esta cheia. Nao e possivel inserir o elemento %d.\n", valor);
        return;
    }
    topo++;
    pilha[topo] = valor;
    //printf("Elemento %d inserido na pilha.\n", valor);
    return;
}
void remover() {
    if (topo == -1) {
        printf("\nA pilha esta vazia. Nao ha elementos para remover.\n");
        return;
    }
    int valorRemovido = pilha[topo];
    //pilha[topo] = 0;
    topo--;
    printf("\nElemento %d removido da pilha.\n", valorRemovido);
}

int buscar(int valor) {
    if (topo == -1) {
        printf("\nA pilha esta vazia. Nenhum elemento para buscar.\n");
        return -1;
    }

    for (int i = topo; i >= 0; i--) {
        if (pilha[i] == valor) {
            printf("\nValor %d encontrado na posicao %d da pilha.\n", valor, i);
            return i;
        }
    }
    printf("\nValor %d nao encontrado na pilha.\n", valor);
    return -1;
}

void imprimir() {
    if (topo == -1) {
        printf("\nA pilha esta vazia.\n");
        return;
    }
    printf("Pilha: ");
    for (int i = topo; i >= 0; i--)
        printf("%d ", pilha[i]);

    printf("\n");
    return;
}

int main() {
    int opcao, valor;

    do {
        printf("\nEscolha uma opcao:\n");
        printf("1. INSERIR \n");
        printf("2. REMOVER \n");
        printf("3. BUSCAR \n");
        printf("4. IMPRIMIR \n");
        printf("0. SAIR\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                inserir(valor);
                break;
            case 2:
                remover();
                break;
            case 3:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                buscar(valor);
                break;
            case 4:
                imprimir();
                break;
            case 0:
                printf("BYE...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
