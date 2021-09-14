#ifndef GRIDPOINT_HPP
#define GRIDPOINT_HPP

#include <complex>

class GridPoint {
    public:
        // Constructor
        GridPoint(double real, double imag); 

        // Iterate
        void Iterate(int numIters);
        
        // Get grid point real componant
        double GetReal();
        
        // Get grid point imag. componant
        double GetImag();

        // Get flag 
        bool IsInSet();

        // Get number of iters
        int GetItersToDiverge();

    private:
        // Location in grid
        std::complex<double> c;

        // Flag to indicate if in set
        bool flag;

        // Number of iterations to diverge
        int iters;
};

#endif
