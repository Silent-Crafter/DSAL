#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    unordered_map<string, vector<string>> adjList;

public:
    Graph() = default;

    void DFS(const string& start, vector<string>& order) {
        stack<string> s;
        unordered_map<string, bool> visited = {};

        s.push(start);

        while (!s.empty()) {
            auto curr = s.top();
            s.pop();

            if (!visited[curr]) {
                visited[curr] = true;
                order.push_back(curr);
            }

            for (const auto& neighbour : adjList[curr]) {
                if (!visited[neighbour]) {
                    s.push(neighbour);
                }
            }
        }
    }

    void BFS(const string& start, vector<string>& order) {
        queue<string> q;
        unordered_map<string, bool> visited = {};
        string curr;

        q.push(start);

        while(!q.empty()) {
            curr = q.front();
            q.pop();

            if (!visited[curr]) {
                visited[curr] = true;
                order.push_back(curr);
            }

            for (const auto& neighbour : adjList[curr]) {
                if (!visited[neighbour])
                    q.push(neighbour);
            }
        }
    }

    void addEdge(const string& parent, const string& child) {
        adjList[parent].push_back(child);
        adjList[child].push_back(parent);
    }
};

int main() {

    // Create Graph
    Graph g;
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
    for (const auto& it : dfs_order)
        cout << it << " " << flush;
    cout << endl;

    cout << "BFS: " << flush;
    for (const auto& it : bfs_order)
        cout << it << " " << flush;
    cout << endl;

    return 0;
}
