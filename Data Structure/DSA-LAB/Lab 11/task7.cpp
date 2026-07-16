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

    BNode<T>* LCA(BNode<T>* curr, T val1, T val2)
    {
        if (curr == nullptr)
        {
            return nullptr;
        }

        if (val1 < curr->data && val2 < curr->data)
        {
            return LCA(curr->left, val1, val2);
        }

        if (val1 > curr->data && val2 > curr->data)
        {
            return LCA(curr->right, val1, val2);
        }

        return curr;
    }
};

int main()
{
    BST<int> t;

    t.insert(5);
    t.insert(3);
    t.insert(7);
    t.insert(2);
    t.insert(4);
    t.insert(6);
    t.insert(8);

    cout << "Inorder Traversal: ";
    t.display();
    BNode<int>* ans;

    ans = t.LCA(t.getRoot(), 3, 7);

    cout << "\nLCA of 3 and 7: "
        << ans->data;
    return 0;
}