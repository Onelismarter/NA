#include <vector>
class hermite_Node {
public:
    double x; 
    double f;
    double df;    
};

std::vector<double> hermite_diag(const std::vector<hermite_Node>& nodes);
double  hermite_output(const std::vector<double>& hermite_diag, const std::vector<double>& x, double t);
