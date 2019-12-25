#include <bits/stdc++.h>

using namespace std;

vector<pair<int64_t, int64_t>>
prim_pq(vector<list<pair<int64_t, uint64_t>>> &graph) {
  vector<int64_t> min_distance(graph.size(), numeric_limits<int64_t>::max());
  min_distance[0] = 0;

  priority_queue<pair<int64_t, int64_t>, vector<pair<int64_t, int64_t>>,
                 greater<pair<int64_t, int64_t>>>
      active_vertices;
  active_vertices.push({0, 0});

  vector<bool> spanned(graph.size(), false);

  vector<int64_t> parent(graph.size(), 0);

  vector<pair<int64_t, int64_t>> mst_edges;

  while (!active_vertices.empty()) {
    int source = active_vertices.top().second;
    active_vertices.pop();

    spanned[source] = true;

    if (source != 0)
      mst_edges.push_back({parent[source], source});

    for (auto edge : graph[source]) {
      auto destination = edge.first;
      auto weight = edge.second;

      if (!spanned[destination] && min_distance[destination] > weight) {
        min_distance[destination] = weight;
        active_vertices.push({min_distance[destination], destination});
        parent[destination] = source;
      }
    }
  }
  return mst_edges;
}

vector<pair<int64_t, int64_t>>
prim_set(vector<list<pair<int64_t, uint64_t>>> &graph) {
  vector<int64_t> min_distance(graph.size(), numeric_limits<int64_t>::max());
  min_distance[0] = 0;

  set<pair<int64_t, int64_t>> active_vertices;
  active_vertices.insert({0, 0});

  vector<bool> spanned(graph.size(), false);

  vector<int64_t> parent(graph.size(), -1);

  vector<pair<int64_t, int64_t>> mst_edges;

  while (!active_vertices.empty()) {
    int source = active_vertices.begin()->second;
    active_vertices.erase(active_vertices.begin());

    spanned[source] = true;

    if (source != 0)
      mst_edges.push_back({parent[source], source});

    for (auto edge : graph[source]) {
      auto destination = edge.first;
      auto weight = edge.second;

      if (!spanned[destination] && min_distance[destination] > weight) {
        active_vertices.erase({min_distance[destination], destination});
        min_distance[destination] = weight;
        active_vertices.insert({min_distance[destination], destination});
        parent[destination] = source;
      }
    }
  }
  return mst_edges;
}

void addEdge(vector<list<pair<int64_t, uint64_t>>> &graph, int64_t sourceVertex,
             int64_t destinationVertex, uint64_t weigth) {
  graph[sourceVertex].push_back(make_pair(destinationVertex, weigth));
  graph[destinationVertex].push_back(make_pair(sourceVertex, weigth));
}

int main() {
  vector<list<pair<int64_t, uint64_t>>> graph(9);
  addEdge(graph, 0, 1, 4);
  addEdge(graph, 0, 7, 8);
  addEdge(graph, 1, 2, 8);
  addEdge(graph, 1, 7, 11);
  addEdge(graph, 2, 3, 7);
  addEdge(graph, 2, 8, 2);
  addEdge(graph, 2, 5, 4);
  addEdge(graph, 3, 4, 9);
  addEdge(graph, 3, 5, 14);
  addEdge(graph, 4, 5, 10);
  addEdge(graph, 5, 6, 2);
  addEdge(graph, 6, 7, 1);
  addEdge(graph, 6, 8, 6);
  addEdge(graph, 7, 8, 7);

  for (auto edge : prim_pq(graph)) {
    cout << edge.first << " -> " << edge.second << "\n";
  }

  return EXIT_SUCCESS;
}