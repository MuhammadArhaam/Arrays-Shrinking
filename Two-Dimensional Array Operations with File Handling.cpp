#include <iostream>
#include <fstream>
using namespace std;
void saveToFile(const char* filename, int** arr, int rows, int cols)
{
    ofstream fout(filename);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            fout << arr[i][j] << " ";
        }
        fout << "\n";
    }
    fout.close();
}
void displayArray(int** arr, int rows, int cols)
{
    cout << endl;
    cout << "Current Array = " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int* getNewRow(int cols)
{
    int* newRow = new int[cols];
    cout << "Enter " << cols << " values = ";
    for (int i = 0; i < cols; i++)
    {
        cin >> newRow[i];
    }
    return newRow;
}
void addRowFront(int**& arr, int& rows, int cols)
{
    int** temp = new int* [rows + 1];
    temp[0] = getNewRow(cols);
    for (int i = 0; i < rows; i++)
    {
        temp[i + 1] = arr[i];
    }
    delete[] arr;
    arr = temp;
    rows++;
}
void addRowEnd(int**& arr, int& rows, int cols)
{
    int** temp = new int* [rows + 1];
    for (int i = 0; i < rows; i++)
    {
        temp[i] = arr[i];
    }
    temp[rows] = getNewRow(cols);
    delete[] arr;
    arr = temp;
    rows++;
}
void addRowAt(int**& arr, int& rows, int cols, int pos)
{
    if (pos < 0 || pos > rows)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    int** temp = new int* [rows + 1];
    for (int i = 0; i < pos; i++)
    {
        temp[i] = arr[i];
    }
    temp[pos] = getNewRow(cols);
    for (int i = pos; i < rows; i++)
    {
        temp[i + 1] = arr[i];
    }
    delete[] arr;
    arr = temp;
    rows++;
}
void removeFront(int**& arr, int& rows)
{
    if (rows <= 0)
    {
        return;
    }
    delete[] arr[0];
    for (int i = 0; i < rows - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    rows--;
}
void removeEnd(int**& arr, int& rows)
{
    if (rows <= 0)
    {
        return;
    }
    delete[] arr[rows - 1];
    rows--;
}
void removeAt(int**& arr, int& rows, int pos)
{
    if (pos < 0 || pos >= rows)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    delete[] arr[pos];
    for (int i = pos; i < rows - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    rows--;
}
int main()
{
    int rows, cols;
    cout << "Enter number of rows and columns = ";
    cin >> rows >> cols;

    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
        cout << "Row " << i << ": ";
        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }
    saveToFile("original_array.txt", arr, rows, cols);
    int choice, pos;
    do
    {
        cout << endl;
        cout << "------Menu------" << endl;
        cout << "1. Add row at front" << endl;
        cout << "2. Add row at end" << endl;
        cout << "3. Add row at position" << endl;
        cout << "4. Remove row from front" << endl;
        cout << "5. Remove row from end" << endl;
        cout << "6. Remove row at position" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice = ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            addRowFront(arr, rows, cols);
            break;
        }
        case 2:
        {
            addRowEnd(arr, rows, cols);
            break;
        }
        case 3:
        {
            cout << "Enter position: ";
            cin >> pos;
            addRowAt(arr, rows, cols, pos);
            break;
        }
        case 4:
        {
            removeFront(arr, rows);
            break;
        }
        case 5:
        {
            removeEnd(arr, rows);
            break;
        }
        case 6:
        {
            cout << "Enter position = ";
            cin >> pos;
            removeAt(arr, rows, pos);
            break;
        }
        case 0:
        {
            cout << "Exiting the program" << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice!" << endl;
        }
        }
        saveToFile("updated_array.txt", arr, rows, cols);
        displayArray(arr, rows, cols);

    } while (choice != 0);
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
