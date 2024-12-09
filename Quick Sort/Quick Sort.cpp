#include<iostream>

using namespace std;

class qsorts
{
private:
	int N, LEFT, RIGHT, LOC, TEMP;
	int TOP, BEG, END, LOWER[50], UPPER[50];
	int A[100];
	char ch;
		
public:
	qsorts()
	{
		cout << "enter length of array : ";
		cin >> N;
		cout << "enter values of array\n";
		for (int i = 0; i < N; i++)
		{
			cin >> A[i];
		}

		sort1();
	
	}


	void sort1()
	{
		TOP = 0;

		if (N > 0) 
		{
			TOP++;
			LOWER[TOP] = 0;
			UPPER[TOP] = N - 1;
		}

		while (TOP != 0) 
		{
			BEG = LOWER[TOP];
			END = UPPER[TOP];
			TOP--;

			sort(BEG, END, LOC);

			if (BEG < LOC - 1) 
			{
				TOP++;
				LOWER[TOP] = BEG;
				UPPER[TOP] = LOC - 1;
			}

			if (LOC + 1 < END) 
			{
				TOP++;
				LOWER[TOP] = LOC + 1;
				UPPER[TOP] = END;
			}
		}
	}

	void sort(int BEG, int END, int& LOC)
	{
		LEFT = BEG;
		RIGHT = END;
		LOC = BEG;

		while (true) 
		{
			while (A[LOC] <= A[RIGHT] && LOC != RIGHT) 
			{
				RIGHT--;
			}

			if (LOC == RIGHT) 
			{
				return;
			}

			if (A[LOC] > A[RIGHT]) 
			{
			
				TEMP = A[LOC];
				A[LOC] = A[RIGHT];
				A[RIGHT] = TEMP;
				LOC = RIGHT;
			}

			while (A[LEFT] <= A[LOC] && LEFT != LOC) 
			{
				LEFT++;
			}

			if (LOC == LEFT) 
			{
				return;
			}

			if (A[LEFT] > A[LOC]) 
			{
				TEMP = A[LOC];
				A[LOC] = A[LEFT];
				A[LEFT] = TEMP;
				LOC = LEFT;
			}
		}
	}

	void show()
	{
		cout << "\nenter 'd' for descending\tand\nenter 'a' for ascending\n";
		cin >> ch;
		if (ch=='a')
		{
			cout << "\n\nAfter sorting: \n\n";
			for (int i = 0; i < N; i++)
			{
				cout << "\t" << A[i] << endl;
			}
		}
		else if (ch == 'd')
		{
			cout << "\n\nAfter sorting: \n\n";
			for (int i = N - 1; i >= 0; i--)
			{
				cout << "\t" << A[i] << endl;
			}
		}
	}
};

int main()
{
	qsorts ob;
	ob.show();
	return 0;
}
