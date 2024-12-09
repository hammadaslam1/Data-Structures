#include<iostream>
using namespace std;

class bubble
{
private:
	int a[100], len, temp;
public:
	bubble()
	{
		cout << "enter length of array : ";
		cin >> len;
		cout << "enter values of array\n";
		for (int i = 0; i < len; i++)
		{
			cout << i + 1 << "->\t";
			cin >> a[i];
		}
	}

	void sort()
	{
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len-1; j++)
			{
				if (a[j] > a[j + 1])
				{
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
		show();
	}

	void show()
	{
		cout << endl << "values after sorting\n";
		for (int i = 0; i < len; i++)
		{
			cout << i + 1 << "->\t";
			cout << a[i] << endl;
		}
	}
};

int main()
{
	bubble ob;
	ob.sort();

	return 0;
}