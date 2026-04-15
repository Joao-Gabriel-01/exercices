import java.util.Scanner;

//Nome: João Gabriel da Silva e Gael Felix

// 6. Armazenar seis nomes em uma matriz de ordem 2x3.

public class tp02ex6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String[][] nomes = new String[2][3];
        System.out.println("Digite 6 nomes para a matriz 2x3:");
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++) {
                System.out.print("Nome [" + i + "][" + j + "]: ");
                nomes[i][j] = sc.next();
            }

        System.out.println("\nMatriz de nomes 2x3:");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++)
                System.out.printf("%-15s", nomes[i][j]);
            System.out.println();
        }
        sc.close();
    }
}
