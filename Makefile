
CC=gcc
FLAGS=-Wall -Werror
SRC_DIR=./lib/src
HEADERS_DIR=./lib/headers
UTILS_DIR=./lib/utils

all: lamedb

clean:
	rm -rf lamedb *.o

lamedb: main.c \
		$(SRC_DIR)/init_db.c \
		$(SRC_DIR)/get_record.c \
		$(SRC_DIR)/put_record.c \
		$(SRC_DIR)/show_records.c \
		$(SRC_DIR)/delete_record.c \
		$(SRC_DIR)/clear_db.c \
		$(UTILS_DIR)/insert_node.c \
		$(UTILS_DIR)/query_router.c \
		$(HEADERS_DIR)/init_db.h \
		$(HEADERS_DIR)/get_record.h \
		$(HEADERS_DIR)/put_record.h \
		$(HEADERS_DIR)/show_records.h \
		$(HEADERS_DIR)/delete_record.h \
		$(HEADERS_DIR)/clear_db.h \
		$(HEADERS_DIR)/insert_node.h \
		$(HEADERS_DIR)/query_router.h

	$(CC) -o lamedb \
	main.c \
	$(SRC_DIR)/init_db.c \
	$(SRC_DIR)/get_record.c \
	$(SRC_DIR)/put_record.c \
	$(SRC_DIR)/show_records.c \
	$(SRC_DIR)/delete_record.c \
	$(SRC_DIR)/clear_db.c \
	$(UTILS_DIR)/insert_node.c \
	$(UTILS_DIR)/query_router.c \
	$(FLAGS)