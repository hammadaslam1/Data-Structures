#include<iostream>
using namespace std;

class update
{
private:
	int arr[100], num, val, len, j, k, i;
	char ch;
public:
	update()
	{
		cout << "enter length of Array: ";
		cin >> len;
	}
	void input()
	{
		cout << "enter values of Array:" << endl;
		for (i = 0; i < len; i++)
		{
			cin >> arr[i];
		}

	}
	void choice()
	{
		cout << "what do you want to do:" << endl;
		cout << "Insertion(i)\tor\tDeletion(d)" << endl;
		cin >> ch;
		if (ch == 'i')
		{
			update::insert();
			update::show();
		}
		else if (ch == 'd')
		{
			update::del();
			update::show();
		}
		else
			cout << "\t\t\t!.wrong choice.!" << endl;
	}
	void insert()
	{
		cout << "\nenter location where you want to insert value: ";
		cin >> num;
		cout << "enter value to be inserted: ";
		cin >> val;
		for (j = len - 1; j >= num - 1; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[num - 1] = val;
		cout << endl;
	}
	void del()
	{
		cout << "\nenter location where you want to delete value: ";
		cin >> num;
		for (j = num - 1; j < len; j++)
		{
			arr[j] = arr[j + 1];
		}
		cout << endl;
	}
	void show()
	{
		if (ch == 'i')
		{
			cout << "values of Array after insertion: \n";
			for (k = 0; k <= len; k++)
			{
				cout << arr[k] << endl;
			}
		}
		else if (ch == 'd')
		{
			cout << "values af Array after deletion: \n";
			for (k = 0; k < len - 1; k++)
			{
				cout << arr[k] << endl;
			}
		}
	}
};

int main()
{
	update o1;
	o1.input();
	o1.choice();
	return 0;
}