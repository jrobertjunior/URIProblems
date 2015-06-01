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

//#define DEBUG_MODE_ON

#ifdef DEBUG_MODE_ON
    #define DLOG(x) std::cout << x << std::endl;
#else
    #define DLOG(x)
#endif

template<typename T>
inline bool hasNextCase(T &caseA)
{
    if (std::cin >> caseA)
    {
        return true;
    }
    return false;
}

int main()
{
    // Make it fast in c++
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int caseA;
    while (hasNextCase(caseA))
    {
        // code goes here
    }
    std::cout.flush();
    return 0;
}

