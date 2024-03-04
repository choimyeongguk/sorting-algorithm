#include <stdio.h>

/* ���� ���� 
 * ����:
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
 * ��� ���Ҹ� ���� ���Ͽ� �ּڰ��� ���� ��, �� ���� ���� ������ ������.
 * �� �� �ּڰ��� ������ ������ �ٽ� ���Ͽ� �ּڰ��� ���� ��, ������ ������.
 * �� ������ ��� �ݺ��Ѵ�. 
 */

void selection_sort(int* arr, int N)
{
	int min, temp, i, j;
	
	for(i=0;i<N-1;i++)  // �񱳸� �����ϴ� �� 
	{
		min = i;  // �ּڰ���ġ �ʱ�ȭ 
		for(j=i+1;j<N;j++)  // ������������ ���������� �� 
		{
			if(arr[j]<arr[min])
			{
				min = j;
			}
		}
		temp = arr[i];  // ���������� �ּڰ��� �ִ� ���� ��ȯ 
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
