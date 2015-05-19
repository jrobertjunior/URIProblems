#include <iostream>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n;
	std::cin >> n;

	std::string wordA, wordB;
	for (int i = 0; i < n ; i++)
	{
		std::cin >> wordA >> wordB;
		int changes = 0;
		for (size_t i = 0; i < wordA.size(); i++)
		{
			int module = wordB[i] - wordA[i];
			if (module < 0)
			{
				module = ('z' - wordA[i]) + (wordB[i] - 'a' + 1);
			}
			changes += module;
		}
		std::cout << changes << std::endl;
	}


	return 0;
}
