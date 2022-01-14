#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int info[20][2];
int sum[1001];

int advertisement(int customer, int cityNum) 
{
	int min = 100 * 1000;
	int cost;

	if (customer <= 0)
		return 0;
        
	else if (sum[customer] > 0)
		return sum[customer];
        
	else 
	{
		for (int i = 0; i < cityNum; i++)
		{
			cost = advertisement(customer - info[i][1], cityNum) + info[i][0];
			min = cost < min ? cost : min;
		}
		sum[customer] = min;

		return min;
	}
}

int main()
{
	int c, n;

	scanf("%d%d", &c, &n);
    
	for (int i = 0; i < n; i++)
		scanf("%d%d", &info[i][0], &info[i][1]);

	printf("%d", advertisement(c, n));
}