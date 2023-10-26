package org.example;

public class Casa {
    String cor;

    Porta[] portas = new Porta[3];

    public Casa(String cor, Porta[] portas) {
        this.cor = cor;
        System.arraycopy(portas, 0, this.portas, 0, this.portas.length);
    }

    public void Pintar(String novaCor) {
        this.cor = novaCor;
    }

    public int PortasAbertas() {
        int abertas = 0;
        for (Porta porta: portas) {
            if(porta.aberta) {
                abertas++;
            }
        }
        return abertas;
    }
}
