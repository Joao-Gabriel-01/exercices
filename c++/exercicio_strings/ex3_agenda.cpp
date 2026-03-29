
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


std::vector<std::string> splitWords(const std::string& linha) {
    std::vector<std::string> palavras;
    std::istringstream iss(linha);
    std::string palavra;
    while (iss >> palavra) {
        palavras.push_back(palavra);
    }
    return palavras;
}


std::string formatarAgenda(const std::string& nomeCompleto) {
    std::vector<std::string> partes = splitWords(nomeCompleto);

    if (partes.empty()) return nomeCompleto;
    if (partes.size() == 1) return partes[0];

   
    std::string ultimo = partes.back();

    
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
