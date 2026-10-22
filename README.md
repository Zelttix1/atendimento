# Sistema de Atendimento Hospitalar

Sistema desenvolvido em C++ para simular o atendimento de pacientes em um hospital.

## Funcionalidades

- Cadastro de pacientes com nível de urgência.
- Fila de atendimento de pacientes.
- Consulta do próximo paciente.
- Contagem de pacientes na fila.
- Histórico de atendimentos.
- Cadastro e rodízio de médicos.
- Relatório dos pacientes atendidos.

## Estruturas utilizadas

- **Fila:** gerenciamento dos pacientes.
- **Pilha:** armazenamento do histórico de atendimentos.
- **Lista encadeada:** gerenciamento dos médicos.

## Tecnologias

- C++
- Compilador compatível com C++17.

## Como executar

Compile o arquivo com o comando:

```bash
g++ -std=c++17 -Wall atendimento_template.cpp -o atendimento
```

Depois, execute:

```bash
./atendimento
```

No Windows, utilize:

```bash
atendimento.exe
```

## Objetivo

Praticar o uso de estruturas de dados em C++, utilizando alocação dinâmica de memória e listas encadeadas, sem utilizar containers da STL.

## Projeto acadêmico

Atividade desenvolvida para a disciplina de Engenharia de Software.
