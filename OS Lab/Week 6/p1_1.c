#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int n;  //for no of processes

typedef struct proc {
    int num;
    int ar_t;
    int br_t;
    int pri;
}pr;
 
 
void sort ( pr a[n] )
{
    for ( int i = 0; i < n - 1; i++ )
    {
        for ( int j = 0; j < n - i - 1; j++ )
        {
            if ( a[j].ar_t > a[j+1].ar_t )
            {
                pr c;
                c = a[j];
                a[j] = a[j+1];
                a[j+1] = c;
            }
        }
    }
}
 
void print ( pr a[n], int tat[n], int wait[n] )
{
    for ( int i = 0; i < n; i++ )
    {
        printf( "%d TAT : %d WAIT : %d \t", a[i].num, tat[i], wait[i] );
        //printf( "\t" );
    }
}
 
void comp ( pr a[n], int comp[n] )
{
    int sum = 0;
    for ( int i = 0; i < n; i++ )
    {
        comp[i] = sum + a[i].br_t;
        sum+= a[i].br_t;
    }
}
void turn_wait ( int tat[n], int wait[n], int comp[n], pr a[n] )
{
    for ( int i = 0; i < n; i++ )
    {
        tat[i] = comp[i] - a[i].ar_t;
        wait[i] = tat[i] - a[i].br_t;
    }
}
void main ()
{
    printf( "Enter no of processes\n" );
    scanf( "%d", &n );
    pr a[n];
    int wait[20] ={ 0 };
    int tat[20] = { 0 };
    int com[20] = { 0 };
    int i;
    float av_wait, av_tat;
    printf("Enter process name, arrival time, burst time and priority");
    for ( i = 0; i < n; i++ )
    {
        printf("\nProcess %d :\t", i + 1 );
        scanf( "%d", &a[i].num );
        scanf( "%d", &a[i].ar_t );
        scanf( "%d", &a[i].br_t );
        scanf( "%d", &a[i].pri );
    }
    printf("\nThe result is : ");
    sort ( a );
    comp ( a, com );
    turn_wait ( tat, wait, com, a );
    print ( a, tat, wait );
    for ( i = 0; i < n; i++ )
    {
        av_tat = av_tat + tat[i];
        av_wait = av_wait + wait[i];
    }
    av_wait = (float)av_wait/n;
    av_tat = (float)av_tat/n;
    printf(" \nThe avg times are : \nTAT : %f \nWAIT : %f ", av_tat, av_wait );
   
}
