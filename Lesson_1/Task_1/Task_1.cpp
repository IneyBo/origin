#include <iostream>
#include <fstream>

/*В этом решении создаю массивы, только если размер не равен нулю*/

int* createArr(std::ifstream& fin, int* size) // Создание массива из данных файла
{
    int* arr = new int[*size];

    for (int i = 0; i < *size; i++)
    {
        fin >> arr[i];
    }

    return arr;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    std::string fileIn = "in.txt", fileOut = "out.txt";
    std::ifstream fin(fileIn);

    if (!fin.is_open())
    {
        std::cout << "Не удалось открыть файл" << std::endl;
    }
    else
    {
        int size = 0, sizeArr1 = 0, sizeArr2 = 0;
        int* arr1 = 0; // В этом решении объявил массив (пойнтер) до задания ему значения в условии. Инициализировал его пока нулем. Надеюсь так можно. Так как компилятор ругается на неициализированную переменную.
        int* arr2 = 0;

        fin >> size;
        sizeArr1 = size;
        if (sizeArr1 > 0) // Создаю массив, только если размер не равен нулю
        {
            arr1 = createArr(fin, &size);
        }

        fin >> size;
        sizeArr2 = size;
        if (sizeArr2 > 0) // Создаю массив, только если размер не равен нулю
        {
            arr2 = createArr(fin, &size);
        }

        fin.close();

        std::ofstream fout(fileOut);

        // Вывод второго массива
        if (sizeArr2 > 0)
        {
            fout << sizeArr2 << std::endl;
            fout << arr2[sizeArr2 - 1];
            for (int i = 0; i < sizeArr2 - 1; i++)
            {
                fout << " " << arr2[i];
            }
            delete[] arr2;
        }
        else if (sizeArr2 == 0)
        {
            fout << sizeArr2;
        }
        fout << std::endl;


        // Вывод первого массива
        if (sizeArr1 > 0)
        {
            fout << sizeArr1 << std::endl;
            for (int i = 1; i < sizeArr1; i++)
            {
                fout << arr1[i] << " ";
            }
            fout << arr1[0];
            delete[] arr1;
        }
        else if (sizeArr1 == 0)
        {
            fout << sizeArr1;
        }
        fout << std::endl;

        fout.close();
    }

    return 0;
}
