#include <stdio.h>
#include <math.h>

#define EPS 1e-7
#define EULER 0.577215664901532860606512090082

double ch(double x)
{
    double s = 1;
    double a = 1;
    int k = 2;
    while (fabs(a) > EPS)
    {
        a = a * x * x / (2*k * (2*k - 1));
        s += a;
        k++;
    }
    return s;
}

double sh(double x)
{
    double s = x;
    double a = x;
    int k = 2;
    while (fabs(a) > EPS)
    {
        a = a * x * x / ((2*k - 1) * 2 * k);
        s += a;
        k++;
    }
    return s;
}

// Функция для вычисления интегрального синуса Ci(x)
double Ci(double x)
{
    double s = 0;
    double a = x;
    double t = a;
    int k = 2;
    
    while (fabs(t) > EPS)
    {
        s += t;
        a = -a * x * x / ((2*k-1) * 2 * k);
        t = a;
        k++;
    }

    // Возврат значения интегрального синуса
    return EULER + log(x) + s;
}


int main()
{
    double x;
    for (x = 0.5; x < 10; x += 0.2)
    {
        printf("%16.7lf %16.7lf\n", x, Ci(x));
        //printf("%16.8lf %16.8lf %16.8lf %16.8lf\n", sh(x), ch(x), sinh(x), cosh(x));
    }
    
    return 0;
}
