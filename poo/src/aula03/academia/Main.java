package aula03.academia;

public class Main {
    public static void main(String[] args) {
        Aluno aluno1 = new Aluno("Gabriel", 10, 70, 1.7f);
        
        System.out.println("Nome: " + aluno1.getName());
        System.out.println("Idade: " + aluno1.getIdade());
        System.out.println("Peso: " + aluno1.getPeso());
        System.out.println("Altura: " + aluno1.getAltura());
        
        if (aluno1.isMenor()) {
            System.out.println("Com desconto");
        } else {
            System.out.println("Sem desconto");
        }
    }
}
