#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class linkedlist
{
private:
    Node* head;
public:
    linkedlist()
    {
        head = NULL;
    }

    void insatstart(int data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void insatend(int data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insatloc(int loc, int data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;

        if (loc == 1)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < loc - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Position out of range" << endl;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
};

int main()
{
    int loc, a[100], len;
    char ch;
    linkedlist ob;
    cout << "how many values you want to enter? :\t";
    cin >> len;
    cout << "where do you want to insert the values";
    cout << "\n's' for START\t'e' for END\tand\t'p' for SPECIFIC POSITION :\t";
    cin >> ch;
    
    if (ch == 's' || ch == 'S')
    {
        if (len > 1)
        {
            cout << "enter values you want to insert\n";
        }
        else
        {
            cout << "enter value you want to insert\n";
        }
        for (int i = 0; i < len; i++)
        {
            cin >> a[i];
            ob.insatstart(a[i]);
        }
    }
    else if (ch == 'e' || ch == 'E')
    {
        if (len > 1)
        {
            cout << "enter values you want to insert\n";
        }
        else
        {
            cout << "enter value you want to insert\n";
        }
        for (int i = 0; i < len; i++)
        {
            cin >> a[i];
            ob.insatend(a[i]);
        }
    }
    else if (ch == 'p' || ch == 'P')
    {
        for (int i = 0; i < len; i++)
        {
            cout << "enter position where the value has to be inserted :\t";
            cin >> loc;
            cout << "enter value which has to be inserted :\t";
            cin >> a[i];
            ob.insatloc(loc, a[i]);
        }
    }
    else
    {
        cout << "\n\t\t\t<!!!!----- WRONG CHOICE -----!!!!>";
    }
/*    switch (ch)
    {
    case 's':
        ob.insatstart(ch);
        break;
    case 'e':
        ob.insatend(ch);
        break;
    case 'p':
        cout << "enter position : ";
        cin >> loc;
        ob.insatloc(loc,ch);
        break;
    case 'S':
        ob.insatstart(ch);
        break;
    case 'E':
        ob.insatend(ch);
        break;
    case 'P':
        cout << "enter position : ";
        cin >> loc;
        ob.insatloc(loc, ch);
        break;
    default:
        cout << "\n\t\t\t<!!!!----- WRONG CHOICE -----!!!!>";
    }    */

    return 0;
}