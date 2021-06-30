#include <iostream>
#include <iomanip>
#include <chrono>
#include <fstream>

using namespace std;
double insertionSort(double arr[], int n, int idx);
void swap(double* a, double* b);
int partition(double* arr, int left, int right);
double selection(double arr[], int left, int right, int i);
void bubbleSort(double* arr, int n);
double Quintuplet(double* arr, int n, int idx);
bool isCorrectDouble(double* location);
int findPoint(char* number, int length);