#include <map>
#include <iostream>
#include <stack>
#include <windows.h>
#include <vector>
#include <string>
#include <fstream>
#include "Day.h"
#define NOMINMAX
using namespace std;
/*OPERATOR OVERLOADING*/
ostream& operator << (ostream& out, vector<Task>& st)
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (st.empty())return out;
    int i = 0;
    for (auto& itr: st)
    {
        if (itr.completed) SetConsoleTextAttribute(hConsole, 10);
        out << "(" << ++i << ")" << (char)15 << " " << itr.body << "\n";
        SetConsoleTextAttribute(hConsole, 15);
    }
    return out;
}

string rectangle(const string x) // to make this nice little rectangle around the function
{
    string rect_x;
    string horiz_line = "";
    for (int i = 0; i < x.length(); i++)
    {
        horiz_line += "-";
    }
    rect_x = "+" + horiz_line + "+" + "\n"
        + "|" + x + "|" + "\n"
        + "+" + horiz_line + "+";
    return rect_x;
}

/*BOYER MOORE SEARCH FOR NAMES*/
const int ALPHABET_SIZE = 256;
void computeBadCharShift(const string& pattern, vector<int>& badCharShift) {
    int m = pattern.length();

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        badCharShift[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        badCharShift[(int)pattern[i]] = i;
    }
}
bool BoyerMoore_bool(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    int count = 0;

    std::vector<int> badCharShift(ALPHABET_SIZE, 0);
    computeBadCharShift(pattern, badCharShift);

    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }
        if (j < 0) {
            //std::cout << "Pattern found at index " << s << std::endl;
            return true;
            if (s + m < n) {
                s += m - badCharShift[text[s + m]];
            }
            else {
                s += 1;
            }
        }
        else {
            s += max(1, j - badCharShift[text[s + j]]);
        }
    }
    return false;
}

/*NUMBER-GETTER*/
bool IntCheck(string x)
{
    for (int i = 0; i < x.length(); i++)
    {
        if ((int)x[i] < 48 or 57 < (int)x[i]) return 0;
    }
    return 1;
}
int lenCheck(string x)
{
    if (x.length() == 1) return 1;
    else return 0;
}
int number()
{
    int c;
    string c_0;
    while (1) // number check
    {
        getline(cin, c_0);
        if (IntCheck(c_0) and lenCheck(c_0))
        {
            c = stoi(c_0);
            break;
        }
        cout << "wrong input, you slimo" << '\n';
    }
    return c;
}
int number_big()
{
    int c;
    string c_0;
    while (1) // number check
    {
        getline(cin, c_0);
        if (c_0 != "")
        {
            if (IntCheck(c_0))
            {
                c = stoi(c_0);
                break;
            }
        }
        cout << "wrong input" << '\n';
    }
    return c;
}

/*DATE-GETTER*/
string slice(string x, int start, int end)
{
    string slicie = "";
    for (int i = start; i <= end; i++)
    {
        slicie += x[i];
    }
    return slicie;
}
int DayLength(string month, int year)
{
    if (month == "02" and year % 4 and !(year % 100)) return 29;
    else if (month == "02" and (!(year % 4) or (year % 100))) return 28;
    else if (month == "01" or month == "04" or month == "06" or month == "09" or month == "11") return 30;
    else if (month == "03" or month == "05" or month == "07" or month == "08" or month == "10" or month == "12") return 31;
    else return -1;
}
bool DateCheck(string x)
{
    if (x.length() != 10)
    {
        cout << "that's not what I requested" << '\n';
        return false;
    }
    string year = slice(x, 0, 3);
    char dot1 = x[4];
    string month = slice(x, 5, 6);
    char dot2 = x[7];
    string day = slice(x, 8, 9);
    if (IntCheck(year)
        and IntCheck(month)
        and IntCheck(day)
        and dot1 == '.'
        and dot2 == '.')
    {
        if (stoi(month) <= 12 and stoi(month) > 0 and stoi(day) <= DayLength(month, stoi(year))) return 1;
        else return 0;
    }
    else return 0;
}


/*BUSY DAYS*/
void ShowAllBusyDays(map<string, Day*>days)
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 9);
    for (auto itr = days.begin(); itr != days.end(); itr++)
    {
        if (!itr->second->empty())
        {
            cout << rectangle(itr->first) << '\n';
        }
    }
    SetConsoleTextAttribute(hConsole, 15);
    cout << "Wanna show all their tasks at once? (y/n)" << '\n';
    string yn;
    getline(cin, yn);
    if (yn == "y")
    {
        bool switcher = false;
        for (auto itr = days.begin(); itr != days.end(); itr++)
        {
            if (itr->second->empty()) continue;
            HANDLE  hConsole;
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            if(switcher)SetConsoleTextAttribute(hConsole, 7);
            else SetConsoleTextAttribute(hConsole, 15);
            cout << itr->second->tasks << '\n';
            SetConsoleTextAttribute(hConsole, 15);
            switcher = !switcher;
        }
    }
}
/*DAY DATE SEARCH*/
void DayDateSearch(map<string, Day*>days, string date)
{
    bool foundcheck = false;
    for (auto itr = days.begin(); itr != days.end(); itr++)
    {
        if (itr->first == date)foundcheck = true;
    }
    if (!foundcheck)
    {
        cout << date << ": " << "No such day in the tasklist" << '\n';
        return;
    }
    cout << "Now that you've found it, what do you wanna do?" << '\n'
        << "1. Show all tasks" << '\n'
        << "2. Mark all tasks as completed" << '\n'
        << "3. Delete the day" << '\n' << '\n';
    int c = number();
    switch (c)
    {
    case 1:
    {
        cout << days[date]->tasks;
        break;
    }
    case 2:
    {
        for (int i = 0; i< days[date]->tasks.size(); i++)
        days[date]->tasks[i].completed=true;
        break;
    }
    case 3:
    {
        days[date]->Delete(days,date);
        break;
    }
    default:
    {
        cout << "Try again" << '\n';
    }
    }

}
/*SAVE&LOAD*/
void Save(map<string, Day*>days)
{
    ofstream out;
    out.open("tasklist.txt");
    if (out.is_open())
    {
        if (!days.empty())
        {
            for (auto itr = days.begin(); itr != days.end();itr++)
            {
                out << itr->first << '\n';
                for (auto& i : itr->second->tasks)
                {
                    out << i.body << '\n' << (int)i.completed << '\n';
                }
            }
        }
        else
        {
            cout << "no data to save" << '\n'; 
            return;
        }
    }
    cout << "saved." << '\n';
    out.close();
}
void Load(map<string, Day*>&days)
{
    string str_compl;
    string date;
    string body;
    days.clear();
    ifstream in;
    int i = 0;
    in.open("tasklist.txt");
    if (in.is_open())
    {
        while(true)
        {
            getline(in, date);
            if (!date[0])break;
            while (true)
            {
                getline(in, body);
                if (DateCheck(body)) break;
                getline(in, str_compl);
                days[date]->tasks[i++].body = body;
                days[date]->tasks[i++].completed = stoi(str_compl);
            }
        }
    }
    cout << "info loaded." << '\n';
    in.close();
}