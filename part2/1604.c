#include <stdio.h>

typedef struct {
	int value;
	int amount;
} sign;

int find_imax(sign* signs, int n) {
	int max = 0;
	int i_max = -1;
	for (int i = 0; i < n; i++) {
		if (signs[i].amount >= max) {
			max = signs[i].amount;
			i_max = i;
		}
	}
	return i_max;
}

int find_imin(sign* signs, int n) {
	int min = 10001;
	int i_min = -1;
	for (int i = 0; i < n; i++) {
		if (signs[i].amount > 0 && signs[i].amount < min) {
			i_min = i;
			min = signs[i].amount;
		}
	}
	return i_min;
	
}

int main() {
	int n, i_max, i_min;
	int signs_amount = 0;
	scanf("%d", &n);
	sign signs[n];
	for (int i = 0; i < n; i++) {	
		signs[i].value = i + 1;
		scanf("%d", &signs[i].amount);
		signs_amount += signs[i].amount;
	}

	while (signs_amount > 0) {
		i_max = find_imax(signs, n);
		i_min = find_imin(signs, n);
		if (i_max != i_min) {
			printf("%d %d ", signs[i_max].value, signs[i_min].value);
			signs[i_max].amount--;
			signs[i_min].amount--;
			signs_amount = signs_amount - 2;
		}
		else {
			printf("%d ", signs[i_min].value);
			signs_amount --;
		}
	}
	printf("\n");
	
}
