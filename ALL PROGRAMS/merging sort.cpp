#include<iostream>
using namespace std;

class merges
{
private:
	int na, nb, ptr, la, lb;
	int a[100], b[100], c[200];
	int temp, min;
public:
	merges()
	{
		cout << "enter length of array A : ";
		cin >> la;
		cout << "enter values of array A\n";
		for (int i = 0; i < la; i++)
		{
			cin >> a[i];
		}
	
	
		cout << "\nenter length of array B : ";
		cin >> lb;
		cout << "enter values of array B\n";
		for (int i = 0; i < lb; i++)
		{
			cin >> b[i];
		}
	}

	void arraysort()
	{
		for (int i = 0; i < la - 1; i++)
		{
			min = i;
			for (int j = i + 1; j < la; j++)
			{
				if (a[j] < a[min])
				{
					min = j;
				}
			}
			if (min != i)
			{
				temp = a[i];
				a[i] = a[min];
				a[min] = temp;
			}
		}

		for (int p = 0; p < lb - 1; p++)
		{
			min = p;
			for (int q = p + 1; q < lb; q++)
			{
				if (b[q] < b[min])
				{
					min = q;
				}
			}
			if (min != p)
			{
				temp = b[p];
				b[p] = b[min];
				b[min] = temp;
			}
		}
	}

	void mergesort()
	{
		arraysort();

		na = 0;
		ptr = 0;
		nb = 0;
		while (na<la && nb<lb)
		{
			if (a[na]<b[nb])
			{
				c[ptr] = a[na];
				ptr++;
				na++;
			}
			else
			{
				c[ptr] = b[nb];
				ptr++;
				nb++;

			}
		}
		if (na>=la)
		{
			for (int k = nb; k < lb ; k++)
			{
				c[ptr] = b[k];
				ptr++;
			}
		}
		else
		{
			for (int r = na; r <la; r++)
			{
				c[ptr] = a[r];
				ptr++;
			}
		}
		show();
	}

	void show()
	{
		cout << "values after merging\n\n";
		for (int k = 0; k < (la+lb); k++)
		{
			cout << endl << c[k];
		}	
		cout << endl;
	}
};


int main()
{
	merges ob;
	ob.mergesort();

	return 0;
}