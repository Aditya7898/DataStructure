#include<stdio.h>
#include<string.h>
void bin(int, char[]);

int main(){
  char a[4];
  a[3]='\0';
  bin(3,a);
  
  return 0;	
}

void bin(int n, char a[]){
	if(n<1){
		printf("\n%s",a);
	}else{
		a[n-1]='0';
		bin(n-1,a);
		a[n-1]='1';
		bin(n-1,a);
	}
}
