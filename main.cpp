#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>
#include <queue>
#include <limits>
#include "Main.hpp"

using namespace std;

#define cOut(message) std::cout << message << std::endl;

int main(int argc, char *argv[])
{
  City city = City();
  const Main config = Main();
  const Algo algo = Algo();

  if (argc != 3)
  {
    cErr("Usage: " << argv[0] << " <from_city_code> <to_city_code>");
    return 1;
  }

  const string from_city_code = argv[1];
  const string to_city_code = argv[2];
  const vector<City> cities = city.getCities("city.txt");
  vector<vector<int>> distances = city.getRoads("road.txt");
  const int stops = cities.size(), totalCities = cities.size();
  int from_city_id = -1, to_city_id = -1;

  for (int i = 0; i < cities.size(); ++i)
  {
    if (cities[i].code == from_city_code)
      from_city_id = i;
    else if (cities[i].code == to_city_code)
      to_city_id = i;
  }

  if (from_city_id == -1 || to_city_id == -1)
  {
    cErr("Invalid city code");
    return 1;
  }

  config.printHeader(cities[from_city_id], cities[to_city_id]);

  vector<int> path;
  long ans = algo.findShotestPath(cities.size(), distances, from_city_id, to_city_id, stops, path);

  algo.printResult(ans, cities, cities[from_city_id], cities[to_city_id], path);

  return 0;
}
