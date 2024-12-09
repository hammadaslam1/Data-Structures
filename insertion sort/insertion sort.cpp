#include <iostream>
using namespace std;

class insert
{
private:
    int a[100], len, temp, loc;
public:
    insert()
    {
        a[0] = -99999;
        cout << "enter length of the array : ";
        cin >> len;
        cout << "\nenter values of array \n";
        for (int i = 1; i <= len; i++)
        {
            cout << "\t";
            cin >> a[i];
        }
    }
    void sort()
    {
        for (int j = 2; j <= len; j++)
        {
            temp = a[j];
            loc = j - 1;
            while (temp < a[loc])
            {
                a[loc + 1] = a[loc];
                loc--;
            }
            a[loc + 1] = temp;
        }
        show();
    }
    void show()
    {
        cout << endl << "values after sorting \n\n";
        for (int k = 1; k <= len; k++)
        {
            cout <<"\t"<< a[k] << endl;
        }
    }
};

int main()
{
    insert ob;
    ob.sort();

    return 0;
}
