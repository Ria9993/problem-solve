#pragma warning(disable:4996)
#include <stdio.h>
#define object_len 6
#define objects_ptr(x,y) *(objects+x*(object_len+1)+(y)) //same objects[x][y]

void swap(int *object, int x, int y);
void H_rotation(int* object);
void V_rotation(int* object);
int sum_dice(int *objects, int n, int line);
int main() {
	int dice[10010][object_len + 1];
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)for (int j = 1; j <= 6; j++)scanf("%d", &dice[i][j]);
	printf("%d", sum_dice(*dice, n, 1));
	return 0;
}

int sum_dice(int *objects,int n,int line) {
	int sum = 0;
	for (int i = 1; i <= n; i++)sum+=objects_ptr(i, line + 1);
	return sum;
}
void swap(int *object, int x, int y) {
	int tmp = *(object + x);
	*(object + x) = *(object + y);
	*(object + y) = tmp;
}
void H_rotation(int* object) {
	int tmp = object[2];
	for (int i = 2; i <= 4; i++)object[i] = object[i + 1];
	object[5] = tmp;
}
void V_rotation(int* object) {
	swap(object, 1, 6);
	swap(object, 2, 4);
	swap(object, 3, 5);
}