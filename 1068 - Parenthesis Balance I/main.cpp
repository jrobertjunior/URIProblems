#include <stdio.h>

int main()
{
	char *lines = new char[1002];
	int pile, point;
	while(fgets (lines , 10002, stdin))
	{
		pile = 0;
		point = 0;
		while(lines[point] != '\n')
		{
			if(lines[point] == '(')
			{
				pile++;
			}
			else if(lines[point] == ')')
			{
				if(pile > 0)
				{
					pile--;
				}
				else
				{
					pile = 1;
					break;
				}
			}
			point++;
		}
		if(pile != 0)
		{
			printf("incorrect\n");
		}
		else
		{
			printf("correct\n");
		}

	}
	return 0;
}
