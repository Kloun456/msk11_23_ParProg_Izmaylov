#include <iostream>
#include <fstream>
#include <string>


using namespace std;


int* dinamicArray(int& n)
{
    int *arr;

    cout << "Введите размер массива: ";
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = i;
    return arr;
}

void printArrayRange(int *arr, int n)
{
    int a = -1, b = 0;
    while (a < 0 || a > n)
    {
        cout << "Введите начальную границу диапозона: ";
        cin >> a;
        if (a < 0 || a > n)
            cout << "\nВы ввели недопустимую начальную границу\n";
    }
    b = a;
    do
    {
        cout << "Введите конечную границу диапозона: ";
        cin >> b;
        if (b < a || b > n)
            cout << "\nВы ввели недопустимую конечную границу\n";

    } while (b < a || b > n);
    cout << "\nМассив в диапозоне от " << a << " до " << b << " :\n";
    for (int i = a; i < b; i++)
        cout << arr[i] << endl;
}

void saveArrayInFile(int *arr, int n)
{
    ofstream file;
    file.open("binary.txt", ios::out | ios::binary);
    for (int i = 0; i < n; i++)
    {
        file.write((char*)&arr[i], sizeof arr[i]);
    }
    file.close();
}

void printArrayOutFile(int n)
{
    ifstream file;
    int* arr = new int[n];
    file.open("binary.txt", ios::in | ios::binary);

    cout << "\nМассив:\n";
    for (int i = 0; i < n; i++)
    {
        file.read((char*)&arr[i], sizeof arr[i]);
        cout << arr[i] << endl;
    }
    file.close();
    
}

void funcFile()
{
    ifstream file;
    file.open("comp_system.txt", ios_base::in);
    string str;
    while (getline(file, str))
    {
        cout << str << endl;
    }
    file.close();
}

int main()
{
    setlocale(0, "");
    int n, *arr;
    arr = dinamicArray(n);
    //printArrayRange(arr, n);
    saveArrayInFile(arr, n);
    printArrayOutFile(n);
}
