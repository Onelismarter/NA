#include "interpolation.hpp"

double interpolation(const std::vector<double>& x ,  const std::vector<double>& y , int n , double to_inter)


{
    std::vector<double> diag(y);   
    for (int j = 1; j <= n; ++j) {
        for (int i = n; i >= j; --i) {
            diag[i] = (diag[i] - diag[i - 1]) / (x[i] - x[i - j]);
        }
    }                                  //最终获得差商表里面的对角元素

    double out_put = diag[n];          //最后一个对角元
    for (int i = n - 1; i >= 0; --i) {
        out_put = out_put * (to_inter - x[i]) + diag[i]; //递归计算
    }

    return out_put;
}