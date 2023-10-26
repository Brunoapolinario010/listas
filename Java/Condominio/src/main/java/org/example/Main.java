package org.example;

public class Main {
    public static void main(String[] args) {
        Person p1 = new Person("bruno", "Apolinário", Person.Type.Owner);
        Person p2 = new Person("Carlos", "Silva", Person.Type.Owner, Person.Role.Resident);

        Person[] persons = new Person[50];
        House[] houses = new House[50];
        persons[0] = p1;
        persons[1] = p2;

        houses[0] = new House(0, "Gato de botas");

        Condominium c1 = new Condominium(persons, houses);

        c1.getResidents();
        c1.getHouses();
    }
}