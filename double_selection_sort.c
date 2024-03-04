#include <stdio.h>

/* ���� ���� 
 * ����:
 * 9 1 6 8 4 3 2 0
 * [9] 1 6 8 4 3 2 [0]
 * <0> [1] 6 [8] 4 3 2 <9>
 * 0 <1> [6] 4 3 [2] <8> 9
 * 0 1 <2> [4] [3] <6> 8 9
 * 0 1 2 <3> <4> 6 8 9
 *
 * �⺻���� ����� �������İ� ����, �ּڰ����� �ƴ� �ִ񰪵� ���Ͽ� Ȱ���Ѵ�. 
 */

void selection_sort(int* arr, int N)
{
	int min, max, temp, i, j;
	
	for(i=0;i<N/2;i++)  // �񱳸� �����ϴ� �� 
	{
		min = i;  // �ּڰ��� ��ġ �ʱ�ȭ 
		max = i;  // �ִ��� ��ġ �ʱ�ȭ 
		for(j=i+1;j<N-i;j++)  // ������������ ���������� �� 
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
		// min<->start, max<->end�� �ܼ� ��ȯ�ϸ� ����� ���ĵ��� �ʴ� ��찡 �߻�
		// start==max�� ��Ȳ�̶��, min<->start ��ȯ �� max�� ��ġ�� �޶��� 
		temp = arr[i];  // ���������� �ּڰ��� �ִ� ���� ��ȯ 
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
