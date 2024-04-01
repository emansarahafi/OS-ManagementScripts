//Task 1 by Eman Sarah Afi (A00051) & Yousef Elsonbaty (A00138)

#include <stdio.h>
#include <stdlib.h>

int main(void)
{	
	//Initialize data input and its length
	char *input = NULL;
	size_t length = 0;
	ssize_t read;
	
	//Propmt user to input data
	printf("Input data: ");
	
	//If-else statement to ensure that the data is valid to be read
	if ((read = getline (&input, &length, stdin)) != -1) {
		printf("The inputted data is: %s", input);
	}

	free(input);
	return 0;
}
