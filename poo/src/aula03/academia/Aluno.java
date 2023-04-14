package aula03.academia;

public class Aluno {
    private String name;
    private int idade;
    private float peso;
    private float altura;

    public Aluno(String name, int idade, float peso, float altura) {
        this.name = name;
        this.idade = idade;
        this.peso = peso;
        this.altura = altura;
    }
    
    public boolean isMenor() {
        return idade < 18;
    }
    
    public float getIMC() {
        return peso / (altura * altura);
    }

    public String getName() {
        return name;
    }

    public int getIdade() {
        return idade;
    }

    public float getPeso() {
        return peso;
    }

    public float getAltura() {
        return altura;
    }
}
