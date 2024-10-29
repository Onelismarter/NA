#include "Function.hpp"
#include "interpolation.hpp"
#include <iostream>
#include <cmath>
#include "matplotlibcpp.h"

const double pi = 3.141592653589793;

class F2 : public Function{
public:
    virtual double operator() (double x) const{
        return 1.0 / (1.0 + 25 * x * x);
    }
} f2;

int main()
{
    std::vector<int> n_values = {5 , 10 , 15 , 20};
    std::vector<std::vector<double>> x_values , y_values; 
    for (int n : n_values)
    {
        std::vector<double> x(n+1) , y(n+1);
        for (int i = 0 ; i <= n ; ++i)
        {
            x[i] = cos ( (2.0 * i + 1) / (2.0 * (n + 1)) * pi );
            y[i] = f2(x[i]);
        }
        x_values.push_back(x);
        y_values.push_back(y);
    }
    
 std::vector<double> xo, yo;
    for (double i = -1.0; i <= 1.0; i += 0.1) {
        xo.push_back(i);
        yo.push_back(f2(i));
    }
    std::cout << "C:输出图形" << std::endl;   
    matplotlibcpp::figure();
    matplotlibcpp::named_plot("n = 5", x_values[0], y_values[0], "r-");
    matplotlibcpp::named_plot("n = 10", x_values[1], y_values[1], "b-");
    matplotlibcpp::named_plot("n = 15", x_values[2], y_values[2], "g--");
    matplotlibcpp::named_plot("n = 20", x_values[3], y_values[3], "k:");
    matplotlibcpp::named_plot("y = 1 / (1 + 25 * x^2)", xo, yo, "m-:");

    //matplotlibcpp::legend();
    matplotlibcpp::show();

    return 0;
  
}
