#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#include "portable_utils.h"

using namespace std;

typedef struct pessoa {
    string nome;
    int cpf;
}pessoa;

void alocar_lista(pessoa *&lista, int tamanho) {
    lista = new pessoa[tamanho];
}

void add_inicio_lista(pessoa *&lista, int *tamanho,string nome, int cpf) {
    pessoa *nova_lista;
    alocar_lista(nova_lista, *tamanho+1);

    nova_lista[0].nome = nome;
    nova_lista[0].cpf = cpf;

    for (int i=0; i<*tamanho;i++) {
        nova_lista[i+1].nome = lista[i].nome;
        nova_lista[i+1].cpf = lista[i].cpf;
    }

    delete[] lista;
    lista = nova_lista;
    *tamanho = *tamanho + 1;
}

void add_fim_lista(pessoa *&lista, int *tamanho,string nome, int cpf) {
    pessoa *nova_lista;
    alocar_lista(nova_lista, *tamanho+1);

    for (int i=0; i<*tamanho;i++) {
        nova_lista[i].nome = lista[i].nome;
        nova_lista[i].cpf = lista[i].cpf;
    }

    nova_lista[*tamanho].nome = nome;
    nova_lista[*tamanho].cpf = cpf;

    delete[] lista;
    lista = nova_lista;
    *tamanho = *tamanho + 1;
}

void add_lista_index(int index, pessoa *&lista, int *tamanho,string nome, int cpf) {
    pessoa *nova_lista;
    alocar_lista(nova_lista, *tamanho+1);

    for (int i=0; i<index;i++) {
        nova_lista[i].nome = lista[i].nome;
        nova_lista[i].cpf = lista[i].cpf;
    }

    nova_lista[index].nome = nome;
    nova_lista[index].cpf = cpf;

    for (int i=index; i<*tamanho;i++) {
        nova_lista[i+1].nome = lista[i].nome;
        nova_lista[i+1].cpf = lista[i].cpf;
    }

    delete[] lista;
    lista = nova_lista;
    *tamanho = *tamanho + 1;
}

void imprimirSequencial(pessoa *lista, int tamanho) {
    for (int i=0; i < tamanho; i++) {
        cout << "\nValor: " << i
        << "; Nome: " << lista[i].nome
        << "; Cpf: " << lista[i].cpf << ".";
        if (i == tamanho-1) {
            cout << "\n------------------------------------------------------------\n";
        }
    }
}


int main(){
    pessoa *lista;
    int tamanho;

    Clear();
    printf("Por favor digite o tamanho da lista desejada\n");
    printf("||");
    scanf("%d", &tamanho);

    alocar_lista(lista, tamanho);

    for (int i=0; i<tamanho; i++) {
        lista[i].cpf = i;
        lista[i].nome = "Nome_Generico_" + to_string(i);
    }
    imprimirSequencial(lista, tamanho);

    add_inicio_lista(lista, &tamanho, "Eduardo", 777);
    imprimirSequencial(lista, tamanho);

    add_fim_lista(lista, &tamanho, "Ed", 888);
    imprimirSequencial(lista, tamanho);

    add_lista_index(2, lista, &tamanho, "Edward", 123);
    imprimirSequencial(lista, tamanho);


    delete[] lista;
    return 0;
}