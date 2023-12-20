#pragma once
#include <map>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
class Task
{
public:
    string body;
    bool completed;
    Task()
    {
        body = {};
        completed = false;
    }
};
class Day
{
public:
    string date;
    vector<Task>tasks;
    Day();
    bool empty();
    void Add(map<string, Day*>& days, string date);
    void Delete(map<string, Day*>& days, string date);
    void AddTask(string body);
    void DeleteTask(int index);
};