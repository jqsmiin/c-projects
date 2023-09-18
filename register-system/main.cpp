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

    cout << "*****************Logind & Register System*****************";

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
            std::cout << "Login successful.\n";
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