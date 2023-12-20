#pragma once
#include <map>
#include <iostream>
#include <windows.h>
#include <vector>
#include "Day.h"
using namespace std;
string rectangle(const string x);
/*BOYER MOORE SEARCH FOR NAMES*/
const int ALPHABET_SIZE = 256;
void computeBadCharShift(const string& pattern, vector<int>& badCharShift);
bool BoyerMoore_bool(const string& text, const string& pattern);
/*NUMBER-GETTER*/
bool IntCheck(string x);
int lenCheck(string x);
int number();
int number_big();
/*DATE-GETTER*/
string slice(string x, int start, int end);
int DayLength(string month, int year);
bool DateCheck(string x);
/*OPERATOR OVERLOADING*/
ostream& operator << (ostream& out, vector<Task>& st);
/*SHOW ALL BUSY DAYS*/
void ShowAllBusyDays(map<string, Day*>days);
/*DAY DATE SEARCH*/
void DayDateSearch(map<string, Day*>days, string date);
/*SAVE&LOAD*/
void Save(map<string, Day*>days);
void Load(map<string, Day*>& days);