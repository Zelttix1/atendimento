#include <iostream>
#include <string>
#include <limits>
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

// FILA DE PACIENTES
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

    cout << "Paciente adicionado!\n";
}

void dequeue() {
    if (inicioFila == nullptr) {
        cout << "Fila vazia.\n";
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
        cout << "Fila vazia.\n";
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

// PILHA DE HISTORICO
void push(string nome) {
    No* novo = new No;
    novo->nome = nome;
    novo->urgencia = 0;
    novo->proximo = topoHistorico;
    topoHistorico = novo;

    cout << "Atendimento registrado!\n";
}

void pop() {
    if (topoHistorico == nullptr) {
        cout << "Historico vazio.\n";
        return;
    }

    No* aux = topoHistorico;
    cout << "Removido do historico: " << aux->nome << endl;

    topoHistorico = topoHistorico->proximo;
    delete aux;
}

void peek() {
    if (topoHistorico == nullptr) {
        cout << "Historico vazio.\n";
        return;
    }

    cout << "Ultimo atendimento: "
         << topoHistorico->nome << endl;
}

void imprimirHistorico() {
    if (topoHistorico == nullptr) {
        cout << "Nenhum atendimento registrado.\n";
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

// FILA DE MEDICOS COM RODIZIO
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

    cout << "Medico cadastrado!\n";
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
        cout << "Nenhum medico cadastrado.\n";
        return;
    }

    No* atual = inicioMedicos;

    cout << "\nMedicos cadastrados:\n";

    while (atual != nullptr) {
        cout << atual->nome << endl;
        atual = atual->proximo;
    }
}

// LIBERAR MEMORIA
void liberarMemoria() {
    while (inicioFila != nullptr) {
        No* temp = inicioFila;
        inicioFila = inicioFila->proximo;
        delete temp;
    }

    while (topoHistorico != nullptr) {
        No* temp = topoHistorico;
        topoHistorico = topoHistorico->proximo;
        delete temp;
    }

    while (inicioMedicos != nullptr) {
        No* temp = inicioMedicos;
        inicioMedicos = inicioMedicos->proximo;
        delete temp;
    }

    fimFila = nullptr;
    fimMedicos = nullptr;
}

// MENU PRINCIPAL
int main() {
    int opcao;

    do {
        cout << "\n===== SISTEMA HOSPITALAR =====\n";
        cout << "1 - Adicionar paciente\n";
        cout << "2 - Remover paciente\n";
        cout << "3 - Ver proximo paciente\n";
        cout << "4 - Quantidade de pacientes\n";
        cout << "5 - Registrar atendimento\n";
        cout << "6 - Remover do historico\n";
        cout << "7 - Ver ultimo atendimento\n";
        cout << "8 - Mostrar historico\n";
        cout << "9 - Cadastrar medico\n";
        cout << "10 - Chamar proximo medico\n";
        cout << "11 - Listar medicos\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";

        if (!(cin >> opcao)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string nome;
        int urgencia;

        switch (opcao) {
            case 1:
                cout << "Nome do paciente: ";
                getline(cin, nome);

                cout << "Urgencia (1-baixa, 2-media, 3-alta): ";
                if (cin >> urgencia) {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    enqueue(nome, urgencia);
                } else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Urgencia invalida.\n";
                }
                break;

            case 2:
                dequeue();
                break;

            case 3:
                frente_peak();
                break;

            case 4:
                cout << "Pacientes na fila: " << tamanho() << endl;
                break;

            case 5:
                cout << "Nome do paciente atendido: ";
                getline(cin, nome);
                push(nome);
                break;

            case 6:
                pop();
                break;

            case 7:
                peek();
                break;

            case 8:
                imprimirHistorico();
                break;

            case 9:
                cout << "Nome do medico: ";
                getline(cin, nome);
                adicionarMedico(nome);
                break;

            case 10: {
                string medico = chamarMedico();

                if (medico.empty()) {
                    cout << "Nenhum medico cadastrado.\n";
                } else {
                    cout << "Medico chamado: " << medico << endl;
                }
                break;
            }

            case 11:
                percorrer();
                break;

            case 0:
                cout << "Encerrando o sistema...\n";
                break;

            default:
                cout << "Opcao invalida.\n";
        }

    } while (opcao != 0);

    liberarMemoria();
    return 0;
}