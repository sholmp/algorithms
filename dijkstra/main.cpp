#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
  int id;
  vector<Node *> edges;
};

// connect will add edges to each node, and assign a cost between these nodes
// and store the cost between
void connect(Node *n1, Node *n2, int cost, map<pair<int, int>, int> &cost_map) {
  n1->edges.push_back(n2);
  n2->edges.push_back(n1);

  cost_map[{n1->id, n2->id}] = cost;
}

int main() {

  Node n0{0};
  Node n1{1};
  Node n2{2};
  Node n3{3};
  Node n4{4};
  Node n5{5};
  Node n6{6};
  Node n7{7};

  map<pair<int, int>, int> cost_map;

  // wire graph together
  connect(&n0, &n1, 1, cost_map);
  connect(&n0, &n3, 2, cost_map);
  connect(&n0, &n2, 2, cost_map);
  connect(&n1, &n2, 5, cost_map);
  connect(&n2, &n3, 1, cost_map);
  connect(&n2, &n4, 1, cost_map);
  connect(&n2, &n6, 5, cost_map);
  connect(&n3, &n5, 4, cost_map);
  connect(&n4, &n6, 0, cost_map);
  connect(&n4, &n7, 6, cost_map);
  connect(&n5, &n6, 1, cost_map);
  connect(&n5, &n7, 3, cost_map);
  connect(&n6, &n7, 2, cost_map);


  vector<bool> visited(8, false);



  queue<Node*> q;

  Node* start = &n0;
  Node* goal = &n7;

  q.push(start);

  while(!q.empty())
  {
      Node* front = q.front();
      for(auto node : front->edges)
      {
          if(!visited[node->id])
            q.push(node);
      }

      cout << front->id << endl;
      visited[front->id] = true; //now that all edges have been put into the queue, we are done with this node
      q.pop(); //remove front element
  }








  return 0;
}
