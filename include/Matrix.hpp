/**
 * @file matrix.hpp
 * @author Guillermo Hernández González
 * @brief Fichero que contiene la implementación de una clase Matriz que servirá
 *        como base para guardar los datos dado por fichero
 * @version 1.0
 * @date 2020-04-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
#include <utility>

/**
 * @class Matriz
 * @brief Matrix containing all the distances between nodes
 * 
 */
class Matriz
{
private:
  std::vector<std::vector<float>> matrix;

public:
  /**
   * @brief Construct a new Matriz object
   * 
   * @param {std::string} filename 
   */
  Matriz(std::string filename) : matrix(0, std::vector<float>(0))
  {
    std::ifstream myFile;
    myFile.open(filename);
    int numeroElementos = 0;
    int dimensionElementos = 0;
    float valores = 0;
    if (myFile.is_open())
    {
      myFile >> numeroElementos;
      myFile >> dimensionElementos;
    }
    this->resizeMatrix(numeroElementos, dimensionElementos);
    for (int i = 0; i < numeroElementos; i++)
    {
      for (int j = 0; j < dimensionElementos; j++)
      {
        matrix[i][j] = 0;
      }
    }
    for (int i = 0; i < numeroElementos; i++)
    {
      for (int j = 0; j < dimensionElementos; j++)
      {
          myFile >> valores;
          matrix[i][j] = valores;
      }
    }
    myFile.close();
  }
  /**
   * @brief Change the matrix's dimensions
   * 
   * @param rows 
   * @param cols 
   */
  void resizeMatrix(int rows, int cols);
  /**
   * @brief Get the rows object
   * 
   * @return float 
   */
  int get_rows();
  /**
   * @brief Get the cols object
   * 
   * @return float 
   */
  int get_cols();
  /**
   * @brief Set the position object
   * 
   * @param row 
   * @param col 
   * @param value 
   */
  void set_position(int row, int col, float value);
  /**
   * @brief Get the position object
   * 
   * @param row 
   * @param col 
   * @return float 
   */
  float get_position(int row, int col);
  /**
   * @brief Print the matrix
   * 
   */
  void write();
  /**
   * @brief Operator [] overload
   * 
   * @param index 
   * @return std::vector<float>& 
   */
  std::vector<float> &operator[](int index);

  void printRow(int index);
};