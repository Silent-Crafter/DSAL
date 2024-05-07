#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    map<string, map<string, int>> adjMatrix;

public:
    Graph(vector<string> vertices) {
        // Initialize matrix
        for (auto parent : vertices) {
            for (auto child: vertices) {
                adjMatrix[parent][child] = 0;
            }
        }
    }

    void DFS(string start, vector<string>& order) {
        stack<string> s;
        unordered_map<string, bool> visited;

        s.push(start);

        while (!s.empty()) {
            auto curr = s.top();
            s.pop();

            if (!visited[curr]) {
                visited[curr] = true;
                order.push_back(curr);
            }

            for (const auto& neighbour : adjMatrix[curr]) {
                if (!visited[neighbour.first]  && neighbour.second == 1) {
                    s.push(neighbour.first);
                }
            }
        }
    }

    void BFS(string start, vector<string>& order) {
        queue<string> q;
        unordered_map<string, bool> visited;
        string curr;

        q.push(start);

        while(!q.empty()) {
            curr = q.front();
            q.pop();

            if (!visited[curr]) {
                visited[curr] = true;
                order.push_back(curr);
            }

            for (auto neighbour : adjMatrix[curr]) {
                if (!visited[neighbour.first] && neighbour.second == 1)
                    q.push(neighbour.first);
            }
        }
    }

    void addEdge(string parent, string child) {
        adjMatrix[parent][child] = 1;
        adjMatrix[child][parent] = 1;
    }
};

int main() {

    // Create Graph
    Graph g({"Bus stop", "Auditorium", "College", "Canteen"});

    g.addEdge("Bus stop", "Auditorium");
    g.addEdge("Bus stop", "College");
    g.addEdge("Auditorium", "College");
    g.addEdge("College", "Canteen");

    string start = "Bus stop";

    // Traverse
    vector<string> dfs_order;
    vector<string> bfs_order;
    g.DFS(start, dfs_order);
    g.BFS(start, bfs_order);

    cout << "DFS: " << flush;
    for (auto it : dfs_order)
        cout << it << " " << flush;
    cout << endl;

    cout << "BFS: " << flush;
    for (auto it : bfs_order)
        cout << it << " " << flush;
    cout << endl;

    return 0;
}
