#ifndef FUNCTION_HPP
#define FUNCTION_HPP

const double der_delta = 1e-8;
class Function {                      //包含纯虚函数的类被称为抽象类
public:
    virtual double operator() (double x) const = 0;
    // 纯虚函数，使得function类不能被实例化，只能被继承
    //virtual表示这是一个虚函数，允许在派生类中重写（override）它，即多态；operate（）是指重载了函数调用运算符（）

    virtual double derivative(double x) const {
        return((*this)(x + der_delta) - (*this)(x - der_delta)) / (2 * der_delta);
    }
};

#endif




