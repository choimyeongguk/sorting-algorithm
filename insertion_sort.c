#include <stdio.h>

/* ���� ���� 
 * ����:
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
 * ���� �ϳ��� key�� ���� ��, ���� ���ҿ� ���Ͽ�
 * ���� ���Ұ� ũ�ٸ� ���� ���Ҹ� �ڷ� �а� �� ���� ���ҿ� ���Ѵ�.
 * ���� ���Һ��� key�� ũ�ٸ� �� �ڸ��� key�� �ִ´�. 
 */
void insertion_sort(int* arr, int N)
{
	int key, front, remember;  // key��, key���� ��, �ش� key�� �ִ� ������ �� 
	
	for(key=1;key<N;key++)  // �� ��° ���Һ��� �ϳ��� ���� 
	{
		remember = arr[key];  // key�� �ִ� �� ��� 
		front = key - 1;
		while(arr[front]>remember)  // ���� ���� remember������ �� ū ��� ���� 
		{
			arr[front+1] = arr[front];  // ���� ���� �� ĭ �ڷ� �б� 
			front--;  // �� ���� ĭ���� �̵� 
			if(front<0) break;  // ĭ�� �� ���ٸ� ����(remember���� ���� ����) 
		}
		arr[front+1] = remember;  // �˸��� ��ġ�� remember�� ���� 
		
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
