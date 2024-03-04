#include <stdio.h>

/* 선택 정렬 
 * 예제:
 * 9 1 6 8 4 3 2 0
 * [9] 1 6 8 4 3 2 [0]
 * <0> [1] 6 [8] 4 3 2 <9>
 * 0 <1> [6] 4 3 [2] <8> 9
 * 0 1 <2> [4] [3] <6> 8 9
 * 0 1 2 <3> <4> 6 8 9
 *
 * 기본적인 방법은 선택정렬과 같되, 최솟값만이 아닌 최댓값도 구하여 활용한다. 
 */

void selection_sort(int* arr, int N)
{
	int min, max, temp, i, j;
	
	for(i=0;i<N/2;i++)  // 비교를 시작하는 값 
	{
		min = i;  // 최솟값의 위치 초기화 
		max = i;  // 최댓값의 위치 초기화 
		for(j=i+1;j<N-i;j++)  // 시작지점부터 마지막까지 비교 
		{
			if(arr[j]<arr[min])
			{
				min = j;
			}
			if(arr[j]>arr[max])
			{
				max = j;
			} 
		}
		// min<->start, max<->end를 단순 교환하면 제대로 정렬되지 않는 경우가 발생
		// start==max인 상황이라면, min<->start 교환 시 max의 위치가 달라짐 
		temp = arr[i];  // 시작지점과 최솟값이 있는 지점 교환 
		arr[i] = arr[min];
		arr[min] = temp;
		
		if(max==i)
		{
			max = min;
		} 
		temp = arr[N-1-i];
		arr[N-1-i] = arr[max];
		arr[max] = temp;
		
		printf("step%d: ", i+1);
		for(j=0;j<N;j++) printf("%d ", arr[j]);
		printf("\n");
	}
}

int main()
{
	int N, i;
	printf("length: ");
	scanf("%d", &N);
	int arr[N];
	printf("array: ");
	for(i=0;i<N;i++) scanf("%d", &arr[i]);
	printf("\n");
	
	selection_sort(arr, N);
	
	printf("\n");
	for(i=0;i<N;i++) printf("%d ", arr[i]);
	
	return 0;
}
