
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <fstream>
#include <stdlib.h>



class user;
class book;
void homePage(user a);
void reserve(book b,user a);

class user{

public:
string username;
string password;
string firstname;
string lastname;
string birthdate;

    
};

class book{
public:
    string title;
    string shelfnumber;
    string authors;
    int edition;
    string publisher;
    int publishedyear;
    string ISBN;
    int length;
    string subjects;
    string status;
};

void signup(){
    
    string un;
    cout<<"plaese enter your username: ";
    cin>>un;
    string temp = "a.txt";
    temp.replace(0,1,un);

    ifstream File;
    File.open(temp);

    if (File)
    {
        system("CLS");
        cout << "Username already exists" << endl;
        File.close();
    }
    else
    {
        ofstream MyFile(temp);
        string p;
        cout<<"plaese enter your password: ";
        cin>>p;

        string fn;
        cout<<"plaese enter your first name: ";
        cin>>fn;

        string ln;
        cout<<"plaese enter your last name: ";
        cin>>ln;

        string bd;
        cout<<"plaese enter your birthday: ";
        cin>>bd;
        MyFile<<un<<" "<<p<<" "<<fn<<" "<<ln<<" "<<bd<< endl;
        MyFile.close();
        File.close();
        system("CLS");
        user a;
        a.username = un;
        a.password = p;
        a.firstname = fn;
        a.lastname =ln;
        a.birthdate = bd;
        cout << "Sign Up succsusfull"<<endl;
        homePage(a);
    }
}


user login(){

    user a;
    cout<<"plaese enter your username: ";
    cin>>a.username;

    string temp = "a.txt";
    temp.replace(0,1,a.username);

    ifstream File;
    File.open(temp);

    if (File)
    {
        
        ifstream MyFile(temp);

        string myText;
        getline (MyFile, myText);
        stringstream ss(myText);  
        string word;

        string data[5];
        int j=0;

        while (ss >> word) { 
            data[j]=word;
            j++;
        }
        MyFile.close();
        cout<<"plaese enter your password: ";
        cin>>a.password;
        if(a.password==data[1]){
            system("CLS");
            a.firstname = data[2];
            a.lastname = data[3];
            a.birthdate = data[4];
           cout<<"Login successful"<< endl;
           return a;
        }else{
            system("CLS");            
            cout<<"Incorrect password"<< endl;
            File.close();
            return login();
        }
    }
    else
    {
        system("CLS");
        cout << "Username does not exists" << endl;
        File.close();
        return login();
    }

}

void search(user a){
    system("CLS");
    string searchway;
    cout<<"How do you want to search in the library? "<<endl;
    cout<<"If you want to search by title write title"<<endl;
    cout<<"If you want to search by author write author"<<endl;
    cout<<"If you want to search by publisher write publisher"<<endl;
    cout<<"If you want to search by published year write published_year"<<endl;
    cin>>searchway;

    string myText;
    ifstream MyFile("books.txt");

    string title;
    if(searchway=="title"){

       
       cout<<"please enter book's title: ";
       cin>>title;
       
    }

    string author;
    if(searchway=="author"){

       
       cout<<"please enter book's author: ";
       cin>>author;
       
    }

    string publisher;
    if(searchway=="publisher"){

       cout<<"please enter book's publisher: ";
       cin>>publisher;
       
    }
    
    string pubyear;
    if(searchway=="published_year"){
       
       cout<<"please enter book's published year: ";
       cin>>pubyear;
       
    }    
    

       int counter = 0;
       string result[50];
       while (getline (MyFile, myText)) {
            stringstream ss(myText);  
            string word;
            string data[11];
            int i=0;
            while (ss >> word) { 

                data[i]=word;
                i++;
            }
            
            if(searchway=="title"){
                if(title==data[0]){
                    result[counter] = myText;
                    counter += 1;

                    }
            }     

            else if(searchway=="author"){

                if(author==data[2]){
                    result[counter] = myText;
                    counter += 1;
                    }
      
            }

            else if(searchway=="publisher"){

                if(publisher==data[4]){
                    result[counter] = myText;
                    counter += 1;
                    }
      
            }   

            else if(searchway=="published_year"){

                if(pubyear==data[5]){
                    result[counter] = myText;
                    counter += 1;
                    }
            }      
            else{
                system("CLS");
                homePage(a);
            }                
    }

    result[counter] = '0';

    for (int i=0;i < counter ;i++){
        cout << i+1 << " --> "<< result[i]<< endl;
    }
    int rsrv;
    cout << "to reserv book please insert book's index or insert 0 to leave"<<endl;
    cin >> rsrv;
    if (rsrv == 0){
        system("CLS");
    }
    else if (rsrv-1 < counter){
        rsrv -= 1;
        stringstream ssss(result[rsrv]);  
        string wordd;
        string dataa[11];
        int t=0;
        while (ssss >> wordd) { 

            dataa[t]=wordd;
            t++;
        }        

        book b;
        b.title = dataa[0];
        b.shelfnumber = dataa[1];
        b.authors = dataa[2];
        b.edition = stoi(dataa[3]);
        b.publisher = dataa[4];
        b.publishedyear = stoi(dataa[5]);
        b.ISBN = dataa[6];
        b.length = stoi(dataa[7]);
        b.subjects = dataa[8];
        b.status = dataa[9];

        reserve(b,a);
    }
    else{
        system("CLS");
        cout << "Index is out of range"<< endl;
    }
}

