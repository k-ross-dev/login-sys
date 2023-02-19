#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool is_logged_in()
{
    string username,password,u,p;

    cout << "Enter Username: "; cin >> username;
    cout << "Enter Password: "; cin >> password;

    ifstream read(".\\"+ username + ".txt");
    getline(read, u);
    getline(read, p);

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