import java.util.Scanner;

//Nome: João Gabriel da Silva e Gael Felix

/* 3. Entrar via teclado com "N" valores quaisquer. O valor "N" deverá ser
positivo e menor que vinte. Caso não satisfaça, enviar mensagem de erro
e solicitar novamente. Após a digitação, exibir:
    a. O maior valor;
    b. O menor valor;
    c. A soma dos valores;
    d. A média aritmética dos valores;
    e. A porcentagem de valores positivos;
    f. A porcentagem de valores negativos.
Perguntar se deseja nova execução, aceitando somente "S" ou "N". */
public class tp02ex3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String repetir;

        do {
            int n;
            do {
                System.out.print("Digite a quantidade de valores N (positivo e menor que 20): ");
                n = sc.nextInt();
                if (n <= 0 || n >= 20) {
                    System.out.println("Erro: N deve ser positivo e menor que 20.");
                }
            } while (n <= 0 || n >= 20);

            double[] valores = new double[n];
            for (int i = 0; i < n; i++) {
                System.out.print("Digite o " + (i + 1) + "º valor: ");
                valores[i] = sc.nextDouble();
            }

            double maior = valores[0], menor = valores[0], soma = 0;
            int positivos = 0, negativos = 0;
            for (double v : valores) {
                if (v > maior) maior = v;
                if (v < menor) menor = v;
                soma += v;
                if (v > 0) positivos++;
                else if (v < 0) negativos++;
            }

            System.out.println("\n--- Resultados ---");
            System.out.println("Maior valor: " + maior);
            System.out.println("Menor valor: " + menor);
            System.out.println("Soma: " + soma);
            System.out.printf("Média aritmética: %.2f%n", soma / n);
            System.out.printf("Porcentagem de positivos: %.2f%%%n", (positivos * 100.0) / n);
            System.out.printf("Porcentagem de negativos: %.2f%%%n", (negativos * 100.0) / n);

            do {
                System.out.print("\nDeseja nova execução? (S/N): ");
                repetir = sc.next().toUpperCase();
                if (!repetir.equals("S") && !repetir.equals("N")) {
                    System.out.println("Erro: responda apenas S ou N.");
                }
            } while (!repetir.equals("S") && !repetir.equals("N"));

        } while (repetir.equals("S"));

        System.out.println("Programa encerrado.");
        sc.close();
    }
}
