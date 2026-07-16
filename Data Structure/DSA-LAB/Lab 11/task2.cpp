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

    int count_leaves(BNode<T>* curr)
    {
        if (curr == nullptr)
        {
            return 0;
        }
        if (curr->left == nullptr && curr->right == nullptr)
        {
            return 1;
        }
        return count_leaves(curr->left) + count_leaves(curr->right);
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

    cout <<endl<< "Leaf Nodes: "<< t.count_leaves(t.getRoot());
    return 0;
}