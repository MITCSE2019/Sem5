#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int getpos(int a[],int n,int ele,int startpos){
	for(int i=startpos;i<n;i++){
		if(a[i]==ele){
			return i;
		}
	}
	return -1;
}

int max(int a,int b){
	return a>b?a:b;
}

void optimal_cache(int a[],int n,int size){
	int q[10];
	int count=0;
	int j=0;
	memset(q,-1,sizeof(int)*size);
	for(int i=0;i<n;i++){
		if(count<size){
			int flag=0;
			for(int x=0;x<size;x++){
				if(a[i]==q[x]){
					flag=1;
					break;
				}
			}
			if(flag==0){
				q[j]=a[i];
				j=(j+1)%size;
				count++;
			}
			
		}else{
			//check if present
			int flag=0;
			for(int x=0;x<size;x++){
				if(a[i]==q[x]){
					flag=1;
					break;
				}
			}
			if(flag==0){
				int z=0;
				int ele;
				int found=0;
				for(int x=0;x<size;x++){
					int pos = getpos(a,n,q[x],i);					
					if(pos==-1){
						j=x;
						q[x]=a[i];
						found=1;
						break;
					}
					z = max(z,pos);
				}				
					if(z!=0 && !found){
						ele = a[z];
						for(int x=0;x<size;x++){
							if(q[x]==ele){
								q[x]=a[i];
								break;
							}
						}
					}else if(z==0){
						q[0]=a[i];
					}			
			}
			
		}

		for(int x=0;x<size;x++){
			printf("%d ",q[x] );
		}
		printf("\n");
	}

}


int main(){
	printf("enter the frame size\n");
	int size;
	scanf("%d",&size);
	printf("enter the reference string size \n");
	int n;
	scanf("%d",&n);
	int a[100];
	printf("enter the reference string \n");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	optimal_cache(a,n,size);
}


//Contributed by Dattatreya Nayak