#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct Node { // struct for representing nodes of the tree
	string info;
	int key;
	unsigned char height;
	Node* left;
	Node* right;

	Node(int k, string info = "") {
		key = k;
		this->info = info;
		left = right = NULL;
		height = 1;
	}
};

unsigned char height(Node* p) { // help function to receive height even for NULL nodes
	if (p)
		return p->height;
	return 0;
}

int bfactor(Node* p) {  // function to receive balance factor
	return height(p->right) - height(p->left);
}

void fixHeight(Node* p) { // fixing the height (if right and left nodes have the right height!)
	unsigned char hleft = height(p->left);
	unsigned char hright = height(p->right);
	if (hleft > hright)
		p->height = hleft + 1;
	else if (hright < hleft)
		p->height = hright + 1;
}

Node* rotateRight(Node* p) { // right rotation around node [p]
	Node* newRoot = p->left;
	p->left = newRoot->right;
	newRoot->right = p;
	fixHeight(p);
	fixHeight(newRoot);
	return newRoot;
}

Node* rotateLeft(Node* p) { // left rotation around node [p]
	Node* newRoot = p->right;
	p->right = newRoot->left;
	newRoot->left = p;
	fixHeight(p);
	fixHeight(newRoot);
	return newRoot;
}

Node* balance(Node* p) { // balancing node [p]
	fixHeight(p);
	if (bfactor(p) == 2) {
		if (bfactor(p->right) < 0)
				p->right = rotateRight(p->right);
		return rotateLeft(p);
	}
	if (bfactor(p) == -2) {
		if (bfactor(p->left) > 0)
				p->left = rotateLeft(p->left);
		return rotateRight(p);
	}
	return p; // case if balancing isn't necessary
}

Node* add(Node* p, int k, string inf = "") { // searching the right place and inserting the node
	if (!p) return new Node(k, inf);
	if (k < p->key)
		p->left = add(p->left, k, inf);
	else if (k > p->key)
		p->right = add(p->right, k, inf);
	return balance(p);
}

Node* findMin(Node* p) { // help function to find the minimal node in [p] tree
	if (p->left)
		return findMin(p->left);
	return p;
}

Node* removeMin(Node* p) { // help function to delete the node with minimal key in [p] tree
	if (p->left == NULL)
		return p->right;
	p->left = removeMin(p->left);
	return balance(p);
}

Node* remove(Node* p, int k) { // deleting [k] key from the [p] tree
	if (!p) return 0;
	if (k < p->key)
		p->left = remove(p->left, k);
	else if (k > p->key)
		p->right = remove(p->right, k);
	else if (k == p->key) { // if there are both right and left nodes: 
		Node* left = p->left; // - search for the minimal node in the right node and save pointer [*min] to it (using the [findMin()] funtion)
		Node* right = p->right; // - delete the minimal node in the right node (using the [removeMin()] funtion)
		delete p;               // - make that node a new root of our subtree, using the saved pointer [*min]
		if (!right)             // - return it as a new root.
			return left;
		Node* min = findMin(right);
		min->right = removeMin(right);
		min->left = left;
		return balance(min);
	}
	return balance(p);
}

void find(Node* p, int key) {
	if (!p) {
		cout << "There isn't such value in the tree!" << endl;
		return;
	}
	if (key < p->key)
		find(p->left, key);
	if (key > p->key)
		find(p->right, key);
	if (key == p->key) {
		cout << to_string(p->key) + " " + p->info << endl;
		return;
	}
}

void view(Node* p, int level) { // horizontal printing of the tree
	if (p) {
		view(p->right, level + 5);	
		for (int i = 0; i < level; i++) cout << " ";
		cout << to_string(p->key) + " " + p->info << endl;
		view(p->left, level + 5); 
	}
}

void viewPreOrder(Node* p) { // Print -> Left subtree -> Right subtree.
	if (p) {
		cout << to_string(p->key) + " - " + p->info + '\n';
		viewPreOrder(p->left);
		viewPreOrder(p->right);
	}
}

void viewPostOrder(Node* p) { // Left subtree -> Right subtree -> Print.
	if (p) {
		viewPostOrder(p->left);
		viewPostOrder(p->right);
		cout << to_string(p->key) + " - " + p->info + '\n';
	}
}

void viewInOrder(Node* p) { // Left subtree -> Print -> Right subtree (sorted view in a binary search tree)
	if (p) {
		viewInOrder(p->left);
		cout << to_string(p->key) + " - " + p->info + '\n';
		viewInOrder(p->right);
	}
}

Node* removeMax(Node* p) { // deleting the node with the max value from the tree
	if (p->right == NULL)
		return p->left;
	p->right = removeMax(p->right);
	return balance(p);
}

int main() {
	srand(time(NULL));
	Node* root = NULL;
	while (true) {
		view(root, 0);
		cout << " \n 1 - Fill up the tree, \n 2 - find the key in the tree, \n 3 - delete the key from the tree, \n 4 - print info, \n 5 - task,  6 - exit: ";
		int option;
		cin >> option;
		switch (option) {
		case 1:
		{
			system("cls");
			int option;
			cout << "1 - Fill up the tree with random numbers, \n 2 - Enter numbers: ";
			cin >> option;
			if (option == 1) {
				int n;
				cout << "\n Enter the number of keys: ";
				cin >> n;
				for (int i = 0; i < n; i++)
					root = add(root, rand() % 30);
			}
			else {
				int n;
				cout << " \n How many keys do you want to add? ";
				cin >> n;
				for (int i = 0; i < n; i++) {
					int num;
					string inf;
					system("cls");
					cout << "Enter the key value: ";
					cin >> num;
					cout << "Enter the information: ";
					cin >> inf;
					root = add(root, num, inf);
				}
			}
			break;
		}
		case 2:
		{
			int fkey;
			cout << "Enter the value for search :";
			cin >> fkey;
			find(root, fkey);
			system("pause");
			break;
		}
		case 3:
		{
			int dkey;
			cout << "Enter the value to delete :";
			cin >> dkey;
			system("cls");
			cout << "Old tree: " << endl;
			view(root, 0);
			root = remove(root, dkey);
			cout << "New tree: " << endl;
			view(root, 0);
			system("pause");
			break;
		}
		case 4:
		{
			int opt;
			cout << "1 - Pre-order (NLR), \n 2 - Post-order (LNR), \n 3 - In-order(LRN) " << endl;
			cout << "Choose printing mode: ";
			cin >> opt;
			if (opt == 1) {
				viewPreOrder(root);
				system("pause");
			}
			else if (opt == 2) {
				viewPostOrder(root);
				system("pause");
			}
			else if (opt == 3) {
				viewInOrder(root);
				system("pause");
			}

			break;
		}
		case 5: 
		{
			if (!root->left) {
				cout << "There isn't a left branch in the tree!" << endl;
				system("pause");
				break;
			}

			cout << "Old tree: " << endl;
			view(root, 0);
			root->left = removeMax(root->left);
			root = balance(root);
			cout << "New tree: " << endl;
			view(root, 0);
			system("pause");
			break;
		}
		case 6:
		{
			return 0;
			break;
		}
		}
		system("cls");
	}
}