/**
 * URI Online problem #number#
 * Problem name: #name#
 *
 * Runtime in site: NOT PASSED YET
 *
 * @autor José Junior
 *
 * Description:
 */

#include <iostream>
#include <math.h>
#include <iomanip>
#include <stdio.h>

//#define DEBUG_MODE_ON

#ifdef DEBUG_MODE_ON
    #define DLOG(x) std::cout << x << std::endl;
#else
    #define DLOG(x)
#endif

const double PI          = 3.14159;
const double GRAVITY     = 9.80665;
const double onEighty    = 180.0;

inline double calcX(double alfa, double v, double h)
{
    double Vx = v * cos ( alfa * PI / onEighty);
    double Vy = v * sin ( alfa * PI / onEighty);

    double ts1 = 2.0 * Vy / GRAVITY;
    double T1 = (-Vy + sqrt(Vy*Vy + 2.0*GRAVITY*h))/GRAVITY;

    return Vx * (ts1+T1);
}

int main()
{
    // Make it fast in c++
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    double  h;
    while (std::cin >> h)
    {
        int p1, p2;
        std::cin >> p1 >> p2;
        int nTries;
        std::cin >> nTries;
        double alfa, v;
        for (int i = 0; i < nTries; i++)
        {
            std::cin >> alfa >> v;
            double x =  calcX(alfa, v, h);
            std::cout << std::fixed << std::setprecision(5) << x << " -> ";
            if ( x < p1 ||  x > p2 )
            {
                std::cout << "NUCK\n";
            }
            else
            {
                std::cout << "DUCK\n";
            }
        }
    }
    std::cout.flush();
    return 0;
}

