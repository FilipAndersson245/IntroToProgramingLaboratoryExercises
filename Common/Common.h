#pragma once

typedef int(*ExerciseFunction)(void);

typedef struct Exercise
{
    ExerciseFunction function;
    int number;
} Exercise;

ExerciseFunction selectExercise(Exercise exercises[], const int size, const int selectedValue);

int inputExercise();

int wanntToQuit();

void clrscr();
