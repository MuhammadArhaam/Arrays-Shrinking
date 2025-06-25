#include <iostream>
#include <fstream>
using namespace std;
int* inputRow(int& cols)
{
    cout << "Enter number of columns for the row = ";
    cin >> cols;
    int* row = new int[cols];
    cout << "Enter " << cols << " values = ";
    for (int i = 0; i < cols; i++)
    {
        cin >> row[i];
    }
    return row;
}
void saveToFile(const char* filename, int** arr, int* colSizes, int rows)
{
    ofstream fout(filename);
    for (int i = 0; i < rows; i++)
    {
        fout << colSizes[i] << " ";
        for (int j = 0; j < colSizes[i]; j++)
        {
            fout << arr[i][j] << " ";
        }
        fout << endl;
    }
    fout.close();
}
void displayJaggedArray(int** arr, int* colSizes, int rows)
{
    cout << endl;
    cout << "Current Jagged Array = " << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "Row " << i << " = ";
        for (int j = 0; j < colSizes[i]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void addFront(int**& arr, int*& colSizes, int& rows)
{
    int cols;
    int* newRow = inputRow(cols);
    int** tempArr = new int* [rows + 1];
    int* tempCols = new int[rows + 1];
    tempArr[0] = newRow;
    tempCols[0] = cols;
    for (int i = 0; i < rows; i++)
    {
        tempArr[i + 1] = arr[i];
        tempCols[i + 1] = colSizes[i];
    }
    delete[] arr;
    delete[] colSizes;
    arr = tempArr;
    colSizes = tempCols;
    rows++;
}
void addEnd(int**& arr, int*& colSizes, int& rows)
{
    int cols;
    int* newRow = inputRow(cols);
    int** tempArr = new int* [rows + 1];
    int* tempCols = new int[rows + 1];
    for (int i = 0; i < rows; i++)
    {
        tempArr[i] = arr[i];
        tempCols[i] = colSizes[i];
    }
    tempArr[rows] = newRow;
    tempCols[rows] = cols;
    delete[] arr;
    delete[] colSizes;
    arr = tempArr;
    colSizes = tempCols;
    rows++;
}
void addAtPosition(int**& arr, int*& colSizes, int& rows, int pos)
{
    if (pos < 0 || pos > rows)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    int cols;
    int* newRow = inputRow(cols);
    int** tempArr = new int* [rows + 1];
    int* tempCols = new int[rows + 1];
    for (int i = 0; i < pos; i++)
    {
        tempArr[i] = arr[i];
        tempCols[i] = colSizes[i];
    }
    tempArr[pos] = newRow;
    tempCols[pos] = cols;
    for (int i = pos; i < rows; i++)
    {
        tempArr[i + 1] = arr[i];
        tempCols[i + 1] = colSizes[i];
    }
    delete[] arr;
    delete[] colSizes;
    arr = tempArr;
    colSizes = tempCols;
    rows++;
}
void removeFront(int**& arr, int*& colSizes, int& rows)
{
    if (rows <= 0)
    {
        return;
    }
    delete[] arr[0];
    for (int i = 0; i < rows - 1; i++)
    {
        arr[i] = arr[i + 1];
        colSizes[i] = colSizes[i + 1];
    }
    rows--;
}
void removeEnd(int**& arr, int*& colSizes, int& rows)
{
    if (rows <= 0)
    {
        return;
    }
    delete[] arr[rows - 1];
    rows--;
}
void removeAtPosition(int**& arr, int*& colSizes, int& rows, int pos)
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
        colSizes[i] = colSizes[i + 1];
    }
    rows--;
}
int main()
{
    int rows;
    cout << "Enter number of rows = ";
    cin >> rows;
    int** jagged = new int* [rows];
    int* colSizes = new int[rows];
    for (int i = 0; i < rows; i++)
    {
        cout << "For row " << i << endl;
        jagged[i] = inputRow(colSizes[i]);
    }
    saveToFile("original_jagged_array.txt", jagged, colSizes, rows);
    displayJaggedArray(jagged, colSizes, rows);
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
            addFront(jagged, colSizes, rows);
            break;
        }
        case 2:
        {
            addEnd(jagged, colSizes, rows);
            break;
        }
        case 3:
        {
            cout << "Enter position = ";
            cin >> pos;
            addAtPosition(jagged, colSizes, rows, pos);
            break;
        }
        case 4:
        {
            removeFront(jagged, colSizes, rows);
            break;
        }
        case 5:
        {
            removeEnd(jagged, colSizes, rows);
            break;
        }
        case 6:
        {
            cout << "Enter position = ";
            cin >> pos;
            removeAtPosition(jagged, colSizes, rows, pos);
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
        saveToFile("updated_jagged_array.txt", jagged, colSizes, rows);
        displayJaggedArray(jagged, colSizes, rows);
    } while (choice != 0);
    for (int i = 0; i < rows; i++)
    {
        delete[] jagged[i];
    }
    delete[] jagged;
    delete[] colSizes;
    return 0;
}
