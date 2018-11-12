#include "Common.h"
#include "exercise.h"
#include <stdio.h>

#define ARRAY_MAXSIZE 10000

int exercise(void);
void printArray(double arr[], int n);
int getSizeFromUser(int maxsize);
double getDoubleFromUser(char* str);

int main(int argc, char *argv[])
{
    srand((unsigned int)time(NULL));
    Exercise a[] = { {exercise,1} };
    runExercises(a, 1);
}

int exercise(void)
{
    int size = getSizeFromUser(ARRAY_MAXSIZE);
    double low = getDoubleFromUser("low: ");
    double high = getDoubleFromUser("high: ");
    double arr[ARRAY_MAXSIZE];

    for (size_t i = 0; i < size; i++)
    {
        arr[i] = RandomReal(low, high);
    }
    printArray(arr, size);
    printf("Mean is: %lf\n", calculateMean(arr, size));
    printf("Standdeviation is: %lf\n", calculateStandarddeviation(arr, size));
    printf("Median is: %lf\n", calculateMedian(arr, size));
    bubleSort(arr, size);
    printArray(arr, size);
    return 0;
}

int getSizeFromUser(int maxsize)
{
    int size = -1;
    do
    {
        printf("size: \n");
        scanf_s("%d", &size);
    } while (size < 1 || size > maxsize);
    return size;
}

double getDoubleFromUser(char* str)
{
    double val;
    printf(str);
    scanf_s("%lf", &val);
    return val;
}

void printArray(double arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.3lf  ", arr[i]);
        if (i % 10 == 9)
            printf("\n");
    }
    printf("\n");
}