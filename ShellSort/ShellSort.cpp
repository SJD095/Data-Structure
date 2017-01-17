#include <iostream>

using namespace std;

void InsertSort(int* array, int num, int len)
{
    for(int i = len; i < num; i++)
    {
        if(array[i] > array[i - len])
        {
            int tmp = array[i], j = i - len;

            for(; array[j] < tmp && j >= 0; j -= len)
            {
                array[j + len] = array[j];
            }

            array[j + len] = tmp;
        }
    }
}

void ShellSort(int* array, int num)
{
    for(int i = num / 2; i >= 1; i /= 2)
    {
        InsertSort(array, num, i);
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

    ShellSort(array, num);

    for(auto &i: array)
    {
        cout << i << " ";
    }

    cout << endl;
}
