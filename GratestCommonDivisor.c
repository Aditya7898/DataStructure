#include<stdio.h>
int GCD (int, int);

void main(){
	 int a,b,result;
	 scanf("%d%d",&a,&b);
	 result = GCD(a,b);
	 printf("%d", result);
}

int GCD(int a, int b){
	if(a==b){
		return a;
	}
	if(a%b==0){
		return b;
	}
	if(b%a==0){
		return a;
	}
	if(a>b){
		return GCD(a%b,b);
	}else{
		return GCD(a, b%a);
	}
}


