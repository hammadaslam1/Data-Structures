#include <iostream>
using namespace std;

// structure whose memory is being used
struct node
{
    int info;
    node* link;
};


class linklist
{
private:
    node* head, * tail, * loc;
public:
    linklist()
    {
        // initially head & tail are being set to null
        head = NULL;
        tail = NULL;
    }

    // storing values by creating the new node each time it is called
    void addnode(int n)
    {
        node* ptr = new node;
        ptr->info = n;
        ptr->link = NULL;
        if (head == NULL)
        {
            head = ptr;
            tail = ptr; 
        }
        else
        {
            tail->link = ptr;
            tail = tail->link;
        }
    }

    // traversing
    void display()
    {
        node* temp;
        temp = head;
        cout << "\n\tINFO PART\tNODE ADDRESS\n\n";
        while (temp != NULL)
        {
            cout <<"\t\t"<< temp->info << "\t" << temp << endl;
            temp = temp->link;
        }
    }

    // searching process
    node* search(int item)
    {
        node* ptr = head;
        
        while (ptr != NULL)
        {
            if (ptr->info == item)
            {
                
                loc = ptr;
                
                return loc;
            }
            else
            {
                ptr = ptr->link;
                
            }
        }
        return NULL;
    }
};


int main()
{
    linklist ob;
    int a[100], n, item;
    
    // values entering in the linked list taking from the user
    cout << "how many values you want to enter?\t";
    cin >> n;
    cout << "enter values\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\t";
        cin >> a[i];
        ob.addnode(a[i]);
    }

    // calling display() for traversing
    ob.display();

    //  searching process begins
    cout << "\nenter item you want to find :\t";
    cin >> item;
    // recieves returned pointer
    node* search = ob.search(item);
    if (search != NULL)
    {
        cout << "\n\tINFO PART\tNODE ADDRESS\n\n";
        cout << "\t\t" << search->info;
        cout << "\t" << search << endl;
    }
    else
    {
        cout << "Node not found" << endl;
    }


    return 0;
}