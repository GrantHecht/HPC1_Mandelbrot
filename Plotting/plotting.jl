
using DrWatson
quickactivate(@__DIR__, "Plotting")

using CSV
using DataFrames
using Plots
pgfplotsx()

function main()
    # Read file
    df = DataFrame(CSV.File("cols_500_rows_250.txt"; delim = " "))

    # Filter out GridPoint(s) not in set
    filter!(row -> row.InSet == 1, df)

    # Plot 
    fig = scatter(df.Real, df.Imag; 
                  markersize=0.1, 
                  label="Points in Mandelbrot Set",
                  legend=:none)

    xlabel!("Real")
    ylabel!("Imaginary")
    savefig(fig, "test.pdf")
    return nothing
end

main()
