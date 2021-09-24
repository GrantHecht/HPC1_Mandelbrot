
#include "Grid.hpp"
#include <iostream>
#include <string>

int main()
{
    int initRows = 25;
    int initCols = 50;
    int numIters = 10000;

    for (int ii = 1; ii <= 4; ii++)
    {
        // Compute number of rows and columns for current iteration
        int rows = initRows*ii*ii;
        int cols = initCols*ii*ii;

        // Allocate new Grid object
        Grid* gridPtr = new Grid(rows, cols, numIters);

        // Compute which points are in set
        gridPtr->ComputeSet();

        // Print area
        std::cout << "Approximated area of set: " << gridPtr->GetAreaOfSet() << std::endl;

        // Write results to file 
        std::string  fName = "cols_" + std::to_string(cols) + "_rows_" + 
            std::to_string(rows) + ".txt";
        gridPtr->PrintResults("Plotting/" + fName);

        // Deallocate pointer
        delete gridPtr;
    }

    return 0;
}
