#pragma once
#include "movieTheaterDB_actor.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "helper.h"
#include <string.h>


typedef struct{
    int id;
    char name[100];
    char genre[25];
    float rating;
    actor actor;
}movie;


typedef struct{
    movie* data;
    movieNode* next;
}movieNode;

void insertMovie(movieNode* movieDB){
  // Malloc newMovie since we need this on heap
    movie *newMovie = (movie *)malloc(sizeof(movie));

    // Scanning Movie ID
    printf("Enter movie code:");
    scanf(" %d", &(newMovie->id));
    getchar();

    // Error checking
    if (newMovie->id > 100 || newMovie->id < 0 || checkMovieDB(movieDB, newMovie->id) == true)
    {
        printf("Error: That Code is invalid.");
        free(newMovie);
        return;
    }

    // Checks if new value ends in \n which means the full value fit within the limit (99). Otherwise, flush buffer
    printf("Enter movie name: ");
    if (fgets(newMovie->name, 99, stdin) != NULL)
    {
        if (strchr(newMovie->name, '\n') == NULL)
        {
            // fgets read the maximum number of characters
            flushBuffer();
        }
    }
    // Checks if new value ends in \n which means the full value fit within the limit (24). Otherwise, flush buffer
    printf("Enter movie genre: ");
    if (fgets(newMovie->genre, 24, stdin) != NULL)
    {
        if (strchr(newMovie->genre, '\n') == NULL)
        {
            // fgets read the maximum number of characters
            flushBuffer();
        }
    }

    printf("Enter movie rating: ");
    scanf(" %f", &(newMovie->rating));
    getchar();

    // Error Checking
    if (newMovie->rating > 10.0 || newMovie->rating < 0.0)
    {
        printf("Error: Your rating is out of bounds.");
        free(newMovie);
        return NULL;
    }

    return newMovie;
}

//Checks for Movie based on ID in the Database
bool checkMovieDB(movieNode* movieDB, int id){
    movieNode* node = movieDB;

    while (node != NULL){
        if (node->data->id == id){
            return true;
        }
    }
    return false;
}

int deleteMovie(movieNode* movieDB, int id){
    movieNode* past = NULL;
    movieNode* node = movieDB;

    while (node != NULL){
        if (node->data->id == id){
            past->next = node->next;
            return 0;
        }
        past = node;
        node = past->next;
    }
    return -1;
};


int cleanDatabase(movieNode* movieDB){
    movieNode* node = movieDB;
    movieNode* prev;
    while (node != NULL){
        free(node->data);
        prev = node;
        node = node->next;
        free(prev);
    }
    free(node->data);
    free(node);
    return 0;
};

void appendMovieToDB(movieNode* movieDB, movie* movie){
    movieNode* newMovie = (movieNode*) malloc(sizeof(movieNode));
    movieNode* node = movieDB;
    while (node != NULL){
        node = node->next;
    }
    newMovie->data = movie;
    return;
}
