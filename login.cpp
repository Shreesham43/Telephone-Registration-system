#include<iostream>
#include<fstream>
#include <sstream>
using namespace std;
int login(string username, string password){
    fstream file1,file2;
    string username1, password1;
    string buffer;
    string usertype;
    //file1.open("users.txt", ios::out | ios::app);
    //file1 << "shreesha|1234|admin|\n";
    //file1.close();
    file1.open("users.txt",ios::in | ios::binary);
    while(!file1.eof()){
        username1.erase();
        password1.erase();
        usertype.erase();
        getline(file1, buffer);
        int i = 0;
        while (buffer[i]!='|'){
            username1 += buffer[i];
            i++;
        }
        i++;
        while(buffer[i]!='|'){
            password1 += buffer[i];
            i++;
        }
        i++;
        if(username==username1 && password==password1){
            while(buffer[i]!='|'){
                usertype += buffer[i];
                i++;
            }

            if(usertype=="admin"){
                file1.close();
                return 1;
            }
            if(usertype=="user"){
                file1.close();
                return 2;
            }
        }
        buffer.erase();
    }
    file1.close();
    return 3;
}
