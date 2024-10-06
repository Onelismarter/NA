
#include "Function.hpp"
#include "EquationSolver.hpp"
#include <iostream>
#include <cmath>

const double Pi = acos(-1.);

class D1 : public Function {
public:
    double operator() (double x) const {
        return (sin(x/2)-1);
    }
    double derivative(double x) const {}
};

class D2 : public Function {
public:
    double operator() (double x) const {
        return (std::exp(x)-tan(x));
    }
    double derivative(double x) const {}
};

class D3 : public Function {
public:
    double operator() (double x) const {
        return (std::pow(x,3)-12*std::pow(x,2)+3*x+1);
    }
    double derivative(double x) const {}
};


void solve_D1() {
    std::cout << "Solving D1 " << std::endl;
    D1 d1;
    Secant_Method solver_d1_Secant1(d1, 0, Pi/2);
    double x1 = solver_d1_Secant1.solve();
    std::cout << "Secant Method : the first initial value, a root is: " << x1 << std::endl; 

    
    Secant_Method solver_d1_Secant2(d1, -9, -8);
    double x1_2 = solver_d1_Secant2.solve();
    std::cout << "Secant Method : the second initial value, a root is: " << x1_2 << std::endl; 
}
void solve_D2() {
    std::cout << "Solving D2 " << std::endl;
    D2 d2;
    Secant_Method solver_d2_Secant1(d2, 1, 1.4);
    double x2 = solver_d2_Secant1.solve();
    std::cout << "Secant Method : the first initial value, a root is: "  << x2 << std::endl; 

    Secant_Method solver_d2_Secant2(d2, -4, -2);
    double x2_2 = solver_d2_Secant2.solve();
    std::cout << "Secant Method : the second initial value, a root is: "  << x2_2 << std::endl; 
}
void solve_D3() {
    std::cout << "Solving D3 " << std::endl;
    D3 d3;
    Secant_Method solver_d3_Secant1(d3, 0, -0.5);
    double x3 = solver_d3_Secant1.solve();
    std::cout << "Secant Method : the first initial value, a root is: " << x3 << std::endl; 

    Secant_Method solver_d3_Secant2(d3, 0.2, 0.4);
    double x3_2 = solver_d3_Secant2.solve();
    std::cout << "Secant Method : the second initial value, a root is: "  << x3_2 << std::endl;
}


int main() 
{
    solve_D1();
    solve_D2();
    solve_D3();
    return 0;
}  
