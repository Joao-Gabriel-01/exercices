// ============================================================
// Exercício 2 - Verificação de Palíndromo
// Ignora espaços na verificação
// ============================================================
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    std::string msg;

    std::cout << "=== Exercicio 2: Palindromo ===" << std::endl;
    std::cout << "Digite a mensagem: ";
    std::getline(std::cin, msg);

    // Remove espaços e converte para maiúsculas
    std::string limpa;
    for (char c : msg) {
        if (c != ' ') {
            limpa += toupper((unsigned char)c);
        }
    }

    // Verifica palíndromo comparando com o reverso
    std::string reverso = limpa;
    std::reverse(reverso.begin(), reverso.end());

    std::cout << "\nMensagem original : \"" << msg << "\"" << std::endl;
    std::cout << "Sem espacos (maiusc): \"" << limpa << "\"" << std::endl;
    std::cout << "Invertido          : \"" << reverso << "\"" << std::endl;

    if (limpa == reverso) {
        std::cout << "\nResultado: SIM, e um PALINDROMO! ✓" << std::endl;
    } else {
        std::cout << "\nResultado: NAO, nao e um palindromo. ✗" << std::endl;
    }

    return 0;
}
