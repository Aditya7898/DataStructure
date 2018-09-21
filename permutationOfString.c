#include<stdio.h>
#include<string.h>

// doubt
void permutation(char*, int, int);
void swap(char*,char*);

void main(){
	char *str;
	printf("Enter a string ");
	gets(str);
	permutation(str, 0, strlen(str)-1);
}
void permutation(char *s, int i, int n){
	static int count;
	int j;
	
	if(i==n){
		count++;
		printf("(%d) %s \t",count,s);
	}
	else{
		for(j=i;j<=n;j++){
			swap((s+i),(s+j));
			permutation(s,i+1,n);
			swap((s+i),(s+j)); // Backtracking
		}
	}
}

void swap(char *a, char *b){
	char ch;
	ch = *a;
	*a = *b;
	*b = ch;
}
