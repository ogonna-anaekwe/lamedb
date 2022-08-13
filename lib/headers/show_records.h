#ifndef __show_records_h__
#define __show_records_h__

#include "init_db.h"

/**
 * Writes all records in the db. We could write to stdout or a file stream (in this case the db).
 * @param db_records Records in the db.
 * @param stream Where to write records: stdout or db.
 */
void show_records(struct record *db_records, FILE *restrict stream);

#endif //__show_records_h__