#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

typedef struct shared_use_st 
{
    char c[20];
}ss;

void main ( int d, char * a[] )
{
	pid_t pid;
	int status;
	void * shared_memory = ( void * )0;
    ss *stuff;
    int shmid;
    char q;
    srand( ( unsigned int) getpid() );
    shmid = shmget( ( key_t)1234, sizeof( struct shared_use_st ), 0666 | IPC_CREAT );
    if ( shmid == -1 )
    {
        fprintf( stderr, "shmget failure\n" );
        exit( EXIT_FAILURE );
    } 
    shared_memory = shmat( shmid, ( void * )0, 0 );
    
    if ( shared_memory == ( void * )-1 ) 
    {
        fprintf( stderr,"shmat failed\n" );
        exit( EXIT_FAILURE );
    }

    
    stuff = ( struct shared_use_st * )shared_memory;
    printf( "Enter a character\n" );
    scanf( " %c", &q );
    stuff -> c[0] = q;

	pid = fork();
	if ( pid == -1 )
	{
		fprintf( stderr, "Fork Failed" );
		exit ( -1 );
	}
	else if ( pid == 0 )
	{
        if ( stuff -> c[0] == 'z' )
        {
            stuff -> c[0] = 'a';
            exit ( 0 );
        }
        else if (stuff -> c[0] == 'Z' )
        {
            stuff -> c[0] = 'A';
            exit ( 0 );
        }
        ( stuff -> c[0] )++; 
		exit ( 0 );
	}
	else
	{
		wait ( &status );
		puts( stuff -> c );
	}
}
