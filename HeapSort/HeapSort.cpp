#include <iostream>

using namespace std;

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Heap(int* array, int start, int end)
{
    int tmp = array[start];

    int position = 2 * start + 1;

    while(position <= end)
    {
        if(position + 1 < end && array[position + 1] < array[position])
        {
            position++;
        }

        if(array[position] > tmp)
        {
            break;
        }

        array[start] = array[position];
        start = position;
        position = 2 * start + 1;
    }

    array[start] = tmp;
}

void HeapSort(int* array, int num)
{
    for(int i = num / 2 - 1; i >= 0; i--)
    {
        Heap(array, i, num - 1);
    }

    for(int i = num - 1; i > 0; i--)
    {
        swap(array[i], array[0]);
        Heap(array, 0, i - 1);
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

    HeapSort(array, num);

    for(auto &i: array)
    {
        cout << i << " ";
    }

    cout << endl;
}
