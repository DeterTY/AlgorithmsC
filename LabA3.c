#include <stdio.h>
#include <math.h>

int n;

double si(double x)
{
    return sin(x)/x;
}

double trapezoidal_rule(double z, double eps)
{
    n = 10;
    double prev_result = 0;
    while (1)
    {
        double h = z/n;
        double result = 0;
        for(int i = 1; i < n; i++)
        {
            double x = i * h;
            result += sin(x) * sqrt(x);
        }
        result += (sin(0) * sqrt(0) + sin(z) * sqrt(x))/2;
        result *= h;
        if (fabs(result - prev_result) < eps)
        {
            return result;
        }
        prev_result = result;
        n *= 2;
    }
}

int main()
{
    double start = 0;
    double end = 10;
    double step = 0.2;
    double eps = 1e-8;
    printf("z\t\tintegral\n");
    printf("\n");
    for(double z = start; z <= end; z += step)
    {
        double integral = trapezoidal_rule(z, eps);
        printf("%lf\t%lf %d\n", z, integral, n);
    }
    
    return 0;
}
