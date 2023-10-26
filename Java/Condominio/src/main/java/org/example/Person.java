package org.example;

public class Person {
    private Type type;
    private Role role;
    private String firstName;
    private String lastName;

    enum Type {
        Owner,
        Resident,
        Employee,
        Visitor
    }

    enum Role {
        Resident,
        Manager,
        Doorman,
    }

    public Person(String firstName, String lastName, Type type) {
        this.type = type;
        this.firstName = formatName(firstName);
        this.lastName = formatName(lastName);
        this.role = null;
    }

    public Person(String firstName, String lastName, Type type, Role role) {
        this.type = type;
        this.role = role;
        this.firstName = formatName(firstName);
        this.lastName = formatName(lastName);
    }

    public String getFirstName() {
        return this.firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = formatName(firstName);
    }

    public String getLastName() {
        return this.lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = formatName(lastName);
    }

    public String getName() {
        return String.format("%s %s", getFirstName(), getLastName());
    }

    public Type getType() {
        return this.type;
    }

    public void setType(Type type) {
        this.type = type;
    }

    public Role getRole() {
        return this.role;
    }

    public void setRole(Role role) {
        this.role = role;
    }

    public void getAll() {
        System.out.format("%s\n%s\n%s\n", getName(), getType(), getRole());
    }

    private String formatName(String name) {
        try {
            name = name.trim();

            if(name.isEmpty()) {
                throw new Exception("name cannot be empty");
            }

            return String.format("%s%s", name.trim().substring(0, 1).toUpperCase(), name.trim().substring(1));
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}
