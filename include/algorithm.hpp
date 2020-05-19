/**
 * @file algorithm.hpp
 * @author Guillermo Hernández González
 * @brief Fichero que contiene la clase Algorithm que servirá
 *        como clase base para la implementación de los otros algoritmos
 * @version 1.0
 * @date 2020-04-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once
#include <string>
#include <algorithm>
#include "Matrix.hpp"

/**
 * @class Algorithm
 * @brief virtual algorithm class used to solve the maxmean problem
 * 
 */
class Algorithm
{
protected:
  Matriz graph;
  int solutionSize;

public:
  /**
 * @brief Construct a new Algorithm object
 * 
 * 
 * @param filename 
 */
  Algorithm(std::string filename, int sol) : graph(filename), solutionSize(sol){};
  /**
   * @brief Method that executes the algorithm
   * 
   * @return std::vector<int> 
   */
  virtual std::vector<int> execute() = 0;
};