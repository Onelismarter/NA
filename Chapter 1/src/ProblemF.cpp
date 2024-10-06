
#include "Function.hpp"
#include "EquationSolver.hpp"
#include <iostream>
#include <cmath>

const double Pi = acos(-1.);


class Fac : public Function {
public:
    double operator()(double x) const{
        double l = 89;
        double h = 49;
        double D = 55;
        double beta = 11.5/180*Pi;
        double A = l * sin(beta);
        double B = l * cos(beta);
        double C = (h+0.5*D)*sin(beta)-0.5*D*tan(beta);
        double E = (h+0.5*D)*cos(beta)-0.5*D;
        return (A*sin(x)*cos(x)+B*sin(x)*sin(x)-C*cos(x)-E*sin(x));
    }
    double derivative(double x) const  {  
    double h = 1e-5;  // 微小增量  
    return (operator()(x + h) - operator()(x - h)) / (2 * h);  
    } 
};

class Fb : public Function {
public:
    double operator()(double x) const{
        double l = 89;
        double h = 49;
        double D = 30;
        double beta = 11.5/180*Pi;
        double A = l * sin(beta);
        double B = l * cos(beta);
        double C = (h+0.5*D)*sin(beta)-0.5*D*tan(beta);
        double E = (h+0.5*D)*cos(beta)-0.5*D;
       // std::cout << A << " " << B << " " << C << " " << E << " " << beta << std::endl;
        return (A*sin(x)*cos(x)+B*sin(x)*sin(x)-C*cos(x)-E*sin(x));
    }
    double derivative(double x) const  {  
    double h = 1e-5;  // 微小增量  
    return (operator()(x + h) - operator()(x - h)) / (2 * h);  
    } 
};


void solve_Fac() {
    Fac f;
    std::cout << "Solving F(a)" << std::endl;    
    Newton_Method solver_F_Newton1(f, 34);
    double alpha_a = solver_F_Newton1.solve();
    std::cout << "Newton_Method : a root is: " << alpha_a << std::endl;

    std::cout << "Solving F(c)" << std::endl;  
    Secant_Method solver_F_Secant1(f, 0, 10);
    double alpha_c1 = solver_F_Secant1.solve();
    std::cout << "Secant Method : the first initial value, a root is: " << alpha_c1 << std::endl; 

    Secant_Method solver_F_Secant2(f, 40, 50);
    double alpha_c2 = solver_F_Secant2.solve();
    std::cout << "Secant Method : the second initial value, a root is: " << alpha_c2 << std::endl; 

    Secant_Method solver_F_Secant3(f, 80, 90);
    double alpha_c3 = solver_F_Secant3.solve();
    std::cout << "Secant Method : the third initial value, a root is: " << alpha_c3 << std::endl; 

}

void solve_Fb() {
    std::cout << "Solving F(b)" << std::endl;
    Fb f;
    Newton_Method solver_F_Newton1(f, 33);
    double alpha_b = solver_F_Newton1.solve();
    std::cout << "Newton_Method : a root is: " << alpha_b << std::endl;
}

int main() 
{
    solve_Fac();
    solve_Fb();
    return 0;
}  
