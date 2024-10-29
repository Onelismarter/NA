#include <iostream>
#include "Hermite.hpp"
const double der_delta = 1e-8;

int main() {
    std::vector<hermite_Node> nodes = {{0, 0, 75} , {3, 225, 77} , {5, 383, 80} , {8, 623, 74} , {13, 993, 72}};
    std::vector<double> diag = hermite_diag(nodes);
    std::vector<double> x(2 * nodes.size());
    for (size_t i = 0; i < nodes.size(); ++i) {
        x[2 * i] = x[2 * i + 1] = nodes[i].x;
    }

    double t = 10;
    auto position = hermite_output(diag, x, t);
    auto speed = (hermite_output(diag, x, t + der_delta) - hermite_output(diag, x, t - der_delta) ) / (2 *  der_delta);
    
    std::cout << "D(a):" << std::endl;
    std::cout << "The position of the car at " << t << " is " << position << std::endl;
    std::cout << "The speed of the car at " << t << " is " << speed << std::endl;

    std::cout << "D(b):" << std::endl;
    for( double i = 0 ; i <= 13 ; i = i + 0.1)
    {
        position = hermite_output(diag, x, i);
        speed = (hermite_output(diag, x, i + der_delta) - hermite_output(diag, x, i - der_delta) ) / (2 *  der_delta);
        if (speed > 81)
        {  
            std::cerr << "The first overspeed is at the time of " << i << "s!"<< std::endl;
            break;
        }
        else if(i == 13)
        {
            std::cout << "The speed is limited!" << std::endl;
        }
    }

    return 0;
}  




