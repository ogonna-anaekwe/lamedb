#ifndef __put_record__h
#define __put_record__h

#include "init_db.h"
#include "get_record.h"
#include "insert_node.h"
#include "show_records.h"

/**
 * Adds record to list. If record already exists, update.
 * Overwrites db file with updated list.
 * @param db_records Records in the db.
 * @param record_key Key identifying a record in the db.
 * @param record_value Value corresponding to key in the db.
 * @param cmd Query: p(ut).
 */
void put_record(struct record *db_records, char *record_key, char *record_value, char *cmd);
#endif //__put_record__h