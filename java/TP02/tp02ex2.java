import java.util.Scanner;

//Nome: João Gabriel da Silva e Gael Felix

/*  2. Entrar via teclado com dez valores positivos. Consistir a digitação e
enviar mensagem de erro, se necessário. Após a digitação, exibir:
a. O maior valor;
b. A soma dos valores;
c. A média aritmética dos valores.*/
public class tp02ex2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        double[] valores = new double[10];
        for (int i = 0; i < 10; i++) {
            double v;
            do {
                System.out.print("Digite o " + (i + 1) + "º valor positivo: ");
                v = sc.nextDouble();
                if (v <= 0) {
                    System.out.println("Erro: o valor deve ser positivo.");
                }
            } while (v <= 0);
            valores[i] = v;
        }

        double maior = valores[0], soma = 0;
        for (double v : valores) {
            if (v > maior) maior = v;
            soma += v;
        }

        System.out.println("\n--- Resultados ---");
        System.out.println("Maior valor: " + maior);
        System.out.println("Soma: " + soma);
        System.out.printf("Média aritmética: %.2f%n", soma / 10);
        sc.close();
    }
}
