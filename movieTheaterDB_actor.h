#pragma once

#include "helper.h"
#include "fort.h"
#include <string.h>

typedef struct
{
    int id;
    char name[50];
    int age;
    char imdb[50];
} actor;

typedef struct
{
    actor *data;
    struct actorNode *next;
} actorNode;

/**
 * @param actorDB
 *  A pointer reference to the Actor Dataabase
 * @note
 *  Used for initially adding a actor into an actorDB. Asks series of questions to fill out information.
 * @return
 *  Returns nothing. All Errors are handled within the Function itself
 */
void insertActor(actorNode *actorDB);
/**
 * @param actorDB
 *  A pointer reference to the Actor Database.
 * @param id
 *  The actor id used to check the DB with.
 * @return
 *  Returns Actor if it exists, otherwise Null.
 */
actor *checkActorDB(actorNode *actorDB, int id);
/**
 * @param actorDB
 *  A pointer reference to the Actor Database.
 * @param id
 *  The actor id used to check the DB with.
 * @return
 *  Returns Integer Status Code.
 */
int deleteActor(actorNode **actorDB, int id);
/**
 * @param actorDB
 *  A pointer Reference to the Actor Database
 *
 * @param id
 *  id represents the corresponding actor id to update
 *
 * @note
 *  This function updates an existing actor entry in the database.
 */
void updateActor(actorNode *actorDB, int id);
/**
 * @param actorDB
 *  A pointer reference to the Actor Database.
 *
 * @note
 *  Frees all memory from the DB.
 */
int cleanActorDatabase(actorNode *actorDB);

/**
 * @param actorDB
 *  A pointer reference to the Actor Database.
 * @note
 *  This is different from insertMovie as it ONLY adds actor to DB, whereas insertMovie grabs details for creating the initial actor struct
 * @param actor
 *  New Actor struct to be added to the Database.
 */
void appendActorToDB(actorNode *actorDB, actor *actor);
/**
 * @param movi
 *  A pointer Reference to a single actor
 *
 * @note
 *  Prints out a single actor in a neatly formatted table.
 */
void printActor(actor *actor);
/**
 * @param actorDB
 *  A pointer Reference to the Actor Database
 *
 * @note
 *  Prints out the entire database of movies in a neatly formatted table.
 */
void printActors(actorNode *actorDB);
/**
 * @param moveieDB
 *  A pointer Reference to the Actor Database
 *
 * @note
 *  Dumps entire Actor Database to "actorDB.bin"
 *
 */
void dumpActorDB(actorNode *actorDB);
/**
 * @note
 *  Restores entire Actor Database from "actorDB.bin"
 *
 */
actorNode *restoreActorDB();