#include "database.h"
#include <mysql.h>
#include <iostream>
MYSQL* connection;
MYSQL_RES *res;
MYSQL_ROW row;
void connectToDatabse(){
    char* server = "localhost";
    char* user = "root";
    char* password = "*********";
    char* database = "adressbook";
    connection = mysql_init(NULL);
    if(!mysql_real_connect(connection, server, user, password, database, 3306, NULL, 0)){
        exit(1);
    }
}


void addUserToDatabase(User* user){
    string query = "INSERT INTO users (firstname, lastname, age, phonenumber, address) values(";
    query+= "'"+user->getFirstName()+"','"+user->getLastName()+"',"+to_string(user->getAge())+",'"+user->getPhoneNumber()+"',"+to_string(user->getZipCode())+")";
    mysql_query(connection, query.c_str());
}

void addContactToDatabase(User* user){
    addUserToDatabase(user);
}

void showContact(){
    mysql_query(connection, "SELECT * FROM users");
    res = mysql_store_result(connection);
    system("cls");
    printf("Id   FirstName   LastName  Age  PhoneNumber  ZipCode\n");
    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("%2s %10s %10s %4s   %10s   %6s\n", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
    }

    mysql_free_result(res);
}

void editContact(int id, User* user){
    string query = "UPDATE users set firstname='";
    query+=user->getFirstName()+"', lastname='"+user->getLastName()+"',age="+to_string(user->getAge())+
    ", phonenumber='"+user->getPhoneNumber()+"', address="+to_string(user->getZipCode())+" WHERE id="+to_string(id);
    mysql_query(connection, query.c_str());
}

void deleteContact(int id){
    string query = "DELETE FROM users where id=";
    query+=to_string(id);
    mysql_query(connection, query.c_str());
}

void closeConnectionToDatabase(){
    mysql_close(connection);
}
