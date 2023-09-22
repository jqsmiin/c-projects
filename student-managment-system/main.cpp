// Student treba da ima prvo mogucnost da unese sve svoje predmete
// Nakon tog ima mogucnost da unese ocjenu za predmet, takodjer i da vidi informacije od prije
// Svaki student ima svoj akaunt
// Dakle prije nego pustimo studenta, mora biti registrovan
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <deque>
using namespace std;

void registerUser(string username, string email, string password);
bool loginUser(const std::string &username, const std::string &password);
int main()
{

    cout << "****************Student Managment System******************\n";

    int choice;
    string username;
    string email;
    string password;

    cout << "Enter your choice!\n";
    cout << "#1 - Registration\n";
    cout << "#2 - Login\n";

    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your email: ";
        cin >> email;
        cout << "Enter your password: ";
        cin >> password;
        registerUser(username, email, password);
    }
    else if (choice == 2)
    {
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;
        if (loginUser(username, password))
        {
            int option;
            std::cout << "Login successful.\n";
            cout << "Choose one of the options below\n";
            cout << "1. Enter your subjects: \n";
            cout << "2. Enter your grade: \n";
            cout << "3. See info: \n";

            switch (option)
            {
            case 1:
            }
        }
        else
        {
            std::cout << "Login failed.\n";
        }
    }

    return 0;
}
void registerUser(string username, string email, string password)
{
    ofstream file("data" + username + ".txt", ::ios::app);
    file << username << "," << email << "," << password << endl;

    cout << "Your registration is successfull.";
    file.close();
}
bool loginUser(const std::string &username, const std::string &password)
{
    ifstream file("data" + username + ".txt");
    if (!file.is_open())
    {
        std::cout << "User not found." << std::endl;
        return false; // User file does not exist
    }

    string userData;

    if (getline(file, userData))
    {
        istringstream iss(userData);
        string storedUsername, storedEmail, storedPassword;

        if (getline(iss, storedUsername, ',') &&
            getline(iss, storedEmail, ',') &&
            getline(iss, storedPassword))
        {
            if (username == storedUsername && password == storedPassword)
            {
                file.close();
                return true; // Credentials match
            }
        }
    }

    cout << "Invalid email or password.\n";
    file.close();
    return false;
}