#include <iostream>

using namespace std;

inline int getCards(const int cards[], int right)
{
	int result = 0;
	int andrew = 1;
	int left = 0;
	int card = 0;
	while(right-left > 0)
	{
		if (cards[left] > cards[right])
		{
			if (cards[left] > cards[left+1])
			{
				card = cards[left];
				left++;
			}
			else if(cards[right] > cards[right - 1])
			{
				card = cards[right];
				right--;
			}
		}
		else if (cards[right] > cards[left] && cards[right] > cards[right - 1])
		{
			if (cards[right] > cards[right - 1])
			{
				card = cards[right];
				right--;
			}
			else if(cards[left] > cards[left+1])
			{
				card = cards[left];
				left++;
			}
		}

		if(andrew == 1)
		{
			result += card;
		}
		andrew *= -1;
	}
	return result;
}
int main()
{
	int N;
	while(cin >> N)
	{
		int cards[N];
		for(int i = 0; i < N; i++)
		{
			cin >> cards[i];
		}
		cout << getCards(cards, N-1) << endl;
	}
	return 0;
}
