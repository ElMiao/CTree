#include<stdio.h>
#include<stdlib.h>

#define N 10

//this is an example to how to shift between array elements using a void pointer


int main(){
	

	void* miao=malloc(sizeof(int)*N);

	for(int i=0;i<N;i++){
		
		*(int*)(miao+sizeof(int)*i)=(int)i;

	}


	printf("miao[0]: \t%p\n",miao);

	printf("miao[1]: \t%p\n",miao+sizeof(int));
	printf("miao[2]: \t%p\n",miao+sizeof(int)*2);



}
