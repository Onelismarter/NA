
#ifndef EQUATIONSOLVER
#define EQUATIONSOLVER

#include <iostream>
#include "Function.hpp"
#include <cmath>
class EquationSolver{
protected:
    const Function & F; //在类中的某个地方，必须通过构造函数或者其他方法将一个 `Function`的派生类的实例！！！分配给这个引用，并且一旦分配后，就不能再将其引用其他对象。
public:
    EquationSolver(const Function& F) : F(F) {}
    virtual double solve() = 0;
};

class Bisection_Method : public EquationSolver {
private:
    double a, b;
    double eps, delta;
    int Maxiter;
public:
    Bisection_Method(const Function &F, double a, double b, 
        double eps = 1e-7, double delta = 1e-6, int Maxiter = 50) :
        EquationSolver(F), a(a), b(b), eps(eps), delta(delta), Maxiter(Maxiter) {} 
 virtual double solve() {
    if (F(a) * F(b) > 0) {
        std::cout << "f(a) and f(b) have the same sign." << std::endl;
        return NAN;
    }
    if (F(a) == 0) 
    {
        return a;
    }
    if (F(b) == 0) 
    {
        return b;       
    }
    double h = b - a;
    double c = a;
    for (int i = 0; i < Maxiter; i++) {
      h = h/2;
      c = a + h;
      double fc = F(c);
      if (std::abs(fc) < eps && h < delta) 
      {
         return c;
      }
      if (F(a) * F(c) > 0) 
       {
          a = c;
       }
    }
    std::cout << "Failed to find the root." << std::endl;
    return NAN;
  }
};

class Newton_Method : public EquationSolver {
private:
    double x0;
    double eps;
    int Maxiter;
public:
    Newton_Method(const Function &F, double x0, 
        double eps = 1e-7, int Maxiter = 8) :  
        EquationSolver(F), x0(x0), Maxiter(Maxiter), eps(eps) {}
    double x;
    virtual double solve() {
        x = x0;
        for(int i = 0 ; i < Maxiter ; i++)
        {
            if(std::abs(F(x))< eps)
                break;
            x = x - F(x)/F.derivative(x);
        }
        return x;   // to be replaced.
    }
};

class Secant_Method : public EquationSolver{
private:
    double x0, x1; 
    double eps, delta;
    int Maxiter;
public:
    Secant_Method(const Function &F, double x0, double x1,
    double eps = 1e-7,double delta = 1e-6, int Maxiter = 40) :
    EquationSolver(F), x0(x0), x1(x1), eps(eps), delta(delta), Maxiter(Maxiter){}

  virtual double solve() {
    double xn = x1;
    double xn_1 = x0;
    double fn = F(x1);
    double fn_1 = F(x0);

    for (int i = 0; i < Maxiter; i++) {
      double s = (xn - xn_1) / (fn - fn_1);
      xn_1 = xn;
      fn_1 = fn;
      xn = xn-fn*s;
      fn = F(xn);
      if (std::abs(fn) < eps && std::abs(xn - xn_1) < delta)
      {
        return xn;
      } 
    }
    std::cout << "Failed to find the root." << std::endl;
    return NAN;
  } 
};
#endif 
