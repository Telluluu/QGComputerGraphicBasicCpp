#include<vector>
#include<algorithm>
#include<math.h>
#include <iostream>
#include"Sort.h"

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void InsertSort(int* a, int n)
{
	if (a == nullptr || n <= 0)
		return;

	for (int i = 1; i < n; i++)
	{
		int temp = a[i];
		for (int j = i; j >= 1; j--)
		{
			if (a[j] < a[j - 1])
			{
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
	}
}

/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int* a, int begin, int mid, int end, int* temp)
{
	using namespace std;
	//begin为第1有序区的第1个元素，i指向第1个元素, mid为第1有序区的最后1个元素
	int i = begin, j = mid + 1, k = 0; //mid+1为第2有序区第1个元素，j指向第1个元素

	while (i <= mid && j <= end) {
		if (a[i] <= a[j]) //较小的先存入temp中
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while (i <= mid)//若比较完之后，第一个有序区仍有剩余，则直接复制到t数组中
		temp[k++] = a[i++];
	while (j <= end)//同上
		temp[k++] = a[j++];
	for (i = begin, k = 0; i <= end; i++, k++)//将排好序的存回arr中low到high这区间
		a[i] = temp[k];
}
/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int* a, int begin, int end, int* temp)
{
	if (begin < end)
	{
		int mid = (begin + end) / 2;
		MergeSort(a, begin, mid, temp);
		MergeSort(a, mid + 1, end, temp);
		MergeArray(a, begin, mid, end, temp);
	}
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int* a, int begin, int end)
{
	int mid;
	if (begin >= 0 && end > 0)
	{
		if (begin < end)
		{
			mid = Partition(a, begin, end);  // 返回基准元素位置
			QuickSort_Recursion(a, begin, mid - 1); // 左区间递归快速排序
			QuickSort_Recursion(a, mid + 1, end); // 右区间递归快速排序
		}
	}	
}

/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
//void QuickSort(int* a, int size);

/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int* a, int begin, int end)
{
	using namespace std;

	int i = begin, j = end;
	int pivot = a[begin]; //基准元素

	while (i < j) //i = begin, j = end
	{
		while (i<j && a[j]>pivot) //从右向左开始找一个 小于等于 pivot的数值
		{
			j--;
		}
		if (i < j)
		{
			swap(a[i++], a[j]);  //a[i]和a[j]交换后 i 向右移动一位
		}
		while (i < j && a[i] <= pivot) //从左向右开始找一个 大于 pivot的数值
		{
			i++;
		}
		if (i < j)
		{
			swap(a[i], a[j--]);  //a[i]和a[j]交换后 i 向左移动一位
		}
	}
	return i;  //返回最终划分完成后基准元素所在的位置
}

/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int* a, int size, int max)
{
	using namespace std;

	int* b = new int[size];
	for (int i = 0; i < size; i++)
		b[i] = a[i];

	int min=a[0];
	for (int i = 0; i < size; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
	}

	int l = max - min;
	int* temp = new int[l + 1];
	for (int i = 0; i < l + 1; i++)
		temp[i] = 0;

	for (int i = 0; i < size; i++)
	{
		temp[b[i]-min]++;//统计元素个数
	}

	for (int i = 1; i < l+1; i++)//统计数组做变形，后面的元素等于前面元素的和
	{
		temp[i] += temp[i-1];
	}

	for (int i = size - 1; i >= 0; i--)//倒序遍历原始数组，从统计数组中找到正确位置
	{
		a[temp[b[i]-min]-1] = b[i];
		temp[b[i]-min]--;
	}
	delete []b;
	delete []temp;
}

/**
 *  @name        : int maxbit(int* a, int size)
 *  @description : 查找数据最大位数
 *  @param       : 数组指针a，数组长度size
 */
int maxbit(int* a, int size)
{
	if (a == nullptr)
		return 0;
	int maxData = a[0];
	for (int i = 0; i < size; i++)
	{
		if (maxData < a[i])
			maxData = a[i];
	}
	int bit = 1;
	int j = 10;
	while (maxData >= j)
	{
		maxData /= 10;
		bit++;
	}
	return bit;
}

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int* a, int size)
{
	if (a == nullptr)
		return;

	int bit = maxbit(a, size);
	int* temp = new int[size];
	int* count = new int[10];
	int k = 1;
	int radix = 1;
	for (int i = 1; i <= bit; i++)
	{
		for (int j = 0; j < 10; j++)
			count[j] = 0;

		for (int j = 0; j < size; j++)
		{
			k = (a[j] / radix) % 10;
			count[k]++;
		}

		for (int j = 1; j < 10; j++)
			count[j] += count[j - 1];

		for (int j = size - 1; j >= 0; j--)
		{
			k = (a[j] / radix) % 10;
			temp[count[k] - 1] = a[j];
			count[k]--;
		}
		for (int j = 0; j < size; j++)
			a[j] = temp[j];
		radix = radix * 10;
	}
	delete []temp;
	delete []count;
}

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int* a, int size)
{
	using namespace std;

	int p0, p2;
	p0 = 0;
	p2 = size - 1;
	for (int i = 0; i <= p2; i++)
	{
		if (a[i] == 0)
		{
			swap(a[i], a[p0]);
			p0++;
		}
		else if (a[i] == 2)
		{
			swap(a[i], a[p2]);
			p2--;
			i--;
		}
	}
}

/**
 *  @name        : 自拟 int Find_Kth(int *a,int size)
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */
int Find_KthSmallest(int* a, int begin, int end, int k)
{
	using namespace std;
	if ((k <= 0 || begin < 0 || end < 0)|| (k > end - begin + 1))
	{
		cout << "error param" << endl;
		return -1;
	}
	if (k > 0 && k <= end - begin + 1)
	{
		int pos = Partition(a, begin, end);
		if (pos - begin == k-1)
			return a[pos];
		else if (k - 1 > pos - begin)
			return Find_KthSmallest(a, pos + 1, end, k - pos + begin - 1);
		else if (k-1 < pos - begin)
			return Find_KthSmallest(a, begin, pos - 1, k);
	}

}