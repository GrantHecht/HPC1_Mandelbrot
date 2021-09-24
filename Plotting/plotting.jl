
using DrWatson
quickactivate(@__DIR__, "Plotting")

using CSV
using DataFrames
using MATLAB

# Read file
df = DataFrame(CSV.File("cols_800_rows_400.txt"; delim = " "))

# Filter out GridPoint(s) not in set
filter!(row -> row.InSet == 1, df)

# Plot with MATLAB
mat"""
scatter($(df.Real), $(df.Imag), 2, 'filled')
legend("Points in Mandelbrot Set", "location", "northwest")
xlabel("Real")
ylabel("Imaginary")
"""

mat"""
plot([1.57823, 1.50084, 1.51074, 1.5082])
hold on
yline(1.506484, '--')
hold off
xticks([1,2,3,4])
xticklabels({'25 x 50', '100 x 200', '225 x 400', '400 x 800'})
xlabel("Grid Size (Rows x Cols.)")
ylabel("Area")
legend("Estimated Area", "Expected Area")
"""