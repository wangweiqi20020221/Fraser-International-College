#include <iostream>
#include <cmath>
using namespace std;

//A global named constant for static arrays size
const int SIZE = 25;

int getBitPatternLength() {
    /**
     * The function let user to enter the bit pattern length.
     */
	int bit_pattern_length;
	cout << "Enter the required bit pattern length between 1 and " << SIZE << ": ";
	cin >> bit_pattern_length;
	while (bit_pattern_length < 1 || bit_pattern_length > SIZE)
	{
		cout << "You must enter between 1 and " << SIZE << ". Enter again please: ";
		cin >> bit_pattern_length;
	}
	return bit_pattern_length;
}

void printArray(const int arr[], const int bit_pattern_length) {
	for (int i = 0; i < bit_pattern_length; i++)
		cout << arr[i];
}

int selectComputation() {
    /*
     * This function prints a menu and let user choose the function they want to use.
     */
	cout << endl << endl;
	cout << "Select your computation" << endl;
	cout << "   1. Unsigned Binary Number Representation" << endl;
	cout << "   2. Two's Complement Binary Number Representation" << endl;
	cout << "   3. Exit Program" << endl;
	int selection;
	cout << "Enter your selection (1, 2, or 3): ";
	cin >> selection;
	while (selection != 1 && selection != 2 && selection != 3) {
		cout << "Please enter a correct choice: ";
		cin >> selection;
	}
	return selection;
}

void computeUnsignedBinary(int A[], const int bit_pattern_length, const int num) {
    /*
     * This function takes a static array, bit pattern length, and a non-negative integer number as its arguments.
     * The function must populate the array with the unsigned binary representation of the non-negative integer
     * number argument in the given bit pattern length.
     * You must use the following function declaration and you are not allowed to change it. 
     */
    int num_temp = num;
    // %2 and append it to the arrey from right to left
    // The second statement in this for loop is i >= 0, means the loop will run in the condition of i >= 0, otherwise the loop will be broken. 
    for (int i = bit_pattern_length-1; i >= 0; i--) {
        A[i] = num_temp % 2;
        num_temp /= 2;
    }
}

void computeTwosComplementBinary(int A[], const int bit_pattern_length, const int num) {
    /*
     * This function takes a static array, bit pattern length, and an integer number as its arguments. The function
     * must populate the array with the two's complement binary representation of the integer number
     * argument in the given bit pattern length.
     * 
     * You must use the following function declaration and you are not allowed to change it.
     */
    computeUnsignedBinary(A, bit_pattern_length, abs(num));
    if (num < 0) {
        // flip
        for (int i = bit_pattern_length-1; i >= 0; i--) {
            A[i] = abs(A[i]-1);
        }
        // add 1
        bool addition = 1;
        for (int i = bit_pattern_length-1; i >= 0; i--) {
            A[i] += addition;
            if (A[i] > 1) {
                addition = 1;
                A[i] -= 2;
            } else {
                addition = 0;
            }
        }
    }
}

void binaryAddition(const int A1[], const int A2[], const int bit_pattern_length, int A3[]) {
    /*
     * This function takes two static arrays, bit pattern length, and a third static array as its arguments. The
     * function must populate the third array with the binary sum of the first two arrays in the given bit pattern
     * length. Assume the first two arrays are populated with binary bits in the given bit pattern length.
     * 
     * You must use the following function declaration and you are not allowed to change it.
     * 
     * 0 + 0 = 0
     * 1 + 0 = 0 + 1 = 1
     * 1 + 1 = 10
     * 1 + 1 + 1 = 11
     */
    bool addition = 0;
    for (int i = bit_pattern_length-1; i >= 0; i--) {
        A3[i] = A1[i] + A2[i] + addition;
        if (A3[i] > 1) {
            addition = 1;
            A3[i] -= 2;
        } else {
            addition = 0;
        }
    }
}

