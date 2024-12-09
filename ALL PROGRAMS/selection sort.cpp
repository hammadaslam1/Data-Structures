

#include <iostream>
using namespace std;

class selection
{
private:
    int a[100], len, min, num, i, j;
public:
    selection()
    {
        cout << "enter length of the array : ";
        cin >> len;
        cout << "enter values of the array :\n";
        for ( i = 0; i < len; i++)
        {
            cin >> a[i];
        }
    }
    void sort()
    {
		for (i = 0; i < len - 1; i++)
		{
			min = i;
			for (j = i + 1; j < len; j++)
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
		show();
    }
	void show()
	{
		cout << endl << "values of array after sorting :\n";
		for ( j = 0; j < len; j++)
		{
			cout <<"\t"<< a[j] << endl;
		}
	}
};

int main()
{
	selection ob;
	ob.sort();
	return 0;
}

