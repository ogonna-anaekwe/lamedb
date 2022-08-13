#ifndef __show_records_h__
#define __show_records_h__

#include "init_db.h"

/**
 * Prints all records in the db.
 * @param existing_record Records in the db.
 * @param cmd Query: a(ll).
 */
void show_records(struct record *existing_record, char *cmd);

#endif //__show_records_h__