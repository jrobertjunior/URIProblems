#include <iostream>
#include <string>

int main()
{
	std::string number;
	while(getline(std::cin, number))
	{
		char top = 0;
		for(int pointer = 0; pointer < number.size(); pointer++)
		{
			if(number[pointer] > top)
			{
				top = number[pointer];
			}
		}
		short base;
		if(top <= '9' )
		{
			base = (top - '0');
		}
		else if (top <= 'Z')
		{
			base = (top - 'A') + 10;
		}
		else if (top <= 'z')
		{
			base = (top - 'z') + 10 + 26;
		}
		std::cout << base +1 << std::endl;
	}

	return 0;
}
