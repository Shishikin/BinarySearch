// BinarySearch.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <random>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#endif

bool FixFlow()
{
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        fflush(stdin);
        return true;
        //        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else
    {
        return false;
    }
}


template <typename T>
void Input(T& side1, const std::string& message)
{
    do
    {
        std::cout << message << '\n';
        std::cin >> side1;
    } while (FixFlow());
}

// Функция для генерации случайного целого числа в диапазоне [min, max]
int GenerateRandomInteger(int min = 0, int max = 100) {
    // Используем генератор случайных чисел mt19937
    std::random_device rd;
    std::mt19937 gen(rd());

    // Используем равномерное распределение в заданном диапазоне
    std::uniform_int_distribution<int> dis(min, max);

    // Генерируем случайное целое число
    return dis(gen);
}



void PushVectorRandom(std::vector<int>& array, int len)
{
    for (int i = 0; i < len; ++i)
    {
        array.push_back(GenerateRandomInteger());
    }
}

void PrintVector(const std::vector<int>& array)
{
    for (auto a: array)
    {
        std::cout << a << ' ';
    }
}

void swap(int& a, int& b)
{
    int c = a;
    a = b;
    b = c;
}

void quick_sort(std::vector<int>& list, int left, int right)
{
    int left_arrow = left;
    int right_arrow = right;
    int pivot = list[(left + right) / 2];
    do {
        while (list[right_arrow] > pivot)
            right_arrow--;
        while (list[left_arrow] < pivot)
            left_arrow++;
        if (left_arrow <= right_arrow)
        {
            swap(list[left_arrow], list[right_arrow]);
            left_arrow++;
            right_arrow--;
        }
    } while (right_arrow >= left_arrow);
    if (left < right_arrow)
        quick_sort(list, left, right_arrow);
    if (left_arrow < right)
        quick_sort(list, left_arrow, right);
}



int BinarySearch(int value, const std::vector<int>& array, int begin, int end)
{
    if (end - begin == 0)
    {
        return array[begin] == value ? begin : -1;
    }

    if (array[(end - begin) / 2 + 1 + begin] == value)
    {
        return (end - begin) / 2 + 1 + begin;
    }
    else
    {
        if (array[(end - begin) / 2 + 1 + begin] > value)
        {
            return BinarySearch(value, array, begin, (end - begin) / 2 + begin);
        }
        else
        {
            return BinarySearch(value, array, (end - begin) / 2 + 1 + begin, end);
        }
    }
}

int main()
{
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
    std::vector<int> array = { 0, 13, 25, 27, 31, 48, 55, 70, 84, 97 };
//    PushVectorRandom(array, 10);
    quick_sort(array, 0, array.size() - 1);
    PrintVector(array);
    int value = 0;
    int begin = 0;
    int end = 0;
    Input(value, "Введите искомый элемент");
    Input(begin, "Введите начальный индекс");
    Input(end, "Введите конечный индекс");
    std::cout << BinarySearch(value, array, begin, end);
    std::cout << "Hello World!\n";
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
