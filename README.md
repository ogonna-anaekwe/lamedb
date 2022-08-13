# lamedb
This is a simplistic database that functions as a key-value store. It doesn't do much: it's that lame, hence the name `lamedb`. `lamedb` has only 2 fields: `key` and `value`. The db is `.txt` file named `lamedb_kv.txt`. This file holds all the records in the db. So what little does `lamedb` do?
1. Adds record or updates (existing) record.
2. Gets a specific record.
3. Deletes a specific record.
4. Deletes all records.
5. Shows all records.

# Why is it lame?
1. It only does the aforementioned things.
2. It only supports two fields: `key` and `value`. (`key` is our guarantee of uniquess: no two records can have the same key.)
3. It is not thread safe. So it is not ideal for concurrent operations. 
4. It only accepts one query per time.
5. It uses linked lists which are [terrible for search](https://en.wikipedia.org/wiki/Linked_list#Speeding_up_search). (*Someone* assigned this a fancy term `O(n)`, `n` being the number of records in the db.)

# Implementation
While the db is a `.txt` file, every query (get, put, etc) works with an in-memory linked list. This list contains all the records in the db. And now the implementation:
1. **init**(ialize) db: This means returning a list containing the db records. (If the db file doesn't exist, we create an empty file and by extension, an empty list). The returned list is made available to all other methods/queries.
2. **p**(ut) record: Add record to list (if it doesn't exist). If the record exists, update existing record. Also overwrite the file with the updated list.
3. **g**(et) record: Lookup `<key>` in the list. This will print the corresponding record if the `<key>` exists.
4. **d**(elete) record: Overwrite db file with list (leaving out the record that we seek to delete).
5. **c**(lear) db: Drop all records. Here, we simply overwrite the db file with an empty file.
6. **a**(all) db: Prints all records in the db.

# Compilation
```sh
$ make
```
# Example Usage
Get a record:
```sh
$ ./lamedb g,<key>
```
Add a record:
```sh
$ ./lamedb p,<key>,<value>
```
Update an existing record:
```sh
$ ./lamedb p,<key>,<value>
```
Delete a record:
```sh
$ ./lamedb d,<key>
```
Delete/Clear all records:
```sh
$ ./lamedb c
```
Show all records:
```sh
$ ./lamedb a
```

**NOTE:** `<key>` must be a number greater than 0. Ideally, `<value>` should be a string. E.g., to add a record: `./lamedb p,1,first`; to get that record: `./lamedb g,1`; to update that record: `./lamedb p,1,one`.

