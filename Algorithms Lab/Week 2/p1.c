#include <stdio.h>
#include <stdlib.h>

void main()
{
	int m,n,t,res,opc = 0;
	printf("\nEnter two numbers\n");
	scanf("%d %d", &m,&n);
	if( m > n )
		t = m;
	else
		t = n;
	while( t != 0 )
	{
		opc++;
		if( m%t == 0 )
		{
			if( n%t == 0 )
			{
				res = t;
				break;
			}
		}
		t--;
	}
	if( m == 0 )
		res = n;
	if( n == 0 )
		res = m;
	printf("The gcd of the numbers is : %d\n",res );
	printf("The operation count is : %d\n", opc);
}