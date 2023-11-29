#include <stdio.h>
#include <stdbool.h>
#include "movieTheaterDB_movie.h"


int main(void){

    bool running = true;
    movieNode* movieDB = (movieNode*) malloc(sizeof(movieNode));
    movieDB->data = NULL;
    movieDB->next = NULL;


    while(running){
        char operation = 'i'; // Sets default operation which will get overwritten later
        printf("\nEnter operation code: ");
        scanf(" %c", &operation);
        getchar();

        switch(operation){
            case 'h':
            case 'm':
                int id;
                printf("Enter Movie Operation Code: ");
                scanf(" %c", &operation);
                getchar();

                switch(operation){
                    case 'i':
                        insertMovie(movieDB);
                        break;
                    case 's':
                        printf("Enter a Movie Code to print out: ");
                        scanf(" %d", &id);
                        getchar();
                        if (checkMovieDB(movieDB, id) != NULL){
                            printMovie(checkMovieDB(movieDB, id));
                        }
                        else{
                            printf("Error: That Movie ID was not found.\n");
                        }
                        break;
                    case 'u':
                    case 'p':
                    case 'e':
                        printf("Enter a Movie Code to Erase: ");
                        scanf(" %d", &id);
                        getchar();
                        if (checkMovieDB(movieDB, id) != NULL){
                            deleteMovie(movieDB, id);
                            printf("Deleted Movie with ID: %d\n", id);
                        }
                        else{
                            printf("Error: That Code was not located.");
                        }
                        break;
                }
                break;
            case 'a':
            case 'q':
                cleanDatabase(movieDB);
        }
    }


    return 0;
}