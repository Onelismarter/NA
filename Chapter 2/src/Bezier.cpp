#include "Bezier.hpp"

// 每次调用生成一条贝塞尔曲线，这个曲线是由 num 个点而形成的
std::vector<std::pair<double, double>> Bezier(const std::pair<double, double>& p0 , const std::pair<double, double>& p1,
                                                 const std::pair<double,double>& p2 , const std::pair<double, double>& p3 , int num) 
{
    std::vector<std::pair<double, double>> bezier;
    for (int i = 0; i <= num; ++i) {
        double t = static_cast<double>(i) / num;           //将int i类型转化为double类型
        double x = std::pow(1 - t, 3) * p0.first + 3 * std::pow(1 - t, 2) * t * p1.first + 3 * (1 - t) * std::pow(t, 2) * p2.first + std::pow(t, 3) * p3.first;
        double y = std::pow(1 - t, 3) * p0.second + 3 * std::pow(1 - t, 2) * t * p1.second + 3 * (1 - t) * std::pow(t, 2) * p2.second + std::pow(t, 3) * p3.second;
        bezier.emplace_back(x, y);                          //在vector的末尾直接构造对象，而不需要像类中的构造函数那样
    }
    return bezier;
}