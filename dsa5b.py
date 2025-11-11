#include <iostream>
#include <climits>
using namespace std;

#define V 5

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    cout << "Edges in the Minimum Spanning Tree (Prim's Algorithm):\n";
    int total = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " -- " << i << " == " << graph[i][parent[i]] << endl;
        total += graph[i][parent[i]];
    }
    cout << "Minimum Spanning Tree Cost: " << total << endl;
}

int main() {
    int graph[V][V] = {
        {0, 2, 8, 0, 0},
        {2, 0, 5, 3, 0},
        {8, 5, 0, 0, 6},
        {0, 3, 0, 0, 0},
        {0, 0, 6, 0, 0}
    };
    primMST(graph);
    return 0;
}