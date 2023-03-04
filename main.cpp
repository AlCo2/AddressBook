#include <iostream>
#include <conio.h>
#include "database.h"
#include "users.h"


using namespace std;

bool running = true;

//Functions List:
User* createContact();

void stopApp();


int main()
{
    while(running){
        int choice;
        system("color 3");
        cout << "1-Add Contact\n2-Show Contacts\n3-Stop App" << endl;
        cin >> choice;
        switch(choice){
        case 1:
            {
                //add Contact
                User* user = createContact();
                connectToDatabse();
                addContactToDatabase(user);
                closeConnectionToDatabase();
                cout << "User " << user->getFirstName() << " added successful" << endl;
                getch();
                break;
            }
        case 2:
            {
                connectToDatabse();
                showContact();
                int choice;
                cout << "\n1-Edit Contact\n2-Delete Contact\n3-Back\n";
                cin >> choice;
                switch(choice){
                case 1:
                    {
                        system("cls");
                        int id;
                        showContact();
                        cout << "\n Id: ";
                        cin >> id;
                        User* user = createContact();
                        editContact(id, user);
                        system("cls");
                        cout << "User Edited Successful";
                        getch();
                        break;
                    }
                case 2:
                    {
                        system("cls");
                        showContact();
                        int id;
                        cout << "\n warning: use 0 to cancle\n Id: ";
                        cin >> id;
                        if(id==0)
                            break;
                        deleteContact(id);
                        system("cls");
                        cout << "User number " + to_string(id) +" Deleted Successfuly";
                        getch();
                        break;
                    }
                default:
                    break;
                }
                closeConnectionToDatabase();
                system("cls");
                break;
            }
        case 3:
            {
                stopApp();
                break;
            }
        default:
            {
            cout << "Error in choice" << endl;
            break;
            }
        }
    }
    return 0;
}

User* createContact(){
    string firstName;
    string lastName;
    int age;
    string phoneNumber;
    string country;
    string city;
    int zipCode;
    cout << "FirstName: ";
    cin >> firstName;
    cout << "LastName: ";
    cin >> lastName;
    cout << "Age: ";
    cin >> age;
    cout << "PhoneNumber: ";
    cin >> phoneNumber;
    cout << "Country: ";
    cin >> country;
    cout << "City: ";
    cin >> city;
    cout << "ZipCode: ";
    cin >> zipCode;
    User* user = new User(firstName, lastName, age, phoneNumber, country, city, zipCode);
    return user;
}

void stopApp(){
    running = false;
}
