
#ifndef GRID_HPP
#define GRID_HPP

#include "GridPoint.hpp"
#include <vector>
#include <string>

class Grid
{
    public:
        // Constructor 
        Grid(int numRowsIn, int numColsIn, int numItersIn = 1000);

        // Destructor
        ~Grid();

        // Compute set
        void ComputeSet();

        // Compute area of set
        void ComputeSetArea();
        
        // Print resuls to file
        void PrintResults(std::string fileName);

        // Get set area
        double GetAreaOfSet();

    private:
        // Vector of vectors containing pointers to GridPoint(s)
        std::vector<std::vector<GridPoint*>> grid; 

        // Number of rows 
        int numRows;

        // Number of columns
        int numCols;

        // Desired number of iterations when checking for divergence
        int numIters;

        // Area of set
        double area;

        // Grid bounds
        double realMin;
        double realMax;
        double imagMin;
        double imagMax;

        // Flag indicating set has been computed
        bool setComputed;
        bool areaComputed;
};

#endif
