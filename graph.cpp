#include <bits/stdc++.h>

using namespace std;

template <typename T> class Graph {
public:
  Graph(size_t num_vertices);
  void addVertex();
  void addEdge(T v1, T v2);
  size_t shortestPath(T sourceVertex, T destinationVertex);
  void DFS(T sourceVertex);

private:
  vector<list<T>> vertices;
};

template <typename T> Graph<T>::Graph(size_t num_vertices) {
  this->vertices = vector<list<T>>(num_vertices);
}

template <typename T> void Graph<T>::addVertex() {
  this->vertices.push_back(list<T>());
}

template <typename T> void Graph<T>::addEdge(T v1, T v2) {
  this->vertices[v1].push_back(v2);
  // this->vertices[v2].push_back(v1);
}

template <typename T> void Graph<T>::DFS(T sourceVertex) {
  vector<bool> visited(this->vertices.size());
  stack<T> stack;
  stack.push(sourceVertex);
  visited[sourceVertex] = true;

  while (!stack.empty()) {
    auto vertex = stack.top();
    cout << " --> " << vertex;
    stack.pop();
    for (auto edge : this->vertices[vertex]) {
      if (!visited[edge]) {
        stack.push(edge);
        visited[edge] = true;
      }
    }
  }
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

int main() {
  Graph<int64_t> graph(8);
  graph.addEdge(0, 1);
  graph.addEdge(0, 3);
  graph.addEdge(1, 2);
  graph.addEdge(3, 4);
  graph.addEdge(3, 7);
  graph.addEdge(4, 5);
  graph.addEdge(4, 6);
  graph.addEdge(4, 7);
  graph.addEdge(5, 6);
  graph.addEdge(6, 7);
  cout << graph.shortestPath(0, 7) << endl;
  return EXIT_SUCCESS;
}
