#include "movieTheaterDB_movie.h"

void insertMovie(movieNode *movieDB)
{
    // Malloc newMovie since we need this on heap
    movie *newMovie = (movie *)malloc(sizeof(movie));

    // Scanning Movie ID
    printf("Enter movie code:");
    scanf(" %i", &(newMovie->id));
    getchar();

    // Error checking
    if (newMovie->id < 0 || checkMovieDB(movieDB, newMovie->id) == true)
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
        return;
    }
    appendMovieToDB(movieDB, newMovie);
}

// Checks for Movie based on ID in the Database
movie* checkMovieDB(movieNode *movieDB, int id)
{
    movieNode *node = movieDB;

    if (movieDB->data == NULL){
        return false;
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


int deleteMovie(movieNode* movieDB, int id){
    movieNode* past = NULL;
    movieNode* node = movieDB;
    if (node->next == NULL){
        free(movieDB->data);
        movieDB->data = NULL;
        return 0;
    }
    if (node != NULL && node->data->id == id){
        movieDB = node->next;
        free(node->data);
        free(node);
        return 0;
    }

    while (node != NULL && node->data->id != id){
        past = node;
        node = node->next;
    }

    if (node == NULL) return -1;

    past->next = node->next;
    free(node->data);
    free(node);

    return 0;
}


// Should Work
int cleanDatabase(movieNode *movieDB)
{
    movieNode *node = movieDB;
    movieNode *prev;
    while (node != NULL)
    {
        free(node->data);
        prev = node;
        node = node->next;
        free(prev);
    }
    return 0;
}

// Should Work
void appendMovieToDB(movieNode *movieDB, movie *movie)
{
    movieNode *newMovieNode = (movieNode *)malloc(sizeof(movieNode));
    movieNode *node = movieDB;
    if (movieDB->data == NULL){
        movieDB->data = movie;
        free(newMovieNode);
        return;
    }

    while (node->next != NULL)
    {
        node = node->next;
    }
    newMovieNode->data = movie;
    newMovieNode->next = NULL;
    node->next = newMovieNode;
    return;
}

void printMovie(movie *movie)
{
    // Strings needed for the printing function, so we convert later with sprintf
    char stringid[4];
    char stringRating[4];

    // Table Boilerplate
    ft_table_t *table = ft_create_table();
    ft_set_cell_prop(table, 0, FT_ANY_COLUMN, FT_CPROP_ROW_TYPE, FT_ROW_HEADER);
    ft_write_ln(table, "Movie Code", "Movie name", "Movie Genre", "Movie Rating");

    // Convert to Strings
    sprintf(stringid, " %d", movie->id);
    sprintf(stringRating, "%.1f", movie->rating);

    // Main Printing Function for the table
    ft_write_ln(table, stringid, movie->name, movie->genre, stringRating);

    printf("%s", ft_to_string(table));

    // Cleanup
    ft_destroy_table(table);
}
