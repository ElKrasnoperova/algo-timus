#include <stdio.h>
#include <stdbool.h>
#define true  1
#define false 0

int main() {
	int n;
	bool result = true;
	int position = 0;
	int position2 = 0;
	int size = 0;
	scanf("%d", &n);
	int a[n];
	int st[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	while (result && (position < n)) {
		if ((size > 0) && (st[size -1] == a[position])) {
			size--;
			position++;
		} else if (position2 < n) {
			position2++;
			st[size] = position2;
			size++;
		}
		else result = false;
	}
	if (result == true) {
		printf("Not a proof");
	} else printf("Cheater");
return 0;
}


