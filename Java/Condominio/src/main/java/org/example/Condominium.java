package org.example;

public class Condominium {
    Person[] residents;
    House[] houses;

    public Condominium(Person[] residents, House[] houses) {
        this.residents = residents;
        this.houses = houses;
    }

    public void getHouses() {
        for(House house : this.houses) {
            if(house != null) {
                System.out.printf("Owner Id: %d - Street: %s", house.getOwnerId(), house.getStreet());
            }
        }
    }

    public void getResidents() {
        for(Person person : this.residents) {
            if(person != null) {
                System.out.printf("%2d %50s %20s %40s %n", findPersonIndex(person), person.getName(), person.getType(), person.getRole() == null ? "Doesn't live at the condominium" : person.getRole());
                System.out.println("-------------------------------------------------------------------------------------------------------------------");
            }
        }
    }

    public int findPersonIndex(Person personToFind) {
        for (int i = 0; i < residents.length; i++) {
            if (residents[i] != null && residents[i].equals(personToFind)) {
                return i;
            }
        }
        return -1;
    }
}
