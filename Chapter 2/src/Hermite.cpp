#include "Hermite.hpp"

std::vector<double> hermite_diag(const std::vector<hermite_Node>& nodes) {
    int n = nodes.size();
    std::vector<double> z(2 * n);
    std::vector<double> Q(2 * n * 2 * n, 0.0);

    for (int i = 0; i < n; ++i) {                      //只做了一阶差商
        z[2 * i] = z[2 * i + 1] = nodes[i].x;
        Q[2 * i * 2 * n] = nodes[i].f;                 //2n*2n的横方向的差商表矩阵转成2n*2n的向量了
        Q[(2 * i + 1) * 2 * n] = nodes[i].f;
        if (i != 0) {
            Q[2 * i * 2 * n + 1] = (Q[2 * i * 2 * n] - Q[(2 * i - 1) * 2 * n]) / (z[2 * i] - z[2 * i - 1]);
        }
        Q[(2 * i + 1) * 2 * n + 1] = nodes[i].df;
    }

    for (int i = 2; i < 2 * n; ++i) {                  //之后的外层
        for (int j = 2; j < i + 1; ++j) {
            Q[i * 2 * n + j] = (Q[i * 2 * n + j - 1] - Q[(i - 1) * 2 * n + j - 1]) / (z[i] - z[i - j]);
        }
    }

    std::vector<double> diag(2 * n);                   //差商表的对角
    for (int i = 0; i < 2 * n; ++i) {
        diag[i] = Q[i * 2 * n + i];
    }
    return diag;
}

double  hermite_output(const std::vector<double>& hermite_diag, const std::vector<double>& x, double t) {
    int n = hermite_diag.size();
    double output = hermite_diag[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        output = output * (t - x[i]) + hermite_diag[i];
    }
    return output;
}