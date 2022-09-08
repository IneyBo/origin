#include <iostream>
#include <fstream>

int* createArr(std::ifstream& fin) // �������� ������� �� ��������� ������ �����
{
    int size = 0;

    fin >> size;
    size++;
    int* arr = new int[size];
    arr[0] = size; // ����� ������� ������ ������� � ������ ��� ��������. �� ���� ��������� ��, �� �������� �������� � ������� �������� ������� � �� �������� ������ ���������� � �����. �������� �� ��� ������, ���� �������� � �������� ����� ����� ���� �� ������ ���, � ����� ����������.

    for (int i = 1; i < size; i++)
    {
        fin >> arr[i];
    }

    return arr;
}

int main()
{
    std::string fileIn = "in.txt", fileOut = "out.txt";
    std::ifstream fin(fileIn);

    if (!fin.is_open())
    {
        std::cout << "�� ������� ������� ����" << std::endl;
    }
    else
    {
        int* arr1 = createArr(fin);
        int* arr2 = createArr(fin);

        fin.close();

        std::ofstream fout(fileOut);

        // ����� �������, ������� ��� ������ � �������� �����
        fout << arr2[0] - 1 << std::endl; // ����� ���������� ��������� �������
        fout << arr2[arr2[0] - 1]; // ����� ���������� �������� �������
        for (int i = 1; i < arr2[0] - 1; i++) // ����� ��������� ���������
        {
            fout << " " << arr2[i];
        }
        fout << std::endl;

        // ����� �������, ������� ��� ������ � �������� �����
        fout << arr1[0] - 1 << std::endl; // ����� ���������� ��������� �������
        for (int i = 2; i < arr1[0]; i++) // ����� ��������� ������� �� ������� �� ���������
        {
            fout << arr1[i] << " ";
        }
        fout << arr1[1]; // ����� ������� �������� �������

        fout.close();

        delete[] arr1, arr2;
    }

    return 0;
}
