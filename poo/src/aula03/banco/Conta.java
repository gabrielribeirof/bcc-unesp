package aula03.banco;

public class Conta {
    private int id;
    private float saldo;

    public Conta(int nome, float saldo) {
        this.id = nome;
        this.saldo = saldo;
    }
    
    public void sacar(float valor) {
        if (saldo <= 0 || valor > saldo) return;
                
        saldo = saldo - valor;
    }
    
    public void depositar(float valor) {
        saldo = saldo + valor;
    }

    public int getID() {
        return id;
    }

    public void setID(int id) {
        this.id = id;
    }

    public float getSaldo() {
        return saldo;
    }

    public void setSaldo(float saldo) {
        this.saldo = saldo;
    }
}
