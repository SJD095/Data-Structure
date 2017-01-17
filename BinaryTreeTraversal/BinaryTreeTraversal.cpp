#include <iostream>

using namespace std;

class Node
{
    public:
        Node* leftNode;
        Node* rightNode;
        int key;
};

bool insert(Node* &treeNode, int key)
{
    if(!treeNode)
    {
        Node* tmp = new Node();
        tmp -> key = key;
        treeNode = tmp;

        return true;
    }

    if(key < treeNode -> key)
    {
        return insert(treeNode -> leftNode, key);
    }
    else if(key > treeNode -> key)
    {
        return insert(treeNode -> rightNode, key);
    }
    else
    {
        return false;
    }
}

Node* createTree(int* array, int num)
{
    Node* tree = NULL;

    for(int i = 0; i < num; i++)
    {
        insert(tree, array[i]);
    }

    return tree;
}

void preTraverse(Node* node)
{
    if(node)
    {
        cout << node -> key << " ";
        preTraverse(node -> leftNode);
        preTraverse(node -> rightNode);
    }
}

void inTraverse(Node* node)
{
    if(node)
    {
        inTraverse(node -> leftNode);
        cout << node -> key << " ";
        inTraverse(node -> rightNode);
    }
}

void behTraverse(Node* node)
{
    if(node)
    {
        behTraverse(node -> leftNode);
        behTraverse(node -> rightNode);
        cout << node -> key << " ";
    }
}

int main()
{
    int num = 0;
    cout << "请输入节点的个数: ";
    cin >> num;

    int array[num];

    for(int i = 0; i < num; i++)
    {
        cin >> array[i];
    }

    Node* BSTree = createTree(array, num);

    cout << "前序遍历结果： " << endl;
    preTraverse(BSTree);
    cout << endl;

    cout << "中序遍历结果： " << endl;
    inTraverse(BSTree);
    cout << endl;

    cout << "后序遍历结果： " << endl;
    behTraverse(BSTree);
    cout << endl;
}
