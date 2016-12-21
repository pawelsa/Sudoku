#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

#define sud 9
int sudoku[sud][sud];
int sudokubl[sud][sud];
int value;
int x, y;

void tablica(int sudoku[sud][sud]) {

	//Draw 3 rows
	printf(" Y |     \t\tX\n   |");
	for (int i = 1; i < 10; i++) {
		printf("%3.d", i);

		while ((i == 3) || (i == 6)) {
			printf(" |");
			break;
		}
	}
	printf("\n");
	for (int k = 0; k < 18; k++)
		printf(" -");
	printf("\n");

	//Draw full table
	for (int i = 0; i < sud; i++) {
		printf(" %d |", i + 1);
		for (int j = 0; j < sud; j++) {
			printf("%3.d", sudoku[i][j]);	  //values

			while ((j == 2) || (j == 5)) {		//spaces
				printf(" |");
				break;
			}	//loop while
		}	 //loop for

		printf("\n");

		//Horizontal spaces
		while ((i == 2) || (i == 5)) {
			for (int k = 0; k < 18; k++)
				printf(" -");
			printf("\n");
			break;
		}//loop while ^

	}//1st loop

}

int sprawdzanie(int sudoku[sud][sud], int value, int x, int y, int sudokubl[sud][sud]) {

	int condition = 0;//if condition = 1, value can't be signed

					  //Prepares values for checking 3x3 squares
	int Ywar, Xwar;
	Ywar = Xwar = 0;

	if ((y >= 4) && (y <= 6))
		Ywar = 3;
	else if (y >= 7)
		Ywar = 6;

	if ((x >= 4) && (x <= 6))
		Xwar = 3;
	else if (x >= 7)
		Xwar = 6;

	//Check if values may be signed without corrupion of sudoku rules in horizontal and vertical axis
	for (int i = 0; i < 9; i++) {
		if ((value == sudoku[y - 1][i]) || (value == sudoku[i][x - 1])) {
			condition = 1;
			break;
		}
	}

	//Checks 3x3 squares
	for (int k = Ywar; k < (Ywar + 3); k++)		//3-6	6 - 9
		for (int j = Xwar; j < (Xwar + 3); j++)
			if (sudoku[k][j] == value)
				condition = 1;

	if (condition == 0) {
		sudoku[y - 1][x - 1] = value;
		printf("\nGood ! Go ahead\n\n");
	}
	else {
		printf("NOPE ! You can't sign here, because it breaks sudoku rules! \n");
	}
	return condition;
}

int finalcheck(int sudoku[sud][sud], int sudokubl[sud][sud]) {

	int condition = 0;

	//Checks if all values are different than 0
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudoku[i][j] != 0);
			else
				condition = 1;
		}
	}
	return condition;
}

void save(int sudoku[sud][sud]) {

	FILE *save;
	save = fopen("sudoku.txt", "w");

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			fprintf(save, "%d ", sudoku[i][j]);
		}
		fprintf(save, "\n");
	}
	fclose(save);
}

void read(int sudoku[sud][sud], int sudokubl[sud][sud]) {

	FILE *save;
	FILE *saveblock;
	save = fopen("sudoku.txt", "r");
	saveblock = fopen("sudokublock.txt", "r");

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			fscanf(save, "%d ", &sudoku[i][j]);
			fscanf(saveblock, "%d ", &sudokubl[i][j]);
		}
	}
	fclose(save);
	fclose(saveblock);
}

int main() {

	do {
		read(sudoku, sudokubl);//Reads a file
		tablica(sudoku);//Draw table
		do {
			do {
				printf("\n Which box do you want to change ?\n");
				printf(" Enter x, y : ");
				scanf("%d %d", &x, &y);
			} while (((x < 1) && (x > 9) && (y < 1) && (y > 9)) || (sudokubl[y - 1][x - 1] == 1));	//till a point of change is ok

			printf("\n Enter value <1-9> : ");
			scanf("%d", &value);
		} while ((value < 1) && (value > 9) || ((sprawdzanie(sudoku, value, x, y, sudokubl)) == 1));	//till value is proper
		save(sudoku);
		system("CLS");
	} while (finalcheck != 0);//till all values are different than 0

	return 0;
}
