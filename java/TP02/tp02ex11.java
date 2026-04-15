import java.util.Scanner;

//Nome: João Gabriel da Silva e Gael Felix

/*  11. Entrar com uma matriz quadrada MxM, onde a ordem também será escolhida
    pelo usuário, sendo no máximo 10x10. Após a digitação dos elementos,
    calcular e exibir o determinante da matriz. */
public class tp02ex11 {
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

        System.out.printf("%nDeterminante: %.4f%n", determinante(matriz, m));
        sc.close();
    }

   
    static double determinante(double[][] mat, int n) {
        double[][] a = new double[n][n];
        for (int i = 0; i < n; i++)
            a[i] = mat[i].clone();

        double det = 1;
        for (int col = 0; col < n; col++) {
            int pivotRow = -1;
            for (int row = col; row < n; row++) {
                if (Math.abs(a[row][col]) > 1e-9) { pivotRow = row; break; }
            }
            if (pivotRow == -1) return 0; 

            if (pivotRow != col) {
                double[] tmp = a[col]; a[col] = a[pivotRow]; a[pivotRow] = tmp;
                det *= -1;
            }

            det *= a[col][col];
            double pivo = a[col][col];
            for (int j = col; j < n; j++)
                a[col][j] /= pivo;

            for (int row = col + 1; row < n; row++) {
                double fator = a[row][col];
                for (int j = col; j < n; j++)
                    a[row][j] -= fator * a[col][j];
            }
        }
        return det;
    }
}
