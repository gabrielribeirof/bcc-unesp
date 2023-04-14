package aula03.relogio;

public class Main {
    public static void main(String[] args) {
        Relogio relogio1 = new Relogio(1, 0, 0);
        
        relogio1.print();
        relogio1.printEmSegundos();

        Relogio relogio2 = new Relogio();

        relogio2.print();
    }
}
