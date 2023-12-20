#include<iostream>
#include<map>
#include<string>
using namespace std;
string rectangle(string& x)
{
	string rect_x;
	string horiz_line="";
	for (int i = 0; i < x.length(); i++)
	{
		horiz_line += "-";
	}
	rect_x = "+" + horiz_line + "+" + "\n"
		   + "|"     + x +      "|" + "\n" 
		   + "+" + horiz_line + "+";
	return rect_x;
}
string operator*(string& symbol, int multi)
{
	string symbol1 = symbol;
	for (int i = 1; i <multi; i++)
	{
		symbol += symbol1;
	}
	return symbol;
}
int main()
{
	string name;
	getline(cin, name);
	cout << rectangle(name)<<endl;
	cout << name * 2;
}