/**
 * @file localSearch.hpp
 * @author Guillermo Hernández González
 * @brief Fichero que contiene la implementación de la búsqueda local.
 * @version 1.0
 * @date 2020-05-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once
#include "Matrix.hpp"
#include "algorithm.hpp"
#include "math.h"
/**
 * @brief Implementation of the Local Search algorithm
 * 
 */
class localSearch : public Algorithm
{
private:
  std::vector<int> solutionGreedy;
public:
  /**
   * @brief Construct a new localSearch object
   * 
   * @param filename 
   */
  localSearch(std::string filename, int sol, std::vector<int> solutionGreedy) : Algorithm(filename, sol), solutionGreedy(solutionGreedy) {}
  /**
   * @brief Method that executes the algorithm
   * 
   * @return std::vector<float> 
   */
  std::vector<int> execute();
  /**
   * @brief Returns the a vector with the improved solution after applying the local search algorithm
   * 
   * @param solution 
   * @return std::vector<int> 
   */
  std::vector<int> local_Search(std::vector<int> solution);
  /**
   * @brief Method that computes the total distance given a solution
   * 
   * @return float 
   */
  float totalDistance(std::vector<int>);
  /**
   * @brief Calculates the distance between two points.
   * 
   * @return float 
   */
  float distanceTwoPoints(int,int);
};