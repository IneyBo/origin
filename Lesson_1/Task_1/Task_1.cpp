#include <iostream>
#include <fstream>

int* createArr(std::ifstream& fin, int* size) // �������� ������� �� ��������� ������ �����
{
    fin >> *size; // ����� ������ ������� �� ������ ������� � ��������� ����������
    int* arr = new int[*size];

    for (int i = 0; i < *size; i++)
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
        int size = 0, sizeArr1 = 0, sizeArr2 = 0;
        int* arr1 = createArr(fin, &size);
        sizeArr1 = size;
        int* arr2 = createArr(fin, &size);
        sizeArr2 = size;

        fin.close();

        std::ofstream fout(fileOut);

        // ����� �������, ������� ��� ������ � �������� �����
        fout << sizeArr2 << std::endl; // ����� ���������� ��������� �������
        fout << arr2[sizeArr2 - 1]; // ����� ���������� �������� �������
        for (int i = 0; i < sizeArr2 - 1; i++) // ����� ��������� ���������
        {
            fout << " " << arr2[i];
        }
        fout << std::endl;

        delete[] arr2; // ������ �������� ������ ��� ���� �������� ��������. ������ ��� � ���� ������, ����� ��� ������� ����� ������� ���.

        // ����� �������, ������� ��� ������ � �������� �����
        fout << sizeArr1 << std::endl; // ����� ���������� ��������� �������
        for (int i = 1; i < sizeArr1; i++) // ����� ��������� ������� �� ������� �� ���������
        {
            fout << arr1[i] << " ";
        }
        fout << arr1[0]; // ����� ������� �������� �������

        delete[] arr1;

        fout.close();
    }

    return 0;
}
