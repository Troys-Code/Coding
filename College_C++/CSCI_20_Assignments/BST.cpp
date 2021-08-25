#include <iostream>

using namespace std;

class BST
{
	int data;
	BST *left, *right;
public:
	BST()		// Default Contructor
	{
		data = 0;
		left = right = NULL; 
	}

	BST( int value )	// Parameterized Contructor
	{
		data = value;
		left = right = NULL;
	}
	
	BST* Insert( BST* root, int value )
	{
		if ( root == NULL )			// Insert the first node, if root is NULL.
        		return new BST( value );
    		if ( value > root->data )		// Insert right node data, if 'value' is greater than 'root' node data.
			root->right = Insert( root->right, value );
		else					// Insert left node data, if the 'value' is greater than 'root' node data.
			root->left = Insert( root->left, value );
		return root;				// Return 'root' node, after insertion.
	}

	BST* Search( BST *root, int key)
	{
		if( root == NULL || root->data == key )	// Base Case: Root is NULL or Key is present root
			return root;
		if ( root->data < key )			// if Key is greater than roots data
			return Search( root->right, key );
		return Search( root->left, key );	// else Key is smaller than roots data
	}

	BST* find_min( BST *root )
	{
		if( root != NULL )
			while( root->left != NULL )
				root = root->left;
		return root;
	}	

	BST* find_max( BST *root )
	{
		if( root != NULL )
			while( root->right != NULL )
				root = root->right;
		return root;
	}

	void print_in_order( BST *root )
	{
		if( root == NULL )
			return;
		print_in_order(root->left);
		cout << root->data << endl;
		print_in_order(root->right);
	}

	void print_pre_order( BST *root )
        {
                if( root == NULL )
                        return;
		cout << root->data << endl;
                print_pre_order(root->left);
                print_pre_order(root->right);
        }

        void print_post_order( BST *root )
        {
                if( root == NULL )
                        return;
                print_post_order(root->left);
                print_post_order(root->right);
		cout << root->data << endl;
        }
	
	void print_children( BST *root )
	{	
		if( root->left != NULL )
			cout << "Left: " << root->left->data << endl;
		if ( root->right != NULL )
			cout << "Right: " << root->right->data << endl;
	}
	
	int val( BST *root )
	{
		return root->data;
	}
};

int main()
{
	BST tree;
	BST *root = NULL;
	BST *Found = NULL;
	int search_val;
	bool run = true;

	root = tree.Insert( root, 12 );
	tree.Insert( root, 17 );
	tree.Insert( root, 2008 );
	tree.Insert( root, 8 );
	tree.Insert( root, 12 );
	tree.Insert( root, 2 );
	tree.Insert( root, 22 );
	
	cout << "Print Tree IN ORDER" << endl;	
	tree.print_in_order(root);
	
	while ( run )
	{
		system("clear");
		//cout << "Print Tree IN ORDER" << endl;
		//tree.print_in_order(root);

		cout << "Print Tree PRE ORDER" << endl;
                tree.print_pre_order(root);

		//cout << "Print Tree POST ORDER" << endl;
		//tree.print_post_order(root);
/*
		cout << "\nEnter a Tree value to search for: ";
		cin >> search_val;

		cout << "Searching for value " <<  to_string(search_val) << " and printing its children" << endl;
		Found = tree.Search( root, search_val );
		Found->print_children( Found );
*/

		Found = tree.find_min(root);
		cout << "\n\nMin Value: " << to_string(tree.val(Found));
		
		Found = tree.find_max(root);
		cout << "\n\nMax Value: " << to_string(tree.val(Found));
		
		cin.ignore();
		cin.get();
	}
	return 0;
}
