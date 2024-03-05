#include <iostream>
#include <cmath> // Include the math library for logarithmic functions

using namespace std;

int main() {
    char op;
    double num1, num2, result;

    cout << "Enter operator (+, -, *, /, log): ";
    cin >> op;

    if (op == '+' || op == '-' || op == '*' || op == '/') {
        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        switch(op) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    cout << "Error! Division by zero.";
                    return -1; // Exiting with error code -1
                }
                break;
            default:
                cout << "Invalid operator!";
                return -1; // Exiting with error code -1
        }
        cout << "Result: " << result << endl;
    }
    else if (op == 'l' || op == 'L') { // Logarithm operation
        cout << "Enter a number to calculate its logarithm: ";
        cin >> num1;
        if (num1 > 0) {
            result = log(num1);
            cout << "Result: " << result << endl;
        } else {
            cout << "Error! Logarithm of a non-positive number is undefined.";
            return -1; // Exiting with error code -1
        }
    }
    else {
        cout << "Invalid operator!";
        return -1; // Exiting with error code -1
    }

    return 0;
}
