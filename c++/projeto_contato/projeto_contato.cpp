#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Data {
private:
    int dia, mes, ano;

public:
    // construtor padrão
    Data() {
        dia = 1; mes = 1; ano = 2000;
    }
    // construtor parametrizado
    Data(int d, int m, int a) {
        dia = d; mes = m; ano = a;
    }

    int getDia() { return dia; }
    int getMes() { return mes; }
    int getAno() { return ano; }

    void setDia(int d) { dia = d; }
    void setMes(int m) { mes = m; }
    void setAno(int a) { ano = a; }
};

class Contato {
private:
    string nome;
    string email;
    string telefone;
    Data   dtnasc;

public:
    Contato() {}

    Contato(string n, string e, string t, Data d) {
        nome = n; email = e; telefone = t; dtnasc = d;
    }

    string getNome()     { return nome; }
    string getEmail()    { return email; }
    string getTelefone() { return telefone; }
    Data   getDtnasc()   { return dtnasc; }

    void setNome     (string n) { nome     = n; }
    void setEmail    (string e) { email    = e; }
    void setTelefone (string t) { telefone = t; }
    void setDtnasc   (Data   d) { dtnasc   = d; }

    int idade() {
        time_t agora = time(NULL);     
        tm* t = localtime(&agora);
        int anoAtual = 1900 + t->tm_year;
        int mesAtual = 1    + t->tm_mon;
        int diaAtual =        t->tm_mday;

        int id = anoAtual - dtnasc.getAno();
        if (mesAtual < dtnasc.getMes() ||
           (mesAtual == dtnasc.getMes() && diaAtual < dtnasc.getDia()))
            id--;
        return id;
    }
};


int main() {
    const int N = 5;
    Contato contatos[N];

    cout << "=== CADASTRO DE CONTATOS ===\n\n";

    for (int i = 0; i < N; i++) {
        string nome, email, tel;
        int dia, mes, ano;

        cout << "-- Contato " << (i+1) << " --\n";
        cout << "Nome     : "; getline(cin, nome);
        cout << "E-mail   : "; getline(cin, email);
        cout << "Telefone : "; getline(cin, tel);
        cout << "Nasc. (dd mm aaaa): ";
        cin >> dia >> mes >> ano;
        cin.ignore();
        cout << "\n";

        Data d(dia, mes, ano);
        contatos[i] = Contato(nome, email, tel, d);
    }

    cout << "\n=== LISTAGEM DE CONTATOS ===\n\n";
    cout << "Nome             | E-mail                  | Telefone        | Idade\n";
    cout << "-----------------+-------------------------+-----------------+------\n";

    for (int i = 0; i < N; i++) {
        cout << contatos[i].getNome()     << " | "
             << contatos[i].getEmail()    << " | "
             << contatos[i].getTelefone() << " | "
             << contatos[i].idade()       << " anos\n";
    }

    return 0;
}