#include <stdio.h>
#include <stdlib.h>
 
#define min(x,y) ((x) <= (y)) ? (x) : (y)
 
int main(int argc, char const *argv[])
{
    int x,y,i;
    scanf("%d%d",&x,&y);
    int m = min(x,y);
    int gcd = 1;
    int op=0;
    if(!x)
    	{
    		gcd=y;
    		goto end;
    	}
    if(!y)
    	{
    		gcd=x;
    		goto end;
    	}
    for(i=2;i<=m;)
    {	
    	m=min(x,y);
        if(x%i==0 && y%i==0)
        {
            op++;
            gcd = gcd * i;
            x=x/i;
            y=y/i;
        }
        else
        {
            if(i==2)
                i=3;
            else if(i>=3)
                i=i+2;
        }
    }
end:printf("%d\n",gcd );
    printf("%d\n",op);
    return 0;
}