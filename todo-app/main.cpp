#include <iostream>
#include <vector>
using namespace std;

int main()
{

    cout << "This is my first program!";
    cout << "****************This is a todo app******************\n";
    vector<string> taskArray;
    string task;

    do
    {
        cout << "Enter a task (or 'x' to exit): ";
        getline(cin, task);
        if (task != "x" && !task.empty())
        {
            taskArray.push_back(task);
        }

    } while (task != "x");

    if (taskArray.empty())
    {
        cout << "You don't have any task on your list!";
    }
    else
    {
        cout << "Tasks entered:" << endl;
        for (const string &t : taskArray)
        {
            cout << t << endl;
        }
    }

    return 0;
}