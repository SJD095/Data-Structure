#include <iostream>

using namespace std;

void CountSort(int* array, int num, int range)
{
    int result[range];

    for(int i = 0; i < range; i++)
    {
        result[i] = 0;
    }

    for(int i = 0; i < num; i++)
    {
        result[array[i]]++;
    }

    for(int i = range - 1, j = 0; i >= 0; i--)
    {
        if(result[i] != 0)
        {
            array[j] = i;
            j++;
        }
    }
}

int main()
{
    int num = 0;
    cout << "请输入排序的个数: ";
    cin >> num;

    int range = 0;
    cout << "请输入范围: ";
    cin >> range;

    int array[num];

    for(int i = 0; i < num; i++)
    {
        cin >> array[i];
    }

    CountSort(array, num, range);

    for(auto &i: array)
    {
        cout << i << " ";
    }

    cout << endl;
}
