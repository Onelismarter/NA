#include<vector>
#include<cmath>

std::vector<std::pair<double, double>> Bezier(const std::pair<double, double>& p0 , const std::pair<double, double>& p1,
                                                 const std::pair<double,double>& p2 , const std::pair<double, double>& p3 , int num = 200) ;