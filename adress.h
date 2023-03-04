#pragma once
#include <string>

using namespace std;


class Address{
private:
    string country;
    string city;
    int zipCode;
public:
    Address(string country, string city, int zipCode);
    void setCountry(string country);
    string getCountry();
    void setCity(string city);
    string getCity();
    void setZipCode(int zipCode);
    int getZipCode();
};
