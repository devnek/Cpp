#include <stdio.h>
#include "math_operations.h"

int main() {
	int num1, num2;
	
	// Input two numbers
	printf("Enter the first number: ");
	scanf("%d", &num1);
	printf("Enter the second number: ");
	scanf("%d", &num2);
	
	// Use functions from the custom header
	int sum = add(num1, num2);
	int product = multiply(num1, num2);
	
	// Print results
	printf("Sum: %d\n", sum);
	printf("Product: %d\n", product);
	
	return 0;
}