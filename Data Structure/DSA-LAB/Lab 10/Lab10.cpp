#include<iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

template <class T>
class BNode
{
public:
    T data;
    BNode<T>* left;
    BNode<T>* right;

    BNode()
    {
        left = nullptr;
        right = nullptr;
    }

    BNode(T v)
    {
        data = v;
        left = nullptr;
        right = nullptr;
    }
};

template <class T = int>
class BST
{
private:
    BNode<T>* root;

public:
    BNode<T>* rec_insert(BNode<T>* curr, T v)
    {
        if (curr == nullptr)
        {
            return new BNode<T>(v);
        }

        if (v < curr->data)
        {
            curr->left = rec_insert_helper(curr->left, v);
        }
        else
        {
            curr->right = rec_insert_helper(curr->right, v);
        }

        return curr;
    }

    BST()
    {
        root = nullptr;
    }

    BNode<T>* getroot()
    {
        return root;
    }

    void it_insert(T v)
    {
        BNode<T>* temp = new BNode<T>(v);

        if (root == nullptr)
        {
            root = temp;
            return;
        }

        BNode<T>* curr = root;

        while (true)
        {
            if (v > curr->data)
            {
                if (curr->right == nullptr)
                {
                    curr->right = temp;
                    break;
                }

                curr = curr->right;
            }
            else
            {
                if (curr->left == nullptr)
                {
                    curr->left = temp;
                    break;
                }

                curr = curr->left;
            }
        }
    }


    void inorder(BNode<T>* curr)
    {
        if (curr == nullptr)
        {
            return;
        }

        inorder(curr->left);
        cout << curr->data << " ";
        inorder(curr->right);
    }
    void preorder(BNode<T>* curr)
    {
        if (curr == nullptr)
        {
            return;
        }

        cout << curr->data << " ";
        preorder(curr->left);
        preorder(curr->right);
    }

    void postorder(BNode<T>* curr)
    {
        if (curr == nullptr)
        {
            return;
        }

        postorder(curr->left);
        postorder(curr->right);
        cout << curr->data << " ";
    }



    void bfs()
    {
        if (root == nullptr)
        {
            return;
        }

        Queue<BNode<T>*> q;

        q.enqueue(root);

        while (!q.isEmpty())
        {
            BNode<T>* curr = q.dequeue();

            cout << curr->data << " ";

            if (curr->left != nullptr)
            {
                q.enqueue(curr->left);
            }

            if (curr->right != nullptr)
            {
                q.enqueue(curr->right);
            }
        }
    }


    void inorder_iter()
    {
        Stack<BNode<T>*> s;

        BNode<T>* curr = root;

        while (curr != nullptr || !s.isEmpty())
        {
            while (curr != nullptr)
            {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.Top();
            s.pop();

            cout << curr->data << " ";

            curr = curr->right;
        }
    }



    void preorder_iter()
    {
        if (root == nullptr)
        {
            return;
        }

        Stack<BNode<T>*> s;

        s.push(root);

        while (!s.isEmpty())
        {
            BNode<T>* curr = s.Top();
            s.pop();

            cout << curr->data << " ";

            if (curr->right != nullptr)
            {
                s.push(curr->right);
            }

            if (curr->left != nullptr)
            {
                s.push(curr->left);
            }
        }
    }


    void postorder_iter()
    {
        if (root == nullptr)
        {
            return;
        }

        Stack<BNode<T>*> s1;
        Stack<BNode<T>*> s2;

        s1.push(root);

        while (!s1.isEmpty())
        {
            BNode<T>* curr = s1.Top();
            s1.pop();

            s2.push(curr);

            if (curr->left != nullptr)
            {
                s1.push(curr->left);
            }

            if (curr->right != nullptr)
            {
                s1.push(curr->right);
            }
        }

        while (!s2.isEmpty())
        {
            cout << s2.Top()->data << " ";
            s2.pop();
        }
    }

    bool search_iter(T val)
    {
        BNode<T>* curr = root;

        while (curr != nullptr)
        {
            if (curr->data == val)
            {
                return true;
            }

            if (val < curr->data)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }

        return false;
    }


    bool search_rec(BNode<T>* curr, T val)
    {
        if (curr == nullptr)
        {
            return false;
        }

        if (curr->data == val)
        {
            return true;
        }

        if (val < curr->data)
        {
            return search_rec(curr->left, val);
        }
        else
        {
            return search_rec(curr->right, val);
        }
    }
};

int main()
{
    BST<int> b;
    b.it_insert(50);
    b.it_insert(30);
    b.it_insert(70);
    b.it_insert(20);
    b.it_insert(40);
    b.it_insert(60);
    b.it_insert(80);

    cout << "Recursive Inorder: ";
    b.inorder(b.getroot());

    cout << endl << "Recursive Preorder: ";
    b.preorder(b.getroot());

    cout << endl << "Recursive Postorder: ";
    b.postorder(b.getroot());

    cout << endl << "Breadth First Traversal: ";
    b.bfs();

    cout << endl << "Iterative Inorder: ";
    b.inorder_iter();

    cout << endl << "Iterative Preorder: ";
    b.preorder_iter();

    cout << endl << "Iterative Postorder: ";
    b.postorder_iter();

    cout << endl;

    if (b.search_iter(60))
    {
        cout << "60 Found using Iterative Search" << endl;
    }
    else
    {
        cout << "60 Not Found" << endl;
    }

    int v;
	cout << "Enter the value to search: ";
	cin >> v;
	if (b.search_rec(b.getroot(), v))
	{
		cout << v << " Found using Recursive Search" << endl;
	}
	else
	{
		cout << v << " Not Found" << endl;
	}
    return 0;
}