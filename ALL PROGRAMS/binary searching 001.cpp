#include<iostream>
using namespace std;
class sortnsearch
{
private:
	int arr[100], len, mid, beg, end, i, j, k, min, max, num, item;
public:
	sortnsearch()
	{
		cout << "enter length of array: ";
		cin >> len;
		beg = 0;
		end = len - 1;
	}
	void input()
	{
		cout << "enter values of array:\n";
		for (i = 0; i < len; i++)
		{
			cout << i + 1 << "->\t";
			cin >> arr[i];
		}
	}
	void sort()
	{
		for (i = 0; i < len - 1; i++)
		{
			min = i;
			for (j = i + 1; j < len; j++)
			{
				if (arr[j] < arr[min])
				{
					min = j;
				}
			}
			if (min != i)
			{
					num = arr[i];
					arr[i] = arr[min];
					arr[min] = num;
			}
		}
	}
	void show()
	{
		cout << "\n values after sorting:\n";
		for (k = 0; k < len; k++)
		{
			cout << k + 1 << "->\t" << arr[k] << endl;
		}
	}
	void set()
	{
		cout << "\n enter number which has to be found : ";
		cin >> item;
		mid = ((beg + end) / 2);
	}
	void search()
	{
		while ((beg <= end) && (arr[mid] != item))
		{
			if (item < arr[mid])
				end = mid - 1;
			else
				beg = mid + 1;
			mid = ((beg + end) / 2);
		}
		int cnt[100], count;
		count = 0;
		for (int i = 0; i < len; i++)
		{
			if (arr[i] == item)
			{
				cnt[count] = i + 1;
				count++;
			}
		}
		cout << "value found at location : ";
		for (int i = 0; i < count; i++)
		{
			//if (arr[mid] == item)
			cout << endl <<"\t-> "<< cnt[i]<<" <-";
		}

	}


};

int main()
{
	sortnsearch ob;
	ob.input();
	ob.sort();
	ob.show();
	ob.set();
	ob.search();
	return 0;
}
