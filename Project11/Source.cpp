#include<iostream>
#include<exception>
#include<queue>
using namespace std;
struct Node
{
	Node(int el) :data(el) {}
	Node* right = NULL;
	Node* left = NULL;
	int data;
};
void add(Node*, int);
void print(Node*);


int main()
{
	Node* root = new Node(64);

	root->left = new Node(22);
	root->left->left = new Node(17);
	root->left->right = new Node(37);
	root->left->right->right = new Node(54);
	root->left->right->left = new Node(23);
	root->left->right->left->right = new Node(35);

	root->right = new Node(112);
	root->right->right = new Node(114);
	root->right->left = new Node(72);

	print(root);
}
void print(Node* root)
{
	queue<pair<Node*,int>* > q;

	q.push(new pair<Node*,int>(root, 0));
	while (!q.empty())
	{
		//извлекаем элемент

		pair<Node*, int>* r = NULL;
		r = q.front();
		q.pop();
		//обрабатываем элемент
		if (r->first == NULL) continue;
		cout << r->first->data <<"-"<<r->second<< " ";

		//добавляем прямых потомков элемента в очередь
		q.push(new pair<Node*,int>(r->first->left,r->second+1));
		q.push(new pair<Node*, int>(r->first->right, r->second + 1));
		
		

	}
}
