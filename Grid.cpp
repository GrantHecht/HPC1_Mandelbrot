
#include "Grid.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>

Grid::Grid(int numRowsIn, int numColsIn, int numItersIn) :
    numRows(numRowsIn), numCols(numColsIn), numIters(numItersIn)
{
    // Set feilds
    realMin  = -2.0;
    realMax  =  2.0;
    imagMin  = -1.0;
    imagMax  =  1.0; 

    // Size vector of *GridPoint(s)
    int numPoints = numRowsIn*numColsIn;
    grid.resize(numPoints);

    // Instantiate GridPoint objects
    double imagStep = (imagMax - imagMin) / (numRowsIn - 1);
    double realStep = (realMax - realMin) / (numColsIn - 1);
    double currentImag;
    for (int ii = 0; ii < numRows; ii++)
    {
        // Compute current imaginary value
        currentImag = imagMax - ii*imagStep;
        for (int jj = 0; jj < numCols; jj ++) {
            // Add pointer to grid
            grid[GetGridVecIdx(ii,jj)].SetReal(realMin + jj*realStep);
            grid[GetGridVecIdx(ii,jj)].SetImag(currentImag);
        }
    }

    // Set remaining class variables
    area = 0.0;
    setComputed = false;
    areaComputed = false;
}

Grid::~Grid()
{
}

void Grid::ComputeSet()
{
    // Iterate for all GridPoint(s)
    for (int ii = 0; ii < numRows; ii++)
        for (int jj = 0; jj < numCols; jj++)
            grid[GetGridVecIdx(ii,jj)].Iterate(numIters);

    // Set flag
    setComputed = true;
}

void Grid::ComputeSetArea()
{
    // Compute set if necessary
    if (setComputed == false)
        ComputeSet();

    double gridPointArea = ((imagMax - imagMin) / (numRows - 1))*((realMax - realMin) / (numCols - 1));
    for (int ii = 0; ii < numRows; ii++) 
        for (int jj = 0; jj < numCols; jj++)
            if (grid[GetGridVecIdx(ii,jj)].IsInSet())
                area += gridPointArea;

    // Set flag
    areaComputed = true;
}

void Grid::PrintResults(std::string fileName)
{
    // Open file
    std::ofstream outFile;
    outFile.open(fileName);
    outFile << std::setprecision(14);

    // Print column lables
    outFile << "Real Imag InSet Iters\n";

    // Loop through GridPoint(s)
    for (int ii = 0; ii < numRows; ii++) {
        for (int jj = 0; jj < numCols; jj++) {
            // Write line to file
            outFile << grid[GetGridVecIdx(ii,jj)].GetReal() << " " << grid[GetGridVecIdx(ii,jj)].GetImag() << " " 
                << grid[GetGridVecIdx(ii,jj)].IsInSet() << " " << grid[GetGridVecIdx(ii,jj)].GetItersToDiverge() << "\n";
        }
    }

    // Close file
    outFile.close();
}

double Grid::GetAreaOfSet()
{
    // Compute area if necessary
    if (areaComputed == false)
        ComputeSetArea();

    // Return area
    return area;
}

int Grid::GetGridVecIdx(int row, int col)
{
    return (row*numCols + col);
}
