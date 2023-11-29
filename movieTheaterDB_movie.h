#pragma once

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
movie *checkMovieDB(movieNode *movieDB, int id);
/**
 * @param movieDB
 *  A pointer reference to the Movie Database.
 * @param id
 *  The movie id used to check the DB with.
 * @return
 *  Returns Integer Status Code.
 */
int deleteMovie(movieNode **movieDB, int id);

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
/**
 * @param movi
 *  A pointer Reference to a single movie
 *
 * @note
 *  Prints out a single movie in a neatly formatted table.
 */
void printMovie(movie *movie);
/**
 * @param movieDB
 *  A pointer Reference to the Movie Database
 *
 * @param id
 *  id represents the corresponding movie id to delete
 *
 * @note
 *  Deletes a single movie from the database
 */
void eraseMovie(movieNode *movieDB, int id);
/**
 * @param movieDB
 *  A pointer Reference to the Movie Database
 *
 * @note
 *  Prints out the entire database of movies in a neatly formatted table.
 */
void printMovies(movieNode *movieDB);
/**
 * @param movieDB
 *  A pointer Reference to the Movie Database
 *
 * @param id
 *  id represents the corresponding movie id to update
 *
 * @note
 *  This function updates an existing movie entry in the database.
 */
void updateMovie(movieNode *movieDB, int id);
/**
 * @param moveieDB
 *  A pointer Reference to the Movie Database
 *
 * @note
 *  Dumps entire Movie Database to "movieDB.bin"
 *
 */
void dumpMovieDB(movieNode *movieDB);
/**
 * @note
 *  Restores entire Movie Database from "movieDB.bin"
 */
movieNode *restoreMovieDB();