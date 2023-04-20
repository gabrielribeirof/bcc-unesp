package aula03.banco;

public class ContaEspecial {
	private String titular;
	private float saldo;
	private float limite;

	public ContaEspecial(String titular, float saldo, float limite) {
		this.titular = titular;
		this.saldo = saldo;
		this.limite = limite;
	}

	public ContaEspecial() {

	}

	public void sacar(float valor) {
		if ((saldo - valor) < (-limite))
			return;

		saldo = saldo - valor;
	}

	public void depositar(float valor) {
		saldo = saldo + valor;
	}

	public String getTitular() {
		return titular;
	}

	public void setTitular(String titular) {
		this.titular = titular;
	}

	public float getSaldo() {
		return saldo;
	}

	public void setSaldo(float saldo) {
		this.saldo = saldo;
	}

	public float getLimite() {
		return limite;
	}

	public void setLimite(float limite) {
		this.limite = limite;
	}

}
