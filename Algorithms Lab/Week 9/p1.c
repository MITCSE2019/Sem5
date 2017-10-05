#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shifttable(char p[],int table[],int size){

	int m=strlen(p);
	for(int i=m-2;i>=0;i--){
		char c=p[i];
		int sh=m-i-1;
		int pos;
		/*if(c>='A'&&c<='Z')
			pos = (int)c - 65;//only for capital letters
		else if(c>='a'&&c<='z')
			pos = (int)c - 90;//only for capital letters*/
		pos = (int)c - 65;//only for capital letters
		//printf("pos = %d , shift = %d\n",pos,sh );
		if(table[pos]>sh)
			table[pos]=sh;
	}
}


int is_present(char p[],char c,int len){
	
	for(int i=0;i<len;i++){
		if(p[i]==c)
			return 1;
	}
	return 0;
}

int main(){
	char t[100],p[30];
	printf("Enter text\n");
	gets(t);
	printf("Enter pattern\n");
	gets(p);
	int m=strlen(p);
	int table[26];
	for(int i=0;i<26;i++)
		table[i]=m;
	shifttable(p,table,26);
	printf("\n");
	/*for(int i=0;i<26;i++){
		printf("%d ",table[i] );
	}*///SHIFT TABLE



	int i=m-1;
	
	int n = strlen(t);
	int flag=0;

	while(i<=n-1){
		int k=0;
		while(k<m && p[m-1-k]==t[i-k])
			k++;
		if(k==m){
			flag = 1;
			printf("found at %d \n",i+2-m );
		}

		if(t[i-k]==' '){
			i+=m;
		}
		else{
			int s=(int)t[i]-65;
			i+=table[s];
		}
	}
	if ( flag == 0 )
	{
		printf( " No match found\n" );
	}

}