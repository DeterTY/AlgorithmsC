#include <stdio.h>
#include <math.h>

#define EPS 1e-7
#define EULER 0.577215664901532860606512090082

double ch(double x)
{
    //ch(x) = 1 + x2/2! + x4/4! + x6/6! + x8/8! + ...
    double s = 0;
    int k = 0;
    // ... ... ...
    return s;
}

double sh(double x)
{
    //sh(x) = x + x3/3! + x5/5! + x7/7! + x9/9! + ...
    double s = 0;
    int k = 0;
    // ... ... ...
    return s;
}

// Функция для вычисления интегрального синуса Ci(x)
double Ci(double x)
{
    // Сумма членов ряда
    double s = 0;
    
    // Первый член ряда
    double a = x;
    
    // Текущий член ряда
    double term = a;
    
    // Начальное значение номера члена ряда
    int k = 2;

    // Выполняем цикл до тех пор, пока текущий член ряда больше EPS
    while (fabs(term) > EPS)
    {
        // Обновляем сумму
        s += term;

        // Вычисляем следующий член ряда
        a = -a * x * x / ((2*k-1) * 2 * k);

        // Обновляем текущий член ряда
        term = a;

        // Увеличиваем номер члена ряда
        k++;
    }

    // Возвращаем значение интегрального синуса
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
