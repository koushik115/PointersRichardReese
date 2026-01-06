#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getLine(void);
char *trim(char *buffer);

int *allocateVector(int size);
int **allocateMatrix(int rows, int cols);
int ***allocateCube(int depth, int rows, int cols);
int ****allocateHyperCube(int time, int depths, int rows, int cols);

void freeVector(int *vector);
void freeMatrix(int **matrix, int rows);
void freeCube(int ***cube, int depths, int rows);
void freeHyperCube(int ****hypercube, int time, int depths, int rows);

void displayVector(int *arr, int vectorSize);
void displayMatrix(int *arr, int rows, int cols); // Non Conatgious
void displayCube(int *arr, int depth, int rows, int cols);
void displayHyperCube(int *arr, int time, int depths, int rows, int cols);

int main(void) {
	/*
	// Array declaration: One Dimensional
	int vectorOne[5] = {1, 2, 3, 4, 5};
	// Pointer to One Dimensional Array
	int *pv = vectorOne;
	// Number of elements in vectorOne 
	// int vectorOneElements = sizeof(vectorOne)/sizeof(int);
	*/
	// Array declaration: Two Dimensional
	int matrixOne[2][3] = {	{1, 2, 3}, 
				{4, 5, 6} 
			      };

	
	// Array declaration: Three Dimensional
	int cube[3][2][4] = { {	{1, 2, 3, 4}, {5, 6, 7, 8} },
			      {	{9, 10, 11, 12}, {13, 14, 15, 16} },
			      {	{17, 18, 19, 20}, {21, 22, 23, 24} }
			    };
	
	
	/*
	printf("=============== 1D Array ===============\n");
	for(int i = 0; i < 5; i++) {
		printf("vector[%d]	Address: %p	Value: %d\n", i, (vectorOne + i), *(vectorOne + i));
	}

	printf("=============== Pointer to 1D Array ===============\n");
	for(int i = 0; i < 5; i++) {
		printf("*(pv + %d)	Address: %p	Value: %d\n", i, (pv + i), *(pv + i));
	}


	printf("=============== Dynamic Allocation of 1D Array ===============\n");
	int *dynamicVector = allocateVector(5);
	for(int i = 0; i < 5; i++) {
		*(dynamicVector + i) = i * 2;
	}
	for(int i = 0; i < 5; i++) {
		printf("*(dynamicVector + %d)	Address: %p	Value: %d\n", i, (dynamicVector + i), *(dynamicVector + i));
	}
	free(dynamicVector);

	printf("=============== 2D Array ===============\n");
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 3; j++) {
			printf("matrixOne[%d][%d]	Address: %p	Value: %d\n", i, j, (*(matrixOne + i) + j), *(*(matrixOne + i) + j));
		}
	}

	printf("=============== 3D Array ===============\n");
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 2; j++) {
			for(int k = 0; k < 4; k++) {
				printf("cubeOne[%d][%d][%d]	Address: %p	Value: %d\n", i, j, k, (*(*(cube + i) + j) + k), *(*(*(cube + i) + j) + k));	
			}
			
		}
	}

	printf("=============== getLine() (Using realloc()) ===============\n");
	char *buffer = getLine();
	printf("%s\n", buffer);
	
	printf("=============== One Dimensional Array of Pointers ===============\n");
	int *arrayOfPointers[5];
	for(int i = 0; i < 5; i++) {
int ***allocateCube(int depth, int rows, int cols) {
	int ***cube = (int ***)malloc(depth * sizeof(int **));

	for(int i = 0; i < depth; i++) {
		*(cube + i) = (int **)malloc(rows * sizeof(int *));

		for(int j = 0; j < rows; j++) {
			*(*(cube + i) + j) = (int *)malloc(cols * sizeof(int));
		}
	}

	return cube;
}

		*(arrayOfPointers + i) = (int *)malloc((i + 1) * sizeof(int));
		for(int j = 0; j <= i; j++) {
			*(*(arrayOfPointers + i) + j) = j + 1;
		}
		displayVector(*(arrayOfPointers + i), i + 1);
		free(*(arrayOfPointers + i));
	}
	*/

	displayMatrix(&matrixOne[0][0], 2, 3);
	displayCube(&cube[0][0][0], 3, 2, 4);


	return 0;
}

int *allocateVector(int size) {
	int *vector = (int *)malloc(size * sizeof(int));
	if(!vector) return NULL;
	return vector;
}

