#include <stdio.h>
#include <math.h>
#include <functional>


double nthDerive(std::function<double(double)> function, double x, int n, double h) {
  if (n == 1) return (function(x + h) - function(x)) / h;

  std::function<double(double)> derivedFunction = [function, h](double x) {
    return (function(x + h) - function(x)) / h;
  };
  return nthDerive(derivedFunction, x, n-1, h);
}

int main() {
  std::function<double(double)> func = [](double x) { return x * x * x; };
  printf("%f\n", nthDerive(func, 5.0, 2, 0.00000001));
}


