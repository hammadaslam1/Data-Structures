#include<iostream>
using namespace std;

class search
{
private:
	int arr[100], len, loc, i, item, count = 0, cnt[100];
public:
	search()
	{
		cout << "\nenter the length of array: ";
		cin >> len;
	}
	void input()
	{
		cout << "\nenter the values of array:\n";
		for (i = 0; i < len; i++)
		{
			cout<<endl<<i+1<<"->\t";
			cin >> arr[i];
		}
	}
	void find()
	{
		cout << "\nenter item you want the location of: ";
		cin >> item;
		for (i = 0; i < len; i++)
		{
			if (arr[i] == item)
			{
				cnt[count] = i+1;
				count++;
			}
		}
		show();
	}
	void show()
	{
		cout << endl << "we have found " << count << " elements in the array.\n\n";
		cout << "\nand the locations are as follows:\n";
		for (int j = 0; j < count; j++)
		{
			cout <<"\t->  "<< cnt[j] <<"  <-"<< endl;
		}
	}
};

int main()
{
	search ob;
	ob.input();
	ob.find();
	return 0;
}
