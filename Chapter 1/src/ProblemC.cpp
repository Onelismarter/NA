
#include "Function.hpp"
#include "EquationSolver.hpp"
#include <iostream>
#include <cmath>

const double Pi = acos(-1.);

class C : public Function {
public:
    double operator() (double x) const {
        return (x-tan(x));
    }

    double derivative(double x) const  {  

    double h = 1e-5;  // 微小增量  
    return (operator()(x + h) - operator()(x - h)) / (2 * h);  
    }
};

void solve_C() {
    std::cout << "Solving C near 4.5 、 7.7" << std::endl;
    C c;

    Newton_Method solver_c_Newton1(c, 4.4);
    double x1 = solver_c_Newton1.solve();
    std::cout << "Newton_Method : near 4.5 ,the root is: " << x1 << std::endl;

    Newton_Method solver_c_Newton2(c, 7.8);
    double x2 = solver_c_Newton2.solve();
    std::cout << "Newton_Method : near 7.7 ,the root is: " << x2 << std::endl;
}

int main() 
{
    solve_C();
    return 0;
}  