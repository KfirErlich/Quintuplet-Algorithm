#include "functionsSigns.h"

bool isCorrectDouble(double* location) {
	char getInput[100], * correctInput;
	int length = 0, i = 0;
	const char endWord = '\0';
	const char endLine = '\n';
	getInput[length] = getchar();

	while (getInput[length] != ' ' && getInput[length] != endLine) {
		length++;
		getInput[length] = getchar();
	}

	getInput[length] = endWord;
	correctInput = new char[length + 1];
	correctInput[length] = endWord;

	while (i != length + 1) {
		correctInput[i] = getInput[i];
		i++;
	}

	int digitsAfterPoint = (length - 1) - findPoint(correctInput, length);
	if ((digitsAfterPoint < 1) || (digitsAfterPoint > 4))
		return false;

	*location = atof(correctInput);
	delete[] correctInput;
	return true;
}

int findPoint(char* number, int length) {
	for (int i = 0; i < length; i++) {
		if (number[i] == '.')
			return i;
	}
	return 0;
}