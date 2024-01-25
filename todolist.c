#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 500

/*
loop forever:

    if user choice is 1: Add Task
        read task description from user - V
        create a new task with the given description
        add the task to the list

    else if user choice is 2: Mark Task as Complete
        display the list of tasks with their indices
        read the index of the task to mark as complete
        mark the selected task as complete

    else if user choice is 3: Delete Task
        display the list of tasks with their indices
        read the index of the task to delete
        remove the selected task from the list

end loop
*/

char *libvar;

void chooseAnOpt(bool *loop, int *choice) {
    printf("What do you want to do: ");
    scanf("%d", &choice);
    if (choice != 0) {
        *loop = true;
    } else {
        *loop = false;
    }
}

int main(void) {
    int choice;
    char task[MAX];
    int count;
    libvar = getenv("USERNAME");
    bool loop = false;

    FILE *fptr;
    char *ptr = (char*)malloc(1000 * sizeof(char));
    char filepath[50];

    printf("Welcome to your to-do list. What do you want to do today?\nEnter a number from 1-5 included. Here are your options:\n");
    printf("1. Add a task\n2. Mark a task as complete\n3. Delete a task\n4. View your tasks\n5. Exit from the program.\n");
    chooseAnOpt(&loop, &choice);

    do {
        if (choice == 1) {
            if (libvar != NULL) {
                sprintf(filepath, "C:\\Users\\%s\\Documents\\To-Do List.txt", libvar);
            } else {
                printf("Failed to get username.\n");
                return -1;
            }

            fptr = fopen(filepath, "a");
            if (fptr == NULL) {
                printf("Error opening the file.\n");
                break;
            }

            printf("How many tasks do you want to add? ");
            scanf("%d", &count);

            for (int i = 0; i <= count; i++) {
                fgets(task, MAX, stdin);
            }
            fclose(fptr);
            loop = false;
        } else if (choice == 2) {
            // TODO
            loop = false;
        } else if (choice == 3) {
            // TODO
            loop = false;
        } else if (choice == 4) {
            printf("Here is your to-do list:\n ");
            fptr = fopen(filepath, "r");

            if (fptr == NULL) {
                printf("Error opening the file.\n");
                break;
            }

            fgets(ptr, 1000, fptr);
            printf("%s\n", ptr);
            fclose(fptr);
            free(ptr);
            loop = false;
        } else if (choice > 5 || choice <= 0) {
            printf("Error in the choice, enter a number from 1-5 included.\n");
            loop = false;
        }
    } while (!loop);

    if (choice == 5) { 
        printf("Exiting.. Bye!\n");
        return 0;
    }
}