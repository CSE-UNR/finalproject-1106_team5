//CS 135 Final Project
//Authors: Peyton Otey & Jarenz Romero
//Date: 05/01/2024

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 150

void load_image(char filename[], char image[MAX_SIZE][MAX_SIZE], int *rows, int *columns);
void display_image(char image[MAX_SIZE][MAX_SIZE], int rows, int columns);
void edit_image(char image[MAX_SIZE][MAX_SIZE], int rows, int columns);
void save_image(char filename[], char image[MAX_SIZE][MAX_SIZE], int rows, int columns);
void crop_image(char image[MAX_SIZE][MAX_SIZE], int *rows, int *columns);
void dim_image(char image[MAX_SIZE][MAX_SIZE], int rows, int columns);
void brighten_image(char image[MAX_SIZE][MAX_SIZE], int rows, int columns);
bool is_valid_index(int index, int max);

int main () {
	char filename[50], choice;
	char image [MAX_SIZE][MAX_SIZE];
	int rows = 0, columns = 0;
	
	do {
		printf("**ERINSTAGRAM**\n");
		printf("1: Load image\n");
		printf("2: Display image\n");
		printf("3: Edit image\n");
		printf("0: Exit\n");
		printf("Choose from one of the options above: \n");
		scanf(" %c", &choice);
		
		switch (choice) {
			case '1':
				printf("What is the name of the image file?  ");
				fgets(filename, sizeof(filename), stdin);
				load_image(filename, image, &rows, &columns);
				break;
			case '2':
				display_image(image, rows, columns);
				break;
			case '3':
				edit_image(image, rows, columns);
				break;
			case '0':
				printf("\nGoodbye!\n");
				break;
			default:
				printf("Invalid option, please try again.");
			}
		} while (choice != '0');
		
	return 0;
}

void load_image(char filename[], char image[MAX_SIZE][MAX_SIZE], int *rows, int *columns,) { 		
	FILE *file = fopen(filename, "r");
	if (file == '\0') {
		printf("Error opening the file.\n");
		return;
	}
	
	*rows = 0
	*columns = 0
	char line[MAX_SIZE];
	while (fgets(line, MAX_SIZE, file) != '\0') {
		int length = 0;
		while (line[length] != '\0' && line[length] != '\n') {
			image[*rows][length] = line[length];
			length++;
		}
		if (length > *columns) {
			*columns = length;
		}
		(*rows)++;
	}
	
	fclose(file);
)

void display_image(char image[MAX_SIZE][MAX_SIZE], int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int k = 0; k < columns; k++) {
			printf("%c", image[i][k]);
		}
	}
}

void edit_image(char image[MAX_SIZE][MAX_SIZE], int rows, int columns) {
	char choice;
	do {
		printf("**EDITING**\n");
		printf("1: Crop image\n");
		printf("2: Dim image\n");
		printf("3: Brighten image\n");
		printf("0: Return to main menu\n");
		printf("Choose from one of the options above: \n");
		scanf(" %c", &choice);
		
		switch (choice) {
			case '1':
				crop_image(image, &rows, &columns);
				display_image(image, rows, columns);
				break;
			case '2':
				dim_image(image, &rows, &columns);
				display_image(image, rows, columns);
				break;
			case '3':
				brighten_image(image, &rows, &columns);
				display_image(image, rows, columns);
				break;
			case '0':
				printf("Returning to main menu.\n");
				break;
			default:
				printf("Invalid choice, please try again.\n");
			}
	} while (choice != 0);
}

void save_image(char filename[], char image[MAX_SIZE][MAX_SIZE], int rows, int columns) {
	FILE *file = fopen(filename, "w");
	if (file == '\0') {
		printf("Error opening the file.\n");
		return;
	}
	
	for (int i = 0; i < rows; i++) {
		fputs(image[i], file);
	} 
	
	fclose(file);
	
	char choice;
	printf("Would you like to save the file? (y/n) ");
	scanf(" %c", &choice);
	if (choice == 'y' || choice == 'Y') {
		printf("What do you want to name the image file? (include the extension) ");
		fgets(filename, sizeof(filename), stdin);
	}
}

void crop_image(char image[MAX_SIZE][MAX_SIZE], int *rows, int *columns) {
	int row_start, row_end, column_start, column_end;
	printf("The image you want to crop is %c x %c", *rows, *column);
	printf("The row and column values start in the upper left hand corner.");
	printf("Which column do you want to be the new left side? ");
	scanf("%d", &column_start);
	printf("Which column do you want to be the new right side? ");
	scanf("%d", &column_end);
	printf("Which row do you want to be the new top? ");
	scanf("%d", &row_start);
	printf("Which row do you want to be the new bottom? ");
	scanf("%d", &row_end);
	
	if (row_start < 0 || row_start >= *rows || row_end < row_start || row_end >= *rows) {
		printf("Invalid row value. Choose a value between %c and %c: ", *rows, *rows);
		return;
	}
	if (column_start < 0 || column_start >= *columns || column_end <column_start || column_end >= *columns) {
	printf("Invalid column value. Choose a new value between %c and %c: ", *columns, *columns);
	
	int new_rows = row_end - row_start + 1;
	int new_columns = column_start - column_end + 1;
	
	char cropped_image[MAX_SIZE][MAX_SIZE];
	for(int i = 0;i < new_rows; i++) {
		for(int k = 0; k < new_columns; k++) {
			cropped)image[i][k] = image[row_start + i][column_start + k];
		}
		cropped_image[i][new_columns] = '\0';
	}
	
	*rows = new_rows;
	*columns = new_colums;
	for(int i = 0; i < new_rows; i++) {
		image[i][k] = cropped_image[i][k];
	}
	}
}

	
			

