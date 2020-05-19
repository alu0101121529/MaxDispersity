#include "../include/greedyAlgorithm.hpp"

std::vector<int> greedyAlgorithm::execute()
{
  std::vector<int> Elem;
  std::vector<int> solution;
  for (int i = 0; i < graph.get_rows(); i++)
  {
    Elem.push_back(i);
  }
  std::vector<float> SC = gravityCenter(Elem);
  while(solution.size() != solutionSize) {
    int far = furthestElement(Elem, SC);
    solution.push_back(far);
    Elem.erase(std::find(Elem.begin(), Elem.end(), far));
    SC = gravityCenter(solution);
  }
  return solution;
}

std::vector<float> greedyAlgorithm::gravityCenter(std::vector<int> Elem) {
  std::vector<float> solution;
  for(int i = 0; i < graph.get_cols(); i++) {
    float sum = 0;
    for(int j = 0; j < Elem.size(); j++) {      
      sum += graph[Elem[j]][i]; 
    }
    solution.push_back(sum / Elem.size());
  }
  return solution;
}

int greedyAlgorithm::furthestElement(std::vector<int> Elem, std::vector<float> SC) {
  float distance = 0;
  int solution = 0;
  std::vector<int> repetidos;
  for(int i = 0; i < Elem.size(); i++) {
    float sum = 0;
    for(int j = 0; j < graph.get_cols(); j++) {
      sum += pow(SC[j] - graph[Elem[i]][j], 2);
    }
    sum = sqrt(sum);
    if(sum > distance) {
      distance = sum;
      solution = Elem[i];
      repetidos.clear();
      repetidos.push_back(Elem[i]);
    } else if(sum == distance) {
      repetidos.push_back(Elem[i]);
    }
  }
  if(repetidos.size() > 1) {
    int index = std::rand() % repetidos.size();
    return repetidos[index];
  }
  return solution;
}


float greedyAlgorithm::totalDistance(std::vector<int> solution) {
  float sum = 0;
  for(int i = 0; i < solution.size(); i++) {
    for(int j = i + 1; j < solution.size(); j++) {
      sum += distanceTwoPoints(solution[i], solution[j]);
    }
  }
  return sum;
}

float greedyAlgorithm::distanceTwoPoints(int point1, int point2) {
  float sum = 0; 
  for(int j = 0; j < graph.get_cols(); j++) {
    sum += pow(graph[point1][j] - graph[point2][j], 2);
  }
  sum = sqrt(sum);
  return sum;
}