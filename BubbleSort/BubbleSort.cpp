#include <iostream>

using namespace std;

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void BubbleSort(int* array, int num)
{
    for(int i = num - 1; i >= 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(array[j] < array[j + 1])
            {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

int main()
{
    int num = 0;
    cout << "请输入排序的个数: ";
    cin >> num;

    int array[num];

    for(int i = 0; i < num; i++)
    {
        cin >> array[i];
    }

    BubbleSort(array, num);

    for(auto &i: array)
    {
        cout << i << " ";
    }

    cout << endl;
}
