#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

// overkill but it is nicer :)
struct circle
{
	int r;
	int x;
	int y;


	bool isInside(const circle &outCircle)
	{
		// center distance
		float dist = sqrt((x-outCircle.x) * (x-outCircle.x) + (y-outCircle.y) * (y-outCircle.y));
		if(dist + r <= outCircle.r)
		{
			return true;
		}
		return false;
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::string testCase;
	circle cHunter, cFlower;
	while(getline(std::cin, testCase))
	{
		std::stringstream st(testCase);
		st >> cHunter.r >> cHunter.x >> cHunter.y
		   >> cFlower.r >> cFlower.x >> cFlower.y;

		if(cFlower.isInside(cHunter))
		{
			std::cout << "RICO" << std::endl;
		}
		else
		{
			std::cout << "MORTO" << std::endl;
		}

	}

	return 0;
}
