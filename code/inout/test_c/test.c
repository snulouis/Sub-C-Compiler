#include<stdio.h>


struct c{
	int a;
	int b;
} s1;

struct c foo(int a, int b){
	struct c s2;
	s2.a=a;
	s2.b=b;
	return s2;
}


int main(){

	int a;
	int b;
	int c;

	struct c s3;

	a=100;
	b=100;

	c = foo(a,b).a;
	s3=foo(a,b);
	printf("%d\n", c);
	return 0;

}
