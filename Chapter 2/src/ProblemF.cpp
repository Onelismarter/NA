#include <iostream>
#include <vector>
#include <cmath>
#include "matplotlibcpp.h"
#include "Bezier.hpp"

// 首先生成原来的心形曲线上的点 在原来的心形曲线上生成了多少个点，每个点后来都对应一条曲线
std::vector<std::pair<double, double>> heart_Points(int number = 400) {
    std::vector<std::pair<double, double>> heart_points;
    //将曲线根据y值分为上下两部分
    for (int i = 0; i <= number; ++i) {
        double x = -2.0 + 4.0 * i / number;  
        if (3 - x * x >= 0) {
            double y_up = (2.0 / 3.0) * (sqrt(3 - x * x) + sqrt(fabs(x)));
            heart_points.emplace_back(x, y_up);
        }
    }
    for (int i = number; i >= 0; --i) {
        double x = -2.0 + 4.0 * i / number;  
        if (3 - x * x >= 0) {
            double y_down = (2.0 / 3.0) * (-sqrt(3 - x * x) + sqrt(fabs(x)));
            heart_points.emplace_back(x, y_down);
        }
    }
    return heart_points;
}

// 其次根据心形点生成每个点的切向量
std::vector<std::pair<double, double>> tan_Vectors(const std::vector<std::pair<double, double>>& heart_points) {
    std::vector<std::pair<double, double>> tan(heart_points.size());
     for (size_t i = 1 ; i < heart_points.size() - 1 ; ++i) {
        double delta_x = heart_points[i + 1].first - heart_points[i - 1].first;
        double delta_y = heart_points[i + 1].second - heart_points[i - 1].second;
        tan[i] = {delta_x / std::sqrt(delta_x * delta_x + delta_y * delta_y) , delta_y / std::sqrt(delta_x * delta_x + delta_y * delta_y)};
    }
    tan[0] = tan[1];
    tan[heart_points.size() - 1] = tan[heart_points.size() - 2];      //最后一个切向量方向用倒数第二个代替
    return tan;
}

// 使用贝塞尔曲线拟合心形曲线：这个m是指有多少条曲线，是原来的多少个点
std::vector<std::pair<double, double>> Fit(const std::vector<std::pair<double, double>>& points , const std::vector<std::pair<double, double>>& tan , int interval) {
    std::vector<std::pair<double, double>> Points;
    for (size_t i = 0 ; i < points.size() - interval ; i += interval) {
        auto p0 = points[i];
        auto p3 = points[i + interval];
        auto p1 = std::make_pair(p0.first + tan[i].first / 3, p0.second + tan[i].second / 3);
        auto p2 = std::make_pair(p3.first - tan[i + interval].first / 3, p3.second - tan[i + interval].second / 3);
        auto to_add = Bezier(p0, p1, p2, p3);                                              //返回一条拟合曲线的点
        Points.insert(Points.end(), to_add.begin(), to_add.end());                         //将这个拟合曲线的点从头到尾 在旧拟合曲线的末尾插入
    }
    return Points;
} 

int main() {
    int num = 800;  
    auto h_points = heart_Points(num);
    auto tan_vec = tan_Vectors(h_points);
    std::vector<int> m = {10 , 40 , 160};
    std::vector<int> interval(3);
    for (int i = 0 ; i <= 2 ; ++i)
    {
        interval[i] = num / m[i];
    }

    for (int it : interval) {
        std::vector<double> x_heart, y_heart, x_bezier, y_bezier;
        for (const auto& point : h_points) {
            x_heart.push_back(point.first);
            y_heart.push_back(point.second);
        }

        auto b_points = Fit(h_points, tan_vec, it);
        for (const auto& point : b_points) {
            x_bezier.push_back(point.first);
            y_bezier.push_back(point.second);
        }
        std::cout << "F:输出图形" << std::endl;
        matplotlibcpp::figure();
        matplotlibcpp::named_plot("Heart", x_heart, y_heart, "ro");
        matplotlibcpp::named_plot("Bezier", x_bezier, y_bezier, "b-");
        matplotlibcpp::title("Here m = " + std::to_string(num / it));
        matplotlibcpp::legend();
    }
    matplotlibcpp::show();
    return 0;
}

