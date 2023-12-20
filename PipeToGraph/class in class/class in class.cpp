#include <iostream>
#include <Windows.h>
#include <cwchar>
#include <vector>
#pragma comment(lib, "user32")
//#include <queue>

using namespace std;

/*MY WAY*/
//class net
//{
//
//public:
//    class CS
//    {
//
//    public:
//        bool operator == (const net::CS& cs2)
//        {
//            return this->name == cs2.name
//                and this->wksh_num == cs2.wksh_num
//                and this->active == cs2.active
//                and this->eff == cs2.eff;
//        }
//        string name;
//        int wksh_num, active, eff;
//        CS()
//        {
//            name = "0";
//            wksh_num = 0;
//            active = 0;
//            eff = 0;
//        }
//        bool exist()
//        {
//            return this->name[0] - '0';
//        }
//    };
//
//    class Pipe
//    {
//    private:
//        bool on = true;
//
//    public:
//        bool operator == (const net::Pipe& pipe2)
//        {
//            return this->name == pipe2.name
//                and this->len == pipe2.len
//                and this->diam == pipe2.diam
//                and this->state == pipe2.state
//                and this->start == pipe2.start
//                and this->end == pipe2.end;
//        }
//        string name, state;
//        int len, diam;
//        CS start;
//        CS end;
//        const CS nullCS;
//        Pipe()
//        {
//            name = "0";
//            len = 0;
//            diam = 0;
//            state = "0";
//            start = nullCS;
//            end = nullCS;
//        }
//        bool exist()
//        {
//            return this->name[0] - '0';
//        }
//        void flick()
//        {
//            if (state == "Ready for exploitation") state = "Under maintenance";
//            else state = "Ready for exploitation";
//        }
//        void connect(CS a, CS b)
//        {
//            if (!a.exist() or !b.exist())
//            {
//                cout << "ERROR: object(s) not found\n";
//                return;
//            }
//            if (a == b)
//            {
//                cout << "Connecting a CS to iteslf? Genius. \n";
//            }
//            else
//            {
//                start = a;
//                end = b;
//                cout << "CS's connected successfully\n";
//                cout << "the start of the new edge is " << this->start.name << '\n'
//                    << "and the end of it is " << this->end.name << '\n';
//            }
//        }
//        void disconnect()
//        {
//            start = end = nullCS;
//        }
//    };
//};
//class Graph {
//public:
//    map<net::CS, vector<net::Pipe>> adjacencyList;
//
//    // �����������
//    Graph(vector<net::Pipe> const& edges, int N) {
//
//        // ��������� ����� � ����
//        for (auto& edge : edges) {
//            adjacencyList[edge.start].push_back(edge);
//        }
//    }
//};
/*END MY WAY*/

// ����� ��� ������������� ����� � �����
class Edge {
public:
    int start, end, weight;
};

// ����� ��� ������������� �����
class Graph {
public:
    vector<vector<Edge>> adjacencyList;

    // �����������
    Graph(vector<Edge> const& edges, int N) {
        adjacencyList.resize(N);

        // ��������� ����� � ����
        for (auto& edge : edges) {
            adjacencyList[edge.start].push_back(edge);
        }
    }
};

// ������� ��� �������� ������� ����� � �����
bool isCyclicUtil(int v, vector<bool>& visited, vector<bool>& recStack, vector<vector<Edge>>& adjacencyList) {
    if (!visited[v]) {
        // �������� ������� ������� ��� ���������� � ��������� � ���� ��������
        visited[v] = true;
        recStack[v] = true;

        // ���������� ��������� ������� �������
        for (auto& edge : adjacencyList[v]) {
            int dest = edge.end;
            if (!visited[dest] && isCyclicUtil(dest, visited, recStack, adjacencyList)) {
                return true;
            }
            else if (recStack[dest]) {
                return true;
            }
        }
    }

    // ������� ������� �� ����� �������� ����� �������
    recStack[v] = false;

    return false;
}

// ������� ��� �������� ������� ����� � �����
bool isCyclic(Graph& graph, int N) {
    // ������ ��� ������������ ���������� ������
    vector<bool> visited(N, false);
    // ������ ��� ������������ ������ � ����� ��������
    vector<bool> recStack(N, false);

    for (int i = 0; i < N; i++) {
        if (isCyclicUtil(i, visited, recStack, graph.adjacencyList)) {
            return true;
        }
    }

    return false;
}

// ������� ��� �������������� ���������� �����
void topologicalSortUtil(int v, vector<bool>& visited, vector<Edge>& result, vector<vector<Edge>>& adjacencyList) {
    visited[v] = true;

    for (auto& edge : adjacencyList[v]) {
        if (!visited[edge.end]) {
            topologicalSortUtil(edge.end, visited, result, adjacencyList);
        }
    }

    // ��������� ������� � ������ ����������
    result.insert(result.begin(), adjacencyList[v].begin(), adjacencyList[v].end());
}

// ������� ��� ������ �������������� ���������� �����
vector<Edge> topologicalSort(Graph& graph, int N) {
    // ��������� ������� ����� � �����
    if (isCyclic(graph, N)) {
        printf("There's a cycle in the graph. Top sort cannot be completed.");
        return {};
    }

    // ������ ��� ������������ ���������� ������
    vector<bool> visited(N, false);
    // ������ ��� �������� ���������� �������������� ����������
    vector<Edge> result;

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, result, graph.adjacencyList);
        }
    }

    return result;
}

int main() {
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 18;                  // Height
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    // ������ �����
    vector<Edge> edges = {
            {0, 1, 5},
            {0, 2, 3},
            {1, 3, 2},
            {2, 3, 6},
            {2, 4, 4},
            {3, 4, 1}
    };

    int N = 5; // ���������� ������ � �����

    // ������� ����
    Graph graph(edges, N);

    try {
        // ��������� �������������� ����������
        vector<Edge> result = topologicalSort(graph, N);

        // ������� ���������
        cout << "Top sort: ";
        for (auto& edge : result) {
            cout << edge.start << " ";
        }
        cout << endl;
    }
    catch (runtime_error const& e) {
        cerr << e.what() << endl;
    }

    return 0;
}