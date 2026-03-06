#include <stdio.h>
#include <cmath>
#include <functional>
#include <QR>

double nthDerive(std::function<double(double)> function, double x, int n) {
  double h = .01;

  printf("%f\n", (function(x + h) - function(x-h)) / (2*h) );

  if (n == 1) return (function(x + h) - function(x-h)) / (2*h);

  std::function<double(double)> derivedFunction = [function, h](double x) {
    return (function(x + h) - function(x-h)) / (2*h);
  };
  return nthDerive(derivedFunction, x, n-1);
}

int main() {
  std::function<double(double)> func = [](double x) { return sin(x); };
  nthDerive(func, 0, 12);
}