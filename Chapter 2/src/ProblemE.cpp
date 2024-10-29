#include "Function.hpp"
#include "interpolation.hpp"
#include <iostream>
#include <cmath>
#include "matplotlibcpp.h"

int main()
{
    int n = 6;
    std::vector<double> x = {0 , 6 , 10 , 13 , 17 , 20 , 28 };
    std::vector<double> fE1 = {6.67 , 17.3 , 42.7 , 37.3 , 30.1 , 29.3 , 28.7};
    std::vector<double> fE2 = {6.67 , 16.1 , 18.9 , 15.0 , 10.6 , 9.44 , 8.89};   
    std::vector<double> x0(29) , y1(29) , y11(16); 
    std::vector<double> y2(29) , y22(16);

    std::cout << "E(a)使用牛顿公式计算出两个样本的平均重量曲线！" << std::endl;
    for(int i = 0 ; i <= 28 ; ++i)
    {
        x0[i] = i;
        y1[i] = interpolation(x , fE1 , n , x0[i]);
        y2[i] = interpolation(x , fE2 , n , x0[i]);     

    }
    matplotlibcpp::figure();
    matplotlibcpp::named_plot("Sp1", x0, y1, "r-");
    matplotlibcpp::named_plot("Sp2", x0, y2, "b-");
    matplotlibcpp::legend();
    matplotlibcpp::show();

    std::cout << "E(b)判断两个样本是否会死亡：" << std::endl;    
    for(int i = 1 ; i <= 15 ; ++i)
    {
        y11[i] = interpolation(x , fE1 , n , i + 28);
        if(y11[i] <= 0)
        {
           std::cerr << "Sp1 is dead at the date of " << i + 28 << "!" << std::endl; 
           break;            
        }
        if(i == 15)
            std::cout << "Sp1 isnot dead within the following 15days." << std::endl;
    }

    for(int i = 1 ; i <= 15 ; ++i)
    {
        y22[i] = interpolation(x , fE2 , n , i + 28);
        if(y22[i] <= 0)
        {
           std::cerr << "Sp2 is dead at the date of " << i + 28 << "!" << std::endl; 
           break;            
        }
        if(i ==15)
            std::cout << "Sp2 isnot dead within the following 15days." << std::endl;
    } 

    return 0;
}
