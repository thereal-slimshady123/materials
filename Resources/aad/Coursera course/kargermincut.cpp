#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> readGraphFromInput(int V) {
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < V; ++i) {
        int u;
        cin >> u;
        string line;
        getline(cin, line);
        if (line.empty()) getline(cin, line); // in case first getline reads leftover newline
        stringstream ss(line);
        int v;
        while (ss >> v) {
            graph[u].push_back(v);
        }
    }
    return graph;
}

void contractEdge(unordered_map<int, vector<int>>& G, int u, int v) {
    G[u].insert(G[u].end(), G[v].begin(), G[v].end());
    for (auto& [x, nbrs] : G) {
        for (auto& w : nbrs) if (w == v) w = u;
    }
    auto& nbrs = G[u];
    nbrs.erase(remove(nbrs.begin(), nbrs.end(), u), nbrs.end());
    G.erase(v);
}

int kargerMinCut(unordered_map<int, vector<int>> G) {
    while (G.size() > 2) {
        auto it = G.begin();
        advance(it, rand() % G.size());
        int u = it->first;
        int v = G[u][rand() % G[u].size()];
        contractEdge(G, u, v);
    }
    return G.begin()->second.size();
}

int main() {
    srand((unsigned)time(nullptr));

    int V;
    cin >> V;
    auto original = readGraphFromInput(V);

    int trials = 200;
    int bestCut = INT_MAX;
    for (int i = 0; i < trials; ++i) {
        int cut = kargerMinCut(original);
        bestCut = min(bestCut, cut);
    }

    cout << "Minimum cut found over " << trials << " trials: " << bestCut << "\n";
    return 0;
}
