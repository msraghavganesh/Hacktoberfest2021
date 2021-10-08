#include <bits/stdc++.h>
using namespace std;

int graph[9999][9999];

void input(int m)
{
  int x, y, Weight;
  for (int i = 0; i < m; i++)
  {
    cin >> x >> y >> Weight;
    graph[x - 1][y - 1] = Weight;
  }
}

bool negCyclefloydWarshall(int V)
{

  int dist[V][V], i, j, k;

  for (i = 0; i < V; i++)
    for (j = 0; j < V; j++)
      dist[i][j] = graph[i][j];

  for (k = 0; k < V; k++)
  {
    for (i = 0; i < V; i++)
    {
      for (j = 0; j < V; j++)
      {
        if (dist[i][k] + dist[k][j] < dist[i][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }

  for (int i = 0; i < V; i++)
    if (dist[i][i] < 0)
      return true;

  for (i = 0; i < V; i++)
  {
    for (j = 0; j < V; j++)
    {
        cout<<i<<" "<<j<<" "<<dist[i][j]<<endl;
    }
  }
  return false;
}

int main()
{
  int v;
  cin >> v;
  input(v);
  if (negCyclefloydWarshall(v))
    cout << "Negetive Cycle Present";
  else
    cout << "Negetive Cycle NOT Present";
  return 0;
}
