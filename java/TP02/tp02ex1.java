import java.util.Scanner;

//Nome: João Gabriel da Silva e Gael Felix

/* 1. Entrar com dois valores via teclado, onde o segundo valor deverá ser maior
que o primeiro. Caso contrário solicitar novamente apenas o segundo valor. */
public class tp02ex1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Digite o primeiro valor: ");
        double v1 = sc.nextDouble();

        double v2;
        do {
            System.out.print("Digite o segundo valor (deve ser maior que " + v1 + "): ");
            v2 = sc.nextDouble();
            if (v2 <= v1) {
                System.out.println("Erro: o segundo valor deve ser maior que o primeiro.");
            }
        } while (v2 <= v1);

        System.out.println("Valores aceitos: " + v1 + " e " + v2);
        sc.close();
    }
}