void reserve(book b,user a){
    if(b.status == "free"){
        string bookString = b.title + " "+ b.shelfnumber +" "+ b.authors+" "+ to_string(b.edition)+" "+b.publisher+" "+to_string(b.publishedyear)+" "+b.ISBN+" "+to_string(b.length)+" "+b.subjects+" "+b.status + " NULL"; 
        // string newText = "";
        string line;
        ifstream file("books.txt");
        ofstream nfile("books1.txt");
        while (getline(file,line)){
            if(line == bookString){
                nfile << b.title + " "+ b.shelfnumber +" "+ b.authors+" "+ to_string(b.edition)+" "+b.publisher+" "+to_string(b.publishedyear)+" "+b.ISBN+" "+to_string(b.length)+" "+b.subjects+" "+ "occupied"+ " NULL";
                nfile << endl;
            }
            else{
                nfile << line<<endl;
            }
        }
        file.close();
        nfile.close();

        string temp = "a.txt";
        temp.replace(0,1,a.username);

        string userData;
        string reservedData;
        ifstream userFile(temp);
        getline(userFile,userData);
        getline(userFile,reservedData);
        reservedData += " " + b.ISBN; 

        ofstream newUserFile(temp);
        newUserFile << userData << endl << reservedData;

        userFile.close();
        newUserFile.close();

        system("CLS");
        cout <<"reserved succsusfully"<< endl;

        
    }else{
        system("CLS");
        cout << "Book is not free!"<< endl;
        homePage(a);
    }
}

void returnBook(user a){
    system("CLS");
    cout << "List of your books"<< endl;
    
    string temp = "a.txt";
    temp.replace(0,1,a.username);

    string userData;
    string reservedData;
    ifstream userFile(temp);
    getline(userFile,userData);
    getline(userFile,reservedData);

    
    string booksISBN[1000];
    stringstream s(reservedData);  
    string word;
    string data[11];
    int t=0;
    while (s >> word) { 
        booksISBN[t]=word;
        t++;
    }
    userFile.close();

    string line;
    
    for (int i=0 ; i < t;i++){
        ifstream booksfile("books.txt");
        while(getline(booksfile,line)){
            stringstream ss(line);
            string wordd;
            string dataa[11];
            int j=0;
            while (ss >> wordd) { 
               dataa[j]=wordd;
                j++;
            }
            if (dataa[6] == booksISBN[i]){
                cout << i+1 <<" --> " << line << endl;
                break;
            }
        }
    }
    cout << "please Index of book you want to return" << endl;
    int bookIndex;
    cin >> bookIndex;
    if (bookIndex -1 >=t){
        system("CLS");
        cout << "index is out of range" << endl;
    }
    else{
        ofstream newfile(temp);
        newfile << userData << endl;
        for(int c;c < t; c++){
            if(c != bookIndex-1){
                newfile << booksISBN[c] << " ";
            }
        }
        newfile.close();


        ifstream file("books.txt");
        ofstream nfile("books1.txt");

        while (getline(file,line)){
            stringstream sss(line);
            string worddd;
            string dataaa[11];
            int j=0;
            while (sss >> worddd) { 
               dataaa[j]=worddd;
                j++;
            }
            if (dataaa[6] == booksISBN[bookIndex-1]){
                nfile << dataaa[0]+" " + dataaa[1] +" "+ dataaa[2]+" " + dataaa[3] +" "+ dataaa[4]+" " + dataaa[5]+" " + dataaa[6]+" " + dataaa[7]+" " + dataaa[8] + " free " + dataaa[10] << endl;
                
            }else{
                nfile << line << endl;
            }

            
        }
        file.close();
        nfile.close();

        system("CLS");
        cout << " returned sucssesfully" << endl;
    }
}


void homePage(user a){
    cout << "welcome "<<a.firstname<< endl;
    string optionn;
    while (true){
        cout <<"Options: search   returnBook"<<endl;
        cin >> optionn;
        if (optionn =="search"){
            search(a);
        }
        else if(optionn =="returnBook"){
            returnBook(a);
        }
        else{
            system("CLS");
        }
    }
}

int main()
{  
    string option;
    system("CLS");
    while (true){
        cout << "signup   login"<< endl;
        cin >> option;
        if (option == "signup"){
            signup();
        }
        else if(option == "login"){
            user a = login();
            homePage(a);
        }
        else{system("CLS");}
    }

    // search();
    return 0;
}
