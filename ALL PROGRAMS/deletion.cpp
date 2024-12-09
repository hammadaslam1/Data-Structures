#include<iostream>
using namespace std;

class del
{
private:
	int a[100], len, min, num, de, temp;
public:
	del()
	{
		cout << "enter length of the array : ";
		cin >> len;
		cout << "enter values of array\n\n";
		for (int i = 0; i < len; i++)
		{
			cout << i + 1 << "->\t";
			cin >> a[i];
		}
	}

	void sort()
	{
		for (int i = 0; i < len - 1; i++)
		{
			min = i;
			for (int j = i + 1; j < len; j++)
			{
				if (a[j] < a[min])
				{
					min = j;
				}
			}
			if (min != i)
			{
				num = a[i];
				a[i] = a[min];
				a[min] = num;
			}
		}
		cout << endl << "after sorting\n";
		for (int i = 0; i < len; i++)
		{
			cout << i + 1 << "->\t" << a[i] << endl;
		}
	}

	void deleting()
	{
		sort();
		cout << endl << "enter location of element you want to delete : ";
		cin >> de;

		temp = a[de];

		for (int i = de - 1; i < len - 1; i++)
		{
			a[i] = a[i + 1];

		}
		len--;
		show();
	}

	void show()
	{
		for (int i = 0; i < len; i++)
		{
			cout << i + 1 << "->\t" << a[i] << endl;
		}
	}
};

int main()
{
	del ob;
	ob.deleting();

	return 0;
}