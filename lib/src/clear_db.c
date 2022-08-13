#include "../headers/clear_db.h"

#define YES_LEN 3

bool clear_db(void)
{
    char *user_choice = (char *)malloc(YES_LEN);
    bool drop_db = 0;

    printf("Drop the db? (This action is irreversible!)\n");
    printf("Enter yes or no: ");
    scanf("%s", user_choice);

    drop_db = strncmp(user_choice, "yes", YES_LEN) == 0;
    if (drop_db)
    {
        FILE *db = fopen(DB_NAME, "w");
        CHECK_FILE(db);
        fclose(db);
    }

    free(user_choice);

    return drop_db;
}