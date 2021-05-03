#include <stdio.h>
#include <math.h>


// the function of initialization the coefficients
int* quadr_coeff_decl(int arr[]) {
	int coeff;
	printf("Welcome to the program of solving of a quadratic equation \n Please, enter coefficients\n");
	for (int i = 0; i < 3; i += 1) {
		printf("Coefficient %d: ", i + 1);
		scanf_s("%d", &coeff);
		arr[i] = coeff;
		printf("\n");
	}
	return *arr;
}

// the function of discriminant calculating 
float discrim_calc(int a, int b, int c) {
	float discriminant = (float)(b * b - 4 * a * c);
	return discriminant;
}


// the method of calculating the first root of the square equation
float first_root_calc(float disc, int arr[]) {
	float x1;
	x1 = ((-(*(arr + 1))) + sqrt(disc)) / (2.0 * (*arr));
	return x1;
}


// the method of calculating the second root of the square equation
float second_root_calc(float disc, int arr[]) {
	float x2;
	x2 = ((-(*(arr + 1))) - sqrt(disc)) / (2.0 * (*arr));
	return x2;
}


int main() {

	int array_of_coeff[3];  // array that gets the coefficients of square equation
	float discriminant; // variable for discriminant

	// initialization of coefficients
	quadr_coeff_decl(array_of_coeff);
	printf("The square equation: (%d)x^2 + (%d)x + (%d) = 0 \n", *(array_of_coeff), *(array_of_coeff + 1), *(array_of_coeff + 2));


	// calculating the discriminant
	discriminant = discrim_calc(*(array_of_coeff), *(array_of_coeff + 1), *(array_of_coeff + 2));
	printf("The discriminant: %f \n", discriminant);

	// If the DISCRIMINANT less of ZERO
	if (discriminant < 0) {
		printf("The square equation has no real roots");
		return 0;
	} // If the DISCRIMINANT equals ZERO
	else if (discriminant == 0) {
		printf("The square equation has one root: %f", first_root_calc(discriminant, array_of_coeff));
		return 0;
	}// If the DISCRIMINANT more of ZERO
	else {
		printf("The square equation has two roots: \n x1 = %f \n x2 = %f \n", first_root_calc(discriminant, array_of_coeff), second_root_calc(discriminant, array_of_coeff));
		return 0;
	}
}