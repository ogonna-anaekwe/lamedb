#ifndef __insert_node_h__
#define __insert_node_h__

#include "init_db.h"

/**
 * Inserts node in list. Each node is a record, and also points
 * to the next record.
 * @param existing_record Records in the db.
 * @param record_key Key identifying a record in the db.
 * @param record_value Value corresponding to record in the db.
 * @param is_new Is this a new record?
 * @return struct record*
 */
struct record *insert_node(struct record *existing_record, char *record_key, char *record_value, bool is_new);

#endif // __insert_node_h__