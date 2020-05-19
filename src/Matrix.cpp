#include "../include/Matrix.hpp"

void Matriz::resizeMatrix(int rows, int cols)
{
  for (int i = 0; i < matrix.size(); i++)
  {
    matrix[i].resize(cols);
  }
  matrix.resize(rows, std::vector<float>(cols));
}

int Matriz::get_rows()
{
  return matrix.size();
}

int Matriz::get_cols()
{
  return matrix[0].size();
}

void Matriz::set_position(int row, int col, float value)
{
  matrix[row][col] = value;
}

float Matriz::get_position(int row, int col)
{
  return matrix[row][col];
}

void Matriz::write()
{
  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = 0; j < matrix[0].size(); j++)
    {
      std::cout << "[" << matrix[i][j] << "] ";
    }
    std::cout << std::endl;
  }
}

std::vector<float> &Matriz::operator[](int index)
{
  if (index >= matrix.size())
  {
    std::cerr << "Index fuera de rango" << std::endl;
    std::exit(0);
  }
  else
  {
    return matrix[index];
  }
}

void Matriz::printRow(int index) {
  for(int i = 0; i < matrix[index].size(); i++) {
    std::cout << matrix[index][i] << " ";
  }
}