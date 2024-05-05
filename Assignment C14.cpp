#include <bits/stdc++.h>
using namespace std;


class Graph {
private:
    map<string, map<string, int>> adjMatrix;

public:
    Graph() {};

    Graph(vector<string>& cities) {
        // Initialize everything to 0
        for (string cityA : cities) {
            for (string cityB : cities) {
                adjMatrix[cityA][cityB] = 0;
            }
        }
    }

    void addEdge(string ca, string cb, int weight) {
        adjMatrix[ca][cb] = weight;
        adjMatrix[cb][ca] = weight;
    }

    void displayMatrix() {
        cout << endl;

        // Display Column Labels
        cout << "   ";
        for (auto element : adjMatrix) {
            cout << " " << element.first;
        }
        cout << endl;

        // Display Rows
        for (auto key : adjMatrix) {
            cout << key.first << " [";
            for (auto element : key.second) {
                cout << " " << element.second;
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
