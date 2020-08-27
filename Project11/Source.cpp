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
int dfs(Node* n, int value);

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
	add(root, 5);
	add(root, 4);
	add(root, 3);
	add(root, 6666666);
	add(root, 17);

	print(root);
}
void print(Node* root)
{
	struct St
	{
		Node* n;
		int vert_level, horizont_level;
		St(Node* n, int v_l, int h_l) :vert_level(v_l), horizont_level(h_l)
		{
			this->n = n;
		}
	};
	int root_level = dfs(root, 0);
	queue<St*> q;

	q.push(new St(root, 0, root_level));
	pair<int, int> prev;
	prev.first = 0;
	prev.second = 0;

	while (!q.empty())
	{
		//извлекаем элемент

		St* r = NULL;
		r = q.front();
		q.pop();
		//обрабатываем элемент
		if (r->n == NULL) continue;

		if (r->vert_level != prev.first)
		{
			cout << endl;
			prev.second = 0;
		}
		for (int i = 0; i < r->horizont_level - prev.second; i++) cout << "\t";
		cout << r->n->data << " ";

		prev.first = r->vert_level;
		prev.second = r->horizont_level;
		//добавляем прямых потомков элемента в очередь
		q.push(new St(r->n->left, r->vert_level + 1, r->horizont_level - 1));
		q.push(new St(r->n->right, r->vert_level + 1, r->horizont_level + 1));


	}

}
int dfs(Node* n, int value)
{
	if (n == NULL) return value;
	return max(dfs(n->left, value + 1), dfs(n->right, value - 1));
}
void add(Node* root, int value)
{
	Node* node = root;
	while (1)
	{
		if (value == node->data) return;

		if (value < node->data)
		{
			if (node->left == NULL)
			{
				node->left = new Node(value);
				return;
			}
			node = node->left;
		}
		if (value > node->data)
		{

			if (node->right == NULL)
			{
				node->right = new Node(value);
				return;
			}
			node = node->right;
		}
	}
}