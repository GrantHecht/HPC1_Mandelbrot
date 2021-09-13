
#include "GridPoint.hpp"

GridPoint::GridPoint(double real, double imag)
{
    // Set real and imaginary componants of c
    c.real(real);
    c.imag(imag);

    // Set flag and iterations
    flag  = true;
    iters = -1;
}

void GridPoint::Iterate(int numIters, int maxIters)
{
    // Initialize iteration counter and z
    int ii = 0;
    std::complex<double> z(0.0, 0.0);

    // Begin iterating
    for (int iter = 1; iter <= maxIters; iter++)
    {
        // Update z
        z = z*z + c;

        // Check for divergence
        if (std::abs(z) > 2)
        {
            flag  = false;
            iters = iter;
            break;
        }
    }
}