int twosComplementBinaryToDecimal(const int A[], const int bit_pattern_length) {
    /*
     * This function takes a static array and bit pattern length as its arguments. The function must return the
     * decimal (integer) value computed from the two's complement binary representation given in the array
     * argument in the given bit pattern length. Assume the array is populated with binary bits in the given bit
     * pattern length and that it is a two's complement representation.
     * 
     * You must use the following function declaration and you are not allowed to change it.
     */
    int temp_A[bit_pattern_length];
    for (int i = 0; i <= bit_pattern_length - 1; i++) {
        temp_A[i] = A[i];
    }
    bool is_negative = false;
    if (temp_A[0] == 1) {
        is_negative = true;
        // minors 1
        bool subtraction = 1;
        for (int i = bit_pattern_length-1; i >= 0; i--) {
            temp_A[i] -= subtraction;
            if (temp_A[i] < 0) {
                subtraction = 1;
                temp_A[i] += 2;
            } else {
                subtraction = 0;
            }
        }
        // flip
        for (int i = bit_pattern_length-1; i >= 0; i--) {
            temp_A[i] = abs(temp_A[i]-1);
        }
    }
    // binary to decimal
    int decimal = 0;
    int j = 0;
    for (int i = bit_pattern_length-1; i >= 0; i--) {
        decimal += temp_A[i] * pow(2, j);
        j++;
    }
    if (is_negative) {
        decimal = -decimal;
    }
    return decimal;
}


int main() {
	cout << "This program demonstrates numeric information representation using" << endl;
	cout << " *** Unsigned Binary Number Representation, and " << endl;
	cout << " *** Two's Complement Binary Number Representation" << endl;
	cout << "In addition, the program demonstrates" << endl;
	cout << " *** Two's Complement Binary Numbers Addition, and" << endl;
	cout << " *** Conversion from two's complement binary to decimal." << endl;
	do {
		int selection = selectComputation();
		if (selection == 1) {
            // Unsigned Binary Number Representation
			int A[SIZE];
			int bit_pattern_length = getBitPatternLength();
			int num;
			cout << "Enter a non-negative integer: ";
			cin >> num;
			while (num < 0)
			{
				cout << "You must enter a non-negative integer. Enter again please: ";
				cin >> num;
			}
			computeUnsignedBinary(A, bit_pattern_length, num);
			cout << "The unsigned binary representation of " << num << " in " << bit_pattern_length << " bit is ";
			printArray(A, bit_pattern_length);
			cout << endl;
		}
		else if (selection == 2) {
            // Two's Complement Binary Number Representation
			int A1[SIZE], A2[SIZE], A3[SIZE];
			int bit_pattern_length = getBitPatternLength();
			int num1, num2;
			cout << "Enter an integer: ";
			cin >> num1;
			computeTwosComplementBinary(A1, bit_pattern_length, num1);
			cout << "The two's complement binary representation of " << num1 << " in " << bit_pattern_length << " bit is ";
			printArray(A1, bit_pattern_length);
			cout << endl;
			cout << "Enter a second integer: ";
			cin >> num2;
			computeTwosComplementBinary(A2, bit_pattern_length, num2);
			cout << "The two's complement binary representation of " << num2 << " in " << bit_pattern_length << " bit is ";
			printArray(A2, bit_pattern_length);
			cout << endl;
			binaryAddition(A1, A2, bit_pattern_length, A3);
			cout << "The binary sum of ";
			printArray(A1, bit_pattern_length);
			cout << " and ";
			printArray(A2, bit_pattern_length);
			cout << " is ";
			printArray(A3, bit_pattern_length);
			cout << endl;
			int sum = twosComplementBinaryToDecimal(A3, bit_pattern_length);
			cout << "The integer value of the binary sum is " << sum << endl;
			if (sum == num1 + num2)
				cout << "This is a correct result." << endl;
			else
				cout << "This is not correct result because our bit pattern is too small to store the result." << endl;
		}
		else
			break;
	}while (true);
	system("Pause");
	return 0;
}