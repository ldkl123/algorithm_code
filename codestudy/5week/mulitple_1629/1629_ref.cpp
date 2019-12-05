#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long go(long long a, long long b, long long c) {
	if (b == 1) return a%c;

	if (b % 2 == 0)	
		return (go(a, b / 2, c)%c * go(a, b / 2, c)) % c;
	else 
		return ((go(a, (b - 1) / 2, c)%c * go(a, (b - 1) / 2, c))%c * a) % c;
}

int main() {
	

		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);

		printf("%lld\n", go(a%c, b, c));
	
	return 0;
}