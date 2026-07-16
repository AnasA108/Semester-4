#include<iostream>
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

    BNode(T val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

template <class T>
class BST
{
private:
    BNode<T>* root;

public:

    BST()
    {
        root = nullptr;
    }

    BNode<T>* insert(BNode<T>* curr, T val)
    {
        if (curr == nullptr)
        {
            return new BNode<T>(val);
        }

        if (val < curr->data)
        {
            curr->left = insert(curr->left, val);
        }
        else if (val > curr->data)
        {
            curr->right = insert(curr->right, val);
        }

        return curr;
    }

    void insert(T val)
    {
        root = insert(root, val);
    }

    void inorder(BNode<T>* curr)
    {
        if (curr != nullptr)
        {
            inorder(curr->left);
            cout << curr->data << " ";
            inorder(curr->right);
        }

    }
    BNode<T>* getRoot()
    {
        return root;
    }
    void display()
    {
        inorder(root);
    }

    bool is_valid_BST(BNode<T>* curr, T min_val, T max_val)
    {
        if (curr == nullptr)
        {
            return true;
        }

        if (curr->data <= min_val || curr->data >= max_val)
        {
            return false;
        }

        return is_valid_BST(curr->left, min_val, curr->data) &&is_valid_BST(curr->right, curr->data, max_val);
    }
};

int main()
{
    BST<int> t;

    t.insert(50);
    t.insert(30);
    t.insert(70);
    t.insert(20);
    t.insert(40);
    t.insert(60);
    t.insert(80);

    cout << "Inorder Traversal: ";
    t.display();
    cout <<endl<< "BST Valid: ";

    if (t.is_valid_BST(t.getRoot(), -9999, 9999))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}