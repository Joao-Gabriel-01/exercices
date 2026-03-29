
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_BARALHOS       2
#define CARTAS_POR_BARALHO 52
#define NUM_NAIPES         4
#define NUM_NUMEROS        13
#define NUM_JOGADORES      4
#define CARTAS_MAO         11
#define TOTAL_CARTAS       104   
#define TAM_COD            5     


char baralho[NUM_BARALHOS][CARTAS_POR_BARALHO][TAM_COD];
char mao[NUM_JOGADORES][CARTAS_MAO][TAM_COD];

void gerarCodigo(char* buf, int naipe, int numero, int bnum) {
    sprintf(buf, "%d%02d%d", naipe, numero, bnum);
}

void inicializarBaralhos() {
    int b, naipe, num, idx;
    for (b = 0; b < NUM_BARALHOS; b++) {
        idx = 0;
        for (naipe = 1; naipe <= NUM_NAIPES; naipe++) {
            for (num = 1; num <= NUM_NUMEROS; num++) {
                gerarCodigo(baralho[b][idx], naipe, num, b + 1);
                idx++;
            }
        }
    }
}

void trocarCarta(char* a, char* b) {
    char tmp[TAM_COD];
    strcpy(tmp, a);
    strcpy(a, b);
    strcpy(b, tmp);
}

void embaralhar(char deck[][TAM_COD], int total) {
    int i, j;
    for (i = total - 1; i > 0; i--) {
        j = rand() % (i + 1);
        trocarCarta(deck[i], deck[j]);
    }
}

void distribuirCartas() {
    char deck[TOTAL_CARTAS][TAM_COD];
    int b, c, j, idx;
    idx = 0;
    for (b = 0; b < NUM_BARALHOS; b++)
        for (c = 0; c < CARTAS_POR_BARALHO; c++) {
            strcpy(deck[idx], baralho[b][c]);
            idx++;
        }

    embaralhar(deck, TOTAL_CARTAS);
    idx = 0;
    for (c = 0; c < CARTAS_MAO; c++)
        for (j = 0; j < NUM_JOGADORES; j++) {
            strcpy(mao[j][c], deck[idx]);
            idx++;
        }
}

const char* nomeNaipe(char n) {
    switch (n) {
        case '1': return "Copas  ";
        case '2': return "Paus   ";
        case '3': return "Ouro   ";
        case '4': return "Espada ";
        default:  return "?      ";
    }
}

const char* nomeNumero(const char* cod) {
    char buf[3];
    buf[0] = cod[1]; buf[1] = cod[2]; buf[2] = '\0';
    int n = atoi(buf);
    switch (n) {
        case  1: return "As    ";
        case 11: return "Valete";
        case 12: return "Dama  ";
        case 13: return "Rei   ";
        case  2: return "2     ";
        case  3: return "3     ";
        case  4: return "4     ";
        case  5: return "5     ";
        case  6: return "6     ";
        case  7: return "7     ";
        case  8: return "8     ";
        case  9: return "9     ";
        case 10: return "10    ";
        default: return "?     ";
    }
}
void exibirCarta(const char* cod) {
    if (strlen(cod) < 4) {
        cout << "  [????]";
        return;
    }
    cout << "  [" << cod << "]  "
         << nomeNaipe(cod[0])
         << "- " << nomeNumero(cod)
         << " (Baralho " << cod[3] << ")";
}
void exibirBaralhos() {
    int b, c;
    cout << "\n============================================================\n";
    cout << "  BARALHOS INICIALIZADOS (antes do embaralhamento)\n";
    cout << "============================================================\n";

    for (b = 0; b < NUM_BARALHOS; b++) {
        cout << "\n  --- Baralho " << (b + 1) << " ---\n";
        for (c = 0; c < CARTAS_POR_BARALHO; c++) {
            printf("  baralho[%d][%2d] = \"%s\"", b, c, baralho[b][c]);
            exibirCarta(baralho[b][c]);
            cout << "\n";
        }
    }
}

const char* nomeJogador(int j) {
    switch (j) {
        case 0: return "Jogador 1 (Norte)";
        case 1: return "Jogador 2 (Leste)";
        case 2: return "Jogador 3 (Sul)  ";
        case 3: return "Jogador 4 (Oeste)";
        default: return "Jogador ?";
    }
}

void exibirMaos() {
    int j, c;
    cout << "\n============================================================\n";
    cout << "  MAOS DOS JOGADORES (apos embaralhamento e distribuicao)\n";
    cout << "============================================================\n";

    for (j = 0; j < NUM_JOGADORES; j++) {
        cout << "\n  *** " << nomeJogador(j) << " ***\n";
        for (c = 0; c < CARTAS_MAO; c++) {
            printf("  mao[%d][%2d] = \"%s\"", j, c, mao[j][c]);
            exibirCarta(mao[j][c]);
            cout << "\n";
        }
    }
}

void exibirMaosCompacto() {
    const char* naipes[] = { "", "Copa", "Paus", "Ouro", "Espa" };
    const char* nums[]   = { "", "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
    int j, c, naipe, num, bnum;
    char buf[3];

    cout << "\n============================================================\n";
    cout << "  VISAO COMPACTA DAS MAOS\n";
    cout << "============================================================\n";

    for (j = 0; j < NUM_JOGADORES; j++) {
        cout << "\n  " << nomeJogador(j) << ": ";
        for (c = 0; c < CARTAS_MAO; c++) {
            const char* cod = mao[j][c];
            naipe = cod[0] - '0';
            buf[0] = cod[1]; buf[1] = cod[2]; buf[2] = '\0';
            num  = atoi(buf);
            bnum = cod[3] - '0';
            cout << "[" << naipes[naipe] << "-" << nums[num];
            if (bnum == 2) cout << "'";
            cout << "] ";
        }
        cout << "\n";
    }
    cout << "\n  Legenda: ' = baralho 2 | A=As J=Valete Q=Dama K=Rei\n";
}

int main() {
    srand((unsigned)time(NULL));

    cout << "\n+--------------------------------------+\n";
    cout << "|        PROJETO BURACO - C++          |\n";
    cout << "|  2 baralhos | 4 jogadores | 11 cartas|\n";
    cout << "+--------------------------------------+\n";

    // 1. inicializa os baralhos
    inicializarBaralhos();

    // 2. exibe estrutura dos baralhos antes do embaralhamento
    exibirBaralhos();

    // 3. embaralha e distribui
    distribuirCartas();

    // 4. exibe as maos detalhadas
    exibirMaos();

    // 5. exibe visao compacta
    exibirMaosCompacto();

    cout << "\n============================================================\n";
    cout << "  Total de cartas no baralho : " << TOTAL_CARTAS << "\n";
    cout << "  Cartas distribuidas         : " << NUM_JOGADORES * CARTAS_MAO << "\n";
    cout << "  Cartas restantes no monte   : "
         << TOTAL_CARTAS - NUM_JOGADORES * CARTAS_MAO << "\n";
    cout << "============================================================\n\n";

    return 0;
}
