#include <iostream>

using namespace std;

class Node
{
    public:
        Node* leftNode;
        Node* rightNode;
        int key = 0;
};

void inTraverse(Node* BSTree)
{
    if(!BSTree)
    {
        return;
    }

    inTraverse(BSTree -> leftNode);
    cout << BSTree -> key << " ";
    inTraverse(BSTree -> rightNode);
}

bool insert(Node* &BSTree, int key)
{
    if(!BSTree)
    {
        Node* tmp = new Node();
        tmp -> key = key;

        BSTree = tmp;

        return true;
    }

    if(key < BSTree -> key)
    {
        return insert(BSTree -> leftNode, key);
    }
    else if(key > BSTree -> key)
    {
        return insert(BSTree -> rightNode, key);
    }
    else
    {
        return false;
    }
}

bool search(Node* BSTree, int key)
{
    if(!BSTree)
    {
        return false;
    }

    if(key < BSTree -> key)
    {
        return search(BSTree -> leftNode, key);
    }
    else if(key > BSTree -> key)
    {
        return search(BSTree -> rightNode, key);
    }
    else
    {
        return true;
    }
}

void deleteNode(Node* &treeNode, int key)
{
    if(!treeNode -> leftNode)
    {
        Node* p = treeNode;
        treeNode = treeNode -> rightNode;
        delete p;
    }
    else if(!treeNode -> rightNode)
    {
        Node* p = treeNode;
        treeNode = treeNode -> leftNode;
        delete p;
    }
    else
    {
        Node* tmp = treeNode -> leftNode;
        while(tmp -> rightNode)
        {
            tmp = tmp -> rightNode;
        }

        tmp -> rightNode = treeNode -> rightNode;
        Node* p = treeNode;
        treeNode = treeNode -> leftNode;

        delete p;
    }
}

bool deleteSpecific(Node* &BSTree, int key)
{
    if(!search(BSTree, key))
    {
        return false;
    }

    else
    {
        if(key < BSTree -> key)
        {
            return deleteSpecific(BSTree -> leftNode, key);
        }
        else if(key > BSTree -> key)
        {
            return deleteSpecific(BSTree -> rightNode, key);
        }
        else
        {
            deleteNode(BSTree, key);
            return true;
        }
    }
}

Node* createTree(int* array, int num)
{
    Node* BSTree = NULL;

    for(int i = 0; i < num; i++)
    {
        insert(BSTree, array[i]);
    }

    return BSTree;
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

    cout << "中序遍历结果： " << endl;
    inTraverse(BSTree);

    cout << endl;

    int key = 0;
    cout << "请输入要查找的整数: ";
    cin >> key;

    if(search(BSTree, key))
    {
        cout << "查找成功" << endl;
    }
    else
    {
        cout << "查找失败" << endl;
    }

    cout << "请输入要插入的整数: ";
    cin >> key;

    if(insert(BSTree, key))
    {
        cout << "插入成功" << endl;
        inTraverse(BSTree);
        cout << endl;
    }
    else
    {
        cout << "插入失败" << endl;
    }

    cout << "请输入要删除的整数: ";
    cin >> key;

    if(deleteSpecific(BSTree, key))
    {
        cout << "删除成功" << endl;
        inTraverse(BSTree);
        cout << endl;
    }
    else
    {
        cout << "删除失败" << endl;
    }
}
