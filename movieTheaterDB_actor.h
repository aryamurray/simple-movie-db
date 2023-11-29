#pragma once

typedef struct{
    int id;
    char name[50];
    int age;
    char imdb[50];
}actor;

typedef struct{
    actor* actor;
    struct actorNode* next;
}actorNode;