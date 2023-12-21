#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
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
template<typename T>
int whereabouts(map<int, T>a, T t)
{
    for (auto itr = a.begin();itr != a.end();itr++)
    {
        if (itr->second == t) return itr->first;
    }
    return -1;
}
ostream& operator << (ostream& out, vector<int>& adj)
{
    for (auto& itr : adj)
    {
        out << itr << ' ';
    }
    return out;
}
class net
{
public:
    class CS
    {
    private:
        static int all_id;
    public:
        int id;
        bool operator == (const net::CS& cs2)
        {
            return this->name == cs2.name
                and this->wksh_num == cs2.wksh_num
                and this->active == cs2.active
                and this->eff == cs2.eff;
        }
        string name;
        int wksh_num, active, eff;
        CS();
        
        bool exist()
        {
            return this->name[0] - '0';
        }
    };
    unordered_map<int, vector<net::CS>>adj;
    void printAdjList(net::CS cs)
    {
        for (auto& i : this->adj[cs.id]) cout << i.name << " ";
        //cout << '\n';
    }
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
        for (auto& i : this->adj[cs.id])
        { // iterate through all adjacent vertices
            if (!isVisited(i))
            {
                topsort_action(i, visited, stack);
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
    };
    void topsort(map<int, net::CS> css)
    {
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
    void connect(map<int, net::CS>css, net::CS& a, net::CS& b, net::Pipe& p)
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
            p.start = a;
            p.end = b;
            int i = whereabouts(css, a);
            this->adj[i].push_back(b);
            cout << "CS's connected successfully\n";
        }
    }
    void printAdjMatrix(map<int,net::CS>css)
    {
        if (this->adj.empty())
        {
            cout << "The adjacency matrix is empty" << '\n';
            return;
        }
        for (auto& itr : this->adj)
        {
            cout << "Vertex " << css[itr.first].name << "'s adjacency list: ";
            for (auto& i : this->adj[itr.first]) cout << i.name << " ";
            cout << '\n';
        }
    }
};
int net::CS::all_id = -2;
net::CS::CS()
{
    name = "0";
    wksh_num = 0;
    active = 0;
    eff = 0;
    id = all_id;
    all_id++;
}
ostream& operator << (ostream& out, net::Pipe& a)
{
    out << "Name:                      " << a.name << endl
        << "Length:                    " << a.len << endl
        << "Diameter:                  " << a.diam << endl
        << "State:                     " << a.state << endl;
    return out;
}
ostream& operator << (ostream& out, net::CS& b)
{
    out << "Name:                      " << b.name << endl
        << "Workshops number:          " << b.wksh_num << endl
        << "Active workshops number:   " << b.active << endl
        << "Efficiency (0-5):          " << b.eff;
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
    net::Pipe pipe;
    map<int, net::CS>css;
    map<int, net::Pipe>pipes;

    for (int i = 1; i <= 5; i++)
    {
        net::CS cs;
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
    net.connect(css, css[1], css[4], pipes[0]);
    net.connect(css, css[5], css[3], pipes[1]);
    net.connect(css, css[4], css[3], pipes[2]);
    net.connect(css, css[3], css[2], pipes[3]);
    net.connect(css, css[5], css[2], pipes[4]);
    net.topsort(css);
}
