
#include "Function.hpp"
#include "EquationSolver.hpp"
#include <iostream>
#include <cmath>

const double Pi = acos(-1.);

class E : public Function {
public:
    double operator() (double x) const {
        double L = 10;
        double r = 1;
        double V = 12.4;
        return L*(0.5*Pi*r*r-r*r*asin(x/r)-x*std::sqrt(r*r-x*x))-V;
    }

    double derivative(double x) const  {  
    double h = 1e-5;  // 微小增量  
    return (operator()(x + h) - operator()(x - h)) / (2 * h);  
    } 
};

void solve_E() {
    std::cout << "Solving E by three methods" << std::endl;
    E e;
    Bisection_Method solver_E_Bisection(e, 0.1, 0.2);  //创建 Bisection_Method 匿名对象，传递了一个临时的 F1 对象，在表达式结束时就被销毁了；F1()(some_value)`，它会返回 `1.0/some_value - tan(some_value)` 的值，重载了第二个（）
    double x1 = solver_E_Bisection.solve();
    std::cout << "Bisection_Method : a root is: " << x1 << std::endl;

    Newton_Method solver_E_Newton(e, 0.1);
    double x2 = solver_E_Newton.solve();
    std::cout << "Newton_Method : a root is: " << x2 << std::endl;

    Secant_Method solver_E_Secant(e, 0.1, 0.2);
    double x3 = solver_E_Secant.solve();
    std::cout << "Secant Method : a root is: " << x3 << std::endl; 
}

int main() 
{
    solve_E();
    return 0;
}  
