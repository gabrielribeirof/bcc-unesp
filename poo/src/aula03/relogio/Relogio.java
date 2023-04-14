package aula03.relogio;

public class Relogio {
    private int hora;
    private int minuto;
    private int segundo;
    
    public Relogio(int hora, int minuto, int segundo) {
        this.hora = hora;
        this.minuto = minuto;
        this.segundo = segundo;
    }
     
    public Relogio() {
        hora = 4;
        minuto = 3;
        segundo = 2;
    }
    
    public void print() {
        System.out.println(getHora() + ":" + getMinuto() + ":" + getSegundo());
    }
    
    public void printEmSegundos() {
        System.out.println(getHora()*3600 + getMinuto()*60 + getSegundo());
    }

    public int getHora() {
        return hora;
    }

    public void setHora(int hora) {
        this.hora = hora;
    }

    public int getMinuto() {
        return minuto;
    }

    public void setMinuto(int minuto) {
        this.minuto = minuto;
    }

    public int getSegundo() {
        return segundo;
    }

    public void setSegundo(int segundo) {
        this.segundo = segundo;
    }
}
