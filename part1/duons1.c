#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) a>b?a:b
#define CONNECTIONS 3
#define CORNERS 8
#define MAX_ACTIONS 1000

const char letters[CORNERS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
const int neighboors[CORNERS][CONNECTIONS] = {
			1,4,3,
			0,2,5,
			1,5,6,
			0,2,7,
			0,5,7,
			1,4,6,
			2,5,7,
			3,4,6
			};
const int diag[CORNERS] = {6,7,4,5,2,3,0,1};

int find_imax(int* numbers) {
int max = 0;
int imax = -1;
	for (int i = 0; i < CORNERS; i++) {
		if (numbers[i]>max) {
			max = numbers[i];
			imax = i;
		}
	}
return imax;
}

int duons_exist(int* numbers) {
	for (int i = 0; i < CORNERS; i++) {
		if (numbers[i] != 0) {
			return 1;
		}
	}
	return 0;
}

int is_duon_has_neighboor(int* numbers, int duon_id) {
	for (int i = 0; i < CONNECTIONS; i++){
		if (numbers[neighboors[duon_id][i]] != 0) {
			return 1;
		}
	}
	return 0;
}

int is_has_diag(int* numbers, int duon_id) {
	if (numbers[diag[duon_id]]!=0){return 1;}
	return 0;
}
void format_result (char* result, int* result_size, char first_duon, char second_duon, char sign) {
	result[*result_size] = first_duon;
	result[*result_size+1] = second_duon;
	result[*result_size+2] = sign;
	*result_size += 3;
}

int check_if_possible(int* numbers) {
	int sum = 0;
	for (int i = 0; i < CORNERS; i++) {
		sum+=numbers[i];
	}
	if (sum % 2 != 0) {
		return 0;
	}
return 1;
}


int main() {
	int result_size = 0;
	int imax =-1;
	int numbers[CORNERS];	
	char minus = '-';
	char plus = '+';
	char* result = (char*)malloc(MAX_ACTIONS*3*sizeof(char));
	for (int i = 0; i<CORNERS; i++) {
		scanf("%d", &numbers[i]);
	}

	if (!check_if_possible) {printf("IMPOSSIBLE");
				return 0;}

	while (duons_exist(numbers)) {
		imax = find_imax(numbers);

		if (is_duon_has_neighboor(numbers, imax)) {
			for (int i = 0; i < CONNECTIONS; i++) {
				while ((numbers[neighboors[imax][i]] > 0) && (numbers[imax] > 0)) {			
					numbers[imax]--;
					numbers[neighboors[imax][i]]--;
					format_result(result, &result_size, letters[imax],letters[neighboors[imax][i]], minus);
				}			
			}
		}else if (is_has_diag(numbers, imax)) {
			while ((numbers[diag[imax]]>0) && (numbers[imax]>0)) {
				format_result(result, &result_size, letters[neighboors[imax][0]], letters[neighboors[diag[imax]][0]], plus);
				numbers[imax]--;
				numbers[diag[imax]]--;
				format_result(result, &result_size, letters[imax], letters[neighboors[imax][0]], minus);
				format_result(result, &result_size, letters[diag[imax]], letters[neighboors[diag[imax]][0]], minus);
			}
		} else {
			printf("IMPOSSIBLE");
			return 0;
		}
	}
	int x = result_size / 3;
	for (int i = 0; i < result_size; i+= 3) {
		printf("%c", result[i]);
		printf("%c", result[i+1]);
		printf("%c", result[i+2]);
		printf("\n");
	}
return 0;
}
