#include<iostream>
using namespace std;

class stack
{
private:
	int a[100], len, top, num, item;

public:
	stack()
	{
		cout << "enter length of array : ";
		cin >> len;
		//top = 0;
	}

	int push(int ind)
	{
		top = ind;
		if (top==len)
		{
			cout << "\nStack OverFlow\n";
			show();
			return top;
		}
		else
		{
			top++;
			cout << "how many values you want to PUSH : ";
			cin >> num;
			cout << "enter elements to PUSH : \n";
			for (int i = 0; i < num; i++)
			{
				cin >> item;
				a[i] = item;
				top = i;
			}
			if (top >= len)
			{
				top = len-1;
			}
			return top;
		}
	}
	
	void pop(int ind)
	{
		top = ind;
		if (top==-1)
		{
			cout << "\n\tStack UnderFlow\nfirst PUSH values then do POP process\n";
			show();
			return;
		}
		else
		{
			num = a[top];
			top--;
		}
		show();
	}

	void show()
	{
		for (int i = 0; i <= top && i != len; i++)
		{
			cout << "\t" << a[i] << endl;
		}
		cout<<"because length of stack is "<<len<<endl<<endl;
	}
};


int main()
{
	int top = -1;
	int ch, a;
	string choice;
	stack ob;
	cout << "enter choice between  -> push <-  OR  -> pop <-\n";
	cin >> choice;
	if (choice == "push")
	{
		
		a=ob.push(top);

		cout << "after " << choice << "ing values are" << endl;
		ob.show();
		

		cout << "do you want to do POP process?\nenter you choice between 1 and 0 : ";
		cin >> ch;
		if (ch == 1)
		{
			cout << "after poping values are" << endl;
			ob.pop(a);
			
		}
		else
		{
			ob.show();
		}
		
	}
	else if (choice == "pop")
	{
		cout << "after " << choice << "ing values are" << endl;
		ob.pop(top);
	}
	else
	{
		cout << "!----wrong choice----!";
	}

	//ob.show();
	
	
	return 0;
}
