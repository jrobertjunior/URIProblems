#include <stdio.h>
#include <sstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


bool greater(int a, int b, short mod)
{
    int mod_a = a % mod;
    int mod_b = b % mod;
    if (mod_a != mod_b)
    {
        if (mod_a > mod_b)
        {
            return true;
        }
        return false;
    }
    else
    {
        bool even_a = a%2 == 0;
        bool even_b = b%2 == 0;
        if (!even_a && even_b )
        {
            return false;
        }
        else if (even_a && !even_b)
        {
            return true;
        }
        else if (even_a && even_b)
        {
            return a > b;
        }
        else
        {
            return a < b;
        }
    }

}

inline void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}


int partition(int words[], short init, short end, short m)
{
    //short pointer = init/2 + end/2;
    short pointer = init + (rand() % (int)(end - init + 1));

    const int pivotValue = words[pointer];

    // the idea is to put the pivot as the last member of the array
    swap(&words[pointer],&words[end]);

    pointer = init;
    for(int i = init; i < end; i++)
    {
        if(greater(words[i],pivotValue, m))
        {
            swap(&words[i], &words[pointer++]);
        }
    }

    swap(&words[pointer], &words[end]);
    return pointer;
}

void quickSort(int *words[], short ini, short end, short m)
{
    if(ini < end)
    {
        int p = partition(*words, ini, end, m);
        quickSort(words, ini, p-1, m);
        quickSort(words, p+1, end, m);
    }

}


int main()
{
    short numbers;
    short m;

    srand (time(NULL));

    scanf("%hd %hd", &numbers, &m);
    std::stringstream ss;

    while(numbers != 0)
    {
        int *list = new int[numbers];
        ss << numbers << " " << m << std::endl;

        for (int i = 0; i < numbers; i++)
        {
            scanf("%d", &list[i]);
        }

        quickSort(&list,0,numbers-1, m);

        for (int i = numbers-1; i >= 0 ; i--)
        {
            ss << list[i] << std::endl;
        }

        scanf("%hd %hd", &numbers, &m);
    }
    ss << "0 0" << std::endl;
    printf("%s", ss.str().c_str());
    return 0;
}
