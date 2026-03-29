// ============================================================
// Exercício 1 - Cascata de Letras
// Recebe uma mensagem e faz cada letra "cair" da linha 5 até 20
// ============================================================
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#ifdef _WIN32
  #include <windows.h>
  void gotoxy(int x, int y) {
      COORD coord = {(SHORT)(x-1), (SHORT)(y-1)};
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
  }
  void clearScreen() { system("cls"); }
#else
  #include <cstdio>
  void gotoxy(int x, int y) {
      printf("\033[%d;%dH", y, x);
      fflush(stdout);
  }
  void clearScreen() { printf("\033c"); fflush(stdout); }
#endif

void sleep_ms(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

int main() {
    const int LINHA_INICIO = 5;
    const int LINHA_FIM    = 20;
    const int DELAY_MS     = 80;

    std::string msg;
    clearScreen();

    gotoxy(1, 1);
    std::cout << "=== Exercicio 1: Cascata ===" << std::endl;
    gotoxy(1, 2);
    std::cout << "Digite a mensagem: ";
    std::getline(std::cin, msg);

    clearScreen();

    // Calcula coluna inicial para centralizar (assumindo largura 80)
    int largura = 80;
    int colInicio = (largura - (int)msg.size()) / 2 + 1;
    if (colInicio < 1) colInicio = 1;

    // Para cada letra, ela cai individualmente
    for (int i = 0; i < (int)msg.size(); i++) {
        // Mostra a letra caindo da linha 5 até a linha 20
        for (int linha = LINHA_INICIO; linha <= LINHA_FIM; linha++) {
            // Apaga posição anterior
            if (linha > LINHA_INICIO) {
                gotoxy(colInicio + i, linha - 1);
                std::cout << ' ';
            }
            // Desenha letra na posição atual
            gotoxy(colInicio + i, linha);
            std::cout << msg[i];
            std::cout.flush();
            sleep_ms(DELAY_MS);
        }
        // Letra chegou à linha 20 — deixa ela lá e passa para a próxima
    }

    // Posiciona cursor abaixo da animação para não sobrescrever
    gotoxy(1, LINHA_FIM + 2);
    std::cout << "Pressione ENTER para sair...";
    std::cin.get();

    clearScreen();
    return 0;
}
