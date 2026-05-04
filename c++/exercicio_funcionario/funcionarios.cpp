#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Funcionario {
    int prontuario;
    string nome;
    double salario;
};

vector<Funcionario> lista;

int buscarPorProntuario(int prontuario) {
    for (int i = 0; i < (int)lista.size(); i++) {
        if (lista[i].prontuario == prontuario)
            return i;
    }
    return -1;
}

void incluir() {
    Funcionario f;
    cout << "\n--- Incluir Funcionario ---\n";
    cout << "Prontuario: ";
    cin >> f.prontuario;
    cin.ignore();

    if (buscarPorProntuario(f.prontuario) != -1) {
        cout << "Erro: ja existe um funcionario com este prontuario!\n";
        return;
    }

    cout << "Nome: ";
    getline(cin, f.nome);
    cout << "Salario: ";
    cin >> f.salario;
    cin.ignore();

    lista.push_back(f);
    cout << "Funcionario incluido com sucesso!\n";
}

void excluir() {
    int prontuario;
    cout << "\n--- Excluir Funcionario ---\n";
    cout << "Prontuario: ";
    cin >> prontuario;
    cin.ignore();

    int idx = buscarPorProntuario(prontuario);
    if (idx == -1) {
        cout << "Funcionario nao encontrado!\n";
        return;
    }

    cout << "Funcionario \"" << lista[idx].nome << "\" removido com sucesso!\n";
    lista.erase(lista.begin() + idx);
}

void pesquisar() {
    int prontuario;
    cout << "\n--- Pesquisar Funcionario ---\n";
    cout << "Prontuario: ";
    cin >> prontuario;
    cin.ignore();

    int idx = buscarPorProntuario(prontuario);
    if (idx == -1) {
        cout << "Funcionario nao encontrado!\n";
        return;
    }

    cout << "\nProntuario : " << lista[idx].prontuario << "\n";
    cout << "Nome       : " << lista[idx].nome << "\n";
    cout << fixed << setprecision(2);
    cout << "Salario    : R$ " << lista[idx].salario << "\n";
}

void listar() {
    cout << "\n--- Lista de Funcionarios ---\n";
    if (lista.empty()) {
        cout << "Nenhum funcionario cadastrado.\n";
        return;
    }

    cout << fixed << setprecision(2);
    cout << left
         << setw(12) << "Prontuario"
         << setw(30) << "Nome"
         << setw(15) << "Salario" << "\n";
    cout << string(57, '-') << "\n";

    double total = 0;
    for (const auto& f : lista) {
        cout << left
             << setw(12) << f.prontuario
             << setw(30) << f.nome
             << "R$ " << setw(12) << f.salario << "\n";
        total += f.salario;
    }

    cout << string(57, '-') << "\n";
    cout << "Total de salarios: R$ " << total << "\n";
}

int main() {
    int opcao;
    do {
        cout << "\n============================\n";
        cout << "   GESTAO DE FUNCIONARIOS\n";
        cout << "============================\n";
        cout << "  0. Sair\n";
        cout << "  1. Incluir\n";
        cout << "  2. Excluir\n";
        cout << "  3. Pesquisar\n";
        cout << "  4. Listar\n";
        cout << "============================\n";
        cout << "Opcao: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 0: cout << "Encerrando...\n"; break;
            case 1: incluir();   break;
            case 2: excluir();   break;
            case 3: pesquisar(); break;
            case 4: listar();    break;
            default: cout << "Opcao invalida!\n";
        }
    } while (opcao != 0);

    return 0;
}