int **allocateMatrix(int rows, int cols) {
	int **matrix = (int **)malloc(rows * sizeof(int *));
	if(matrix == NULL) return NULL;

	for(int i = 0; i < rows; i++) {
		*(matrix + i) = (int *)malloc(cols * sizeof(int));
	}
	return matrix;
}

int ***allocateCube(int depth, int rows, int cols) {
	int ***cube = (int ***)malloc(depth * sizeof(int **));

	for(int i = 0; i < depth; i++) {
		*(cube + i) = (int **)malloc(rows * sizeof(int *));

		for(int j = 0; j < rows; j++) {
			*(*(cube + i) + j) = (int *)malloc(cols * sizeof(int));
		}
	}

	return cube;
}

int ****allocateHyperCube(int time, int depths, int rows, int cols) {
	int ****hypercube = (int ****)malloc(time * (sizeof(int ***)));

	for(int i = 0; i < time; i++) {
		*(hypercube + i) = (int ***)malloc(depths * sizeof(int **));

		for(int j = 0; j < depths; j++) {
			*(*(hypercube + i) + j) = (int **)malloc(rows * sizeof(int *));
					for(int k = 0; k < rows; k++) {
						*(*(*(hypercube + i) + j) + k) = (int *)malloc(cols * sizeof(int));
					}
		}
	}

	return hypercube;
}

void freeVector(int *vector) {
	free(vector);
	vector = NULL;
}

void freeMatrix(int **matrix, int rows) {
	for(int i = 0; i < rows; i++) {
		free(*(matrix + i));
		*(matrix + i) = NULL;
	}

	free(matrix);
	matrix = NULL;
}

void freeCube(int ***cube, int depth, int rows) {
	for(int i = 0; i < depth; i++) {
		for(int j = 0; j < rows; j++) {
			free(*(*(cube + i) + j));
			*(*(cube + i) + j) = NULL;
		}

		free(*(cube + i));
		*(cube + i) = NULL;
	}

	free(cube);
	cube = 	NULL;
}

void freeHyperCube(int ****hypercube, int time, int depth, int rows) {
	for(int i = 0; i < time; i++) {
		for(int j = 0; j < depth; j++) {
			for(int k = 0; k < rows; k++) {
				free(*(*(*(hypercube + i) + j) + k));
				*(*(*(hypercube + i) + j) + k) = NULL;
			}

			free(*(*(hypercube + i) + j));
			*(*(hypercube + i) + j) = NULL;
		}
		
		free(*(hypercube + i));
		*(hypercube + i) = NULL;
	}

	free(hypercube);
	hypercube = NULL;
}

void displayVector(int *arr, int vectorSize) {
	for(int i = 0; i < vectorSize; i++)
		printf("%d ", *(arr + i));
	printf("\n");
}

void displayMatrix(int *arr, int rows, int cols) {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			printf("%d ", *(arr + (i * cols) + j));
		}
	}
	printf("\n");
}

void displayCube(int *arr, int depth, int rows, int cols) {
	for(int i = 0; i < depth; i++) {
		for(int j = 0; j < rows; j++) {
			for(int k = 0; k < cols; k++) {
				printf("%d ", *(arr + i * rows * cols + j * cols + k));
			}
		}
	}
	printf("\n");
}

void displayHyperCube(int *arr, int time, int depths, int rows, int cols) {
	for(int i = 0; i < time; i++) {
		for(int j = 0; j < depths; j++) {
			for(int k = 0; k < rows; k++) {
				for(int l = 0; l < cols; l++) {
					printf("%d ", *(arr + (i * depths * rows * cols) + (j * rows * cols) + (k * cols) + l));
				}
			}
		}
	}
}


char *getLine(void) {
	size_t incrementalLength = 10;
	size_t maximumLength = incrementalLength;
	size_t length = 0;
	char *buffer = (char *)malloc(incrementalLength);
	char *currentPos = buffer;
	int character;

	if(!currentPos) return NULL;

	while(1) {
		character = fgetc(stdin);

		if(character == '\n') break;

		if(++length >= maximumLength) {
			char *newBuffer = (char *)realloc(buffer, maximumLength += incrementalLength);

			if(!newBuffer) {
				free(buffer);
				return NULL;
			}
		
		currentPos = newBuffer + (currentPos - buffer);
		buffer = newBuffer;
		
		}
		*currentPos++ = character;
	}

	*currentPos = '\0';
	return buffer;
}

char *trim(char *buffer) {
	char *old = buffer;
	char *new = buffer;

	while(*old == ' ') old++;
	while((*new = *old)) {
		old++; new++;
	}

	return (char *)realloc(buffer, strlen(buffer) + 1);
}


