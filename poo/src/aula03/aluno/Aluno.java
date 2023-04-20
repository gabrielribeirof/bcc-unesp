package aula03.aluno;

public class Aluno {
	private int ra;
	private String nome;
	private float p1;
	private float p2;
	private float t1;
	private float t2;

	public Aluno(int ra, String nome, float p1, float p2, float t1, float t2) {
		this.ra = ra;
		this.nome = nome;
		this.p1 = p1;
		this.p2 = p2;
		this.t1 = t1;
		this.t2 = t2;
	}

	public boolean isAprovado() {
		return getMedia() >= 5.0f;
	}

	public int getRA() {
		return ra;
	}

	public String getNome() {
		return nome;
	}

	public float getP1() {
		return p1;
	}

	public float getP2() {
		return p2;
	}

	public float getT1() {
		return t1;
	}

	public float getT2() {
		return t2;
	}

	public float getMedia() {
		return (p1 + p2 + t1 + t2) / 4;
	}
}
