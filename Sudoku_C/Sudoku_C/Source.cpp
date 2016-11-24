#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


#define sud 9
int sudoku[sud][sud];
int wartosc;
int x, y;


void tablica(int sudoku[sud][sud]) {


	for (int i = 0; i < sud; i++) {
		for (int j = 0; j < sud; j++) {
			printf("%3.d", sudoku[i][j]);	  //liczby
			while ((j == 2) || (j == 5)) {		//odstêpy
				printf("|");
				break;
			}	//pêtla while
		}	 //pêtla for


		printf("\n");


		while ((i == 2) || (i == 5)) {
			for (int k = 0; k < 15; k++)
				printf(" -");
			printf("\n");
			break;
		}//pêtla while ^


	}//1 pentla


}


int sprawdzanie(int sudoku[sud][sud], int wartosc, int x, int y) {


	//wprowadzanie i sprawdzanie miejsca zmiany
	int Ywar, Xwar;


	int warunek = 0;


	Ywar = Xwar = 0;


	if ((y >= 4) && (y <= 6))
		Ywar = 3;
	else if (y >= 7)
		Ywar = 6;


	if ((x >= 4) && (x <= 6))
		Xwar = 3;
	else if (x >= 7)
		Xwar = 6;


	for (int i = 0; i < 9; i++) {
		if ((wartosc == sudoku[y - 1][i]) || (wartosc == sudoku[i][x - 1])) {
			warunek = 1;
			break;
		}
	}


	for (int k = Ywar; k < (Ywar + 3); k++)		//3-6	6 - 9
		for (int j = Xwar; j < (Xwar + 3); j++)
			if (sudoku[k][j] == wartosc)
				warunek = 1;


	if (warunek == 0){
		sudoku[y - 1][x - 1] = wartosc;
		printf("\nDobrze ! Jedziemy dalej\n\n");
	}
	else{
		printf("Nie mozna tego dodac, poniewaz bedzie to lamanie zasad sudoku !!\nWartosci nie moga sie powtarzac w obu osiach !!\nWracamy do poczatku zmiany !!\n");
	}
	return warunek;
}


int main(){


	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			sudoku[i][j] = 0;




	sudoku[0][1] = 5;
	sudoku[0][2] = 3;
	sudoku[0][3] = 2;
	sudoku[0][5] = 7;
	sudoku[0][8] = 8;
	sudoku[1][0] = 6;
	sudoku[1][2] = 1;
	sudoku[1][3] = 5;
	sudoku[1][8] = 2;
	sudoku[2][0] = 2;
	sudoku[2][3] = 9;
	sudoku[2][4] = 1;
	sudoku[2][5] = 3;
	sudoku[2][7] = 5;
	sudoku[3][0] = 7;
	sudoku[3][1] = 1;
	sudoku[3][2] = 4;
	sudoku[3][3] = 6;
	sudoku[3][4] = 9;
	sudoku[3][5] = 2;
	sudoku[4][1] = 2;
	sudoku[4][7] = 6;
	sudoku[5][3] = 4;
	sudoku[5][4] = 5;
	sudoku[5][5] = 1;
	sudoku[5][6] = 2;
	sudoku[5][7] = 9;
	sudoku[5][8] = 7;
	sudoku[6][1] = 6;
	sudoku[6][3] = 3;
	sudoku[6][4] = 2;
	sudoku[6][5] = 5;
	sudoku[6][8] = 9;
	sudoku[7][0] = 1;
	sudoku[7][5] = 6;
	sudoku[7][6] = 3;
	sudoku[7][8] = 4;
	sudoku[8][0] = 8;
	sudoku[8][3] = 1;
	sudoku[8][5] = 9;
	sudoku[8][6] = 6;
	sudoku[8][7] = 7;

	do{
		do{
			tablica(sudoku);
			do {
				printf("\nGdzie chcesz zmienic pole ?\n");
				printf("Podaj x, y : ");
				scanf("%d %d", &x, &y);
			} while (((x < 1) && (x > 9)) && ((y < 1) && (y > 9)));
			do {
				printf("\nPodaj wartosc <1-9> : ");
				scanf("%d", &wartosc);
			} while ((wartosc < 1) && (wartosc > 9));
		} while ((sprawdzanie(sudoku, wartosc, x, y)) != 1);
	} while ((sprawdzanie(sudoku, wartosc, x, y)) == 0);






	return 0;
}


