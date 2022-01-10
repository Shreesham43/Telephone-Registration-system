#include<iostream>
#include<fstream>
#include<malloc.h>
#include <math.h>
#include<string.h>
#include<cstdlib>
#include<sstream>
#include<windows.h>
#include<stdio.h>
//#include<bits/stdc++.h>
using namespace std;
int requests = 0;
int delete_request(int);
void hashinsert(string username, int pos, int hashkey);
void ui(int x, int y){
    COORD C;
    C.X = x;
    C.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), C);
}
class User{
public:
    string username;
    string password;
    string usertype;
    int write_to_file();

};
class node{
public:
    string username;
    int pos;
    node *link;
};
class tele_node{
public:
    string phone;
    int pos;
    tele_node* link;
};
node *h[29];
tele_node *ht[29];
void view_all_tele(){
    tele_node *curr;
    int flag = 0, display = 0;
    char exit1;
    fstream file;
    string buffer;
    string aadhar, phone, name;
    int j;
    ui(20,2);
    cout << "Aadhar Number";
    ui(35,2);
    cout << "Mobile Number";
    ui(50,2);
    cout << "Name";
    for(int i = 0; i < 29; i++){
        curr = ht[i];
        while(curr != NULL){
            j = 0;
            buffer.erase();
            file.open("telephone.txt", ios::in | ios::binary);
            file.seekp(curr->pos, ios::beg);
            getline(file, buffer);
            file.close();
            if(buffer[j] == '*')break;
            name.erase();
            aadhar.erase();
            phone.erase();
            while(buffer[j]!='|'){
                aadhar += buffer[j];
                j++;
            }
            j++;
            while(buffer[j] != '|'){
                phone += buffer[j];
                j++;
            }
            j++;
            while(buffer[j] != '|'){
                name += buffer[j];
                j++;
            }
            curr = curr->link;
            ui(20, 4+display);
            cout << aadhar;
            ui(35, 4+display);
            cout << phone;
            ui(50, 4+display);
            cout << name;
            flag = 1;
            display++;
        }
    }
    if( flag == 0){
        system("CLS");
        ui(35,3);
        cout << "No data found";
    }
    ui(35, 4+display);
    cout << "Press any key to return";
    cin >> exit1;
}
void tele_hashinsert(string username, int pos, int hashkey, int display){
    tele_node *p,*prev,*curr;
    int flag = 0;
	p = new tele_node;
	p->phone = username;
	p->pos = pos;
	p->link = NULL;
	curr = ht[hashkey];
	if(curr == NULL)
	{
		ht[hashkey] = p;
		return;
	}
	while(curr != NULL)
	{
	    if(curr->phone == username){
            curr->pos = pos;
            ui(35,4+display);
            //cout << "Mobile number has been updated";
            flag = 1;
            break;
	    }
		prev = curr;
		curr = curr->link;

	}
	if(flag == 0)
	prev->link = p;
	ui(35,4+display);
    //cout << "Mobile number has been activated  ";

}
void insert(string username, int pos){
	int count = 0;
	for(int j = 0;j < username.length(); j++)
	{
		count += username[j];
	}
	count = count % 29;
	hashinsert(username, pos, count);
}
void tele_insert(string username, int pos, int display){
    int count = 0;
	for(int j = 0;j < username.length(); j++)
	{
		count += username[j];
	}
	count = count % 29;
	tele_hashinsert(username, pos, count, display);
}
void hashinsert(string username, int pos, int hashkey){
	node *p,*prev,*curr;
	p = new node;
	p->username = username;
	p->pos = pos;
	p->link = NULL;
	curr = h[hashkey];
	if(curr == NULL)
	{
		h[hashkey] = p;
		return;
	}
	while(curr != NULL)
	{
		prev = curr;
		curr = curr->link;
	}
	prev->link = p;
}
string retrive(){
	int j, i = 0, count;
	char exit1;
	fstream file;
	string username, password, buffer;
	node *curr;
	username.erase();
	password.erase();
	buffer.erase();
	ui(25,4);
	cout << "Enter the username : ";
	cin >> username;
	count = 0;
	for(j = 0; j < username.length(); j++)
		count += username[j];
	count %= 29;
	curr = h[count];
	if(curr == NULL)
	{
	    ui(25,6);
		cout << "Record not found";
		ui(25,7);
		cout << "Enter any character to return : ";
        cin >> exit1;
		return " ";
	}
	do
	{
		if(curr->username == username)
		{
			file.open("users.txt",ios::in | ios::binary);
			file.seekg(curr->pos, ios::beg);
			getline(file, buffer);
            while(buffer[i]!='|'){
                i++;
            }
            i++;
            ui(25,6);
            cout << "Username is " << username << endl;
            while(buffer[i]!='|'){
                password += buffer[i];
                i++;
            }
            ui(25,7);
            cout << "Password is " << password << endl;
            //ui(25,8);
            //cout << "Enter any character to return : ";
            //cin >> exit1;
			return username;
		}
		else
		{
			curr = curr->link;
		}
	}while(curr != NULL);
	ui(25,8);
    cout << "Enter any character to return : ";
    cin >> exit1;
	return " ";
}
string retrive_display(){
	int j, i = 0, count;
	char exit1;
	fstream file;
	string username, password, buffer;
	node *curr;
	username.erase();
	password.erase();
	buffer.erase();
	ui(25,4);
	cout << "Enter the username : ";
	cin >> username;
	count = 0;
	for(j = 0; j < username.length(); j++)
		count += username[j];
	count %= 29;
	curr = h[count];
	if(curr == NULL)
	{
	    ui(25,6);
		cout << "Record not found";
		ui(25,7);
		cout << "Enter any character to return : ";
        cin >> exit1;
		return " ";
	}
	do
	{
		if(curr->username == username)
		{
			file.open("users.txt",ios::in | ios::binary);
			file.seekg(curr->pos, ios::beg);
			getline(file, buffer);
            while(buffer[i]!='|'){
                i++;
            }
            i++;
            ui(25,6);
            cout << "Username is " << username << endl;
            while(buffer[i]!='|'){
                password += buffer[i];
                i++;
            }
            ui(25,7);
            cout << "Password is " << password << endl;
            ui(25,8);
            cout << "Enter any character to return : ";
            cin >> exit1;
			return username;
		}
		else
		{
			curr = curr->link;
		}
	}while(curr != NULL);
	ui(25,8);
    cout << "Enter any character to return : ";
    cin >> exit1;
	return " ";
}
void retrieve_tele(){
	int j, i = 0, count;
	char exit1;
	fstream file;
	string name,aadhar, phone, buffer;
	tele_node *curr;
	name.erase();
	aadhar.erase();
    phone.erase();
    ui(35,3);
	cout << "Enter the phone number : ";
	cin >> phone;
	count = 0;
	for(j = 0; j < phone.length(); j++)
		count += phone[j];
	count %= 29;
	curr = ht[count];
	if(curr == NULL)
	{
	    ui(35,5);
		cout << "Record not found";
		ui(35,7);
		cout << "Press any key to continue : ";
		cin >> exit1;
		return;
	}
	do
	{
		if(curr->phone == phone)
		{
			file.open("telephone.txt",ios::in | ios::binary);
			file.seekg(curr->pos, ios::beg);
			getline(file, buffer);
            while(buffer[i]!='|'){
                aadhar += buffer[i];
                i++;
            }
            i++;
            ui(35,5);
            cout << "Username :  " << phone;
            while(buffer[i]!='|'){
                i++;
            }
            i++;
            ui(35,6);
            cout << "Aadhar :  " << aadhar;
            while(buffer[i]!='|'){
                name += buffer[i];
                i++;
            }
            ui(35,7);
            cout << "Name: " << name;
            ui(35,9);
            cout << "Press any to continue : ";
            cin >> exit1;
			return;
		}
		else
		{
			curr = curr->link;
		}
	}while(curr != NULL);

	return;
}
void View_all(){
    int display = 0, flag = 0;
    char exit1;
    node *curr;
    fstream file;
    string buffer;
    string username;
    string password;
    int j;
    ui(20,2);
    cout << "Username";
    ui(33,2);
    cout << "Password";
    for(int i = 0; i < 29; i++){
        curr = h[i];
        while(curr != NULL){
            j = 0;
            buffer.erase();
            file.open("users.txt", ios::in | ios::binary);
            file.seekp(curr->pos, ios::beg);
            getline(file, buffer);
            file.close();
            username.erase();
            password.erase();
            while(buffer[j]!='|'){
                username += buffer[j];
                j++;
            }
            j++;
            while(buffer[j] != '|'){
                password += buffer[j];
                j++;
            }
            j++;
            curr = curr->link;
            ui(20,3+display);
            cout << username;
            ui(33,3+display);
            cout << password;
            display++;
            flag = 1;
        }
    }
    if(flag == 0){
        system("CLS");
        ui(20, 3);
        cout << "No data found";
        ui(20,5);
        cout << "Press any key to return : ";
        cin >> exit1;
        return;
    }
    ui(20, 3+display);
    cout << "Press any key to return : ";
    cin >> exit1;
    return;
}
int User::write_to_file(){
    fstream file;
    int pos;
    usertype = "user";
    ui(25,6);
    cout << "Enter Username : ";
    cin >> username ;
    ui(25,7);
    cout << "Enter password : ";
    cin >> password;
    file.open("users.txt",ios::app | ios::ate | ios::binary);
    pos = file.tellp();
    string buffer = username + "|" + password + "|" + usertype + "|" + "\n";
    file << buffer;
    file.close();
    insert(username, pos);
    return pos;


}
void delete_user(string username){
	int j, i = 0, count, position;
	fstream file;
	node *curr, *next, *prev;
	count = 0;
	for(j = 0; j < username.length(); j++)
		count += username[j];
	count %= 29;
	curr = h[count];
	prev = h[count];
	next = h[count];
	if(curr->username == username ){
        position = curr->pos;
        file.open("users.txt", ios::out |ios::in | ios::binary);
        file.seekp(position, ios::beg);
        file.put('*');
        file.close();
        h[count] = curr->link;
        return;
    }
    while (curr != NULL && curr->username != username) {
        prev = curr;
        curr = curr->link;
    }
    if (curr == NULL)
        return;
    position = curr->pos;
    file.open("users.txt", ios::out | ios::binary);
    file.seekp(position, ios::beg);
    file.put('*');
    file.close();
    prev->link = curr->link;
}
void View_all_request(){
    fstream file;
    int i, display = 0, flag = 0;
    char exit1;
    string buffer, name, username, mobile, aadhar;
    ui(20,2);
    cout << "Aadhar number";
    ui(35,2);
    cout << "Mobile number";
    ui(50,2);
    cout << "Name";
    file.open("requests.txt",ios::in | ios::binary);
    while(!file.eof()){
        i = 0;
        buffer.erase();
        mobile.erase();
        aadhar.erase();
        username.erase();
        name.erase();
        getline(file, buffer);
        if(buffer.length() == 0) break;
        if(buffer[i] == '*') continue;
        while(buffer[i] != '|'){
            aadhar +=buffer[i];
            i++;
        }
        i++;
        while(buffer[i] != '|'){
            mobile += buffer[i];
            i++;
        }
        i++;
        while(buffer[i] != '|'){
            name += buffer[i];
            i++;
        }
        i++;
        ui(20,4+display);
        cout << aadhar;
        ui(35,4+display);
        cout << mobile;
        ui(50,4+display);
        cout << name;
        display++;
        flag = 1;
        requests++;
    }
    //if(flag == 1){
      //  ui(20, 4+display);
        //cout << "Press any key to return : ";
        //cin >> exit1;
    //}
    if(flag == 0){
        system("CLS");
        ui(20, 2+display);
        cout << "No data found";
        ui(20, 4+display);
        cout << "Press any key to return : ";
        cin >> exit1;
        return;
    }
    while(requests){
        ui(20,4+display);
        display++;
        cout << "Do you want to accept any request(y/n) : ";
        char choice2;
        cin >> choice2;
        if(choice2 == 'y' || choice2 == 'Y'){
            display = delete_request(display);
        }
        else
            return;
    }

}

