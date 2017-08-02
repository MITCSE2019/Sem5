#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main()
{
	char buf[BUFSIZ];
	int n, input, output;
	input = open ("f1.txt", O_RDONLY );
	output = open ("f1copy.txt", O_WRONLY | O_CREAT, 0644 );

	while (( n = read( input, buf, BUFSIZ)) > 0)
	{
		write ( output, buf, n);
	}
	close ( input );
	close ( output );
	return 0;


	// Contributed by Ayush Garg.
}