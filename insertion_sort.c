#include <stdio.h>

/* 삽입 정렬 
 * 예제:
 * 31 25 12 22 11
 * 31 [25] 12 22 11
 * <25> 31 12 22 11
 * 25 31 [12] 22 11
 * <12> 25 31 22 11
 * 12 25 31 [22] 11
 * 12 <22> 25 31 11
 * 12 22 25 31 [11]
 * <11> 12 22 25 31
 *
 * 원소 하나를 key로 정한 뒤, 앞의 원소와 비교하여
 * 앞의 원소가 크다면 앞의 원소를 뒤로 밀고 그 앞의 원소와 비교한다.
 * 앞의 원소보다 key가 크다면 그 자리에 key를 넣는다. 
 */
void insertion_sort(int* arr, int N)
{
	int key, front, remember;  // key값, key앞의 값, 해당 key에 있는 원소의 값 
	
	for(key=1;key<N;key++)  // 두 번째 원소부터 하나씩 삽입 
	{
		remember = arr[key];  // key에 있는 값 기억 
		front = key - 1;
		while(arr[front]>remember)  // 앞의 값이 remember값보다 더 큰 경우 실행 
		{
			arr[front+1] = arr[front];  // 앞의 값을 한 칸 뒤로 밀기 
			front--;  // 더 앞의 칸으로 이동 
			if(front<0) break;  // 칸이 더 없다면 중지(remember값이 가장 작음) 
		}
		arr[front+1] = remember;  // 알맞은 위치에 remember값 삽입 
		
		printf("step%d: ", key);
		for(int i=0;i<N;i++) printf("%d ", arr[i]);
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
	
	insertion_sort(arr, N);
	
	printf("\n");
	for(i=0;i<N;i++) printf("%d ", arr[i]);
	
	return 0;
}
