#include "Common.h"
#include "exercises.h"
#include <locale.h>
int main(int argc, char *argv[])
{
    char *locale;
    locale = setlocale(LC_ALL, "");

    srand((unsigned int)time(NULL));

    Exercise a[] = { {exercise1,1},{exercise2,2},{exercise3,3},{exercise4,4},{exercise5,5} };
    runExercises(a, 5);
}