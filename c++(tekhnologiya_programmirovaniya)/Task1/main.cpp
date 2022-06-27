#include <iostream>

int getSumIndex(const int[] , int);
void randomFillVector( int vector[], int);

int main()
{
    const int SIZE1 = 5,
              SIZE2 = 10;
    int size3 = 1;
    std::cout << " Enter size of array: " << '\n';
    std::cin >> size3;
    int array1[SIZE1] = {1, 2, 3, 4, 5},
        array2[SIZE2] = {0},
        *array3 = new int[size3];
    //randomFillVector(array1, SIZE1);
    for (int i: array1)
    {
        std::cout << i << '\t';
    }
    std::cout  << '\n';
    randomFillVector(array2, SIZE2);
    for (int i: array2)
    {
        std::cout << i << '\t';
    }
    std::cout  << '\n';
    randomFillVector(array3, size3);
    for (int i = 0; i < size3; ++i)
    {
        std::cout << array3[i] << '\t';
    }
     std::cout  << '\n';

    std::cout << R"( The summaries of "min" and "max" indexes are)" << '\n';
    std::cout << "1)" << getSumIndex(array1,SIZE1) << '\n';
    std::cout << "2)" << getSumIndex(array2,SIZE2) << '\n';
    std::cout << "3)" << getSumIndex(array3,size3) << '\n';
    delete[] array3;
    return 0;
}
int getSumIndex(const int vector[] , int size )
{
    int maxVal = vector[0],
        minVal = vector[0],
        maxIndex = 0,
        minIndex = 0;

    for (int i = 0; i < size; ++i)
    {
        if (vector[i] > maxVal)
        {
            maxVal = vector[i];
            maxIndex = i;
        }
        if (vector[i] < minVal)
        {
            minVal = vector[i];
            minIndex = i;
        }
    }
    return ( minIndex + maxIndex);
}

void randomFillVector(int vector[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        vector[i] = static_cast<int>(arc4random() % 70 - 20);
    }
}