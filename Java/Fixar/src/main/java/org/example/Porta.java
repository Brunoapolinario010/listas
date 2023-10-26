package org.example;

public class Porta {
    boolean aberta;
    String cor;
    double altura;
    double largura;

    public Porta(boolean Aberta, String Cor, double Altura, double Largura) {
        this.aberta = Aberta;
        this.cor = Cor;
        this.altura = Altura;
        this.largura = Largura;
    }

    public void Abrir() {
        this.aberta = true;
    }

    public void Fechar() {
        this.aberta = false;
    }

    public void Pintar(String novaCor) {
        this.cor = novaCor;
    }

    public boolean EstaAberta() {
        return this.aberta;
    }
}
