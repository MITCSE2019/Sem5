#include <stdio.h>
#include <stdlib.h>

void main()
{
	int addr, p, offs, i, byte;
	printf("\nEnter byte size " );
	scanf("%d", &byte);
	printf("\nEnter address " );
	scanf("%d", &addr );
	p = addr / byte;
	offs = addr % byte;
	printf( "Page Number : %d Offset : %d ",p,offs );
}