#pragma once
#include "movieTheaterDB_actor.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "helper.h"
#include <string.h>
#include "fort.h"

typedef struct
{
    int id;
    char name[100];
    char genre[25];
    float rating;
    actor actor;
} movie;

typedef struct
{
    movie *data;
    struct movieNode *next;
} movieNode;

/**
 * @param movieDB
 *  A pointer reference to the Movie Dataabase
 * @note
 *  Used for initially adding a movie into a movieDB. Asks series of questions to fill out information.
 * @return
 *  Returns nothing. All Errors are handled within the Function itself
 */
void insertMovie(movieNode *movieDB);
/**
 * @param movieDB
 *  A pointer reference to the Movie Database.
 * @param id
 *  The movie id used to check the DB with.
 * @return
 *  Returns Movie if it exists, otherwise Null.
 */
movie* checkMovieDB(movieNode *movieDB, int id);
/**
 * @param movieDB
 *  A pointer reference to the Movie Database.
 * @param id
 *  The movie id used to check the DB with.
 * @return
 *  Returns Integer Status Code.
 *
 */
int deleteMovie(movieNode *movieDB, int id);

/**
 * @param movieDB
 *  A pointer reference to the Movie Database.
 * 
 * @note
 *  Frees all memory from the DB.
*/
int cleanDatabase(movieNode *movieDB);

/**
 * @param movieDB
 *  A pointer reference to the Movie Database.
 * @note
 *  This is different from insertMovie as it ONLY adds movie to DB, whereas insertMovie grabs details for creating the initial movie struct
 * @param movie
 *  New Movie struct to be added to the Database. 
*/
void appendMovieToDB(movieNode *movieDB, movie *movie);

void printMovie(movie *movie);

void eraseMovie(movieNode* movieDB, int id);