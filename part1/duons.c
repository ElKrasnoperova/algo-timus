#include <stdio.h>
#include <stdlib.h>

#define CONNECTIONS 3
#define CORNERS 8
#define MAX_ACTIONS 1000
#define CHARS 3

const int neighboors[CORNERS][3] = { { 1,3,4 },
{ 0,2,5 },
{ 1,3,6 },
{ 0,2,7 },
{ 0,5,7 },
{ 1,4,6 },
{ 2,5,7 },
{ 3,4,6 } };

const int diag[CORNERS] = {6,7,4,5,2,3,0,1};

int find_imax(int* numbers) {
	int max = 0;
	int max_i = -1;
	for (int i = 0; i < CORNERS; i++) {
		if (numbers[i] > max) {
			max = numbers[i];
			max_i = i;
		}
	}
	return max_i;
}

int is_duons_exist(int* numbers){
	for (int i = 0; i < CORNERS; i++){
		if (numbers[i] != 0) { return 1; }
	}
	return 0;
}

int is_duon_has_neighboor(int* numbers, int duon_number) {
	for (int i = 0; i < CONNECTIONS; i++) {
		if (numbers[neighboors[duon_number][i]] != 0) { return 1; }
	}
	return 0;
}

int is_duon_has_diag_neighboor(int* numbers, int duon_number){
	if (numbers[diag[duon_number]] != 0) { return 1; }
	return 0;
}

void format_result(char* result,int* result_length, char char1, char char2, char sign){
	result[*result_length] = char1;
	result[*result_length +1] = char2;
	result[*result_length +2] = sign;
	*result_length += CHARS;	
}

int is_possible (int* numbers) {
	int sum = 0;
	for (int i = 0; i < CORNERS; i++) {
		sum += numbers[i];
	}
	if (sum % 2 != 0) {
		return 0;
	}
return 1;
}

int main(){
	char* result = (char*)malloc(MAX_ACTIONS * CHARS * sizeof(char));
	int result_length = 0;
	char minus = '-';
	char plus = '+';

	char letters[CORNERS] = { 'A','B','C','D','E','F','G','H' };
		
	int numbers[CORNERS];
	for (int i = 0; i < CORNERS; i++) {
		scanf("%d", &numbers[i]);
	}
	if (!is_possible) {
		printf("IMPOSSIBLE");
		return 0;
	}

	while (is_duons_exist(numbers)) {
		int max_i = find_imax(numbers);

		if(is_duon_has_neighboor(numbers,max_i)){
			for (int i = 0; i < CONNECTIONS; i++) {
				while ((numbers[neighboors[max_i][i]] > 0) && (numbers[max_i] > 0)) {
					numbers[max_i] --;
					numbers[neighboors[max_i][i]] --;
					format_result(result, &result_length, letters[max_i], letters[neighboors[max_i][i]], minus);
				}
			}
		}else if(is_duon_has_diag_neighboor(numbers, max_i)){
			while ((numbers[diag[max_i]] > 0) && (numbers[max_i] > 0)) {
				format_result(result, &result_length, letters[neighboors[max_i][0]], letters[neighboors[diag[max_i]][0]], plus);
				numbers[max_i] --;
				numbers[diag[max_i]] --;
				format_result(result, &result_length, letters[max_i], letters[neighboors[max_i][0]], minus);
				format_result(result, &result_length, letters[diag[max_i]], letters[neighboors[diag[max_i]][0]], minus);
			}			
		}else{
			printf("IMPOSSIBLE");
			return 0;
		}
	}
	int x = result_length / CHARS;
	for (int i = 0; i < result_length; i+= CHARS) {
		printf("%c", result[i]);
		printf("%c", result[i+1]);
		printf("%c", result[i+2]);
		printf("\n");
	}
    return 0;
}