int delete_request(int display){
    string adhar, buffer, aadhar, mobile, username;
    fstream file;
    int i = 0, position;
    ui(35,5+display);
    cout << "Enter Aadhar number : ";
    display++;
    cin >> adhar;
    aadhar.erase();
    file.open("requests.txt",ios::in | ios::binary);
    while(!file.eof()){
        buffer.erase();
        aadhar.erase();
        username.erase();
        position = file.tellg();
        getline(file, buffer);
        i = 0;
        if(buffer[i] == '*')continue;
        if(buffer == ""){
            ui(35,5+display);
            cout << "Aadhar Number not found";
            display+=3;
            return display;
        }
        while(buffer[i] != '|'){
            aadhar += buffer[i];
            i++;
        }
        i++;
        if(adhar == aadhar){
            while(buffer[i] != '|'){
                mobile += buffer[i];
                i++;
            }
            i++;
            while(buffer[i] != '|'){
                username += buffer[i];
                i++;
            }
            file.close();
            file.open("requests.txt",ios::in | ios::out | ios::binary);
            file.seekp(position, ios::beg);
            file.put('*');
            file.close();
            requests--;
            file.open("telephone.txt", ios::out | ios::ate| ios::binary | ios::app);
            position = file.tellp();
            file << aadhar << "|" << mobile << "|" << username << "|" << "\n";
            file.close();
            tele_insert(mobile, position, display);
            ui(35,5+display);
            cout << "Mobile number has been activated";
            display+=3;
            return display;
        }
    }
}
void restore_hash_user(){
    fstream file;
    int i, pos, hashkey;
    string buffer, username, pos1, hashkey1;
    file.open("admin_hash.txt", ios::in | ios::binary);
    while(!file.eof()){
        i = 0;
        buffer.erase();
        username.erase();
        pos1.erase();
        hashkey1.erase();
        getline(file, buffer);
        if(buffer.length() == 0) break;
        while(buffer[i] != '|'){
            username += buffer[i];
            i++;
        }
        i++;
        while(buffer[i] != '|'){
            pos1 += buffer[i];
            i++;
        }
        stringstream ss1(pos1);
        ss1 >> pos;
        ss1.str(std::string());
        i++;
        while(buffer[i] != '|'){
            hashkey1 += buffer[i];
            i++;
        }
        stringstream ss2(hashkey1);
        ss2 >> hashkey;
        ss1.str(std::string());
        hashinsert(username, pos, hashkey);
    }
}
void restore_hash_tele(){
    fstream file;
    int i, pos, hashkey;
    string buffer, username, pos1, hashkey1;
    file.open("admin_hash_tele.txt", ios::in | ios::binary);
    while(!file.eof()){
        i = 0;
        buffer.erase();
        username.erase();
        pos1.erase();
        hashkey1.erase();
        getline(file, buffer);
        if(buffer.length() == 0) break;
        while(buffer[i] != '|'){
            username += buffer[i];
            i++;
        }
        i++;
        while(buffer[i] != '|'){
            pos1 += buffer[i];
            i++;
        }
        stringstream ss1(pos1);
        ss1 >> pos;
        ss1.str(std::string());
        i++;
        while(buffer[i] != '|'){
            hashkey1 += buffer[i];
            i++;
        }
        stringstream ss2(hashkey1);
        ss2 >> hashkey;
        ss2.str(std::string());
        tele_hashinsert(username, pos, hashkey,0);
    }
}
void store_hash_user(){
    node *curr;
    fstream file;
    string buffer;
    string position, hashkey;
    string username;
    int j;
    file.open("admin_hash.txt", ios::out | ios::binary | ios::trunc);
    for(int i = 0; i < 29; i++){
        curr = h[i];
        while(curr != NULL){
            j = 0;
            buffer.erase();
            ostringstream str1,str2;
            str1 << curr->pos;
            position = str1.str();
            str2 << i;
            hashkey = str2.str();
            buffer = curr->username + "|" + position + "|" + hashkey + "|" + "\n";
            file << buffer;
            curr = curr->link;
        }
    }
    file.close();
}
void store_hash_tele(){
    tele_node *curr;
    fstream file;
    string buffer;
    string position, hashkey;
    string username;
    int j;
    file.open("admin_hash_tele.txt", ios::out | ios::binary | ios::trunc);
    for(int i = 0; i < 29; i++){
        curr = ht[i];
        while(curr != NULL){
            j = 0;
            buffer.erase();
            ostringstream str1,str2;
            str1 << curr->pos;
            position = str1.str();
            str2 << i;
            hashkey = str2.str();
            buffer = curr->phone + "|" + position + "|" + hashkey + "|" + "\n";
            file << buffer;
            curr = curr->link;
        }
    }
    file.close();
}
int admin(){
    int j;
    char exit1;
    char option;
    string delete_return;
    User user;
    restore_hash_user();
    restore_hash_tele();
    while(true){
        int choice, choice1, record_num, position;
        char choice2;
        system("CLS");
        ui(30,1);
        cout << "1.User";
        ui(30,2);
        cout << "2.View Requests";
        ui(30,3);
        cout << "3.View Telephone Users";
        ui(30,4);
        cout << "4.Search Telephone Users";
        ui(30,5);
        cout << "5.Exit";
        ui(30,6);
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice){
            case 1: do{system("CLS");
                        ui(30,1);
                        cout << "1.Add User";
                        ui(30,2);
                        cout << "2.Remove User";
                        ui(30,3);
                        cout << "3.View all Users";
                        ui(30,4);
                        cout << "4.Search User";
                        ui(30,5);
                        cout << "5.Return";
                        ui(30,6);
                        cout << "Enter your choice : ";
                        cin >> choice1;
                        if(choice1 == 5){
                            break;
                        }
                        switch(choice1){
                            case 1: system("CLS");
                                    ui(20,2);
                                    cout << "Number of user details to enter : ";
                                    cin >> record_num;
                                    system("CLS");
                                    for(int i = 0; i < record_num; i++){
                                        ui(25,4);
                                        cout << "Enter details of user "<< i + 1;
                                        position = user.write_to_file();
                                        system("CLS");
                                    }
                                    break;
                            case 2: system("CLS");
                                    ui(20,2);
                                    delete_return = retrive();
                                    if(delete_return != " "){
                                        ui(25,8);
                                        cout << "Are you sure to delete(Y/N) : " ;
                                        cin >> option;
                                        if(option == 'y' || option == 'Y'){
                                            delete_user(delete_return);
                                        }
                                        ui(25,10);
                                        cout << "User deleted successfully!!";
                                        ui(25,11);
                                        cout << "Press any key to continue : ";
                                        cin >> exit1;
                                    }


                                    break;
                            case 3: system("CLS");
                                    View_all();
                                    break;
                            case 4: system("CLS");
                                    retrive_display();
                                    break;
                            case 5: system("CLS");
                                    break;
                            default :ui(20,2);
                                    cout << "Invalid choice";
                                    break;
                        }
                    }while(choice1 != 5);
                    break;
            case 2: system("CLS");
                    View_all_request();
                    break;
            case 3:system("CLS");
                    view_all_tele();
                    break;
            case 4:system("CLS");
                    retrieve_tele();
                    break;
            case 5:store_hash_tele();
                    store_hash_user();
                    return 0;
            default: cout << "Invalid choice" ;
                     break;
        }

    }


}
