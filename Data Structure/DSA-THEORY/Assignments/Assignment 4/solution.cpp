#include<iostream>
#include "bst.cpp"
using namespace std;

int range_sum(BNode<int>* root, int low, int high)
{
	if (root == nullptr)
		return 0;
	else
	{
		
		if (root->data >= low && root->data <= high)
		{
			cout << root->data << " ";
			return root->data + range_sum(root->left, low, high)+range_sum(root->right,low,high);
			
		}
		else if (root->data < low)
			return range_sum(root->right, low, high);
		else
			return  range_sum(root->left, low, high);
	}
}
int countNodes(BNode<int>* root)
{
	if (root == NULL)
		return 0;

	return 1 + countNodes(root->left) + countNodes(root->right);
}
int kth_smallest(BNode<int>* root, int k)
{
	if (root == NULL)
		return -1;

	int count_left = countNodes(root->left);

	if (k <= count_left)
		return kth_smallest(root->left, k);
	if (k == count_left + 1)
		return root->data;
	return kth_smallest(root->right, k - count_left - 1);

}
int kth_smallest_itr(BNode<int>* root, int k)
{
	if (k <= 0)		return -1;
	BNode<int>* curr = root;
	while (curr != nullptr)
	{
		if (curr->left == nullptr)
		{
			k--;
			if (k == 0)
			{
				return curr->data;
			}
			curr = curr->right;
		}
		else
		{
			BNode<int>* pred = curr->left;
			while (pred->right != nullptr && pred->right != curr)
			{
				pred = pred->right;
			}
			if (pred->right == nullptr)
			{
				pred->right = curr;
				curr = curr->left;
			}
			else
			{
				pred->right = nullptr;
				k--;
				if (k == 0)
				{
					return curr->data;
				}
				curr = curr->right;
			}
		}


	}
	return -1;
}
int main()
{
	BST<int> scores;
	int n;
	cout << "Enter number of players: ";;
	cin >> n;
	int e;

	cout << "Enter scores one by one: ";
	for (int i = 0;i < n;i++)
	{
		cin >> e;
		scores.insert(e);
	}
	cout <<endl<< "Scores in order :" << endl;
	scores.inorder(scores.getRoot());
	cout << endl<<endl << "Enter k to find the kth smallest: ";
	int k;
	cin >> k;
	int result = kth_smallest(scores.getRoot(), k);
	if (result != -1)
		cout << "The " << k << "th smallest score is: " << result << endl;
	else
		cout << "K out of range." << endl;

	int low,high;
	cout <<endl<< "Enter score range for prize eligibility (low high): ";
	cin >> low;
	cin >> high;
	cout << "Eligible scores: "<<endl;
	cout << endl << "Total prize pool Score sum: " << range_sum(scores.getRoot(), low, high) << endl;
}