#ifndef __insert_node_h__
#define __insert_node_h__

#include "init_db.h"

/**
 * Inserts node in list. Each node is a record, and points
 * to the next record.
 * @param db_records Records in the db.
 * @param record_key Key identifying a record in the db.
 * @param record_value Value corresponding to key in the db.
 * @param is_new Is this a new record?
 * @return struct record* - List containing records, updated with a new record.
 */
struct record *insert_node(struct record *db_records, char *record_key, char *record_value, bool is_new);

#endif // __insert_node_h__