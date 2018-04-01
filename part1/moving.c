#include <stdio.h>
#define MAX(x, y) x > y ? x: y

int main()
{
	int n;
	scanf("%d", &n);
	int numbers[n];
	for(int i=0;i<n;++i)
		scanf("%d", &numbers[i]);
	int sum=0;
	int ans=0;
	for(int i=0;i<n;++i)
	{
		sum=MAX(0,sum+numbers[i]);
		ans=MAX(sum,ans);
	}
	printf("%d", ans);
	return 0;
}

/*
#define MAX(x, y) x > y ? x: y

int main(int argc, char *argv[]) {
  int count;
  int sum = 0;
  int sum1 = 0;
  scanf("%d", &count);
  int numbers[count];
  for (int i = 0; i < count; i++) {
    scanf("%i", &numbers[i]);
  }
  for (int i = 0; i < count; i++) {
    sum = sum + numbers[i];
    printf ("\n sum for numbers[i-1] and %d is %d", numbers[i], sum);
    if (numbers[i]<0){
	if (MAX(sum,sum1)<=0) {
	  printf ("\nmax of %d and %d is %d", sum, sum1, MAX(sum, sum1));
	  sum1 = MAX(sum, sum1);
	  printf("\nsum1 is %d", sum1);
          sum = 0;
	  printf("\nsum is ZERO");
	} else {
	  sum1 = sum;
	  printf("\nsum1 for else is %d", sum);
	}
    printf("\nsum1 внешний is %d", MAX(sum, sum1));
    } 
  }
  printf("\n%d%", sum1);
  return 0;
}
*/
