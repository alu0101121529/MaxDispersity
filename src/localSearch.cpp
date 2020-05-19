#include "../include/localSearch.hpp"
std::vector<int> localSearch::execute()
{
  std::vector<int> solution = solutionGreedy;
  float distance = totalDistance(solution);
  bool improvement = true;
  if(improvement) {
    std::vector<int> improvedSolution = local_Search(solution);
    if(totalDistance(improvedSolution) > distance) {
      solution = improvedSolution;
      distance = totalDistance(improvedSolution);
    } else {
      improvement = false;
    }
  }
  return solution;
}


std::vector<int> localSearch::local_Search(std::vector<int> solution)
{
  float distance = totalDistance(solutionGreedy);
  std::vector<int> improved;
  std::vector<int> actualSolution = solutionGreedy;
  std::vector<int> candidates;
  bool improv = false;
  do {
    for(int i = 0; i < solution.size(); i++) {
      if(std::find(solution.begin(), solution.end(), i) == solution.end()) {
        candidates.push_back(i);
      }
    }
    improv = false;
    for(int i = 0; i < actualSolution.size(); i++) {
      int aux = actualSolution[i];
      for(int j = 0; j < candidates.size(); j++) {
        actualSolution[i] = candidates[j];
        float actualDistance = totalDistance(actualSolution);
        if(actualDistance > distance) {
          distance = actualDistance;
          improved = actualSolution;
          improv = true;
        }
      }
      actualSolution[i] = aux;
    }
  } while(improv);
  return improved;
}

float localSearch::totalDistance(std::vector<int> solution) {
  float sum = 0;
  for(int i = 0; i < solution.size(); i++) {
    for(int j = i + 1; j < solution.size(); j++) {
      sum += distanceTwoPoints(solution[i], solution[j]);
    }
  }
  return sum;
}

float localSearch::distanceTwoPoints(int point1, int point2) {
  float sum = 0; 
  for(int j = 0; j < graph.get_cols(); j++) {
    sum += pow(graph[point1][j] - graph[point2][j], 2);
  }
  sum = sqrt(sum);
  return sum;
}