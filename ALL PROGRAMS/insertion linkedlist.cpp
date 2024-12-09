#include<iostream>
using namespace std;

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
        loc = NULL;
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

    void at1st(node *A, int num)
    {
        node* spare = new node;
        spare->info = num;
        if (A==NULL)
        {
            spare->link = head;
            head = spare;
        }
        else
        {
            spare->link = A->link;
            A->link = spare;
        }
        
    }
    void atAny(int item)
    {
        node* avail = new node;
        node* save = new node;
        node* ptr = new node;
        if (head == NULL)
        {
            avail = NULL;

        }
        else if (item < head->info)
        {
            avail = NULL;

        }
        else
        {

            save = head;
            ptr = head->link;
            while (ptr != NULL)
            {
                if (item <= ptr->info)
                {
                    avail = save;
                    break;
                }
                else
                {
                    save = ptr;
                    ptr = ptr->link;
                }
            }
            avail = save;
        }


        at1st(avail, item);
    }

    // deletion

    void findLoc(int item)
    {
        node* locs = new node;
        node* locp = new node;
        node* save = new node;
        node* ptr = new node;
        if (head == NULL)
        {
            locs = locp = NULL;
        }
        else if (head->info == item)
        {
            locs = head;
            locp = NULL;
        }
        else
        {
            save = head;
            ptr = head->link;
            while (ptr != NULL)
            {
                if (ptr->info == item)
                {
                    locs = ptr;
                    locp = save;
                    break;
                }
                else
                {
                    save = ptr;
                    ptr = ptr->link;
                }
                locs = NULL;
            }

        }
        delnode(locp, locs);
    }

    void delnode(node* locp, node* locs)
    {
        if(locs == NULL)
        {
        	cout<<"\n\n\t\t< - - - - node does not exist - - - - >\n";
		}
		else
		{
			if (locp == NULL)
        	{
    	        head = head->link;
	        }
        	else
        	{
    	        locp->link = locs->link;
	        }
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
            cout << "\t\t" << temp->info << "\t" << temp << endl;
            temp = temp->link;
        }
    }

     //searching process
  
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
    int a[100],num , len, avail, item;
    char ch;

    // values entering in the linked list taking from the user
    
    cout << endl << "how many values you want to insert in the linkedlist?\t";
    cin >> len;
    cout << "\n\tenter values\n";
    for (int i = 0; i < len; i++)
    {
        cout << "\t";
        cin >> a[i];
        ob.addnode(a[i]);
    }

    // calling display() for traversing
    ob.display();


    // users choice

    repeatall:

    cout << endl << "what do you want to do?\n";
    cout << "\t'i'\tfor\tINSERTION\n";
    cout << "\t's'\tfor\tSEARCHING\n";
    cout << "\t'd'\tfor\tDELETION\n\n\t\t";
    cin >> ch;

    // inserting values
    if (ch == 'i' || ch == 'I')
    {
    insert:

        cout << endl << "enter item you want to insert:\t";
        cin >> num;
        ob.atAny(num);
        ob.display();

        // recalling process

    repeatinsert:

        cout << "\nnow do you want to proceed further?\n";
        cout << "\t'y'\tfor\tYES\n";
        cout << "\t'n'\tfor\tNO\n\n\t\t";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            cout << endl << "what do you want to do?\n";
            cout << "\t'i'\tfor\tINSERTION\n";
            cout << "\t's'\tfor\tSEARCHING\n";
            cout << "\t'd'\tfor\tDELETION\n\n\t\t";
            cin >> ch;
            if (ch == 'i' || ch == 'I')
            {
                goto insert;
            }
            else if (ch == 's' || ch == 'S')
            {
                goto search;
            }
            else if (ch == 'd' || ch == 'D')
            {
                goto delet;
            }
            else
            {
                cout << "\n\t< - - - - wrong choice - - - - >\n\n";
                goto repeatinsert;
            }
        }
    }
    //  searching process begins
    else if (ch == 's' || ch == 'S')
    {
    search:

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
            cout << "\t< - - - - Item not found - - - - >" << endl;
        }

        // recalling process

    repeatsearch:

        cout << "\nnow do you want to proceed further?\n";
        cout << "\t'y'\tfor\tYES\n";
        cout << "\t'n'\tfor\tNO\n\n\t\t";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            cout << endl << "what do you want to do?\n";
            cout << "\t'i'\tfor\tINSERTION\n";
            cout << "\t's'\tfor\tSEARCHING\n";
            cout << "\t'd'\tfor\tDELETION\n\n\t\t";
            cin >> ch;
            if (ch == 'i' || ch == 'I')
            {
                goto insert;
            }
            else if (ch == 's' || ch == 'S')
            {
                goto search;
            }
            else if (ch == 'd' || ch == 'D')
            {
                goto delet;
            }
            else
            {
                cout << "\n\t< - - - - wrong choice - - - - >\n\n";
                goto repeatsearch;
            }
        }

    }
    // deleting values
    else if (ch == 'd' || ch == 'D')
    {
    delet:

        cout << endl << "enter item you want to delete:\t";
        cin >> num;
        ob.findLoc(num);
        ob.display();

        // recalling process

    repeatdelete:

        cout << "\nnow do you want to proceed further?\n";
        cout << "\t'y'\tfor\tYES\n";
        cout << "\t'n'\tfor\tNO\n\n\t\t";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            cout << endl << "what do you want to do?\n";
            cout << "\t'i'\tfor\tINSERTION\n";
            cout << "\t's'\tfor\tSEARCHING\n";
            cout << "\t'd'\tfor\tDELETION\n\n\t\t";
            cin >> ch;
            if (ch == 'i' || ch == 'I')
            {
                goto insert;
            }
            else if (ch == 's' || ch == 'S')
            {
                goto search;
            }
            else if (ch == 'd' || ch == 'D')
            {
                goto delet;
            }
            else
            {
                cout << "\n\t< - - - - wrong choice - - - - >\n\n";
                goto repeatdelete;
            }
        }
    }


    // choice not matched
    else
    {
        cout << "\n\t< - - - - Wrong choice - - - - >\n\n";
        goto repeatall;
    }


    

    return 0;
}
