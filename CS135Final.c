//CS 135 Final Project
//Authors: Peyton Otey & Jarenz Romero
//Date: 05/01/2024

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 150

void load_image(char filename[], char image[][MAX_SIZE], int *rows, int *columns);
void display_image(char image[][MAX_SIZE], int rows, int columns);
void edit_image(char image[][MAX_SIZE], int rows, int columns);
void crop_image(char image[MAX_SIZE][MAX_SIZE], int rows, int columns, int crop_left_column, int crop_right_column, int crop_top_row, int crop_bottom_row);
void dim_image(char image[][MAX_SIZE], int rows, int columns);
void brighten_image(char image[][MAX_SIZE], int rows, int columns);


      
int main () {
	char image [MAX_SIZE][MAX_SIZE];
	int rows = 0, columns = 0;
	int choice;
	
	do {
		printf("**ERINSTAGRAM**\n");
		printf("1: Load image\n");
		printf("2: Display image\n");
		printf("3: Edit image\n");
		printf("0: Exit\n");
		printf("Choose from one of the options above: ");
		scanf(" %d", &choice);
		printf("\n");
		
		switch (choice) {
			case 1:
				char filename[MAX_SIZE];
				printf("What is the name of the image file? ");
				scanf("%s", filename);
				load_image(filename, image, &rows, &columns);
				break;
			case 2:
				display_image(image, rows, columns);
				break;
			case 3:
				edit_image(image, rows, columns);
				break;
			case 0:
				printf("\nGoodbye!\n");
				break;
			default:
				printf("\nInvalid option, please try again.");
			}
		} while (choice != '0');
		
	return 0;
}

void load_image(char filename[], char image[MAX_SIZE][MAX_SIZE], int *rows, int *columns) { 		
	FILE *file = fopen(filename, "r");
	if (file == NULL) {
		printf("Error opening the file.\n");
		return;
	}
	
	*rows = *columns = 0;	
	while (fscanf(file, "%c", &image[*rows][*columns]) == 1) {
		if (image[*rows][*columns] == '\n') {
		(*rows)++;
		*columns = 0;
	} else {
		(*columns)++;
	}
	}
	fclose(file);
	printf("\nImage successfully loaded!\n\n");
		
}

void display_image(char image[MAX_SIZE][MAX_SIZE], int rows, int columns) {
	for (int i = 0; i <= rows; i++) {
		for (int k = 0; k <= columns; k++) {
			char pixels = image[i][k];
			switch(pixels) {
				case '0':
					printf(" ");
					break;
				case '1':
					printf(".");
					break;
				case '2':
					printf("o");
					break;
				case '3':
					printf("O");
					break;
                		case '4':
                    			printf("0");
                    			break;
                    		default:
                    			printf("%c", pixels);
			}
		}
		printf("\n");
	}
	printf("\n");
}

void edit_image(char image[MAX_SIZE][MAX_SIZE], int rows, int columns) {
	char choice;
	do {
		printf("\n**EDITING**\n");
		printf("1: Crop image\n");
		printf("2: Dim image\n");
		printf("3: Brighten image\n");
		printf("0: Return to main menu\n");
		printf("Choose from one of the options above: ");
		scanf(" %c", &choice);
		
		switch (choice) {
			case '1':
				int crop_left_column, crop_right_column, crop_top_row, crop_bottom_row;
				printf("Which column do you want to be the new left side? ");
				scanf("%d", &crop_left_column);
				printf("Which column do you want to be the new right side? ");
				scanf("%d", &crop_right_column);
				printf("Which row do you want to be the new top? ");
                		scanf("%d", &crop_top_row);
                		printf("Which row do you want to be the new bottom? ");
                		scanf("%d", &crop_bottom_row);
				crop_image(image, rows, columns, crop_left_column, crop_right_column, crop_top_row, crop_bottom_row);
				display_image(image, rows, columns);
				break;
			case '2':
				dim_image(image, rows, columns);
				display_image(image, rows, columns);
				break;
			case '3':
				brighten_image(image, rows, columns);
				display_image(image, rows, columns);
				break;
			case '0':
				printf("Returning to main menu.\n");
				break;
			default:
				printf("Invalid choice, please try again.\n");
			}
	} while (choice != '0');
}

void dim_image(char image[][MAX_SIZE], int rows, int columns) {
	printf("\n");
	for (int i = 0; i <= rows; i++) {
        	for (int k = 0; k <= columns; k++) {
            	char pixels = image[i][k];
           	 if (pixels >= '1' && pixels <= '4') {
                image[i][k] = pixels - 1; 
            	}
       	 	}
   	 }
}

void brighten_image(char image[][MAX_SIZE], int rows, int columns) {	
	printf("\n");
	for(int i = 0; i <= rows; i++) {
        	for(int k = 0; k <= columns; k++) {
            		char pixels = image[i][k];
           		if(pixels >= '0' && pixels <= '4') {
                		image[i][k] = pixels + 1;                		
            		}
            	}
       	 }
}

void crop_image(char image[MAX_SIZE][MAX_SIZE], int rows, int columns, int crop_top_row, int crop_bottom_row, int crop_left_column, int crop_right_column) {
    if (crop_top_row < 0 || crop_bottom_row >= rows || crop_left_column < 0 || crop_right_column >= columns ||
        crop_top_row >= crop_bottom_row || crop_left_column >= crop_right_column) {
        printf("Invalid crop dimensions or starting position.\n");
        return;
    }

  
    for (int i = 0; i <= crop_bottom_row - crop_top_row; i++) {
        for (int j = 0; j <= crop_right_column - crop_left_column; j++) {
            image[i][j] = image[crop_top_row + i][crop_left_column + j];
        }
    }

 
    rows = crop_bottom_row - crop_top_row + 1;
    columns = crop_right_column - crop_left_column + 1;

    
    printf("\nCropped Image (Rows: %d, Columns: %d):\n", rows, columns);
    for (int i = 0; i < rows; i++) {
        printf("%2d ", i + 1); 
        for (int j = 0; j < columns; j++) {
            printf("%c", image[i][j]);
        }
        printf("\n");
    }
    printf("   ");
    for (int j = 0; j < columns; j++) {
        printf("%2d", j + 1); 
    }
    printf("\n\n");
}




	
			

