// ============================================================
// Exercício 3 - Formato Agenda Telefônica
// "José Antonio Santos Silva" → "Silva, José Antonio Santos"
// ============================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

// Divide uma string em palavras pelo delimitador espaço
std::vector<std::string> splitWords(const std::string& linha) {
    std::vector<std::string> palavras;
    std::istringstream iss(linha);
    std::string palavra;
    while (iss >> palavra) {
        palavras.push_back(palavra);
    }
    return palavras;
}

// Formata nome para agenda: último sobrenome primeiro, vírgula, restante
std::string formatarAgenda(const std::string& nomeCompleto) {
    std::vector<std::string> partes = splitWords(nomeCompleto);

    if (partes.empty()) return nomeCompleto;
    if (partes.size() == 1) return partes[0];

    // Último nome vem primeiro
    std::string ultimo = partes.back();

    // Os demais nomes ficam depois da vírgula
    std::string restante;
    for (int i = 0; i < (int)partes.size() - 1; i++) {
        if (i > 0) restante += " ";
        restante += partes[i];
    }

    return ultimo + ", " + restante;
}

int main() {
    std::string nomeArquivo;

    std::cout << "=== Exercicio 3: Formato Agenda Telefonica ===" << std::endl;
    std::cout << "Nome do arquivo de nomes (ex: nomes.txt): ";
    std::getline(std::cin, nomeArquivo);

    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Erro: nao foi possivel abrir o arquivo \"" << nomeArquivo << "\"" << std::endl;
        return 1;
    }

    std::cout << "\n--- Resultado ---" << std::endl;
    std::cout << std::string(50, '-') << std::endl;

    std::string linha;
    while (std::getline(arquivo, linha)) {
        if (linha.empty()) continue;
        std::string formatado = formatarAgenda(linha);
        std::cout << "Original  : " << linha      << std::endl;
        std::cout << "Agenda    : " << formatado  << std::endl;
        std::cout << std::string(50, '-') << std::endl;
    }

    arquivo.close();
    return 0;
}
