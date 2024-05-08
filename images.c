//CS 135 Final Project
//Authors: Peyton Otey & Jarenz Romero
//Date: 05/01/2024

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 500

void load_image(char filename[], char image[][MAX_SIZE], int *rows, int *columns);
void display_image(char image[][MAX_SIZE], int rows, int columns);
void edit_image(char image[][MAX_SIZE], int *rows, int *columns);
void crop_image(char image[MAX_SIZE][MAX_SIZE], int *rows, int *columns, int crop_left_column, int crop_right_column, int crop_top_row, int crop_bottom_row);
void dim_image(char image[][MAX_SIZE], int rows, int columns);
void brighten_image(char image[][MAX_SIZE], int rows, int columns);
void save_image(char image[][MAX_SIZE], int rows, int columns);


      
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
				edit_image(image, &rows, &columns);
				break;
			case 0:
				printf("Goodbye!\n");
				return 0;
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
	for (int i = 0; i < rows + 1; i++) {
		for (int k = 0; k < columns + 1; k++) {
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

void edit_image(char image[MAX_SIZE][MAX_SIZE], int *rows, int *columns) {
	char choice;
	do {
		printf("**EDITING**\n");
		printf("1: Crop image\n");
		printf("2: Dim image\n");
		printf("3: Brighten image\n");
		printf("0: Return to main menu\n");
		printf("Choose from one of the options above: ");
		scanf(" %c", &choice);
		
		switch (choice) {
			case '1':
				printf("\n");			
				display_image(image, *rows, *columns);
				printf("The image you want to crop is %d x %d.\n", *rows, *columns);
				printf("The row and column values start in the upper lefthand corner.\n");
				int crop_left_column, crop_right_column, crop_top_row, crop_bottom_row;
				printf("\nWhich column do you want to be the new left side? ");
				scanf("%d", &crop_left_column);
				printf("Which column do you want to be the new right side? ");
				scanf("%d", &crop_right_column);
				printf("Which row do you want to be the new top? ");
				scanf("%d", &crop_top_row);
				printf("Which row do you want to be the new bottom? ");
				scanf("%d", &crop_bottom_row);
				printf("\n");				
				crop_image(image, rows, columns, crop_left_column, crop_right_column, crop_top_row, crop_bottom_row);
				display_image(image, *rows, *columns);
				save_image(image, *rows, *columns);
				return;
			case '2':
				dim_image(image, *rows, *columns);
				display_image(image, *rows, *columns);
				save_image(image, *rows, *columns);
				return;
			case '3':
				brighten_image(image, *rows, *columns);
				display_image(image, *rows, *columns);
				save_image(image, *rows, *columns);
				return;
			case '0':
				printf("\nReturning to main menu.\n\n");
				return;
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
           		if(pixels >= '0' && pixels < '4') {
                		image[i][k] = pixels + 1;               		             		 
            		}  
            	}
       	 }
}

void crop_image(char image[MAX_SIZE][MAX_SIZE], int *rows, int *columns, int crop_top_row, int crop_bottom_row, int crop_left_column, int crop_right_column) {		
	int cropped_rows = crop_bottom_row - crop_top_row + 1;
	int cropped_columns = crop_right_column - crop_left_column + 1;
	char cropped_image[cropped_rows][cropped_columns];	
	
	for(int i = 0; i < cropped_rows; i++) {
        	for(int k = 0; k < cropped_columns; k++) {
            		cropped_image[i][k] = image[crop_top_row + i][crop_left_column + k];
        	}
	}
	*rows = cropped_columns;
	*columns = cropped_rows;
	for(int i = 0; i < cropped_rows; i++){
    		for(int k = 0; k < cropped_columns; k++) {
    		image[i][k] = cropped_image[i][k];
		}
	}
}

void save_image(char image[][MAX_SIZE], int rows, int columns) {
    char choice;

    printf("Would you like to save the file? (y/n) ");
    scanf(" %c", &choice);

    printf("\n");

    if (choice == 'Y' || choice == 'y') {
        char filename[MAX_SIZE];
        printf("What do you want to name the image file? (include the extension) ");
        scanf("%s", filename);
        printf("\n");

        FILE *file = fopen(filename, "w");
        if (file == NULL) {
            printf("Error opening the file.\n");
            return;
        }

        for (int i = 0; i < rows; i++) {
            for (int k = 0; k < columns; k++) {
                fprintf(file, "%c", image[i][k]);
            }
            fprintf(file, "\n");
        }

        fclose(file);
        printf("Image successfully saved!\n");
    } else if (choice == 'N' || choice == 'n') {
        return;
    } else {
        printf("Invalid choice. Returning to main menu.\n");
    }
}




	
			
