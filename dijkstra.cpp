#include <bits/stdc++.h>

using namespace std;

int64_t dijkstra_pq(vector<list<pair<int64_t, uint64_t>>> &graph,
                    int64_t sourceVertex, int64_t targetVertex) {
  vector<int64_t> min_distance(graph.size(), numeric_limits<int64_t>::max());
  min_distance[sourceVertex] = 0;

  priority_queue<pair<int64_t, int64_t>, vector<pair<int64_t, int64_t>>,
                 greater<pair<int64_t, int64_t>>>
      active_vertices;
  active_vertices.push({0, sourceVertex});

  while (!active_vertices.empty()) {
    int source = active_vertices.top().second;
    active_vertices.pop();

    if (source == targetVertex)
      return min_distance[source];

    for (auto edge : graph[source]) {
      auto destination = edge.first;
      auto weight = edge.second;

      if (min_distance[destination] > min_distance[source] + weight) {
        min_distance[destination] = min_distance[source] + weight;
        active_vertices.push({min_distance[destination], destination});
      }
    }
  }
  return numeric_limits<int64_t>::max();
}

int64_t dijkstra_set(vector<list<pair<int64_t, uint64_t>>> &graph,
                     int64_t sourceVertex, int64_t targetVertex) {
  vector<int64_t> min_distance(graph.size(), numeric_limits<int64_t>::max());
  min_distance[sourceVertex] = 0;

  set<pair<int64_t, int64_t>> active_vertices;
  active_vertices.insert({0, sourceVertex});

  while (!active_vertices.empty()) {
    int source = active_vertices.begin()->second;
    active_vertices.erase(active_vertices.begin());

    if (source == targetVertex)
      return min_distance[source];

    for (auto edge : graph[source]) {
      auto destination = edge.first;
      auto weight = edge.second;

      if (min_distance[destination] > min_distance[source] + weight) {
        active_vertices.erase({min_distance[destination], destination});
        min_distance[destination] = min_distance[source] + weight;
        active_vertices.insert({min_distance[destination], destination});
      }
    }
  }
  return numeric_limits<int64_t>::max();
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
  cout << dijkstra_pq(graph, 0, 8) << endl;
  return EXIT_SUCCESS;
}