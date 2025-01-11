#include <iostream>
#include <numeric>
#include <vector>

float mean(std::vector<double> const &v) {
  auto const count = static_cast<float>(v.size());
  return std::reduce(v.begin(), v.end()) / count;
}

int main() {
  std::vector<double> x = {1.f, 2.3f, 3.5f, 5.0f, 2.5f, 4.2f, 3.4f};
  std::vector<double> y = {.2f, 2.2f, 2.5f, 4.0f, 3.5f, 5.2f, 4.4f};
  auto x_mean = mean(x);
  auto y_mean = mean(y);

  auto size = x.size();
  auto sum = 0.0f;
  for (size_t i = 0; i < size; i++) {
    sum += (x[i] - x_mean) * (y[i] - y_mean);
  }
  double cov = sum / (size - 1);
  std::cout << cov << std::endl;

  return 0;
}
