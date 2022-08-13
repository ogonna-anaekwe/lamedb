
CC=gcc
FLAGS=-Wall -Werror
SRC_DIR=./lib/src
UTILS_DIR=./lib/utils

all: lamedb

clean:
	rm -rf lamedb *.o

lamedb: main.c $(SRC_DIR)/init_db.* $(SRC_DIR)/get_record.* $(SRC_DIR)/put_record.* $(SRC_DIR)/show_records.* $(SRC_DIR)/clear_db.* $(UTILS_DIR)/insert_node.*
	$(CC) -o lamedb main.c $(SRC_DIR)/init_db.c $(SRC_DIR)/get_record.c $(SRC_DIR)/put_record.c $(SRC_DIR)/show_records.c $(SRC_DIR)/clear_db.c $(UTILS_DIR)/insert_node.c $(FLAGS)