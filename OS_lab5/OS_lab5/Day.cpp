#include <map>
#include <iostream>
#include <stack>
#include <windows.h>
#include <vector>
#include "Other functions.h"

using namespace std;
Day::Day()
{
    this->date = "1863.07.30";
    this->tasks = {};
}
bool Day::empty()
{
    return !tasks.size();
}
void Day::Add(map<string, Day*>& days, string date)
{
    if (days.find(date)==days.end())
    {
        cout << "You can't add a day that is already in the list" << '\n';
        return;
    }
    days.insert(pair<string, Day*>(date, {}));
    cout << "Day added successfully" << '\n';
}
void Day::Delete(map<string, Day*>& days, string date)
{
    if (!days.count(date))
    {
        cout << "You can't delete a day that isn't in the list" << '\n';
        return;
    }
    days.erase(date);
    cout << "Day deleted successfully" << '\n';
}
void Day::AddTask(string body)
{
    Task task;
    task.body = body;
    this->tasks.push_back(task);
}
void Day::DeleteTask(int index)
{
    this->tasks.erase(tasks.begin()+index-1);
}