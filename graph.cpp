#include <bits/stdc++.h>

using namespace std;

template <typename T> class Graph {
public:
  Graph(size_t num_vertices);
  void addVertex();
  void addEdge(T v1, T v2);
  size_t shortestPath(T sourceVertex, T destinationVertex);
  // strongly connected components
  void SCC();

private:
  vector<list<T>> vertices;
  Graph<T> transpose();
  void fillOrder(T sourceVertex, vector<bool> &visited, stack<T> &order);
  void DFS(T sourceVertex, vector<bool> &visited);
};

template <typename T> Graph<T>::Graph(size_t num_vertices) {
  this->vertices = vector<list<T>>(num_vertices);
}

template <typename T> void Graph<T>::addVertex() {
  this->vertices.push_back(list<T>());
}

template <typename T> void Graph<T>::addEdge(T v1, T v2) {
  this->vertices[v1].push_back(v2);
}

template <typename T>
void Graph<T>::DFS(T sourceVertex, vector<bool> &visited) {
  visited[sourceVertex] = true;
  cout << sourceVertex << " ";

  for (auto edge : vertices[sourceVertex])
    if (!visited[edge])
      DFS(edge, visited);
}

template <typename T>
size_t Graph<T>::shortestPath(T sourceVertex, T destinationVertex) {
  vector<bool> visited(this->vertices.size());
  queue<T> q;
  q.push(sourceVertex);
  visited[sourceVertex] = true;
  size_t level = 0;

  while (!q.empty()) {
    for (auto i = 0; i < q.size(); i++) {
      auto vertex = q.front();
      q.pop();

      if (vertex == destinationVertex)
        return level;

      for (auto edge : this->vertices[vertex]) {
        if (!visited[edge]) {
          q.push(edge);
          visited[edge] = true;
        }
      }
    }
    level++;
  }

  return ~0;
}

template <typename T> Graph<T> Graph<T>::transpose() {
  Graph<T> newGraph(vertices.size());
  for (auto v = 0; v < vertices.size(); v++) {
    for (auto edge : vertices[v]) {
      newGraph.addEdge(edge, v);
    }
  }
  return newGraph;
}

template <typename T>
void Graph<T>::fillOrder(T sourceVertex, vector<bool> &visited,
                         stack<T> &order) {
  visited[sourceVertex] = true;

  for (auto edge : vertices[sourceVertex])
    if (!visited[edge])
      fillOrder(edge, visited, order);

  order.push(sourceVertex);
}

template <typename T> void Graph<T>::SCC() {
  vector<bool> visited(vertices.size());
  stack<T> order;
  for (int v = 0; v < vertices.size(); v++)
    if (!visited[v])
      fillOrder(v, visited, order);

  Graph<T> newGraph = transpose();
  fill(visited.begin(), visited.end(), false);

  while (!order.empty()) {
    auto vertex = order.top();
    order.pop();

    if (!visited[vertex]) {
      newGraph.DFS(vertex, visited);
      cout << endl;
    }
  }
}

int main() {
  Graph<int64_t> graph(5);
  graph.addEdge(1, 0);
  graph.addEdge(0, 2);
  graph.addEdge(2, 1);
  graph.addEdge(0, 3);
  graph.addEdge(3, 4);
  graph.SCC();
  return EXIT_SUCCESS;
}
