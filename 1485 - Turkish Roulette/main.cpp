/**
 * 1485 - Turkish Roulette
 * @Autor José Junior
 *
 * Runtime: 0.120s
 * 
 * Date: 2015.05.29
 */

#include <iostream>
#include <cstring>
#include <sstream>
 
// Nice way to exit the loop
inline bool nextTest(int *sSlots, int *bBalls)
{
     std::cin >> *sSlots >> *bBalls;
     if(*sSlots == 0 && *bBalls == 0)
     {
         return false;
     }
     std::cin.ignore();
     return true;
}
 
inline void getIntLine(int array[])
{
    std::string input;
    std::getline(std::cin, input);
    std::stringstream line(input);
    int next;
    int i = 1;
    while (line >> next)
    {
        array[i++] = next;
    }
}
 
inline void getIntLineCircle(int array[], int size)
{
    std::string input;
    std::getline(std::cin, input);
    std::stringstream line(input);
    int next;
    int i = 1;
    while (line >> next)
    {
        array[i] = -next;
        array[size + i++] = -next;
    }
}
 
int main()
{
    // Make it fast in c++
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
 
    int sSlots, bBalls;
 
    while (nextTest(&sSlots, &bBalls))
    {
        int slots[2*(sSlots+1)];
        int balls[bBalls+1];
        int memory[sSlots+1][sSlots+1];
        int best = -2000000000;
        int points;

        getIntLineCircle(slots, sSlots);
        getIntLine(balls);

        // As the Roulette is a circle list, we need to test for the first ball starting in different positions
        // This way the other balls can occupy this space in another round, and all balls in all slots will be verified
        for (int round = 0; round < sSlots; round++)
        {
            for (int i = 1; i <= bBalls; i++)
            {
                for (int j = 2 * i; j <= sSlots; j++)
                {
                    // Calculates the points of the place where the ball is.
                    points = (slots[j + round] + slots[ (j - 1) + round]) * balls[i];

                    if (j == 2 * i)
                    {
                        memory[i][j] = points;
                        if (i > 1)
                        {
                            memory[i][j] += memory[i - 1][j - 2];
                        }
 
                    }
                    else
                    {
                        memory[i][j] = memory[i][j - 1];
 
                        if (i > 1)
                        {
                            points += memory[i - 1][j - 2];
                        }
                        if (points > memory[i][j])
                        {
                            memory[i][j] = points;
                        }
 
                    }
                }
            }
            if (memory[bBalls][sSlots] > best)
            {
                best = memory[bBalls][sSlots];
            }
        }
        std::cout << best << "\n";
    }
    std::cout.flush();
    return 0;
}
