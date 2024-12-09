#include<iostream>
using namespace std;

class linear
{
private:
	int a[100], len, item, loc, count, cnt[100];
public:
	linear()
	{
		loc = 0;
		count = 0;
		cout << "enter length of array : ";
		cin >> len;
		cout << "enter values of array\n";
		for (int i = 0; i < len; i++)
		{
			cout << i + 1 << "->\t";
			cin >> a[i];
		}
	}

	void search()
	{
		cout << "enter element you want to search : ";
		cin >> item;
		a[len] = item;
		loc = 1;
		for (int i = 0; i < len; i++)
		{
			if (a[i] == item)
			{
				cnt[count] = i + 1;
				count++;
			}
		}
		show();
	}

	void show()
	{
		if (count != 0)
		{
			cout << "element is found in this array " << count << " times.";
			cout << "\nand the locations are\n";
			for (int i = 0; i < count; i++)
			{
				cout << i + 1 << "->\t" << cnt[i] << endl;
			}
		}
		else
		{
			cout << "\n!--element not found--!\n";
		}
	}
};

int main()
{
	linear ob;
	ob.search();

	return 0;
}