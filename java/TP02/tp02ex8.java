import java.util.Scanner;

//Nome: João Gabriel da Silva e Gael Felix

/*  8. Entrar via teclado com doze valores e armazená-los em uma matriz 3x4.
Solicitar uma constante multiplicativa, multiplicar cada elemento e
armazenar o resultado em outra matriz de mesma ordem.
Exibir ambas as matrizes na forma matricial (linhas x colunas). */
public class tp02ex8 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        double[][] matrizA = new double[3][4];
        double[][] matrizB = new double[3][4];

        System.out.println("Digite 12 valores para a matriz A (3x4):");
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 4; j++) {
                System.out.print("A[" + i + "][" + j + "]: ");
                matrizA[i][j] = sc.nextDouble();
            }

        System.out.print("Digite a constante multiplicativa: ");
        double constante = sc.nextDouble();

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 4; j++)
                matrizB[i][j] = matrizA[i][j] * constante;

        System.out.println("\nMatriz A (original):");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++)
                System.out.printf("%10.2f", matrizA[i][j]);
            System.out.println();
        }

        System.out.println("\nMatriz B (resultado * " + constante + "):");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++)
                System.out.printf("%10.2f", matrizB[i][j]);
            System.out.println();
        }
        sc.close();
    }
}
