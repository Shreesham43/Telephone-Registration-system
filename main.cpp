#include <iostream>
#include<fstream>
#include <windows.h>
#include "header.h"
using namespace std;


int main(){
    int usertype;
    char choice;
    string username, password;
    do{
        system("CLS");
        position(35,1);
        cout << "--------TELEPHONE REGISTRATION SYSTEM--------" << endl
             << endl;
        position(35,3);
        cout << "---Login---" << endl;
        position(40,5);
        cout << "Username : ";
        cin >> username;
        position(40,7);
        cout << "Password : ";
        cin >> password;
        usertype=login(username,password);
        if(usertype==1){
            position(40,9);
            cout << "\nLogged in as admin\n\n";
            admin();
        }
        else if(usertype==2){
            position(40,9);
            cout << "Logged in as user";
            user(username);
        }
        else{
            position(40,9);
            cout << "Invalid Username/password";
        }
        position(40,11);
        cout << "Do you want to relogin?(Y/N)" << endl;
        position(40,12);
        cin >> choice;
    }while(choice == 'Y' || choice == 'y');
}
