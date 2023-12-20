#include<stdio.h>
#include<stdlib.h>
struct complex{
	int r1,r2;
	int i1,i2;
};
void add(struct complex*);
int main(){
	struct complex* copy=(struct complex*)malloc(sizeof(struct complex));
	printf("Please enter the following parts of complex number 1:\n");
	printf("Real Part: ");
	scanf("%d",&copy->r1);
	printf("Complex Part: ");
	scanf("%d",&copy->i1);
	printf("Please enter the following parts of complex number 2:\n");
	printf("Real Part: ");
	scanf("%d",&copy->r2);
	printf("Complex Part: ");
	scanf("%d",&copy->i2);
	add(copy);
	return 0;
}
void add(struct complex* co){
	int sr,si;
	sr=co->r1+co->r2;
	si=co->i1+co->i2;
	printf("The added complex number is: %d+i%d",sr,si);
}

