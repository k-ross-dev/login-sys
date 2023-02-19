#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <filesystem>

using namespace std;

void encrypt(string filename){
    fstream fin, fout;
    char c;
    int key = 1234;

    fin.open(".\\"+ filename + ".txt", fstream::in);
    fout.open(".\\"+ filename + "_enc.txt", fstream::out);

    while(fin >> noskipws >> c) {
        int temp = (c + key);

        fout << (char)temp;
    }
    fin.close();
    fout.close();
}

void decrypt(string filename){
    fstream fin, fout;
    char c;
    int key = 1234;

    fin.open(".\\"+ filename + "_enc.txt", fstream::in);
    fout.open(".\\"+ filename + ".txt", fstream::out);

    while (fin >> noskipws >> c) {
 
        // Remove the key from the
        // character
        int temp = (c - key);
        fout << (char)temp;
    }

    fin.close();
    fout.close();
}

bool is_logged_in()
{
    string username,password,u,p;
    struct stat buffer;   

    cout << "Enter Username: "; cin >> username;
    cout << "Enter Password: "; cin >> password;

    try  
    {
        decrypt(username); 
        ifstream read(".\\"+ username + ".txt");
        getline(read, u);
        getline(read, p);
    }
    catch (const ifstream::failure& e)
    {
        return false;
    }

    // re-encrypt and then delete temp file.
    encrypt(username);
    std::filesystem::remove(".\\"+ username + ".txt");

    if(u == username && p == password)
    {
        
        return true;
    }
    else
    {
        return false;

    }
}

int main()
{
    int choice;

    cout << "1. Register\n2. Login\nPlease Select: "; cin >> choice;
    if(choice == 1)
    {
        string username, password;
        cout << "Enter your Username: "; cin >> username;
        cout << "Enter your Password: "; cin >> password;

        ofstream file;
        file.open(".\\"+ username + ".txt");

        file << username << endl << password;

        file.close();

        encrypt(username);

        main();
    }
    else if (choice == 2)
    {
        bool status = is_logged_in();

        if(!status)
        {
            cout << "Incorrect Username or password! ";
            system("PAUSE");
            return 0;
        }
        else 
        {
            cout << "You are now logged in." << endl;
            system("PAUSE");
            return 1;
        }
    }
}