#include <iostream>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};


class trees
{
    private:
        node* lefthead, * righthead, * lefttail, * righttail;
    public:
        node* createNode(int data)
        {
            node* ptr = new node();
            if (!ptr)
            {
                cout << "Memory error\n";
                return NULL;
            }
            ptr->data = data;
            ptr->left = ptr->right = NULL;
            return ptr;
        }

        node* insertNode(node* root, int data) 
        {
            if (root == NULL) 
            {
                root = createNode(data);
                return root;
            }
            if (data < root->data) 
            {
                root->left = insertNode(root->left, data);
            }
            else if (data > root->data) 
            {
                root->right = insertNode(root->right, data);
            }

            return root;
        }

        void inorderTraversal(node* root) 
        {
            if (root == NULL) 
            {
                return;
            }
            inorderTraversal(root->left);
            cout << root->data << "\n\t\t";
            inorderTraversal(root->right);
        }
};



int main() 
{
    int len, item;
    trees ob;
    node* root = NULL;
    cout << "how many values you want to insert?\n";
    cin >> len;
    cout << "enter values :\n";
    cin >> item;
    root = ob.insertNode(root, item);
    for (int i = 1; i < len; i++)
    {
        cin >> item;
        ob.insertNode(root, item);

    }

    cout << "\n\nInorder traversal of the tree: \n\t\t";
    ob.inorderTraversal(root);
    cout << endl;

    return 0;
}
