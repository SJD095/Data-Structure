#include <iostream>

using namespace std;

void InsertSort(int* array, int num)
{
    for(int i = 1; i < num; i++)
    {
        if(array[i] > array[i - 1])
        {
            int tmp = array[i], j = i - 1;

            for(; array[j] < tmp && j >= 0; j--)
            {
                array[j + 1] = array[j];
            }

            array[j + 1] = tmp;
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

    InsertSort(array, num);

    for(auto &i: array)
    {
        cout << i << " ";
    }

    cout << endl;
}
