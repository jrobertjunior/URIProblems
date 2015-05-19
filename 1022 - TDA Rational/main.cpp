#include <stdio.h>

using namespace std;

int gdc(int a, int b)
{
	if(b == 0)
	{
		return a;
	}
	return gdc(b, a%b);
}

int main()
{

	int testes;
	scanf("%d", &testes);

	int n1, n2, d1, d2;
	char op;
	int d, n;
	for (int i = 0; i < testes; i++)
	{
		scanf("%d / %d %c %d / %d", &n1, &d1, &op, &n2, &d2);
		if(op == '+')
		{
			n = n1*d2 + n2*d1;
			d = d1*d2;
		}
		else if(op == '-')
		{
			n = n1*d2 - n2*d1;
			d = d1*d2;
		}
		else if(op == '*')
		{
			n = n1*n2;
			d = d1*d2;
		}
		else if(op == '/')
		{
			n = n1*d2;
			d = n2*d1;
		}

		int g;
		if ( n < 0)
		{
			g = gdc(-n,d);
		}
		else
		{
			g = gdc(n,d);
		}
		printf("%d/%d = %d/%d\n",n,d,n/g,d/g);
	}
	return 0;
}
