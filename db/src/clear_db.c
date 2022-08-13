#include "../headers/clear_db.h"

#define YES_LENGTH 3

int clear_db(void)
{
    char *user_choice = (char *)malloc(YES_LENGTH);
    bool drop_db = 0;

    printf("Are you sure you want to drop/clear the db? (This action is irreversible!)\n");
    printf("Enter yes or no: ");
    scanf("%s", user_choice);

    drop_db = strncmp(user_choice, "yes", YES_LENGTH) == 0;
    if (drop_db)
    {
        FILE *db = fopen(DB_NAME, "w");
        CHECK_FILE(db);
        fclose(db);
    }

    free(user_choice);

    return 0;
}