#pragma once
#include <string>
#include "adress.h"

using namespace std;

class User{
private:
    string firstName;
    string lastName;
    int age;
    string phoneNumber;
    Address* address;

public:
    User(string firstName, string lastName, int age, string phoneNumber, string country, string city, int zipCode);
    void setFirstName(string firstName);
    string getFirstName();
    void setLastName(string lastName);
    string getLastName();
    void setAge(int age);
    int getAge();
    void setPhoneNumber(string phoneNumber);
    string getPhoneNumber();
    void setCountry(string country);
    string getCountry();
    void setCity(string city);
    string getCity();
    void setZipCode(int zipCode);
    int getZipCode();
};
