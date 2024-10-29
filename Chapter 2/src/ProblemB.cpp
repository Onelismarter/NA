#include "Function.hpp"
#include "interpolation.hpp"
#include <iostream>
#include <cmath>
#include "matplotlibcpp.h"


class F1 : public Function{
public:
    virtual double operator() (double x) const{
        return 1.0 / (1.0 + x * x);
    }
} f1;

 int main() {
    std::vector<int> n_values = {2, 4, 6, 8};
    std::vector<std::vector<double>> x_values, y_values;

    for (int n : n_values) {
        std::vector<double> x(n + 1);
        std::vector<double> y(n + 1);
        for (int i = 0; i <= n; ++i) {
            x[i] = -5 + 10.0 * i / n;
            y[i] = f1(x[i]);
        }
        x_values.push_back(x);
        y_values.push_back(y);
    }

    std::vector<double> x, y;
    for (double i = -5; i <= 5; i += 0.1) {
        x.push_back(i);
        y.push_back(f1(i));
    }

    std::cout << "B:输出图形" << std::endl;    
    matplotlibcpp::figure();
    matplotlibcpp::named_plot("n = 2", x_values[0], y_values[0], "r-");
    matplotlibcpp::named_plot("n = 4", x_values[1], y_values[1], "b-");
    matplotlibcpp::named_plot("n = 6", x_values[2], y_values[2], "g--");
    matplotlibcpp::named_plot("n = 8", x_values[3], y_values[3], "k:");
    matplotlibcpp::named_plot("y = 1 / (1 + x^2)", x, y, "m-");

    matplotlibcpp::legend();
    matplotlibcpp::show();

    return 0;
} 

 