#include <iostream>
#include <fstream>
using namespace std;
void writeToFile(const char* filename, int* arr, int size)
{
    ofstream file(filename);
    for (int i = 0; i < size; i++)
    {
        file << arr[i] << " ";
    }
    file.close();
}
void growFromFront(int*& arr, int& size, int value) 
{
    int* newArr = new int[size + 1];
    newArr[0] = value;
    for (int i = 0; i < size; i++) 
    {
        newArr[i + 1] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size++;
}
void growFromEnd(int*& arr, int& size, int value)
{
    int* newArr = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        newArr[i] = arr[i];
    }
    newArr[size] = value;
    delete[] arr;
    arr = newArr;
    size++;
}
void growAtPosition(int*& arr, int& size, int value, int pos)
{
    if (pos < 0 || pos > size) 
    {
        cout << "Invalid position!" << endl;
        return;
    }
    int* newArr = new int[size + 1];
    for (int i = 0; i < pos; i++)
    {
        newArr[i] = arr[i];
    }
    newArr[pos] = value;
    for (int i = pos; i < size; i++) 
    {
        newArr[i + 1] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size++;
}
void shrinkFromFront(int*& arr, int& size)
{
    if (size <= 0)
    {
        cout << "Array is already empty!" << endl;
        return;
    }
    int* newArr = new int[size - 1];
    for (int i = 1; i < size; i++) 
    {
        newArr[i - 1] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size--;
}
void shrinkFromEnd(int*& arr, int& size) 
{
    if (size <= 0)
    {
        cout << "Array is already empty!" << endl;
        return;
    }
    int* newArr = new int[size - 1];
    for (int i = 0; i < size - 1; i++)
    {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size--;
}
void shrinkAtPosition(int*& arr, int& size, int pos)
{
    if (pos < 0 || pos >= size)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    int* newArr = new int[size - 1];
    for (int i = 0; i < pos; i++)
    {
        newArr[i] = arr[i];
    }
    for (int i = pos + 1; i < size; i++)
    {
        newArr[i - 1] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size--;
}
void displayArray(int* arr, int size)
{
    cout << "Array = ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int* arr;
    int size;
    cout << "Enter size of array = ";
    cin >> size;
    arr = new int[size];
    cout << "Enter elements = ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    writeToFile("original_array.txt", arr, size);
    int choice, value, pos;
    do
    {
        cout << endl;
        cout << "------Menu------" << endl;
        cout << "1. Grow from Front" << endl;
        cout << "2. Grow from End" << endl;
        cout << "3. Grow at Position" << endl;
        cout << "4. Shrink from Front" << endl;
        cout << "5. Shrink from End" << endl;
        cout << "6. Shrink at Position" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice = ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter value to insert at front = ";
            cin >> value;
            growFromFront(arr, size, value);
            break;
        }
        case 2:
        {
            cout << "Enter value to insert at end = ";
            cin >> value;
            growFromEnd(arr, size, value);
            break;
        }
        case 3:
        {
            cout << "Enter value and position to insert =  ";
            cin >> value >> pos;
            growAtPosition(arr, size, value, pos);
            break;
        }
        case 4:
        {
            shrinkFromFront(arr, size);
            break;
        }
        case 5:
        {
            shrinkFromEnd(arr, size);
            break;
        }
        case 6:
        {
            cout << "Enter position to remove = ";
            cin >> pos;
            shrinkAtPosition(arr, size, pos);
            break;
        }
        case 0:
        {
            cout << "Exiting program" << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice!" << endl;
        }
        }
        writeToFile("updated_array.txt", arr, size);
        displayArray(arr, size);
    } while (choice != 0);
    delete[] arr; 
    return 0;
}
