#define M 7

#include <iostream>

using namespace std;

class Node
{
    public:
        Node* next;
        int data;
};

class HashNode
{
    public:
        Node* first = NULL;
};

HashNode* createTable(int len)
{
    HashNode hashTalbe[len];
    return hashTalbe;
}

bool insertHashTable(HashNode* hashTalbe, int data)
{
    if(searchHashTable(hashTalbe, data))
    {
        return false;
    }

    Node* newNode = new Node();
    newNode -> data = data;

    Node* hashNode = hashTalbe[data % M].first;

    if(!hashNode)
    {
        hashNode = newNode;
        return true;
    }

    while(hashNode -> next != NULL)
    {
        hashNode = hashNode -> next;
    }

    hashNode -> next = newNode;
    return true;
}

bool searchHashTable(HashNode* hashTalbe, )

int main()
{
    int len = 0;
    cout << "请输入哈希表的槽数: ";
    cin >> len;

    HashNode* hashTalbe= createTable(len);

    int num = 0;
    cout << "请输入要插入的数字: ";
    cin >> num;

    for(int i = 0; i < num; i++)
    {
        int tmp = 0;
        cin >> tmp;

        insertHashTable(hashTable, tmp);
    }

    cout << "请输入要查找的数字: ";
    cin >> num;

    if(searchHashTable(hashTable, num))
    {
        cout << "查找成功" << endl;
    }
    else
    {
        cout << "查找失败" << endl;
    }

    cout << "请输入要删除的数字: ";
    cin >> num;

    if(deleteHashTable(hashTable, num))
    {
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "删除失败" << endl;
    }

    deleteTable(hashTable);
}
