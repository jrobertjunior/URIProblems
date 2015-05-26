#include <iostream>
#include <sstream>

using namespace std;

int memory[126][251];

void findMax(int ball, int slot, int ballMax, int slotMax, int max, int *result )
{
    if (ball < ballMax)
    {
        for (int i = slot; i < slotMax + slot - 2; i++)
        {
            int slt = i % (slotMax-1);
            int mem = memory[ball][slt];
            findMax(ball+1, i+2, ballMax, slotMax, max + mem, result);

        }

    }
    if(*result < max)
    {
        *result = max;

    }

}


int main()
{
    int sSlots, bBalls;
    string line;

    while (true)
    {
        cin >> sSlots >> bBalls;
        if (!sSlots) break;

        int slots[sSlots];

        cin.ignore();
        getline(cin, line);

        cout << "lineSlots: " << line << endl;

        stringstream roulette(line);

        getline(cin, line);
        stringstream balls(line);

        cout << "lineBalls: " << line << endl;

        roulette >> slots[0] >> slots[1];
        int first = slots[0];
        for (int i = 0; i < sSlots-1; i++)
        {
            slots[i] += slots[i+1];
            roulette >> slots[i+2];

        }
        slots[sSlots-1] += first;

        for (int i = 0; i < sSlots; i++)
        {
            cout << slots[i] << " ";

        }
        cout << endl;

        for (int i = 0; i < bBalls; i++)
        {
            int ball;
            balls >> ball;
            for (int j = 0; j < sSlots; j++)
            {
                memory[i][j] =  slots[j] * ball;

            }

        }
        cout << endl;

        for (int i = 0; i < bBalls; i++)
        {
            for (int j = 0; j < sSlots; j++)
            {
                cout <<  memory[i][j] << " ";

            }
            cout << endl;

        }
        cout << endl;

        int result = 0;
        findMax(0,0,bBalls, sSlots, 0, &result);
        cout << result << endl;

    }


    return 0;

}


