#include <iostream>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n;
	std::cin >> n;

	std::string word;
	int result;
	for (int i = 0; i < n ; i++)
	{
		std::cin >> word;
		if(word.size() == 5)
		{
			result = 3;
		}
		else
		{
			int one = 0;
			int two = 0;
			if (word[0] == 'o'){ one++;}
			if (word[1] == 'n'){ one++;}
			if (word[2] == 'e'){ one++;}

			if (word[0] == 't'){ two++;}
			if (word[1] == 'w'){ two++;}
			if (word[2] == 'o'){ two++;}

			if(one > two)
			{
				result = 1;
			}
			else
			{
				result = 2;
			}
		}
				std::cout << result << std::endl;
	}


	return 0;
}
