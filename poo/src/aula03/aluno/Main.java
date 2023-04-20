package aula03.aluno;

public class Main {
	public static void main(String[] args) {
		Aluno aluno1 = new Aluno(12345, "Gabriel", 0.0f, 0.0f, 1.0f, 10.0f);

		System.out.println("RA: " + aluno1.getRA());
		System.out.println("Nome: " + aluno1.getNome());
		System.out.println("P1: " + aluno1.getP1());
		System.out.println("P2: " + aluno1.getP2());
		System.out.println("T1: " + aluno1.getT1());
		System.out.println("T2: " + aluno1.getT2());
		System.out.println("Média: " + aluno1.getMedia());

		if (aluno1.isAprovado()) {
			System.out.println("Situação: APROVADO");
		} else {
			System.out.println("Situação: REPROVADO");
		}
	}
}
