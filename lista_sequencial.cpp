#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "portable_utils.h"

using namespace std;

typedef struct pessoa {
    string nome;
    int cpf;
}pessoa;

void alocar_vetor(pessoa **vetor, int tamanho) {
    *vetor = new pessoa[tamanho];
    //*vetor = (pessoa*) malloc(tamanho * sizeof(pessoa));
}

void imprimirSequencial(pessoa *vetor, int tamanhoListaSequencial) {

    for (int i=0; i < tamanhoListaSequencial; i++) {
        cout << "\nValor: " << i
        << "; Nome: " << vetor[i].nome
        << "; Cpf: " << vetor[i].cpf << ".";
    }

}


int main(){

    //int vetor[TAM] = {1,2,3};
    pessoa *vetor;
    int tamanhoLista;

    Clear();
    printf("Por favor digite o tamanho da lista desejada\n");
    printf("||");
    scanf("%d", &tamanhoLista);

    alocar_vetor(&vetor, tamanhoLista);

    for (int i=0; i<tamanhoLista; i++) {
        vetor[i].cpf = i;
        vetor[i].nome = "Nome_Generico_" + to_string(i);
    }

    imprimirSequencial(vetor, tamanhoLista);


    //free(vetor);
    delete[] vetor;

    return 0;
}