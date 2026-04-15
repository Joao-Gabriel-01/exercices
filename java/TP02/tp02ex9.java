import java.util.Scanner;

//Nome: João Gabriel da Silva e Gael Felix

/*  9. Entrar com uma matriz de ordem MxN, onde a ordem também será escolhida
pelo usuário, sendo no máximo 10x10. A matriz não precisa ser quadrática.
Após a digitação dos elementos, calcular e exibir a matriz transposta. */
public class tp02ex9 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int m, n;
        do {
            System.out.print("Digite o número de linhas M (1 a 10): ");
            m = sc.nextInt();
            if (m < 1 || m > 10) System.out.println("Erro: M deve estar entre 1 e 10.");
        } while (m < 1 || m > 10);

        do {
            System.out.print("Digite o número de colunas N (1 a 10): ");
            n = sc.nextInt();
            if (n < 1 || n > 10) System.out.println("Erro: N deve estar entre 1 e 10.");
        } while (n < 1 || n > 10);

        double[][] matriz = new double[m][n];
        System.out.println("Digite os elementos da matriz " + m + "x" + n + ":");
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                System.out.print("Elemento [" + i + "][" + j + "]: ");
                matriz[i][j] = sc.nextDouble();
            }

        double[][] transposta = new double[n][m];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                transposta[j][i] = matriz[i][j];

        System.out.println("\nMatriz original (" + m + "x" + n + "):");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                System.out.printf("%8.2f", matriz[i][j]);
            System.out.println();
        }

        System.out.println("\nMatriz transposta (" + n + "x" + m + "):");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                System.out.printf("%8.2f", transposta[i][j]);
            System.out.println();
        }
        sc.close();
    }
}
