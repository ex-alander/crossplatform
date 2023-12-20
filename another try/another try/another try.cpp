#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


struct Pipe
{
    string name;
    int len = 0;
    int diam = 0;
    string maint;
};
struct CS
{
    string name;
    int wksh_num = 0;
    int act_wksh_num = 0; // <=workshop_num!
    float eff = 0; // from 1 to 10
};
//void one(string x, int y, int z, bool w) // <-- that'd work if we were allowed to use global variables
//{
//    int i;
//    string g;
//    cout << "\nSo you wanna add a new pipe, huh? Write, one after another, the following details:";
//    cout << "\n1. Name\n2. Length\n3. Diameter\n4. 'Maintenance'/'Ready'\n" << endl;
//    i = 1;
//    cout << i << ". ";
//    cin >> x;
//    i++;
//    cout << i << ". ";
//    cin >> g;
//    if (stoi(g)) y = stoi(g);  
//    else y = 0;
//    i++;
//    cout << i << ". ";
//    cin >> g;
//    if (stoi(g)) z = stoi(g);
//    else z = 0;
//    i++;
//    cout << i << ". ";
//    while (0 != 1)
//    {
//        cin >> g;
//        try {
//            if (stoi(g)) w = 1;
//            else w = 0;
//            break;
//        }
//        catch (...) {
//            cout << "Wrong.\n";
//        }
//    }
//}
int SpellCheck(string x)
{
    if (x[0] != '0'
        and x[0] != '-'
        and x[0] != ':'
        and x[0] != ','
        and x[0] != '.'
        and x[0] != '/'
        and x[0] != '|'
        and x[0] != ';') return 1;
    else return 0;
}
void MenuCall(int a) {
    if (a == 1)
    {
        cout << "Welcome to the pipeline description module! \nHere's what you can do:\n1. Add a pipe & describe it\n2. Add a CS & describe it\n3. View all described objects\n4. Edit existing pipe\n5. Edit existing CS\n6. Save\n7. Load\n0. Exit\n0*. Secret function: make '==='" << endl;
        cout << "\nEnter operation number:" << endl;
    }
    else if (a == 2)
    {
        cout << "You did't even try.\n";
    }
    else if (a == 3)
    {
        cout << "Changes were saved temporarily (to save them permamently, press '6').\n";
    }
    else if (a == 4)
    {
        cout << "You can't edit an object that doesn't exist";
    }
    else if (a == 5)
    {
        cout << "You can't call it like that, sorry.\n";
    }
    else if (a == 10)
    {
        cout << "\nSo you wanna add a new pipe, huh? Write, one after another, the following details:";
        cout << "\n1. Name\n2. Length\n3. Diameter\n4. 'Maintenance'/'Ready'\n" << endl;
    }
    else if (a == 20)
    {
        cout << "\nWanna add a new CS? Write, one after another, the following details:";
        cout << "\n1. Name\n2. Number of workshops\n3. Number of workshops in use\n4. Efficiency\n" << endl;
    }
    else if (a == 40)
    {
        cout << "\nEdit pipe info.\nChoose what detail to edit:\n1. Name\n2. Length\n3. Diameter\n4. 'Maintenance'/'Ready'\n5. Everything at once\n0. Exit\n";
    }
    else if (a == 50)
    {
        cout << "\nEdit CS info.\nChoose what detail to edit:\n1. Name\n2. Number of workshops\n3. Number of workshops in use\n4. Efficiency\n5. Everything at once\n0. Exit\n";
    }
}
int IntCheck(string x)
{
    try
    {
        if (stoi(x))1 < 2;
        return 1;
    }
    catch (...)
    {
        MenuCall(2);
        return 0;
    }
}
int main()
{
    string c_0 = "1";
    int c = stoi(c_0);
    int i = 0;
    Pipe A;
    CS B;
    MenuCall(1);
    while (c != 0) {
        while (1 < 2)
        {
            cin >> c_0;
            if (IntCheck(c_0))
            {
                c = stoi(c_0);
                break;
            }
        }
        if (c == 1) {
            //one(A.name, A.len, A.diam, A.maint); // <--that'd if we were allowed to use global variables 
            string g;
            MenuCall(10);
            i = 1;
            while (0 != 1)
            {
                cout << i << ". ";
                cin >> A.name;
                if (SpellCheck(A.name)) break;
                else cout << "You can't call it like that, sorry.\n";
            }
            i++;
            while (0 != 1)
            {
                cout << i << ". ";
                cin >> g;
                if(IntCheck(g)) {
                    A.len = stoi(g);
                    break;
                }
            }
            i++;
            while (0 != 1)
            {
                cout << i << ". ";
                cin >> g;
                try
                {
                    A.diam = stoi(g);
                    break;
                }
                catch (...)
                {
                    MenuCall(2);
                }
            }
            i++;
            cout << "Is the pipe under maintenance?\n";
            while (0 != 1)
            {
                cout << i << ". ";
                cin >> g;
                try {
                    if (g == "Yes" or g == "yes" or g == "YES" or g == "yES")
                    {
                        A.maint = "Maintenance";
                        break;
                    }
                    else if (g == "No" or g == "no" or g == "NO" or g == "nO" or g == "yEs(sarcastic)")
                    {
                        A.maint = "Ready_for_exploitation";
                        break;
                    }
                    else cout << "YES OR NO DUMMY (please)\n";

                }
                catch (...) {
                    MenuCall(2);
                }
            }

        }
        else if (c == 2) {
            MenuCall(20);
            string g;
            i = 1;
            while (0 != 1)
            {
                cout << i << ". ";
                cin >> B.name;
                if (SpellCheck(B.name)) break;
                else cout << "You can't call it like that, sorry.\n";
            }
            i++;
            while (0 != 1)
            {
                cout << i << ". ";
                cin >> g;
                try {
                    B.wksh_num = stoi(g);
                    break;
                }
                catch (...) {
                    MenuCall(2);
                }
            }
            i++;
            while (0 != 1)
            {
                cout << i << ". ";
                cin >> g;
                try {
                    if (stoi(g) <= B.wksh_num)
                    {
                        B.act_wksh_num = stoi(g);
                        break;
                    }
                    else cout << "You can't use more workshops than you have, genius.\n";
                }
                catch (...) {
                    MenuCall(2);
                }
            }
            i++;
            while (0 != 1)
            {
                cout << i << ". ";
                try
                {
                    cin >> g;
                    float f = stof(g);
                    if (f >= 0 and f <= 1)
                    {
                        B.eff = f;
                        break;
                    }
                    else
                    {
                        cout << "Wrong efficiency data.\n---------\nHint: the number must be between 0 and 1\n---------\n";
                    }
                }
                catch (...)
                {
                    MenuCall(2);
                }

            }
        }
        else if (c == 3) {
            cout << "\nPipe info:\n";
            cout << "1. " << A.name << endl
                << "2. " << A.len << endl
                << "3. " << A.diam << endl
                << "4. " << A.maint << endl;
            cout << "\nCS info:\n";
            cout << "1. " << B.name << endl
                << "2. " << B.wksh_num << endl
                << "3. " << B.act_wksh_num << endl
                << "4. " << B.eff << endl;
        }
        else if (c == 4) {
            if (A.name[0])
            {
                MenuCall(4);
            }
            int a;
            MenuCall(40);
            while (1 < 2) {
                cin >> a;
                if (a == 1) // editing name
                {
                    cin >> A.name;
                    MenuCall(3);
                    break;
                }
                else if (a == 2) // editing length
                {
                    cin >> A.len;
                    MenuCall(3);
                    break;
                }
                else if (a == 3) // editing diameter
                {
                    cin >> A.diam;
                    MenuCall(3);
                    break;
                }
                else if (a == 4) // editing maintenance
                {
                    cin >> A.maint;
                    MenuCall(3);
                    break;
                }
                else if (a == 5) // editing everything
                {
                    string g;
                    MenuCall(10);
                    i = 1;
                    cout << i << ". ";
                    cin >> A.name;
                    i++;
                    while (0 != 1)
                    {
                        cout << i << ". ";
                        cin >> g;
                        try {
                            A.len = stoi(g);
                            break;
                        }
                        catch (...)
                        {
                            MenuCall(2);
                        }

                    }
                    i++;
                    while (0 != 1)
                    {
                        cout << i << ". ";
                        cin >> g;
                        try
                        {
                            A.diam = stoi(g);
                            break;
                        }
                        catch (...)
                        {
                            MenuCall(2);
                        }
                    }
                    i++;
                    cout << "Is the pipe under maintenance?\n";
                    while (0 != 1)
                    {
                        cout << i << ". ";
                        cin >> g;
                        try {
                            if (g == "Yes" or g == "yes" or g == "YES" or g == "yES")
                            {
                                A.maint = "Maintenance";
                                break;
                            }
                            else if (g == "No" or g == "no" or g == "NO" or g == "nO" or g == "yEs(sarcastic)")
                            {
                                A.maint = "Ready_for_exploitation";
                                break;
                            }
                            else cout << "YES OR NO DUMMY (please)\n";

                        }
                        catch (...) {
                            MenuCall(2);
                        }
                    }
                    MenuCall(3);
                    break;
                }
                else if (a == 0)
                {
                    break;
                }
                else cout << "Incorrect detail number. Try again:\n";
            }
        }
        else if (c == 5) {
            string a;
            int csdet;
            MenuCall(50);
            while (1 < 2) {
                while (0 != 1)
                {
                    cin >> a;
                    try
                    {
                        csdet = stoi(a);
                        break;
                    }
                    catch (...)
                    {
                        MenuCall(2);
                    }
                }
                if (csdet == 1)
                {
                    cin >> B.name;
                    MenuCall(3);
                    break;
                }
                else if (csdet == 2)
                {
                    cin >> B.wksh_num;
                    MenuCall(3);
                    break;
                }
                else if (csdet == 3)
                {
                    cin >> B.act_wksh_num;
                    MenuCall(3);
                    break;
                }
                else if (csdet == 4)
                {
                    cin >> B.eff;
                    MenuCall(3);
                    break;
                }
                else if (csdet == 5)
                {
                    cin >> A.name >> A.len >> A.diam >> A.maint;
                    MenuCall(3);
                    break;
                }
                else if (csdet == 0)
                {
                    cout << "Exit to main menu.\n";
                    break;
                }
                else cout << "Incorrect detail number. Try again:\n";
            }
        }
        else if (c == 6) {
            ofstream out; // opening the file (writing mode)
            out.open("hello.txt");
            if (out.is_open())
            {
                out << A.name << endl
                    << A.len << endl
                    << A.diam << endl
                    << A.maint << endl
                    << B.name << endl
                    << B.wksh_num << endl
                    << B.act_wksh_num << endl
                    << B.eff << endl;
            }
            out.close(); // closing the file
            cout << "Saved." << endl;
        }
        else if (c == 7) {
            int kl = 0;
            string line;
            ifstream in("hello.txt"); // opening the file (reading mode)
            if (in.is_open())
            {
                in >> A.name;
                in >> A.len;
                in >> A.diam;
                in >> A.maint;
                in >> B.name;
                in >> B.wksh_num;
                in >> B.act_wksh_num;
                in >> B.eff;
            }
            in.close();     // closing the file
            cout << "info loaded.\n";
        }
        else if (c == 10) {
            cout << "a===b\n";
        }
        else if (c == 0) {
            cout << "c ya\n";
            break;
        }
    }
    return 0;
}