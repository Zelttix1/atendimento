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
No* inicioMedicos = nullptr;
No* fimMedicos = nullptr;

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
    cout << "Removido do historico: " << aux->nome << endl;

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

void adicionarMedico(string nome) {
    No* novo = new No;
    novo->nome = nome;
    novo->urgencia = 0;
    novo->proximo = nullptr;

    if (fimMedicos == nullptr) {
        inicioMedicos = novo;
        fimMedicos = novo;
    } else {
        fimMedicos->proximo = novo;
        fimMedicos = novo;
    }
}

string chamarMedico() {
    if (inicioMedicos == nullptr) {
        return "";
    }

    No* aux = inicioMedicos;
    string nome = aux->nome;

    inicioMedicos = inicioMedicos->proximo;

    if (inicioMedicos == nullptr) {
        fimMedicos = nullptr;
    }

    delete aux;
    adicionarMedico(nome);

    return nome;
}

void percorrer() {
    if (inicioMedicos == nullptr) {
        cout << "Nenhum medico cadastrado." << endl;
        return;
    }

    No* atual = inicioMedicos;

    while (atual != nullptr) {
        cout << atual->nome << endl;
        atual = atual->proximo;
    }
}

void imprimirHistorico() {
    if (topoHistorico == nullptr) {
        cout << "Nenhum atendimento registrado." << endl;
        return;
    }

    No* auxiliar = nullptr;
    No* atual = topoHistorico;

    while (atual != nullptr) {
        No* novo = new No;
        novo->nome = atual->nome;
        novo->urgencia = atual->urgencia;
        novo->proximo = auxiliar;
        auxiliar = novo;

        atual = atual->proximo;
    }

    cout << "\nHistorico de atendimentos:\n";

    while (auxiliar != nullptr) {
        cout << auxiliar->nome << endl;

        No* temp = auxiliar;
        auxiliar = auxiliar->proximo;
        delete temp;
    }
}