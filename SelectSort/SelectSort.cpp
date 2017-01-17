#include <iostream>

using namespace std;

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void SelectSort(int* array, int num)
{
    for(int i = 0; i < num - 1; i++)
    {
        int max = 0, maxPosition = 0;

        for(int j = i; j < num; j++)
        {
            if(array[j] > max)
            {
                max = array[j];
                maxPosition = j;
            }
        }

        swap(array[i], array[maxPosition]);
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

    SelectSort(array, num);

    for(auto &i: array)
    {
        cout << i << " ";
    }

    cout << endl;
}
