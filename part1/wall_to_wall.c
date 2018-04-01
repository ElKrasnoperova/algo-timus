#include <stdio.h>

int main() {
	int n;
	int i = 0;
	int m = 2;
	scanf("%d", &n);
	int matrix[n][m];
	long double games = 0;

	
	for (i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &matrix[i][j]);	
		}	
	}

	for (i = 0; i < n; i++) {
		int fighters = matrix[i][0];
		double teams_count = matrix[i][1];
		int teams[(int)teams_count];
		for (int i = 0; i < (int)teams_count; i++) {
			teams[i] = 0;
		}
		while (fighters!=0) {
			if (fighters - teams_count > 0) {
				for (int k = 0; k < teams_count; k++) {
					teams[k] += 1;
					fighters--;
				}
			} else {
				for (int k = fighters-1; k>-1; k--) {
				teams[k] += 1;
				fighters--;
				}
			}
		}
		for (int k = 0; k < teams_count-1; k++) {
			for (int t = k+1; t < teams_count; t++) {
				games+= teams[k] * teams[t];
			}
		}
		printf("%d\n", (int)games);
		games = 0;
	}
	return 0;
}
