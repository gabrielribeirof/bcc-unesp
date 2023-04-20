package aula03.eletrodomestico;

public class Eletrodomestico {
	private String nome;
	private float potencia;
	private int uso;

	public Eletrodomestico(String nome, float potencia, int uso) {
		this.nome = nome;
		this.potencia = potencia;
		this.uso = uso;
	}

	public void exibirRelatorio(float precoKwatts) {
		System.out.println("Eletrodoméstico: " + nome);
		System.out.println("Potência do aparelho: P = " + potencia);
		System.out.println("Tempo de utilização do aparelho: " + uso + " horas/dia");
		System.out.println("Watts/Dia: " + wattsDia() + " W");
		System.out.println("Watts/Mês: " + wattsMes() + " W");
		System.out.println("Watts/Ano: " + wattsAno() + " W");
		System.out.println("Preço do Kwatt: R$ " + precoKwatts);
		System.out.println("Gasto mensal é: R$ " + gastoMes(precoKwatts));
	}

	public float gastoMes(float precoKwatts) {
		return (wattsMes() / 1000) * precoKwatts;
	}

	public float wattsDia() {
		return potencia * uso;
	}

	public float wattsMes() {
		return wattsDia() * 30;
	}

	public float wattsAno() {
		return wattsMes() * 12;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public float getPotencia() {
		return potencia;
	}

	public void setPotencia(float potencia) {
		this.potencia = potencia;
	}

	public int getUso() {
		return this.uso;
	}

	public void setUso(int uso) {
		this.uso = uso;
	}
}
