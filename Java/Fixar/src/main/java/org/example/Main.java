package org.example;

public class Main {
    public static void main(String[] args) {
        // Pessoas
        Pessoa pessoa1 = new Pessoa("Bruno", 21);
        Pessoa pessoa2 = new Pessoa("Carlos", 42);

        System.out.println(String.format("A idade de %s é %d", pessoa1.nome, pessoa1.idade));
        System.out.println(String.format("A idade de %s é %d", pessoa1.nome, pessoa1.FazerAniversario()));

        // Portas
        Porta porta1 = new Porta(false, "Preta", 2.1, 0.9);
        Porta porta2 = new Porta(false, "Branca", 2.1, 0.6);

        System.out.println(String.format("A porta está aberta? %b", porta1.aberta));

        porta1.aberta = true;

        System.out.println(String.format("A porta está aberta? %b", porta1.aberta));

        // Casas
        Casa casa1 = new Casa("Branca", new Porta[]{
                new Porta(false, "Preta", 2.1, 0.9),
                new Porta(false, "Preta", 2.1, 0.9),
                new Porta(false, "Preta", 2.1, 0.9)
        });

        System.out.println(String.format("A casa tem %d portas abertas", casa1.PortasAbertas()));

        System.out.println(casa1.portas[0].aberta = true);

        System.out.println(String.format("A casa tem %d portas abertas", casa1.PortasAbertas()));
    }
}