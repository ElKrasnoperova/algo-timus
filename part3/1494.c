#include <stdio.h>
#include <stdbool.h>
#define true  1
#define false 0

int main() {
	int n;
	bool result = true;
	int position_input = 0;
	int position_reverse = 0;
	int size = 0;
	scanf("%d", &n);
	int input[n];
	int reverse[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &input[i]);
	}
	while (result && (position_input < n)) {
		if ((size > 0) && (reverse[size -1] == input[position_input])) {
			size--;
			position_input++;
		} else if (position_reverse < n) {
			position_reverse++;
			reverse[size] = position_reverse;
			size++;
		}
		else result = false;
	}
	if (result == true) {
		printf("Not a proof");
	} else printf("Cheater");
return 0;
}


