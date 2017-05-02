// http://br.spoj.com/problems/SELOS11/

#include <stdio.h>

char solve(long long int value)
{
	for(long long int i=2; i*i <= value; ++i)
		if(value%i == 0) return 'S';

	return 'N';
}

int main()
{
	long long int n;
	scanf("%Ld", &n);
	
	printf("%c\n", (solve(n)));

	return 0;
}