#include <iostream>

using namespace std;

void Merge(int* array, int start, int end, int mid)
{
    int tmpArrayOne[mid - start + 1], tmpArrayTwo[end - mid];

    for(int i = 0; i < mid - start + 1; i++)
    {
        tmpArrayOne[i] = array[start + i];
    }

    for(int i = 0; i < end - mid; i++)
    {
        tmpArrayTwo[i] = array[mid + i + 1];
    }

    int countOne = 0, countTwo = 0;

    for(int i = 0; i < end - start + 1; i++)
    {
        if(countOne >= mid - start + 1 && countTwo < end - mid)
        {
            array[start + i] = tmpArrayTwo[countTwo];
            countTwo++;
        }
        else if(countTwo >= end - mid && countOne < mid - start + 1)
        {
            array[start + i] = tmpArrayOne[countOne];
            countOne++;
        }
        else if(tmpArrayOne[countOne] > tmpArrayTwo[countTwo])
        {
            array[start + i] = tmpArrayOne[countOne];
            countOne++;
        }
        else
        {
            array[start + i] = tmpArrayTwo[countTwo];
            countTwo++;
        }
    }

}

void M_Sort(int* array, int start, int end)
{
    if(start < end)
    {
        int mid = (start + end) / 2;
        M_Sort(array, start, mid);
        M_Sort(array, mid + 1, end);
        Merge(array, start, end, mid);
    }
}

void MergeSort(int* array, int num)
{
    M_Sort(array, 0, num - 1);
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

    MergeSort(array, num);

    for(auto &i: array)
    {
        cout << i << " ";
    }

    cout << endl;
}
