#include <iostream>
#include <time.h>
#include <fstream>
#include <sstream>
#include<stdlib.h>
#include<windows.h>
#include<stdio.h>
//#include<bits/stdc++.h>
using namespace std;
void ui1(int x, int y){
    COORD C;
    C.X = x;
    C.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), C);
}
void check_status(){
    string mobile1,mobile;
    fstream file;
    string buffer;
    char exit1;
    int i, flag = 0;
    ui1(35,2);
    cout << "Enter your mobile number : ";
    cin >> mobile;
    file.open("requests.txt", ios::in | ios::binary);
    while(!file.eof()){
        buffer.erase();
        mobile1.erase();
        i = 0;
        getline(file, buffer);
        if(buffer == "")break;
        if(buffer[i] == '*')
            continue;
        while(buffer[i]!= '|'){
            i++;
        }
        i++;
        while(buffer[i] != '|'){
            mobile1 += buffer[i];
            i++;
        }
        if(mobile == mobile1){
            ui1(35,3);
            cout << "Status : pending";
            flag = 1;
            break;
        }
    }
    file.close();
    if(flag == 0){
        file.open("telephone.txt", ios::in | ios::binary);
        while(!file.eof()){
            buffer.erase();
            mobile1.erase();
            i = 0;
            getline(file, buffer);
            if(buffer[i] == '*') continue;
            while(buffer[i]!= '|'){
                i++;
            }
            i++;
            while(buffer[i] != '|'){
                mobile1 += buffer[i];
                i++;
            }
            if(mobile == mobile1){
                ui1(35,3);
                cout << "Status : Registered";
                flag = 1;
                break;
            }
        }
    }
    if(flag == 0){
        ui1(35,3);
        cout << "Phone number not found";
    }

    ui1(35,4);
    cout << "Press any key to continue : ";
    cin >> exit1;
}


void update(string username){
    string mobile1,mobile;
    fstream file;
    char exit1;
    int pos, choice;
    string buffer, name, aadhar;
    int i, flag = 0;
    ui1(35,2);
    cout << "Enter your mobile number : ";
    cin >> mobile;
    file.open("requests.txt", ios::in | ios::binary);
    while(!file.eof()){
        buffer.erase();
        mobile1.erase();
        i = 0;
        getline(file, buffer);
        if(buffer == "")break;
        if(buffer[i] == '*') continue;
        while(buffer[i]!= '|'){
            i++;
        }
        i++;
        while(buffer[i] != '|'){
            mobile1 += buffer[i];
            i++;
        }
        if(mobile == mobile1){
            ui1(35,4);
            cout << "Can't update while waiting for confirmation";
            ui1(35,5);
            cout << "Press any key to continue : ";
            cin >> exit1;
            return;
            flag = 1;
            break;
        }
    }
    file.close();
    if(flag == 0){
        file.open("telephone.txt", ios::in | ios::binary);
        while(!file.eof()){
            buffer.erase();
            name.erase();
            aadhar.erase();
            mobile1.erase();
            i = 0;
            pos = file.tellg();
            getline(file, buffer);
            if(buffer[i] == '*') continue;
            while(buffer[i]!= '|'){
                aadhar += buffer[i];
                i++;
            }
            i++;
            while(buffer[i] != '|'){
                mobile1 += buffer[i];
                i++;
            }
            i++;
            while(buffer[i] != '|'){
                name += buffer[i];
                i++;
            }
            if(mobile == mobile1){
                ui1(35,4);
                cout << "Record Found";
                file.close();
                flag = 1;
                break;
            }
        }
    }
    if(flag==1){
        ui1(35,6);
        cout << "Mobile Number : " << mobile1;
        ui1(35,7);
        cout << "Aadhar Number : " << aadhar;
        ui1(35,8);
        cout << "Name : " << name;
        ui1(35,10);
        cout << "1.Update Aadhar";
        ui1(35,11);
        cout << "2.Update name";
        ui1(35,12);
        cout << "3.Cancel";
        ui1(35,13);
        cout << "Enter any option : ";
        cin >> choice;
        switch(choice){
            case 1: file.open("telephone.txt", ios::in | ios::out | ios::binary);
                    file.seekp(pos, ios::beg);
                    file.put('*');
                    file.close();
                    ui1(35,14);
                    cout << "Enter aadhar number : ";
                    aadhar.erase();
                    cin >> aadhar;
                    file.open("requests.txt", ios::out | ios::app | ios::binary);
                    file << aadhar << "|" << mobile << "|" << name << "|" << username << "|" << "\n";
                    file.close();
                    ui1(35,16);
                    cout << "Update Successful";
                    ui1(35,17);
                    cout << "Press any key to continue : ";
                    cin >> exit1;
                    break;
            case 2: file.open("telephone.txt",ios::in | ios::out | ios::binary);
                    file.seekp(pos, ios::beg);
                    file.put('*');
                    file.close();
                    ui1(35,14);
                    cout << "Enter name : ";
                    name.erase();
                    cin >> name;
                    file.open("requests.txt", ios::out | ios::app | ios::binary);
                    file << aadhar << "|" << mobile << "|" << name << "|" << username << "|" << "\n";
                    file.close();
                    ui1(35,16);
                    cout << "Update Successful";
                    ui1(35,17);
                    cout << "Press any key to continue : ";
                    cin >> exit1;
                    break;
            case 3: return;
        }
    }
    if(flag == 0){
        ui1(35,4);
        cout << "Phone number not found";
        ui1(35,5);
        cout << "Press any key to continue : ";
        cin >> exit1;
    }

}

void add_user(string username){
    string aadhar, mobile, name;
    char exit1;
    fstream file;
    time_t t;
    aadhar.erase();
    mobile.erase();
    name.erase();
    long long int mobile1=0,temp,i;
    ui1(35,2);
    cout << "Enter Aadhar number : ";
    cin >> aadhar;
    ui1(35,4);
    cout << "Enter name : ";
    cin >> name;
    mobile = "9";
    srand((unsigned) time(&t));
    for( int i = 0; i < 9 ; i++){
        mobile1 = rand();
        mobile1 = mobile1 % 10;
        ostringstream str1;
        str1 << mobile1;
        mobile += str1.str();
    }

    file.open("requests.txt", ios::out | ios::app | ios::binary);
    file << aadhar << "|" << mobile << "|" << name << "|" << username << "|" << "\n";
    file.close();
    ui1(35,6);
    cout << "Your mobile number is "<< mobile;
    ui1(35,7);
    cout << "Press any key to continue : ";
    cin >> exit1;
}
void user(string username){
    int choice;
    while(1){
        system("CLS");
        ui1(35,2);
        cout << "1.Add details";
        ui1(35,3);
        cout << "2.View Status";
        ui1(35,4);
        cout << "3.Update";
        ui1(35,5);
        cout << "4.Exit";
        ui1(35,6);
        cout << "Enter choice : ";
        cin >> choice;
        switch(choice){
            case 1: system("CLS");
                    add_user(username);
                    break;
            case 2:system("CLS");
                    check_status();
                    break;
            case 3: system("CLS");
                    update(username);
                    break;
            case 4:return;

        }
    }
}

