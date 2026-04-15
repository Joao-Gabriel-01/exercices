import java.util.Scanner;

//Nome: João Gabriel da Silva e Gael Felix

/*  4. Armazenar seis valores em uma matriz de ordem 2x3.
    Apresentar os valores na tela. */
public class tp02ex4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        double[][] matriz = new double[2][3];
        System.out.println("Digite 6 valores para a matriz 2x3:");
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++) {
                System.out.print("Elemento [" + i + "][" + j + "]: ");
                matriz[i][j] = sc.nextDouble();
            }

        System.out.println("\nMatriz 2x3:");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++)
                System.out.printf("%8.2f", matriz[i][j]);
            System.out.println();
        }
        sc.close();
    }
}
