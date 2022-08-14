# lamedb
This is a simplistic database that functions as a key-value store. It doesn't do much: it's that lame, hence `lamedb`. `lamedb` has only 2 fields: `key` and `value`. The db is `.txt` file named `lamedb_kv.txt`. This file holds all the records in the db. So what little does `lamedb` do?
1. Adds record or updates (existing) record.
2. Gets a specific record.
3. Deletes a specific record.
4. Deletes all records.
5. Shows all records.

# Why is it lame?
1. It only does the aforementioned things.
2. It only supports two fields: `key` and `value`. (`key`, which **MUST** be greater than `0`, is our guarantee of uniquess: no two records can have the same key.)
3. It only accepts one query per time as it's not thread safe: it's ill-suited for concurrent queries. 
4. It uses linked lists which are [terrible for search](https://en.wikipedia.org/wiki/Linked_list#Speeding_up_search). (The cpu time taken to search for records in the db grows linearly with the number of records - the [time complexity](https://en.wikipedia.org/wiki/Time_complexity) is `O(n)`, `n` being the number of records in the db.)

# Implementation
While the db is a `.txt` file, every query (get, put, etc) works with an in-memory linked list. This list contains all the records in the db. And now the implementation:
1. **init**(ialize) db: Returns a list containing the db records. (Creates an empty file and by extension, an empty list if the db doesn't exist). Other methods can accept this list as a param.
2. **p**(ut) record: Adds a record to the list (if it doesn't exist). Updates existing record (if it exists). Finally, overwrites the file with the updated list.
3. **g**(et) record: Looks up `<key>` in the list. Also prints the corresponding record if the `<key>` exists.
4. **d**(elete) record: Overwrites db file with list (leaving out the record that we seek to delete).
5. **c**(lear) db: Drops all records. Here, we simply overwrite the db file with an empty file.
6. **a**(all) db: Prints all records in the db.

# Compilation
```sh
$ make
```
# Example Queries
Get a record:
```sh
$ ./lamedb g,<key>
```
Add a record:
```sh
$ ./lamedb p,<key>,"<value>"
```
Update an existing record:
```sh
$ ./lamedb p,<key>,"<value>"
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

**NOTE:** Ideally, `<value>` should be a string. E.g., to add a record: `./lamedb p,1,"first"`; to get that record: `./lamedb g,1`; to update that record: `./lamedb p,1,"one"`; to delete that record `./lamedb d,1`.

