#include "../headers/clear_db.h"

bool clear_db(void)
{
    char *user_choice = (char *)malloc(YES_LEN);
    CHECK_MALLOC(user_choice);

    bool drop_db = 0;

    printf("Drop the db? (This action is irreversible!)\nEnter yes or no: ");
    fgets(user_choice, YES_LEN, stdin);

    drop_db = strncmp(user_choice, "yes", YES_LEN) == 0;
    if (drop_db)
    {
        FILE *db = fopen(DB_NAME, "w");
        CHECK_FILE(db);
        fclose(db);
    }

    free(user_choice);

    printf("Successfully dropped db: %d\n", drop_db);
    return drop_db;
}