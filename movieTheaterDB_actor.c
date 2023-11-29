#include "movieTheaterDB_actor.h"


void insertActor(actorNode* actorDB){
    // Malloc newMovie since we need this on heap
    actor *newActor = (actor *)malloc(sizeof(actor));

    // Scanning Movie ID
    printf("Enter actor code:");
    scanf(" %i", &(newActor->id));
    getchar();

    // Error checking
    if (newActor->id < 0 || checkActorDB(actorDB, newActor->id) != NULL)
    {
        printf("Error: That Code is invalid.");
        free(newActor);
        return;
    }

    // Checks if new value ends in \n which means the full value fit within the limit (99). Otherwise, flush buffer
    printf("Enter actor name: ");
    if (fgets(newActor->name, 49, stdin) != NULL)
    {
        if (strchr(newActor->name, '\n') == NULL)
        {
            // fgets read the maximum number of characters
            flushBuffer();
        }
    }
    // Checks if new value ends in \n which means the full value fit within the limit (24). Otherwise, flush buffer
    printf("Enter actor age: ");
    scanf(" %i", &(newActor->age));
    getchar();

    // Error checking
    if (newActor->age < 0 || newActor->age > 120)
    {
        printf("Error: That age is invalid.");
        free(newActor);
        return;
    }

    printf("Enter actor IMDB: ");
    if (fgets(newActor->imdb, 49, stdin) != NULL)
    {
        if (strchr(newActor->imdb, '\n') == NULL)
        {
            // fgets read the maximum number of characters
            flushBuffer();
        }
    }
    appendActorToDB(actorDB, newActor);
}

actor* checkActorDB(actorNode* actorDB, int id)
{
    actorNode *node = actorDB;

    if (actorDB->data == NULL){
        return NULL;
    }


    while (node != NULL)
    {
        if (node->data->id == id)
        {
           return node->data;
        }
        node = node->next;  // Move to the next node
    }
    return NULL;
}

int deleteActor(actorNode **actorDB, int id);

int cleanActorDatabase(actorNode *actorDB);

void appendActorToDB(actorNode* actorDB, actor* actor)
{
    actorNode *newActorNode = (actorNode *)malloc(sizeof(actorNode));
    actorNode *node = actorDB;
    if (actorDB->data == NULL){
        actorDB->data = actor;
        free(newActorNode);
        return;
    }

    while (node->next != NULL)
    {
        node = node->next;
    }
    newActorNode->data = actor;
    newActorNode->next = NULL;
    node->next = newActorNode;
    return;
}

void printActor(actor* actor)
{
    // Strings needed for the printing function, so we convert later with sprintf
    char stringid[4];
    char stringAge[4];

    // Table Boilerplate
    ft_table_t *table = ft_create_table();
    ft_set_cell_prop(table, 0, FT_ANY_COLUMN, FT_CPROP_ROW_TYPE, FT_ROW_HEADER);
    ft_write_ln(table, "Actor Code", "Actor Name", "Actor Age", "IMDB URL");

    // Convert to Strings
    sprintf(stringid, " %d", actor->id);
    sprintf(stringAge, "%i", actor->age);

    // Main Printing Function for the table
    ft_write_ln(table, stringid, actor->name, stringAge, actor->imdb);

    printf("%s", ft_to_string(table));

    // Cleanup
    ft_destroy_table(table);
}


void eraseActor(actorNode* actorDB, int id);

void printActors(actorNode* actorDB)
{   
    actorNode* node = actorDB;
    // Strings needed for the printing function, so we convert later with sprintf
    char stringid[4];
    char stringAge[4];

    // Table Boilerplate
    ft_table_t *table = ft_create_table();
    ft_set_cell_prop(table, 0, FT_ANY_COLUMN, FT_CPROP_ROW_TYPE, FT_ROW_HEADER);
    ft_write_ln(table, "Actor Code", "Actor Name", "Actor Age", "IMDB URL");

    while (node != NULL){
    // Convert to Strings
    sprintf(stringid, " %d", node->data->id);
    sprintf(stringAge, "%i", node->data->age);

    // Main Printing Function for the table
    ft_write_ln(table, stringid, node->data->name, stringAge, node->data->imdb);
    }
    
    printf("%s", ft_to_string(table));

    // Cleanup
    ft_destroy_table(table);
}