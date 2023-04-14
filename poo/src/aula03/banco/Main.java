package aula03.banco;

public class Main {
    public static void main(String[] args) {
        Conta conta1 = new Conta(123423, 10000.0f);
        
        System.out.println("ID da Conta: " + conta1.getID());
        System.out.println("Saldo inicial: " + conta1.getSaldo());
        
        conta1.depositar(1000f);
        System.out.println("Depósito de 1000: " + conta1.getSaldo());

        conta1.sacar(4000f);
        System.out.println("Saque de 4000: " + conta1.getSaldo());
    }
}
