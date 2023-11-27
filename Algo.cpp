#include <queue>
#include <tuple>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>
#include "Algo.hpp"

long Algo::findShotestPath(const int cities, vector<vector<int>> &distances, int src, int dst, int stops, vector<int> &path) const
{
  vector<vector<pair<int, int>>> adjList(cities);
  for (const auto &distance : distances)
    adjList[distance[0]].emplace_back(distance[1], distance[2]);
  priority_queue<tupl, vector<tupl>, greater<tupl>> pq;
  pq.push(make_tuple(0, src, stops, vector<int>{src}));
  while (!pq.empty())
  {
    tupl t = pq.top();
    pq.pop();

    const int cost = get<0>(t);
    const int current = get<1>(t);
    const int stop = get<2>(t);
    const vector<int> currentPath = get<3>(t);

    if (current == dst)
    {
      path = currentPath;
      return cost;
    }

    if (stop >= 0)
      for (const auto &next : adjList[current])
      {
        vector<int> newPath = currentPath;
        newPath.push_back(next.first);
        pq.push(make_tuple(cost + next.second, next.first, stop - 1, newPath));
      }
  }

  return -1;
}

void Algo::printResult(long ans, vector<City> cities, City fromCity, City toCity, vector<int> path) const
{
  if (ans != -1)
  {
    cOut("The shortest distance from " << fromCity.name << " to " << toCity.name
                                       << " is " << ans);
    cout << "through the route: ";
    for (int i = 0; i < path.size(); ++i)
    {
      cout << cities[path[i]].name;
      if (i < path.size() - 1)
        cout << "->";
    }
    cout << endl;
  }
  else
    cOut("No route from " << fromCity.name << " to " << toCity.name);
}