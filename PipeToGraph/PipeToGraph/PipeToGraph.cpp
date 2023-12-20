#include <iostream>
#include <vector>
#include <map>
#include <stack>
/*
deleting from graph
it doesn't delete the object
deleting the object must delete it from graph
isCyclic!*/
using namespace std;
string slice(string x, int start, int end)
{
    string slicie = "";
    for (int i = start; i <= end; i++)
    {
        slicie += x[i];
    }
    return slicie;
}
void Divider()
{
    cout << "----------------------------------------------------------------------------------\n";
}
void PDivider()
{
    cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . .\n";
}
template<typename T>
void PrintMap(map <int, T> a)
{
    PDivider();
    string typenamie = typeid(a[0]).name();
    typenamie = slice(typenamie, 11, typenamie.length() - 1);
    for (auto itr = a.begin();itr != a.end();itr++)
    {
        cout << "\t\t" << typenamie << " #" << itr->first << endl << itr->second << '\n';
        PDivider();
    }
}
class net
{
public:
    class CS
    {

    public:
        bool operator == (const net::CS& cs2)
        {
            return this->name == cs2.name
                and this->wksh_num == cs2.wksh_num
                and this->active == cs2.active
                and this->eff == cs2.eff;
        }
        string name;
        int wksh_num, active, eff;
        vector <net::CS> adj;
        CS()
        {
            name = "0";
            wksh_num = 0;
            active = 0;
            eff = 0;
        }
        bool exist()
        {
            return this->name[0] - '0';
        }
        void printAdjacents()
        {
            cout << "Vertex " << this->name << "'s adjacency list: ";
            for (auto i : this->adj)
            {
                cout << i.name << ' ';
            }
            cout << "\n";
        }
    };
private:

    vector<net::CS>visited;
    bool isVisited(net::CS a)
    {
        for (auto& i : this->visited)
        {
            if (i == a) return true;
        }
        return false;
    }
    void topsort_action(net::CS cs, vector<net::CS>& visited, stack<net::CS>& stack)
    { // we'll update our vertices stack
        visited.push_back(cs); // mark that we've gone through the vertex
        cs.printAdjacents();
        //if (cs.name == "cs3")
        //{
        //    cout << cs.adj[0].name << endl;
        //}
        for (auto& i : cs.adj) 
        { // iterate through all adjacent vertices
            if (!isVisited(i))
            {
                /*if (i.name == "cs3")
                {
                    cout << i.adj[0].name << "100" << endl;
                }*/
                topsort_action(i, visited, stack);
                /*if (i.name == "cs3")
                {
                    cout << i.adj[0].name << "100" << endl;
                }*/
            }
        }
        stack.push(cs);
    }
public:
    class Pipe
    {
    private:
        bool on = true;

    public:
        bool operator == (const net::Pipe& pipe2)
        {
            return this->name == pipe2.name
                and this->len == pipe2.len
                and this->diam == pipe2.diam
                and this->state == pipe2.state
                and this->start == pipe2.start
                and this->end == pipe2.end;
        }
        string name, state;
        int len, diam;
        CS start;
        CS end;
        const CS nullCS;
        Pipe()
        {
            name = "0";
            len = 0;
            diam = 0;
            state = "0";
            start = nullCS;
            end = nullCS;
        }
        bool exist()
        {
            return this->name[0] - '0';
        }
        void flick()
        {
            if (state == "Ready for exploitation") state = "Under maintenance";
            else state = "Ready for exploitation";
        }
        void connect(CS& a, CS& b)
        {
            if (!a.exist() or !b.exist())
            {
                cout << "ERROR: object(s) not found\n";
                return;
            }
            if (a == b)
            {
                cout << "Connecting a CS to iteslf? Genius. \n";
            }
            else
            {
                start = a;
                end = b;
                a.adj.push_back(b);
                cout << "CS's connected successfully\n";
                cout << "the start of the new edge is " << this->start.name << '\n'
                    << "and the end of it is " << this->end.name << '\n';
                cout << '\n' << "now its adj list is: ";
                for (int i = 0; i < a.adj.size(); i++) cout << a.adj[i].name << " ";
                cout << "\n\n";
            }
        }
        void disconnect()
        {
            start = end = nullCS;
            //start.pop(end);
        }
    };
    void topsort(map<int, net::CS> css)
    {
        PrintMap(css);
        stack<net::CS> stack;
        for (auto& itr : css) 
        {
            if (!isVisited(itr.second)) {
                topsort_action(itr.second, this->visited, stack);
            }
        }
        //print stack contents
        while (!stack.empty()) 
        {
            cout << stack.top().name << " ";
            stack.pop();
        }
    }
};
ostream& operator << (ostream& out, net::Pipe& a)
{
    out << "Name:                      " << a.name << endl
        << "Length:                    " << a.len << endl
        << "Diameter:                  " << a.diam << endl
        << "State:                     " << a.state << endl;
    return out;
}
ostream& operator << (ostream& out, vector<net::CS>& adj)
{
    for (auto& itr : adj)
    {
        out << itr.name << ' ';
    }
    return out;
}
ostream& operator << (ostream& out, net::CS& b)
{
    out << "Name:                      " << b.name << endl
        << "Workshops number:          " << b.wksh_num << endl
        << "Active workshops number:   " << b.active << endl
        << "Efficiency (0-5):          " << b.eff << endl
        << "Adjacency list:            " << b.adj;
    return out;
}
ostream& operator << (ostream& out, stack<net::CS>& st)
{
    while (st.size())
    {
        out << st.top().name << ' ';
        st.pop();
    }
    out << '\n';
    return out;
}
int main()
{
    net net;
    net::CS cs;
    net::Pipe pipe;
    map<int, net::CS>css;
    map<int, net::Pipe>pipes;

    for (int i = 1; i<=5; i++)
    {
        css.insert(pair<int, net::CS>(i, cs));
        css[i].name = { 'c','s', {(char)(i + 48)} };
    }
    for (int i = 0; i < 12; i++)
    {
        pipes.insert(pair<int, net::Pipe>(i, pipe));
    }
    /*pipes[3].connect(css[4], css[3]);
    pipes[4].connect(css[3], css[2]);
    pipes[1].connect(css[5], css[2]);
    pipes[0].connect(css[5], css[3]);
    pipes[2].connect(css[1], css[4]);*/
    pipes[0].connect(css[4], css[5]);
    pipes[1].connect(css[4], css[3]);
    pipes[2].connect(css[1], css[3]);
    pipes[3].connect(css[3], css[2]);
    PrintMap(css);
    net.topsort(css);




}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
