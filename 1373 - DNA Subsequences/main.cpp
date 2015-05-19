/**
 *
 * @autor José Junior
 * URI Online Judge 1373 - DNA Subsequences
 *
 * Algorithm : Modified Longest Common Subsequences to use the k factor
 *
 * URI Runtime: 0.340s
 */

#include <iostream>
#include <string>

// Uncomment to use the debug mode;
// #define DEBUG_MODE_ON

#ifdef DEBUG_MODE_ON
/**
 * Prints the matrix to easily understand the algorithm
 */
inline void printMatrix(size_t w1Size, size_t w2Size, int matrix[1001][1001])
{
	std::cout << " | ";
	for (size_t b = 0; b <= w2Size; b++)
	{
		std::cout << b << " ";
	}
	std::cout << std::endl;
	std::cout << "-|-";
	for (size_t b = 0; b <= w2Size; b++)
	{
		std::cout << "--";
	}
	std::cout << std::endl;
	for (size_t a = 0; a <= w1Size; a++)
	{
		std::cout << a << "| ";
		for (size_t b = 0; b <= w2Size; b++)
		{
			std::cout << matrix[a][b] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


#define DEBUG_PRINT_MATRIX(name, a, b, c) {std::cout << name << ":" << std::endl; printMatrix(a,b,c);}
#else
#define DEBUG_PRINT_MATRIX(name, a, b, c)
#endif


int dp1[1001][1001]; // Dynamic Program Matrix to hold the subsequence count
int dp2[1001][1001]; // Dynamic Program Matrix to hold the result considering the k value

int maxSubsequence(std::string word1, std::string word2, short K)
{
	size_t w1Size = word1.size();
	size_t w2Size = word2.size();

	for (size_t a = 1; a <= w1Size; a++)
	{
		for (size_t b = 1; b <= w2Size; b++)
		{
			if (word1[a-1] == word2[b-1])
			{
				dp1[a][b] = 1 + dp1[a-1][b-1];
			}
			else
			{
				dp1[a][b] = 0;
			}

			DEBUG_PRINT_MATRIX("dp1", w1Size, w2Size, dp1);

			dp2[a][b] = std::max(dp2[a-1][b], dp2[a][b-1]);

			for (int k = K; k <= dp1[a][b]; k++)
			{
				dp2[a][b] = std::max(dp2[a][b], dp2[a-k][b-k] + k);
			}

			DEBUG_PRINT_MATRIX("dp2", w1Size, w2Size, dp2);
		}
	}

    return dp2[w1Size][w2Size];
}


int main()
{

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	// Only need to set one time, as it'll never change;
	// The rest of the matrix will always be filled (inside the length of the string)
	for (size_t a = 0; a <= 1000; a++)
	{
		dp1[a][0] = dp1[0][a] = 0;
		dp2[a][0] = dp2[0][a] = 0;
	}

    short k;
    std::cin >> k;

    std::string w1;
    std::string w2;

    while (k != 0)
    {
    	std::cin >> w1 >> w2;
    	std::cout << maxSubsequence(w1,w2,k) << std::endl;
    	std::cin >> k;
    }

    return 0;
}


