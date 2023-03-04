#include "adress.h"

Address::Address(string country, string city, int zipCode){
    this->country = country;
    this->city = city;
    this->zipCode = zipCode;
}

void Address::setCountry(string country){
    this->country = country;
}
string Address::getCountry(){
    return country;
}
void Address::setCity(string city){
    this->city = city;
}
string Address::getCity(){
    return city;
}
void Address::setZipCode(int zipCode){
    this->zipCode = zipCode;
}
int Address::getZipCode(){
    return zipCode;
}
