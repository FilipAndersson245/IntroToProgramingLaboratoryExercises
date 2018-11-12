#include "exercise.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include <math.h>

// Example on general SWAP function that is inlined before compilation
#define SWAP(x, y, T) do { T SWAP = x; x = y; y = SWAP; } while (0)

double RandomReal(double low, double high)
{
    double d;

    d = (double)rand() / ((double)RAND_MAX + 1);
    return (low + d * (high - low));
}

void swap(double *a, double *b)
{
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubleSort(double arr[], int n)
{
    // number of swaps done for a iteration
    int swaps = 0;

    for (size_t i = 0; i < n - 1; i++)
    {
        swaps = 0;
        for (size_t j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swaps++;
            }
        }
        // break if no swaps has been done so the array is sorted
        if (swaps == 0) {
            break;
        }
    }
}

double calculateMedian(double arr[], int n)
{
    return (n % 2) ? arr[n / 2] : (arr[n / 2] + arr[(n / 2) + 1]) / 2;
}

double calculateMean(double arr[], int n)
{
    return calculateSum(arr, n) / n;
}

double calculateSum(double arr[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

double calculateStandarddeviation(double arr[], int n)
{
    double sum = 0, mean, standardDeviation = 0;

    mean = calculateMean(arr, n);

    for (int i = 0; i < n; i++)
    {
        standardDeviation += pow(arr[i] - mean, 2);
    }
    return sqrt(standardDeviation / n);
}