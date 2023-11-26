#include <queue>
#include <tuple>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>
#include "City.hpp"

vector<City> City::getCities(const string &filename) const
{
  vector<City> cities;
  ifstream file(filename);
  if (file.is_open())
  {
    string line;
    while (getline(file, line))
    {
      istringstream iss(line);
      int id, population, elevation;
      string code, name;
      iss >> id >> code >> name >> population >> elevation;
      cities.push_back({code, name, population, elevation});
    }
    file.close();
  }
  else
  {
    cerr << "Unable to open cities file: " << filename << endl;
    exit(1);
  }
  return cities;
}

vector<vector<int>> City::getRoads(const string &filename) const
{
  vector<vector<int>> distances;
  ifstream file(filename);
  if (file.is_open())
  {
    string line;
    while (getline(file, line))
    {
      istringstream iss(line);
      int from, to, distance;
      iss >> from >> to >> distance;
      distances.push_back({from, to, distance});
    }
    file.close();
  }
  else
  {
    cerr << "Unable to open roads file: " << filename << endl;
    exit(1);
  }
  return distances;
}