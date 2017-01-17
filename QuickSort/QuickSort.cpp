#include <iostream>

using namespace std;

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int findPosition(int* array, int low, int high)
{
    int pivot = array[low];

    int i = low + 1, j = high;

    while(i <= j)
    {
        while(array[i] >= pivot && i <= high)
        {
            i++;
        }

        while(array[j] < pivot && j >= low)
        {
            j--;
        }

        if(i < j)
        {
            swap(array[i], array[j]);
        }
    }

    swap(array[low], array[j]);

    return j;
}

void QuickSort(int* array, int low, int high)
{
    if(low < high)
    {
        int position = findPosition(array, low, high);

        QuickSort(array, low, position - 1);
        QuickSort(array, position + 1, high);
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

    QuickSort(array, 0, num - 1);

    for(auto &i: array)
    {
        cout << i << " ";
    }

    cout << endl;
}
