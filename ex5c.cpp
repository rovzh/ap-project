

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <fstream>

class user{

public:
string username;
string password;
string firstname;
string lastname;
int birthdate;

    
};

class book{

string title;
int shelfnumber;
string authors;
int edition;
string publisher;
int publishedyear;
int ISBN;
int length;
string subjects;
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

        cout << "Username already exists" << endl;
        File.close();
        signup();
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
        MyFile<<un<<" "<<p<<" "<<fn<<" "<<ln<<" "<<bd;
        MyFile.close();
        File.close();
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
           cout<<"Login successful"<< endl;
           return a;
        }else{

            cout<<"Incorrect password"<< endl;
            File.close();
            return login();
        }
    }
    else
    {
        cout << "Username does not exists" << endl;
        File.close();
        return login();
    }

}

void search(){


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
                    for(int j=0; j<11; j++){
                        cout<<data[j]<<" ";
                    }
                    cout<<endl;
                    }
            }     

            if(searchway=="author"){

                if(author==data[2]){
                    for(int j=0; j<11; j++){
                        cout<<data[j]<<" ";
                    }
                    cout<<endl;
                    }
      
            }

            if(searchway=="publisher"){

                if(publisher==data[4]){
                    for(int j=0; j<11; j++){
                        cout<<data[j]<<" ";
                    }
                    cout<<endl;
                    }
      
            }   

            if(searchway=="published_year"){

                if(pubyear==data[5]){
                    for(int j=0; j<11; j++){
                        cout<<data[j]<<" ";
                    }
                    cout<<endl;
                    }
      
            }                      

        
    }
}

reserve(){

    string myText;
    ifstream MyFile("books.txt");
    while (getline (MyFile, myText)) {
        stringstream ss(myText);  
        string word;
        string data[11];
        int i=0;
        while (ss >> word) { 
            data[i]=word;
            i++;
        }

    if(data[9]=="free"){
        data[9]="occupied";
    }else{
        cout<<"this book is not available right now";
    }

    MyFile.close();
    }
}
returnbook(){

    string myText;
    ifstream MyFile("books.txt");
    while (getline (MyFile, myText)) {
        stringstream ss(myText);  
        string word;
        string data[11];
        int i=0;
        while (ss >> word) { 
            data[i]=word;
            i++;
        }

    if(data[9]=="occupied"){
        data[9]="free";
    }else{
        cout<<"this book is not available right now";
    }

    MyFile.close();
    }
}


int main()
{
    search();
    return 0;
}
