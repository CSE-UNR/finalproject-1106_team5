//CS 135 Final Project
//Authors: Peyton Otey & Jarenz Romero
//Date: 05/01/2024

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 150

void load_image(char filename[], char image[][MAX_SIZE], int *rows, int *columns);
void display_image(char image[][MAX_SIZE], int rows, int columns);
void edit_image(char image[][MAX_SIZE], int rows, int columns);
void dim_image(char image[][MAX_SIZE], int rows, int columns);

      
int main () {
	char image [MAX_SIZE][MAX_SIZE];
	int rows = 0, columns = 0;
	int choice;
	
	do {
		printf("\n**ERINSTAGRAM**\n");
		printf("1: Load image\n");
		printf("2: Display image\n");
		printf("3: Edit image\n");
		printf("0: Exit\n");
		printf("Choose from one of the options above: \n");
		scanf(" %d", &choice);
		
		switch (choice) {
			case 1:
				char filename[MAX_SIZE];
				printf("\nWhat is the name of the image file? ");
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
	printf("\nImage successfully loaded!\n");
		
}

void display_image(char image[MAX_SIZE][MAX_SIZE], int rows, int columns) {
	printf("\n");
	for (int i = 0; i < rows; i++) {
		for (int k = 0; k < columns; k++) {
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
	
			case '2':
				dim_image(image, rows, columns);
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

    char brightness[] = " O.o0";

    for (int i = 0; i < rows; i++) {
        for (int k = 0; k < columns; k++) {
            char pixel = image[i][k];

            if (pixel >= '0' && pixel <= '4') {
                int brightness_index = pixel - '0';

                brightness_index = (brightness_index + 1) % 5;
                image[i][k] = brightness[brightness_index];
            }
        }
    }
}



	
			

