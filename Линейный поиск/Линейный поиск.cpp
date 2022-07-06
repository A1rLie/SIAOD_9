#include <iostream>
#include <time.h>
#include <string>

using namespace std;

struct universitySpecialization
{
    long long code;
    string name;
};

int lineSearch(int key, universitySpecialization* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i].code == key) return i;
    }
    return -1;
}

int modificatedLineSearch(int key, universitySpecialization* array, int size)
{
    array[size].code = key;
    int i = 0;
    while (array[i].code != key)
    {
        i++;
    }
    return i;
}

int InterpolSearch(universitySpecialization* array, int key, int size)
{
    int mid, left = 0, right = size - 1;
    while (array[left].code <= key && array[right].code >= key)
    {
        mid = left + ((key - array[left].code) * (right - left)) / (array[right].code - array[left].code);
        if (array[mid].code < key) left = mid + 1;
        else if (array[mid].code > key) right = mid - 1;
        else return mid;
    }
    if (array[left].code == key) return left;
    else return -1;
}

int interpolationSearch(int key, universitySpecialization* array, int size)
{
    int leftIndex = 0;
    int rightIndex = size - 1;
    int count = 0;
    int newIndex = 0;
    while (leftIndex <= rightIndex)
    {
        count++;  
        newIndex = (key - leftIndex) * (rightIndex - leftIndex) / (array[rightIndex].code - array[leftIndex].code) + leftIndex;

        if (newIndex < leftIndex || newIndex > rightIndex) break;

        if (array[newIndex].code == key)
        {
            count++;
            cout << endl << "Операций " << count << endl;
            return newIndex;
        }
        else if (array[newIndex].code < key)
        {
            count++;
            leftIndex = newIndex + 1; 
        }
        else
        {
            count++;
            rightIndex = newIndex - 1;
        }
    }
    cout << endl  << "Операций " << count << endl;
    return -1;
}

int main()
{
    system("chcp 1251 > null");
    int size = 1000000;
    universitySpecialization* arr = new universitySpecialization[size + 1];
    cout << "Заполнение кодов специальностей университета соответственно: " << endl;
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        arr[i].name = "University_" + to_string(i + 1);
        arr[i].code = i + 1;
    }


    cout << "Искомый элемент >> ";
    int key;
    cin >> key;
    int index = interpolationSearch(key, arr, size);
    if (index == -1) cout << "Индекс ключа: " << -1;
    else cout << "Индекс ключа: " << index << ", название университета: " << arr[index].name;
   
   
    //cout << modificatedLineSearch(key, arr, size) << endl;
    
    return 1;
}
