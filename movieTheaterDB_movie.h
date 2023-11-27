#pragma once
#include "movieTheaterDB_actor.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


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
    movie* newMovie = (movie*) malloc(sizeof(movie));


    printf("YOU'VE SELECTED TO CREATE A NEW MOVIE\n\n");
    printf("Please Enter a Movie Code: ");
    scanf("%d", newMovie->)
}

bool checkMovie(movieNode* movieDB, int id){
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
