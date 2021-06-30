#include "functionsSigns.h"

int main() {
	int sizeOfArrays, selectedIndex;
	cin >> sizeOfArrays;

	if (sizeOfArrays > 0) {
		cin >> selectedIndex;
		if (selectedIndex > 0 && selectedIndex <= sizeOfArrays) {
	        getchar();// catch the end line 
			
			double* arr1 = new double[sizeOfArrays];
			double* arr2 = new double[sizeOfArrays];
			double* arr3 = new double[sizeOfArrays];
			bool flag;
			for (int i = 0; i < sizeOfArrays; i++)
			{
				flag = isCorrectDouble(arr1 + i);
				if (!flag) {

					cout << "wrong input";
					break;
				}
				else
				{
					arr2[i] = arr1[i];
					arr3[i] = arr1[i];
				}
			}
			if (flag) {
				
				//insertionSort
				auto start = chrono::high_resolution_clock::now();
				ios_base::sync_with_stdio(false);
				cout << setprecision(4) << fixed << "Insertion sort i'th element: " << insertionSort(arr3, sizeOfArrays, selectedIndex - 1) << endl;
				auto end = chrono::high_resolution_clock::now();
				double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
				time_taken *= 1e-9;
				ofstream myfile("Measure.txt");
				myfile << "Time taken by function insertionSort is : " << fixed << time_taken << setprecision(9);
				myfile << " sec" << endl;
				myfile.close();

				//selection
				start = chrono::high_resolution_clock::now();
				ios_base::sync_with_stdio(false);
				cout << "Selection i'th element: " << selection(arr2, 0, sizeOfArrays - 1, selectedIndex) << endl;
				end = chrono::high_resolution_clock::now();
				time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
				time_taken *= 1e-9;
				ofstream myfile2("Measure2.txt");
				myfile2 << "Time taken by function selection is : " << fixed<< time_taken << setprecision(9);
				myfile2 << " sec" << endl;
				myfile2.close();

				//Quintuplet
				start = chrono::high_resolution_clock::now();
				ios_base::sync_with_stdio(false);
				cout << "Quintuplet algorithm i'th element: " << Quintuplet(arr1, sizeOfArrays, selectedIndex) << endl;
				end = chrono::high_resolution_clock::now();
				time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
				time_taken *= 1e-9;
				ofstream myfile3("Measure3.txt"); 
				myfile3 << "Time taken by function Quintuplet is : " << fixed << time_taken << setprecision(9);
				myfile3 << " sec" << endl;
				myfile3.close();
			}
			delete[] arr1;
			delete[] arr2;
			delete[] arr3;
		}
		else
			cout << "wrong input";
	}
	else
		cout << "wrong input";

	
	return 0;
}
