#pragma warning(disable:4996)
#include<cstdio>
#include <algorithm>
#include<stdlib.h>
using namespace std;
int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int i, n;
	double input, result;
	scanf("%d", &n);
	double *Max = (double *)calloc(n, sizeof(double));
	double *Min = (double *)calloc(n, sizeof(double));
	scanf("%lf", &input);
	Max[0] = Min[0] = input;
	result = input;
	for (i = 1; i < n; i++) {
		scanf("%lf", &input);
		if (input < Max[i - 1] * input) Max[i] = Max[i - 1] * input;
		else Max[i] = input;
		if (Max[i] < Min[i - 1] * input) Max[i] = Min[i - 1] * input;
 
		if (Min[i - 1] * input < input) Min[i] = Min[i - 1] * input;
		else Min[i] = input;
		if (Max[i - 1] * input < Min[i]) Min[i] = Max[i - 1] * input;
 
		if (result < Max[i]) result = Max[i];
	}
	printf("%.3lf", result);
	return 0;
}