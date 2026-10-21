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

int main() {
    int opcao;

    do {
        cout << "\nFila de Pacientes\n";
        cout << "1 - Cadastrar paciente\n";
        cout << "2 - Remover primeiro paciente\n";
        cout << "3 - Ver proximo paciente\n";
        cout << "4 - Mostrar tamanho da fila\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        if (opcao == 1) {
            string nome;
            int urgencia;

            cout << "Nome do paciente: ";
            cin.ignore(10000, '\n');
            getline(cin, nome);

            cout << "Urgencia (1-baixa, 2-media, 3-alta): ";
            cin >> urgencia;

            if (urgencia >= 1 && urgencia <= 3) {
                enqueue(nome, urgencia);
                cout << "Paciente cadastrado." << endl;
            } else {
                cout << "Urgencia invalida." << endl;
            }
        } else if (opcao == 2) {
            dequeue();
        } else if (opcao == 3) {
            frente_peak();
        } else if (opcao == 4) {
            cout << "Total na fila: " << tamanho() << endl;
        } else if (opcao != 0) {
            cout << "Opcao invalida." << endl;
        }

    } while (opcao != 0);

    while (inicioFila != nullptr) {
        No* aux = inicioFila;
        inicioFila = inicioFila->proximo;
        delete aux;
    }

    fimFila = nullptr;

    return 0;
}