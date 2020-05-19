#include "../include/Matrix.hpp"
#include "../include/greedyAlgorithm.hpp"
#include "../include/2ndGreedyAlgorithm.hpp"
#include "../include/localSearch.hpp"
#include <chrono>

int main(int argc, char *argv[]) {
  std::vector<std::string> files;
  if(argc > 1) {
    std::string file = argv[1];
    files.push_back(file);
  } else {
    files.push_back("max_div_15_2.txt");
    files.push_back("max_div_15_3.txt");
    files.push_back("max_div_20_2.txt");
    files.push_back("max_div_20_3.txt");
    files.push_back("max_div_30_2.txt");
    files.push_back("max_div_30_3.txt");
  }
  srand(time(NULL));
  std::vector<int>  resultgreedy;
  std::vector<int>  resultgreedy2; 
  std::vector<int>  resultGRASP;
  std::vector<int>  resultLS; 

  std::cout << "Greedy constructivo"<< std::endl;
  std::cout << "\n";
  for(int f = 0; f < files.size(); f++) {
    Matriz a("../txt/" + files[f]);   
      for (int i = 2; i < 6; i++) {
      greedyAlgorithm greedy("../txt/" + files[f], i);
      auto start = std::chrono::steady_clock::now();
      resultgreedy = greedy.execute();
      auto end = std::chrono::steady_clock::now();
      auto time = std::chrono::duration_cast<std::chrono::microseconds> (end - start);
      std::cout << files[f] << "\t"<< a[0].size() << "\t" << a.get_rows() << "\t" << i;
      std::cout << "\t"<< greedy.totalDistance(resultgreedy) << "\t\t"; 
      for(int k = 0; k < resultgreedy.size(); k++) {
        std::cout<< resultgreedy[k] + 1  << " ";
      }
      std::cout << "\t\t" << (float(time.count()) / 1000) << "\t" << std::endl;
    }
    std::cout << "\n--\n";
  }

  std::cout << "Greedy Destructivo"<< std::endl;
  std::cout << "\n";
  for(int f = 0; f < files.size(); f++) {
    Matriz a("../txt/" + files[f]);   
      for (int i = 2; i < 6; i++) {
      secondGreedyAlgorithm greedy2("../txt/" + files[f], i);
      auto start = std::chrono::steady_clock::now();
      resultgreedy2 = greedy2.execute();
      auto end = std::chrono::steady_clock::now();
      auto time = std::chrono::duration_cast<std::chrono::microseconds> (end - start);
      std::cout << files[f] << "\t"<< a[0].size() << "\t" << a.get_rows() << "\t" << i;
      std::cout << "\t"<< greedy2.totalDistance(resultgreedy2) << "\t\t"; 
      for(int k = 0; k < resultgreedy2.size(); k++) {
        std::cout<< resultgreedy2[k] + 1  << " ";
      }
      std::cout << "\t\t" <<(float(time.count()) / 1000) << "\t" << std::endl;
    }
    std::cout << "\n--\n";
  }

  std::cout << "Local Search greedy constructivo"<< std::endl;
  std::cout << "\n";
  for(int f = 0; f < files.size(); f++) {
    Matriz a("../txt/" + files[f]);   
      for (int i = 2; i < 6; i++) {
      greedyAlgorithm greedy("../txt/" + files[f], i);
      resultgreedy = greedy.execute();
      localSearch ls("../txt/" + files[f], i, resultgreedy);
      auto start = std::chrono::steady_clock::now();
      resultLS = ls.execute();
      auto end = std::chrono::steady_clock::now();
      auto time = std::chrono::duration_cast<std::chrono::microseconds> (end - start);
      std::cout << files[f] << "\t"<< a[0].size() << "\t" << a.get_rows() << "\t" << i;
      std::cout << "\t"<< ls.totalDistance(resultLS) << "\t\t"; 
      for(int k = 0; k < resultLS.size(); k++) {
        std::cout<< resultLS[k] + 1  << " ";
      }
      std::cout << "\t\t" << (float(time.count()) / 1000) << "\t" << std::endl;
    }
    std::cout << "\n--\n";
  }
  std::cout << "Local Search greedy destructivo"<< std::endl;
  std::cout << "\n";
  for(int f = 0; f < files.size(); f++) {
    Matriz a("../txt/" + files[f]);   
      for (int i = 2; i < 6; i++) {
      secondGreedyAlgorithm greedy2("../txt/" + files[f], i);
      resultgreedy2 = greedy2.execute();
      localSearch ls("../txt/" + files[f], i, resultgreedy2);
      auto start = std::chrono::steady_clock::now();
      resultLS = ls.execute();
      auto end = std::chrono::steady_clock::now();
      auto time = std::chrono::duration_cast<std::chrono::microseconds> (end - start);
      std::cout << files[f] << "\t"<< a[0].size() << "\t" << a.get_rows() << "\t" << i;
      std::cout << "\t"<< ls.totalDistance(resultLS) << "\t\t"; 
      for(int k = 0; k < resultLS.size(); k++) {
        std::cout<< resultLS[k] + 1  << " ";
      }
      std::cout << "\t\t" << (float(time.count()) / 1000) << "\t" << std::endl;
    }
    std::cout << "\n--\n";
  }
}