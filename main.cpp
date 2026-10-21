#include <iostream>
#include <string>
using namespace std;

struct No {
    string nome;
    int urgencia;
    No* proximo;
};

No* inicioFila = nullptr;
No* fimFila = nullptr;
No* topoHistorico = nullptr;

void enqueue(string nome, int urgencia) {
    No* novo = new No;
    novo->nome = nome;
    novo->urgencia = urgencia;
    novo->proximo = nullptr;

    if (fimFila == nullptr) {
        inicioFila = novo;
        fimFila = novo;
    } else {
        fimFila->proximo = novo;
        fimFila = novo;
    }
}

void dequeue() {
    if (inicioFila == nullptr) {
        cout << "Fila vazia." << endl;
        return;
    }

    No* aux = inicioFila;
    cout << "Paciente removido: " << aux->nome << endl;

    inicioFila = inicioFila->proximo;

    if (inicioFila == nullptr) {
        fimFila = nullptr;
    }

    delete aux;
}

void frente_peak() {
    if (inicioFila == nullptr) {
        cout << "Fila vazia." << endl;
        return;
    }

    cout << "Proximo paciente: " << inicioFila->nome
         << " - Urgencia: " << inicioFila->urgencia << endl;
}

int tamanho() {
    int total = 0;
    No* atual = inicioFila;

    while (atual != nullptr) {
        total++;
        atual = atual->proximo;
    }

    return total;
}

void push(string nome) {
    No* novo = new No;
    novo->nome = nome;
    novo->urgencia = 0;
    novo->proximo = topoHistorico;

    topoHistorico = novo;
}

void pop() {
    if (topoHistorico == nullptr) {
        cout << "Historico vazio." << endl;
        return;
    }

    No* aux = topoHistorico;

    cout << "Removido do historico: "
         << aux->nome << endl;

    topoHistorico = topoHistorico->proximo;

    delete aux;
}

void peek() {
    if (topoHistorico == nullptr) {
        cout << "Historico vazio." << endl;
        return;
    }

    cout << "Ultimo atendimento: "
         << topoHistorico->nome << endl;
}