#include <stdio.h>

#define mod 10007

int arr[1111][11];

int main() {
	int N, ans = 0;
	scanf("%d", &N);

	for (int i = 0; i <= 10; i++) arr[1][i] = 1;

	for (int j = 2; j <= 1001; j++) {
		for (int i = 9; i >= 0; i--) {
			arr[j][i] = (arr[j][i + 1] + arr[j - 1][i])%mod;
		}
	}
	for (int i = 0; i < 10; i++) {
		ans = (ans + arr[N][i])%mod;
	}
	printf("%d", ans);
	return 0;
}