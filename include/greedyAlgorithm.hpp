/**
 * @file greedyAlgorithm.hpp
 * @author Guillermo Hernández González
 * @brief Fichero que contiene la implementación del algoritmo greedy
 *        de forma constructiva.
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
 * @brief Implementation of the greedy algorithm to solve
 *        Maximum diversity problem
 * 
 */
class greedyAlgorithm : public Algorithm
{
private:
public:
  /**
   * @brief Construct a new greedy Algorithm object
   * 
   * @param filename 
   */
  greedyAlgorithm(std::string filename, int sol) : Algorithm(filename, sol) {}
  /**
   * @brief Method that executes the algorithm
   * 
   * @return std::vector<float> 
   */
  std::vector<int> execute();
  /**
   * @brief Method that calculates the gravity center
   * 
   * @return std::vector<float> 
   */
  std::vector<float> gravityCenter(std::vector<int>);
  /**
   * @brief Returns the index of the furthest element to the center
   * 
   * @return int 
   */
  int furthestElement(std::vector<int>, std::vector<float>);
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