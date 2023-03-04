#include "users.h"

    User::User(string firstName, string lastName, int age, string phoneNumber, string country, string city, int zipCode){
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
        this->phoneNumber = phoneNumber;
        address = new Address(country, city, zipCode);
    }

    void User::setFirstName(string firstName){
        this->firstName = firstName;
    }
    string User::getFirstName(){
        return firstName;
    }
    void User::setLastName(string lastName){
        this->lastName = lastName;
    }
    string User::getLastName(){
        return lastName;
    }
    void User::setAge(int age){
        this->age = age;
    }
    int User::getAge(){
        return age;
    }
    void User::setPhoneNumber(string phoneNumber){
        this->phoneNumber = phoneNumber;
    }
    string User::getPhoneNumber(){
        return phoneNumber;
    }
    void User::setCountry(string country){
        address->setCountry(country);
    }
    string User::getCountry(){
        return address->getCountry();
    }

    void User::setCity(string city){
        address->setCity(city);
    }
    string User::getCity(){
        return address->getCity();
    }
    void User::setZipCode(int zipCode){
        address->setZipCode(zipCode);
    }
    int User::getZipCode(){
        return address->getZipCode();
    }
