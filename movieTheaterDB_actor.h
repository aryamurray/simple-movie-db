#pragma once

#include "helper.h"
#include "fort.h"

typedef struct{
    int id;
    char name[50];
    int age;
    char imdb[50];
}actor;

typedef struct{
    actor* data;
    struct actorNode* next;
}actorNode;


void insertActor(actorNode* actorDB);

actor* checkActorDB(actorNode* actorDB, int id);

int deleteActor(actorNode **actorDB, int id);

int cleanActorDatabase(actorNode* actorDB);

void appendActorToDB(actorNode* actorDB, actor* actor);

void printActor(actor* actor);

void eraseActor(actorNode* actorDB, int id);

void printActors(actorNode* actorDB);