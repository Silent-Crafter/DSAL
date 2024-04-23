#include <bits/stdc++.h>
using namespace std;


class Graph {
private:
    map<string, vector<pair<int, string>>> adjMatrix;

public:
    Graph() {};

    Graph(vector<string>& cities) {
        std::sort(cities.begin(), cities.end());
        // Initialize everything to 0
        for (const string& cityA : cities) {
            for (const string& cityB : cities) {
                adjMatrix[cityA].emplace_back(0, cityB);
            }
        }
    }

    void addEdge(const string& ca, const string& cb, int weight) {
        auto& cityARow = adjMatrix[ca];
        auto pair = std::find(cityARow.begin(), cityARow.end(), make_pair(0, cb));
        pair->first = weight;

        auto& cityBRow = adjMatrix[cb];
        pair = std::find(cityBRow.begin(), cityBRow.end(), make_pair(0, ca));
        pair->first = weight;
    }

    void displayMatrix() {
        cout << endl;

        // Display Column Labels
        cout << "   ";
        for (const auto& element : adjMatrix) {
            cout << " " << element.first;
        }
        cout << endl;

        // Display Rows
        for (const auto& element : adjMatrix) {
            cout << element.first << " [";
            for (auto weights : element.second) {
                cout << " " << weights.first;
            }
            cout << " ]" << endl;
        }

        cout << endl;
    }
};


int main() {
    int n;
    vector<string> edges;

    cout << "Enter number of cities: ";
    cin >> n;
    cout << "Enter list of cities: " << endl;
    string city;
    for (int i = 0 ; i < n ; i++) {
        cin >> city;
        edges.push_back(city);
    }

    Graph g(edges);

    string cityA, cityB;
    int weight;
    char choice;
    cout << "\nDo you want to create paths? (y/n): ";
    cin >> choice;
    while (choice == 'y') {
        // Clear input buffer
        cin.clear();
        cin.ignore();

        cout << "Enter 1st city in path: ";
        cin >> cityA;
        cout << "Enter 2nd city in path: ";
        cin >> cityB;
        cout << "Enter weight of path: ";
        cin >> weight;

        g.addEdge(cityA, cityB, weight);

        // Clear input buffer
        cin.clear();
        cin.ignore();

        cout << "\nDo you want to create paths? (y/n): ";
        cin >> choice;
    }

    g.displayMatrix();

    return 0;
}
