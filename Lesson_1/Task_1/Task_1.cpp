#include <iostream>
#include <fstream>

int* createArr(std::ifstream& fin, int* size) // Create array from file
{
    fin >> *size; // Removed array size from array to separate variable

    int* arr = new int[*size];

    if (*size > 0)
    {
        for (int i = 0; i < *size; i++)
        {
            fin >> arr[i];
        }
    }
    else if (*size == 0) // Condition if size is zero
    {
        arr = nullptr;
    }

    return arr;
}

int main()
{
    std::string fileIn = "in.txt", fileOut = "out.txt";
    std::ifstream fin(fileIn);

    if (!fin.is_open())
    {
        std::cout << "Не удалось открыть файл" << std::endl;
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

        // Second array output
        if (sizeArr2 > 0)
        {
            fout << sizeArr2 << std::endl;
            fout << arr2[sizeArr2 - 1];
            for (int i = 0; i < sizeArr2 - 1; i++)
            {
                fout << " " << arr2[i];
            }
        }
        else if (sizeArr2 == 0) // Condition if size is zero
        {
            fout << sizeArr2;
        }
        fout << std::endl;

        delete[] arr2;

        // First array output
        if (sizeArr1 > 0)
        {
            fout << sizeArr1 << std::endl;
            for (int i = 1; i < sizeArr1; i++)
            {
                fout << arr1[i] << " ";
            }
            fout << arr1[0];
        }
        else if (sizeArr1 == 0) // Condition if size is zero
        {
            fout << sizeArr1;
        }
        fout << std::endl;

        delete[] arr1;

        fout.close();
    }

    return 0;
}
