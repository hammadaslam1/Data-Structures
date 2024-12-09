#include <iostream>
using namespace std;


struct node
{
    int info;
    node* link;
};


class linklist
{
private:
    node* head, * tail;
public:
    linklist()
    {
        head = NULL;
        tail = NULL;
    }
    void addnode(int n)
    {
        node* temp = new node;
        temp->info = n;
        temp->link = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->link = temp;
            tail = tail->link;
        }
    }
    void display()
    {
        node* temp;
        temp = head;
        while (temp != NULL)
        {
            cout <<"\t"<< temp->info << endl;
            temp = temp->link;
        }
    }
};


int main()
{
    linklist ob;
    int a[100], n;
    cout << "how many values you want to enter?\t";
    cin >> n;
    cout << "enter values\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\t";
        cin >> a[i];
        ob.addnode(a[i]);
    }

    cout << "\nValues are\n\n";

    ob.display();

    return 0;
}
