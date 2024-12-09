#include<iostream>
using namespace std;

class insert
{
private:
	int a[100], len, min, num, in, ele, temp;
public:
	insert()
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

	void inserting()
	{
		sort();
		cout << endl << "enter location where you want to insert element : ";
		cin >> in;
		cout << endl << "\nenter element you want to insert : ";
		cin >> ele;

		for (int i = len; i >= in; i--)
		{
			a[i] = a[i - 1];

		}
		a[in-1] = ele;
		len++;
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
	insert ob;
	ob.inserting();

	return 0;
}