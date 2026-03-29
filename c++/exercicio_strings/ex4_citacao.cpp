#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

// Divide linha em palavras
std::vector<std::string> splitWords(const std::string& linha) {
    std::vector<std::string> palavras;
    std::istringstream iss(linha);
    std::string palavra;
    while (iss >> palavra) {
        palavras.push_back(palavra);
    }
    return palavras;
}

// Converte string para maiúsculas
std::string toUpper(const std::string& s) {
    std::string r = s;
    for (char& c : r) c = toupper((unsigned char)c);
    return r;
}

// Retorna apenas a primeira letra maiúscula seguida de ponto: "Antonio" → "A."
std::string inicial(const std::string& nome) {
    if (nome.empty()) return "";
    std::string r;
    r += toupper((unsigned char)nome[0]);
    r += '.';
    return r;
}

// Formata nome para citação bibliográfica
// Estrutura esperada: PrimeiroNome [MeioNome...] Sobrenome
// Resultado: SOBRENOME, PrimeiroNome I. I.
std::string formatarCitacao(const std::string& nomeCompleto) {
    std::vector<std::string> partes = splitWords(nomeCompleto);

    if (partes.empty()) return nomeCompleto;
    if (partes.size() == 1) return toUpper(partes[0]);

    // Último elemento = sobrenome em maiúsculas
    std::string sobrenome = toUpper(partes.back());

    // Primeiro nome = completo
    std::string primeiroNome = partes[0];

    // Nomes do meio = apenas iniciais
    std::string meios;
    for (int i = 1; i < (int)partes.size() - 1; i++) {
        meios += " " + inicial(partes[i]);
    }

    return sobrenome + ", " + primeiroNome + meios;
}

int main() {
    std::string nomeArquivo;

    std::cout << "=== Exercicio 4: Formato Citacao Bibliografica ===" << std::endl;
    std::cout << "Nome do arquivo de nomes (ex: nomes.txt): ";
    std::getline(std::cin, nomeArquivo);

    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Erro: nao foi possivel abrir o arquivo \"" << nomeArquivo << "\"" << std::endl;
        return 1;
    }

    std::cout << "\n--- Resultado ---" << std::endl;
    std::cout << std::string(55, '-') << std::endl;

    std::string linha;
    while (std::getline(arquivo, linha)) {
        if (linha.empty()) continue;
        std::string formatado = formatarCitacao(linha);
        std::cout << "Original  : " << linha     << std::endl;
        std::cout << "Citacao   : " << formatado << std::endl;
        std::cout << std::string(55, '-') << std::endl;
    }

    arquivo.close();
    return 0;
}
