package org.example;

public class House {
    private int ownerId;
    private int residentId;
    private String street;

    public House(int ownerId, String street) {
        this.ownerId = ownerId;
        this.street = street;
    }

    public int getOwnerId() {
        return this.ownerId;
    }

    public void setOwnerId(int newOwnerId) {
        this.ownerId = newOwnerId;
    }

    public int getResidentId() {
        return this.residentId;
    }

    public void setResidentId(int residentId) {
        this.residentId = residentId;
    }

    public String getStreet() {
        return this.street;
    }

    public void getAll() {
        System.out.format("%d\n%d\n%s\n", getOwnerId(), getResidentId(), getStreet());
    }
}
