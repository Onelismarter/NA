
#ifndef FUNCTION
#define FUNCTION

class Function {                      //包含纯虚函数的类被称为抽象类
public:
    virtual double operator() (double x) const = 0;
    // 纯虚函数，使得function类不能被实例化，只能被继承
    //virtual表示这是一个虚函数，允许在派生类中重写（override）它，即多态；operate（）是指重载了函数调用运算符（）
    //const表示函数不会修改类内数据成员；=0表示这是一个纯虚函数，不能有函数体，不能被实例化
    virtual double derivative(double x) const = 0;
    virtual ~Function() = default;    // 虚析构函数：确保了在删除一个指向派生类的基类指针时，派生类的析构函数会被正确调用
};

#endif




