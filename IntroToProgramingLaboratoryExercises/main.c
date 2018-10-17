#include <stdio.h>

#include "../Common/stdafx.h"
#include "Exercises.h"

int main(int argc, char *argv[]) {
    Exercise a[] = { {exercise1,1},{exercise2,2} };
    do {
        ExerciseFunction abc = selectExercise(a, 2, inputExercise());
        if (abc != NULL)
            abc();
        else
            printf("No exercise found");
    } while (wanntToQuit());
}