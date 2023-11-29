#include <stdio.h>
#include <stdbool.h>
#include "movieTheaterDB_movie.h"
#include "movieTheaterDB_actor.h"


int main(void){

    bool running = true;
    movieNode* movieDB = (movieNode*) malloc(sizeof(movieNode));
    actorNode* actorDB = (actorNode*) malloc(sizeof(actorNode));
    movieDB->data = NULL;
    movieDB->next = NULL;
    actorDB->data = NULL;
    actorDB->next = NULL;


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
                        printf("Enter a Movie Code to update: ");
                        scanf(" %d", &id);
                        getchar();

                        if (checkMovieDB(movieDB, id) != NULL){
                            updateMovie(movieDB, id);
                        }   
                        else{
                            printf("Error: That Id was not found.\n");
                        }
                        break;
                    case 'p':
                        printMovies(movieDB);
                        break;
                    case 'e':
                        printf("Enter a Movie Code to Erase: ");
                        scanf(" %d", &id);
                        getchar();
                        if (checkMovieDB(movieDB, id) != NULL){
                            deleteMovie(&movieDB, id);
                            printf("Deleted Movie with ID: %d\n", id);
                        }
                        else{
                            printf("Error: That Code was not located.");
                        }
                        break;
                    case 'd':
                        printf("Dumping MovieDB...\n");
                        dumpMovieDB(movieDB);
                        break;
                    case 'r':
                        printf("Restoring MovieDB...\n");
                        movieDB = restoreMovieDB();
                        break;
                }
                break;
            case 'a':
                printf("Enter Actor Operation Code: ");
                scanf(" %c", &operation);
                getchar();

                switch(operation){
                    case 'i':
                        insertActor(actorDB);
                        break;
                    case 's':
                        printf("Enter a Actor Code to print out: ");
                        scanf(" %d", &id);
                        getchar();
                        if (checkActorDB(actorDB, id) != NULL){
                            printActor(checkActorDB(actorDB, id));
                        }
                        else{
                            printf("Error: That Actor ID was not found.\n");
                        }
                        break;
                    case 'u':
                        printf("Enter a Actor Code to update: ");
                        scanf(" %d", &id);
                        getchar();

                        if (checkActorDB(actorDB, id) != NULL){
                            updateActor(actorDB, id);
                        }   
                        else{
                            printf("Error: That Id was not found.\n");
                        }
                        break;
                    case 'p':
                        printActors(actorDB);
                        break;
                    case 'e':
                        printf("Enter an Actor Code to Erase: ");
                        scanf(" %d", &id);
                        getchar();
                        if (checkActorDB(actorDB, id) != NULL){
                            deleteActor(&actorDB, id);
                            printf("Deleted Actor with ID: %d\n", id);
                        }
                        else{
                            printf("Error: That Code was not located.");
                        }
                        break;
                    case 'd':
                        printf("Dumping ActorDB...\n");
                        dumpActorDB(actorDB);
                        break;
                    case 'r':
                        printf("Restoring ActorDB...\n");
                        actorDB = restoreActorDB();
                        break;


                }
                break;
            case 'q':
                cleanDatabase(movieDB);
                cleanActorDatabase(actorDB);
                running = false;
                break;
        }
    }
    return 0;
}