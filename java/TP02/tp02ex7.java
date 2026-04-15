import java.util.Scanner;

//Nome: João Gabriel da Silva e Gael Felix

/*  7. Entrar via teclado com doze valores e armazená-los em uma matriz 3x4.
   Solicitar uma constante multiplicativa, multiplicar cada elemento da
  matriz por ela e armazenar o resultado na própria matriz. */
public class tp02ex7 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        double[][] matriz = new double[3][4];
        System.out.println("Digite 12 valores para a matriz 3x4:");
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 4; j++) {
                System.out.print("Elemento [" + i + "][" + j + "]: ");
                matriz[i][j] = sc.nextDouble();
            }

        System.out.print("Digite a constante multiplicativa: ");
        double constante = sc.nextDouble();

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 4; j++)
                matriz[i][j] *= constante;

        System.out.println("\nMatriz após multiplicação por " + constante + ":");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++)
                System.out.printf("%10.2f", matriz[i][j]);
            System.out.println();
        }
        sc.close();
    }
}
