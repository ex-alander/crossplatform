#include <map>
#include <iostream>
#include <stack>
#include <windows.h>
#include <vector>
#include <string>
#include "Other functions.h"
#include "Day.h"
using namespace std;
string date()
{
    string c_0;
    while (1)
    {
        getline(cin, c_0);
        if (DateCheck(c_0))
        {
            break;
        }
        cout << "I gave you clear instructions, you chose to disobey. Suffer.\n";
    }
    return c_0;
}

int main()
{
    // setting up the console so that it looks cool
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);
    map <string, Day*> Days;
    cout << "WELCOME TO THE TASKLIST" << '\n';
    while (true)
    {
        cout << "1. Add a day to the list" << '\n'
            << "2. Delete a day from the list" << '\n'
            << "3. Search for a day in the list" << '\n'
            << "4. Add a task to a day" << '\n'
            << "5. Delete a task" << '\n'
            << "6. Show all busy days" << '\n'
            << "7. Save the tasklist" << '\n'
            << "8. Load a tasklist" << '\n';
        int counter = 0;
        int c = number();

        switch (c) // control panel
        {
        case 1:
        {
            cout << "Choose day to add:" << '\n';
            string Date = date();
            Days[Date]->Add(Days,Date);
            break;
        }
        case 2:
        {
            cout << "Choose day to delete:" << '\n';
            string Date = date();
            Days[Date]->Delete(Days,Date);
            break;
        }
        case 3:
        {
            cout << "Choose day to search:" << '\n';
            string Date = date();
            DayDateSearch(Days,Date);
            break;
        }
        case 4:
        {
            cout << "Choose day:" << '\n';
            string Date = date();
            string task;
            cout << "Enter task body:" << '\n';
            getline(cin, task);
            Days[Date]->AddTask(task);
            break;
        }
        case 5:
        {
            cout << "Choose day:" << '\n';
            string Date = date();
            cout << "Here is the full list of tasks for this day:" << '\n';
            cout << Days[Date]->tasks;
            cout << "Enter the number of the task you wanna delete" << '\n';
            int task;
            task = number_big();
            Days[Date]->DeleteTask(task);
            cout << "Task deleted successfully" << '\n';
            break;
        }
        case 6: 
        {
            ShowAllBusyDays(Days);
            break;
        }
        case 7:
        {
            Save(Days);
            break;
        }
        case 8:
        {
            Load(Days);
            break;
        }
        case 0: // close
        {
            cout << "c ya";
            return 0;
        }

        case 9: // Russia
        {
            {
                SetConsoleTextAttribute(hConsole, 255);
                cout << 100000000;
                SetConsoleTextAttribute(hConsole, 0);
                cout << 1 << endl;
                SetConsoleTextAttribute(hConsole, 153);
                cout << 100000000;
                SetConsoleTextAttribute(hConsole, 0);
                cout << 1 << endl;
                SetConsoleTextAttribute(hConsole, 68);
                cout << 100000000;
                SetConsoleTextAttribute(hConsole, 0);
                cout << 1 << endl << endl;
                SetConsoleTextAttribute(hConsole, 11);
            }
            break;
        }
        default:
        {
            cout << "There's no such operation, why don't you try again\n";
        }
        }
    }

}