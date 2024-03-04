#include <stdio.h>

/* 선택 정렬 
 * 예제:
 * 9 1 6 8 4 3 2 0
 * 9 1 6 8 4 3 2 [0]
 * <0> 9 [1] 6 8 4 3 2
 * 0 <1> 9 6 8 4 3 [2]
 * 0 1 <2> 9 6 8 4 [3]
 * 0 1 2 <3> 9 6 8 [4]
 * 0 1 2 3 <4> 9 [6] 8
 * 0 1 2 3 4 <6> 9 [8]
 * 0 1 2 3 5 6 <8> 9
 *
 * 모든 원소를 각각 비교하여 최솟값을 구한 후, 그 값을 가장 앞으로 보낸다.
 * 그 후 최솟값을 제외한 값을을 다시 비교하여 최솟값을 구한 후, 앞으로 보낸다.
 * 이 과정을 계속 반복한다. 
 */

void selection_sort(int* arr, int N)
{
	int min, temp, i, j;
	
	for(i=0;i<N-1;i++)  // 비교를 시작하는 값 
	{
		min = i;  // 최솟값위치 초기화 
		for(j=i+1;j<N;j++)  // 시작지점부터 마지막까지 비교 
		{
			if(arr[j]<arr[min])
			{
				min = j;
			}
		}
		temp = arr[i];  // 시작지점과 최솟값이 있는 지점 교환 
		arr[i] = arr[min];
		arr[min] = temp;
		
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
