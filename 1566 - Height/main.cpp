#include <iostream>
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <cstring>
#include <map>



int main()
{
	int sortVector[231];
	std::memset(sortVector, 0, sizeof sortVector);

	int cases;
	scanf("%d",&cases);

	int persons;
	char *line = new char[12000001];
	std::stringstream output;
	while(cases--)
	{
		scanf("%d\n", &persons);
		persons = persons*4 + 1;

		std::cin.getline (line, persons);
		std::stringstream stream(line);

		bool first = true;
		int n;
		while(stream >> n)
		{
			sortVector[n]++;
		}
//		for(int i = 20; i <= 230; i++)
//		{
//			while(sortVector[i] > 0)
//			{
//				if(first)
//				{
//					output << i ;
//					sortVector[i]--;
//					first = false;
//				}
//				else
//				{
//					output << " " << i ;
//					sortVector[i]--;
//				}
//			}
//		}
		output << std::endl;
	}

	printf("%s \n", output.str().c_str());

	return 0;
}


//using namespace std;
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	short cases; // 100 cases at most
//	cin >> cases; cin.ignore();
//
//	//int sortVector[231];
//
//	int persons;
//
//	string line;
//	stringstream output;
//
//	// zero all positions
//	//std::memset(sortVector, 0, sizeof sortVector);
//
//	while(cases--)
//	{
//		cin >> persons; cin.ignore();
//		std::getline (std::cin,line);
//
//		map<int, int> sortVector;
//
//		stringstream stream(line);
//		bool first = true;
//		int n;
//		while(stream >> n)
//		{
//			//sortVector[n]++;
//			if(sortVector.find(n) == sortVector.end())
//			{
//				sortVector[n] = 1;
//			}
//			else
//			{
//				sortVector[n]++;
//			}
//		}
//
//		for(map<int, int>::iterator it = sortVector.begin(); it != sortVector.end(); ++it)
//		{
//			for(int i = 0; i < it->second; i++)
//			{
//				if(first)
//				{
//					output << it->first ;
//					first = false;
//				}
//				else
//				{
//					output << " " << it->first ;
//				}
//			}
//		}
//
////		for(int i = 20; i <= 230; i++)
////		{
////			while(sortVector[i] > 0)
////			{
////				if(first)
////				{
////					output << i ;
////					sortVector[i]--;
////					first = false;
////				}
////				else
////				{
////					output << " " << i ;
////					sortVector[i]--;
////				}
////			}
////		}
//		output << endl;
//	}
//
//	cout << output.str();
//
//	return 0;
//}
