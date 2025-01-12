#include "csv.hpp"
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Eigenvalues>
#include <iostream>
#include <vector>

using namespace csv;

int main() {
  std::cout << "Eigen version: " << EIGEN_MAJOR_VERSION << "."
            << EIGEN_MINOR_VERSION << std::endl;

  std::vector<std::vector<double>> returns(10, std::vector<double>());
  int i = 0;
  CSVReader reader("returns.csv");
  for (CSVRow &row : reader) { // Input iterator
    for (CSVField &field : row) {
      if (i == 0) {
        i++;
        continue;
      } else {
        returns[i - 1].push_back(field.get<double>());
        i++;
      }
    }
    i = 0;
  }

  std::cout << returns[0].size() << std::endl;
  std::cout << returns.size() << std::endl;

  // i have not found simple construction of eigen matrix from
  // vector<vector<double>>
  Eigen::MatrixXd X(returns[0].size(), returns.size());
  for (size_t n = 0; n < returns.size(); n++) {
    for (size_t j = 0; j < returns[n].size(); j++) {
      X(j, n) = returns[n][j];
    }
  }

  // std::cout << X << std::endl;
  Eigen::VectorXd x_mean = X.colwise().mean();
  Eigen::MatrixXd X_mean = X.rowwise() - x_mean.transpose();

  double k = (1 / (static_cast<double>(X_mean.rows()) - 1));

  Eigen::MatrixXd cov = (X_mean.transpose() * X_mean) * (k);

  std::cout << cov << std::endl;

  Eigen::EigenSolver<Eigen::MatrixXd> es(cov);

  std::cout << es.eigenvalues() << std::endl;

  std::cout << es.eigenvectors() << std::endl;

  return 0;
}
