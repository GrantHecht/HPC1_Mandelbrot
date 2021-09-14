
#include "Grid.hpp"
#include <iostream>
#include <string>

int main()
{
    int rows = 250;
    int cols = 500;

    for (int ii = 1; ii <= 4; ii++)
    {
        // Allocate new Grid object
        Grid* gridPtr = new Grid(rows*ii, cols*ii);

        // Compute which points are in set
        gridPtr->ComputeSet();

        // Print area
        std::cout << "Approximated area of set: " << gridPtr->GetAreaOfSet() << std::endl;

        // Write results to file 
        std::string  fName = "cols_" + std::to_string(cols*ii) + "_rows_" + 
            std::to_string(rows*ii) + ".txt";
        gridPtr->PrintResults("Plotting/" + fName);

        // Deallocate pointer
        delete gridPtr;
    }

    return 0;
}
