
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

  
    int largura = 80;
    int colInicio = (largura - (int)msg.size()) / 2 + 1;
    if (colInicio < 1) colInicio = 1;

    for (int i = 0; i < (int)msg.size(); i++) {
      
        for (int linha = LINHA_INICIO; linha <= LINHA_FIM; linha++) {
           
            if (linha > LINHA_INICIO) {
                gotoxy(colInicio + i, linha - 1);
                std::cout << ' ';
            }
         
            gotoxy(colInicio + i, linha);
            std::cout << msg[i];
            std::cout.flush();
            sleep_ms(DELAY_MS);
        }
    }

    gotoxy(1, LINHA_FIM + 2);
    std::cout << "Pressione ENTER para sair...";
    std::cin.get();

    clearScreen();
    return 0;
}
