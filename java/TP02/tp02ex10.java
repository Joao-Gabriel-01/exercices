import java.util.Scanner;

//Nome: João Gabriel da Silva e Gael Felix

/*  10. Entrar com uma matriz quadrada MxM, onde a ordem também será escolhida
    pelo usuário, sendo no máximo 10x10. Após a digitação dos elementos,
    calcular e exibir a matriz inversa. Exibir as matrizes na forma
    matricial (linhas x colunas). */
public class tp02ex10 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int m;
        do {
            System.out.print("Digite a ordem da matriz quadrada M (1 a 10): ");
            m = sc.nextInt();
            if (m < 1 || m > 10) System.out.println("Erro: M deve estar entre 1 e 10.");
        } while (m < 1 || m > 10);

        double[][] matriz = new double[m][m];
        System.out.println("Digite os elementos da matriz " + m + "x" + m + ":");
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++) {
                System.out.print("Elemento [" + i + "][" + j + "]: ");
                matriz[i][j] = sc.nextDouble();
            }

        double[][] aug = new double[m][2 * m];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++)
                aug[i][j] = matriz[i][j];
            aug[i][i + m] = 1;
        }

        for (int col = 0; col < m; col++) {
            int pivotRow = -1;
            for (int row = col; row < m; row++) {
                if (Math.abs(aug[row][col]) > 1e-9) { pivotRow = row; break; }
            }
            if (pivotRow == -1) {
                System.out.println("Erro: a matriz é singular e não possui inversa.");
                sc.close();
                return;
            }
            double[] tmp = aug[col];
            aug[col] = aug[pivotRow];
            aug[pivotRow] = tmp;

            double pivo = aug[col][col];
            for (int j = 0; j < 2 * m; j++)
                aug[col][j] /= pivo;

            for (int row = 0; row < m; row++) {
                if (row != col) {
                    double fator = aug[row][col];
                    for (int j = 0; j < 2 * m; j++)
                        aug[row][j] -= fator * aug[col][j];
                }
            }
        }

        double[][] inversa = new double[m][m];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                inversa[i][j] = aug[i][j + m];

        System.out.println("\nMatriz original (" + m + "x" + m + "):");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++)
                System.out.printf("%10.4f", matriz[i][j]);
            System.out.println();
        }

        System.out.println("\nMatriz inversa (" + m + "x" + m + "):");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++)
                System.out.printf("%10.4f", inversa[i][j]);
            System.out.println();
        }
        sc.close();
    }
}
