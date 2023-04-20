package aula03.banco;

public class Main {
	public static void main(String[] args) {
		Conta conta1 = new Conta(123423, 10000.0f);

		System.out.println("Conta");
		System.out.println("ID da Conta: " + conta1.getID());
		System.out.println("Saldo inicial: " + conta1.getSaldo());
		System.out.println();

		conta1.depositar(1000f);
		System.out.println("Depósito de 1000: " + conta1.getSaldo());

		conta1.sacar(4000f);
		System.out.println("Saque de 4000: " + conta1.getSaldo());

		ContaEspecial conta2 = new ContaEspecial("Gabriel", 10000f, 200f);

		System.out.println();
		System.out.println("Conta Especial");
		System.out.println("Titular: " + conta2.getTitular());
		System.out.println("Saldo: " + conta2.getSaldo());
		System.out.println("Limite: " + conta2.getLimite());
		System.out.println();

		conta2.depositar(1000f);
		System.out.println("Depósito de 1000: " + conta2.getSaldo());

		conta2.sacar(10500f);
		System.out.println("Saque de 10500: " + conta2.getSaldo());

		conta2.sacar(701f);
		System.out.println("Saque de 701: " + conta2.getSaldo());
	}
}
