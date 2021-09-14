
using DrWatson
quickactivate(@__DIR__, "Plotting")

using CSV
using DataFrames
using Gadfly

function main()
    # Read file
    df = DataFrame(CSV.File("cols_500_rows_250.txt"; delim = " "))

    # Filter out GridPoint(s) not in set
    filter!(row -> row.InSet == 1, df)

    # Plot 
    p = plot(df, x=:Real, y=:Imag)
    draw(SVG("test.svg", 6inch, 4inch), p)
end

main()