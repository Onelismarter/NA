
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
        double eps = 1e-7, double delta = 1e-6, int Maxiter = 1000) :
        EquationSolver(F), a(a), b(b), eps(eps), delta(delta), Maxiter(Maxiter) {} //调用基类的构造函数、初始化后面的成员变量
    
    virtual double solve() {
        double fa = F(a);
        double fb = F(b);
      //  std::cout << fa << "!!" << fb << std::endl;
        double h,c,fc;
        if (fa * fb < 0)
        {
            for (int i = 0 ; i < Maxiter ; i++)
            {
            h = b - a;
            c = a + h /2.0;
            if(std::abs(h) < delta )
                break;
            fc = F(c);
            if(std::abs(fc) < eps)
                break;
            else if(fc * fa < 0)
            {
                b = c;
                fb = fc;
            }
            else
            {
                a = c;
                fa = fc;
            }
            }
            return (a + b) /2.0;
        }
        else
        {
            std::cout << "下面为返回为异常值" << std::endl;
            return NAN;
        }
    }
};

class Newton_Method : public EquationSolver {
private:
    double x0;
    double eps;
    int Maxiter;
public:
    Newton_Method(const Function &F, double x0, 
        double eps = 1e-7, int Maxiter = 1000) :  
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
    double eps = 1e-7,double delta = 1e-6, int Maxiter = 1000) :
    EquationSolver(F), x0(x0), x1(x1), eps(eps), delta(delta), Maxiter(Maxiter){}

    virtual double solve() {
        double xn = x1;
        double xn_1 = x0;
        double fn = F(xn);
        double fn_1 = F(xn_1);
        double s;
        for (int i = 2; i < Maxiter ; i++)
        {
            s = (xn - xn_1)/(fn - fn_1);
            xn_1 = xn;
            fn_1 = fn;
            xn = xn - fn * s;
            if (abs(xn - xn_1) < delta)
                break;
            fn = F(xn);
            if (abs(fn) < eps)
                break;
        }
        return xn;
    }
};

#endif 

/*
// EquationSolver.hpp
#ifndef EQUATIONSOLVER_HPP
#define EQUATIONSOLVER_HPP

#include "Function.hpp"
#include <cmath>
#include <stdexcept> //C++预处理指令，定义了一组用于处理异常的标准异常类，更清晰地表达错误

class Bisection_Method {
public:
    Bisection_Method(const Function& func, double a, double b, double tol = 1e-6, int max_iter = 1000)
        : func(func), a(a), b(b), tol(tol), max_iter(max_iter) {}

    double solve() const {
        double fa = func(a);
        double fb = func(b);

        if (fa * fb > 0) {
            throw std::invalid_argument("The function must have different signs at a and b");
        }

        double c, fc;
        int iter = 0;
        while ((b - a) / 2.0 > tol && iter < max_iter) {
            c = (a + b) / 2.0;
            fc = func(c);

            if (fc == 0.0) {
                return c; // 找到精确根
            }

            if (fa * fc < 0) {
                b = c;
                fb = fc;
            } else {
                a = c;
                fa = fc;
            }
            iter++;
        }
        return (a + b) / 2.0; // 返回中点作为最佳估计
    }

private:
    const Function& func;  //在类中的某个地方，必须通过构造函数或者其他方法将一个 `Function`的派生类的实例！！！分配给这个引用，并且一旦分配后，就不能再将其引用其他对象。
    mutable double a, b;   //即使在常量成员函数中，仍然可以修改 `a` 和 `b` 的值。这通常用于需要在常量成员函数中修改状态的情况
    double tol;
    int max_iter;
};

class Newton_Method {
public:
    Newton_Method(const Function& func, double initial_guess, double tol = 1e-6, int max_iter = 1000)
        : func(func), x0(initial_guess), tol(tol), max_iter(max_iter) {}

    double solve() const {
        double x = x0;
        for (int i = 0; i < max_iter; ++i) {
            double fx = func(x);
            double dfx = (func(x + tol) - fx) / tol; // Numerical derivative

            if (std::abs(dfx) < tol) {
                throw std::runtime_error("Derivative too small");
            }

            double x1 = x - fx / dfx;
            if (std::abs(x1 - x) < tol) {
                return x1;
            }
            x = x1;
        }
        throw std::runtime_error("Maximum iterations exceeded");
    }

private:
    const Function& func;
    double x0;
    double tol;
    int max_iter;
};

class Secant_Method {
public:
    Secant_Method(const Function& func, double x0, double x1, double tol = 1e-6, int max_iter = 1000)
        : func(func), x0(x0), x1(x1), tol(tol), max_iter(max_iter) {}

    double solve() const {
        double f0 = func(x0);
        double f1 = func(x1);

        for (int i = 0; i < max_iter; ++i) {
            if (std::abs(f1 - f0) < tol) {
                throw std::runtime_error("Function values too close to each other");
            }

            double x2 = x1 - f1 * (x1 - x0) / (f1 - f0);
            if (std::abs(x2 - x1) < tol) {
                return x2;
            }

            x0 = x1;
            f0 = f1;
            x1 = x2;
            f1 = func(x1);
        }
        throw std::runtime_error("Maximum iterations exceeded");
    }

private:
    const Function& func;
    mutable double x0, x1; // 将 x0 和 x1 声明为 mutable
    double tol;
    int max_iter;
};

#endif // EQUATIONSOLVER_HPP 

*/




