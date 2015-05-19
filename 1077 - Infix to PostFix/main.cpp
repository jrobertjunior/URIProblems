#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

inline short priority(char a)
{
	if(a == '^') return 3;
	if(a == '*' || a == '/') return 2;
	if(a == '+' || a == '-') return 1;
	return 0;
}


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int rounds;
	cin >> rounds;
	cin.ignore();

	string infix;
	for (int i = 0; i < rounds; i++)
	{
		stringstream postfix;
		vector<char> stack;

		getline(cin,infix);

		for(size_t i = 0; i < infix.size(); i++)
		{
			char c = infix[i];
			if(c == ' ') continue; // não fala nada sobre espaço, mas nunca se sabe !!!
			if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
			{
				if(stack.size() == 0)
				{
					stack.push_back(c);
				}
				else
				{
					while(priority(c) <= priority(stack.back()))
					{
						postfix << stack.back();
						stack.pop_back();
					}
					stack.push_back(c);
				}
			}
			else if (c == '(')
			{
				stack.push_back(c);
			}
			else if (c == ')')
			{
				while(stack.back() != '(')
				{
					postfix << stack.back();
					stack.pop_back();
				}
				stack.pop_back();
			}
			else
			{
				postfix << c;
			}
		}

		while(stack.size() > 0)
		{
			if( stack.back() != '(')
			{
				postfix << stack.back();
			}
			stack.pop_back();
		}
		cout << postfix.str() << endl;
	}

	return 0;

}
