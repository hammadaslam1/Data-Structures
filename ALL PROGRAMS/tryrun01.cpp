#include<iostream>

using namespace std;

struct node
{
	int info;
	node* link;
};


class del
{
	private: 
		node* head, * tail;
	public:
		del()
		{
			head=NULL;
			tail=NULL;
		}
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
	    
	    void findLoc(int item)
	    {
	    	node* loc=new node;
	    	node* locp=new node;
	    	node* save = new node;
	    	node* ptr = new node;
	    	if(head==NULL)
	    	{
	    		loc = locp = NULL;
			}
			else if(head->info==item)
			{
				loc = head;
				locp = NULL;
			}
			else
			{
				save = head;
				ptr = head->link;
				while(ptr!=NULL)
				{
					if(ptr->info==item)
					{
						loc=ptr;
						locp=save;
						break;
					}
					else
					{
						save = ptr;
						ptr = ptr->link;
					}
					loc = NULL;
				}
				
			}
			delnode(locp, loc);
		}
	    
	    void delnode(node* locp, node* loc)
	    {
	    	if(locp==NULL)
	    	{
	    		head = head->link;
			}
			else
			{
				locp->link = loc->link;
			}
			
			display();
		}
	    
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
	    
};


int main()
{
	del ob;
    int a[100],num , len, avail, item;
    char ch;  
    cout << endl << "how many values you want to insert in the linkedlist?\t";
    cin >> len;
    cout << "\n\tenter values\n";
    for (int i = 0; i < len; i++)
    {
        cout << "\t";
        cin >> a[i];
        ob.addnode(a[i]);
    }
    ob.display();
    
    
    cout<<endl<<endl<<"enter item you want to delete?\n\n\t\t";
    cin>>item;
    cout<<endl;
    ob.findLoc(item);
	
	return 0;
}
