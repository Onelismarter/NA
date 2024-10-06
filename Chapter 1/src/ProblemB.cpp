
#include "Function.hpp"
#include "EquationSolver.hpp"
#include <iostream>
#include <cmath>

const double Pi = acos(-1.);

class B1 : public Function {
public:
    double operator() (double x) const {
        return 1.0/x-tan(x);
    }

    double derivative(double x) const  {  
 
    double h = 1e-5;  // 微小增量  
    return (operator()(x + h) - operator()(x - h)) / (2 * h);  
    }    
};

class B2 : public Function {
public:
    double operator() (double x) const {
        return 1.0/x-std::pow(2,x);
    }

    double derivative(double x) const  {  

    double h = 1e-5;  // 微小增量  
    return (operator()(x + h) - operator()(x - h)) / (2 * h);  
    }    
};

class B3 : public Function {
public:
    double operator() (double x) const {
        return std::pow(2,-x)+std::exp(x)+2*cos(x)-6;
    }

    double derivative(double x) const  {  

    double h = 1e-5;  // 微小增量  
    return (operator()(x + h) - operator()(x - h)) / (2 * h);  
    }    
};

class B4 : public Function {
public:
    double operator() (double x) const {
        return (std::pow(x,3)+4*std::pow(x,2)+3*x+5)/(2*std::pow(x,3)-9*std::pow(x,2)+18*x-2);
    }

    double derivative(double x) const  {  

    double h = 1e-5;  // 微小增量  
    return (operator()(x + h) - operator()(x - h)) / (2 * h);  
    }    
};


void solve_B1() {
    std::cout << "Solving B1 on [0, \\pi/2]" << std::endl;
    B1 f1;
    Bisection_Method solver_f1_Bisection(f1, 0.1, Pi/2-0.1);  //创建 Bisection_Method 匿名对象，传递了一个临时的 F1 对象，在表达式结束时就被销毁了；F1()(some_value)`，它会返回 `1.0/some_value - tan(some_value)` 的值，重载了第二个（）
    double x1 = solver_f1_Bisection.solve();
    std::cout << "Bisection_Method : a root is: " << x1 << std::endl;

}

void solve_B2() {
    std::cout << "Solving B2 on [0, 1]" << std::endl;
    B2 f2;
    Bisection_Method solver_f2_Bisection(f2, 0.01, 1-0.01); 
    double x1 = solver_f2_Bisection.solve();
    std::cout << "Bisection_Method : a root is: " << x1 << std::endl;
}


void solve_B3() {
    std::cout << "Solving B3 on [1, 3]" << std::endl;
    B3 f3;
    Bisection_Method solver_f3_Bisection(f3, 0.9, 2.99); 
    double x1 = solver_f3_Bisection.solve();
    std::cout << "Bisection_Method : a root is: " << x1 << std::endl;
}

void solve_B4() {
    std::cout << "Solving B4 on [0, 4]" << std::endl;
    B4 f4;
    Bisection_Method solver_f4_Bisection(f4, 0, 4); 
    double x1 = solver_f4_Bisection.solve();
    std::cout << "Bisection_Method : a root is: " << x1 << std::endl;
}


int main() 
{
    solve_B1();
    solve_B2();
    solve_B3();
    solve_B4();
    return 0;
}  
