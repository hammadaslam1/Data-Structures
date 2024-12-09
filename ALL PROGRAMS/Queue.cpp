#include <iostream>
using namespace std;

class queue
{
private:
    int que[100], len, front, rear, item;

public:
    queue()
    {
        front = rear = -1;
        cout << "enter length of array : ";
        cin >> len;
    }

    int qinsert()
    {
        if ((front == 0 && rear == len - 1) || (front == rear + 1))
        {
            cout << "\n\t<----queue is full---->\n";
            return len;
        }

        
        cin >> item;

        if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == -1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        que[rear] = item;
       
       
    }

    void qdelete()
    {
        if (front==-1)
        {
            cout << "\n\t<----queue is empty---->\n";
            return;
        }

        item = que[front];

        if (front==rear)
        {
            front = rear = -1;
        }
        else if (front==-1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
       
    }

    void show(int n, char ch, int length)
    {
        if (ch == 'n' && length >= len)
        {
            cout << "\n\tvalues after processing\n";
            for (int i = 0; i < len; i++)
            {
                cout << "\t" << que[i] << endl;
            }
        }
        else if (ch == 'n' && length < len)
        {
            cout << "\n\tvalues after processing\n";
            for (int i = 0; i < length; i++)
            {
                cout << "\t" << que[i] << endl;
            }
        }

        else if (ch == 'y' && (n >= length || n >= len))
        {
            cout << "\n\t" << "<----values are deleted---->" << endl;
            cout << "\n\t\t" << "<----now---->" << endl;
            cout << "\n\t" << "<----queue is empty---->" << endl;
        }
        else if (ch == 'y' && n < length && n < len)
        {
            cout << "\n\tvalues after processing\n";
            for (int i = n; i < length && i < len; i++)
            {
                if (que[i]!='\0')
                {
                cout << "\t" << que[i] << endl;
                }
            }
        }
    }
};


int main()
{
    queue ob;
    char ch;
    int n, a, length;
    //cout << "\twhat do you want to do?\tselect \n\t'i'\tfor\tinsert\n\t'd'\tfor\tdelete\n\t";
    //cin >> ch;
    cout << "\nhow many values you want to enter : ";
    cin >> length;
    cout << "\nenter the item you want to insert : \n";
    for (int i = 0; i < length; i++)
    {
        a=ob.qinsert();
        if(a<=length)
        {
        	i=length;
		}
    }
    
    cout << "\ndo you want to delete the values?\t'y' or 'n' :\t";
    cin >> ch;
    if (ch == 'n')
    {
        n = 0;
        ob.show(n, ch, length);
    }
    else if (ch == 'y')
    {
        cout << "\nhow many values you want to delete : ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
        ob.qdelete();
        }
        ob.show(n, ch, length);
    }

    return 0;
}
