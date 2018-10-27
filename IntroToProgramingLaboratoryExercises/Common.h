#pragma once
#include <assert.h>
#include <ctype.h>
#include <stdio.h>

typedef int(*ExerciseFunction)(void);

typedef struct Exercise
{
    ExerciseFunction function;
    int number;
} Exercise;

ExerciseFunction selectExercise(Exercise exercises[], const int size, const int selectedValue);

int inputExercise();

int wanntToQuit();

void runExercises(const Exercise exercises[], int numberOfExercises);

void clrscr();