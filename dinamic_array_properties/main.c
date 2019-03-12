#include <stdio.h>
#include <malloc.h>
#include <math.h>








int calculation_func(long double *input_array_ptr, long long int num_of_el, \
	long double *max_el_ptr, long double *min_el_ptr, long double *average_ptr, \
	long double *standart_dev_ptr) {

	*max_el_ptr = *input_array_ptr;
	*min_el_ptr = *input_array_ptr;
	*average_ptr = 0;
	*standart_dev_ptr = 0;

	long double sum_of_squares = 0;
	long double sum_of_el = 0;

	for (long long int i = 0; i < num_of_el; i++) {

		if (*(input_array_ptr + i) < *min_el_ptr) {
			*min_el_ptr = *(input_array_ptr + i);
		}
		else {

			if (*(input_array_ptr + i) > *max_el_ptr) {
				*max_el_ptr = *(input_array_ptr + i);
			}

		}

		sum_of_squares += *(input_array_ptr + i) * *(input_array_ptr + i);
		sum_of_el += *(input_array_ptr + i);
	}

	*average_ptr = sum_of_el / num_of_el;
	*standart_dev_ptr = sqrt(sum_of_squares / num_of_el - *average_ptr * *average_ptr);

	return 0;

}








int main() {

	printf("This programm searches maximun and minimun elements and calculates average and standard deviation in dinamic array.\n\n");

	for (int cont = 1; cont;) {
		printf("In all following inputs extra elements will be ignored but if you input invalid element insted of expected it will\nbe a mistake.\n\n");
		printf("Input the number of elements in your array\n");

		long long int num_of_el = 0;

		if (scanf_s("%lli", &num_of_el) != 1) {
			ungetc('~', stdin);

			while (getchar() != '\n');

			printf("\nYou input not a number. Please, try again...\n\n");
		}
		else {
			ungetc('~', stdin);

			while (getchar() != '\n');

			printf("\n");

			if (num_of_el <= 0) {
				printf("\nYou input invalid number of element. It should be more then 0. Please, try again...\n\n");
			}
			else {
				printf("Input the elements of your array through the gap.\n");

				long double *input_array_ptr = (long double *) malloc(num_of_el * sizeof(long double));
				int ret_code = 1;

				for (int i = 0; i < num_of_el && ret_code == 1; i++) {
					ret_code = scanf_s("%Lf", input_array_ptr + i);
				}

				ungetc('~', stdin);

				while (getchar() != '\n');

				printf("\n");
				
				if (ret_code != 1) {
					printf("You input not a number. Please, try again...\n\n");
				}
				else {

					long double max_el = 0;
					long double min_el = 0;
					long double average = 0;
					long double standart_div = 0;

					calculation_func(input_array_ptr, num_of_el, &max_el, &min_el, &average, &standart_div);
					printf("Maximum element is %.10Lf\nMinimum element is %.10Lf\nAverage is %.10Lf\nStandard deviation is %.10Lf\n\n", max_el, min_el, average, standart_div);
					free(input_array_ptr);

					printf("If you want to do it again with another parameters input 1, else input 0\n");

					while (scanf_s("%d", &cont) != 1) {
						ungetc('~', stdin);

						while (getchar() != '\n');

						printf("\nTry again...\n\n");
					}

					ungetc('~', stdin);

					while (getchar() != '\n');

					printf("\n");
				}

			}
		}
		
	}

	return 0;
}