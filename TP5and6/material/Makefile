## Definifion of variables

##Fichiers sources
SOURCES = main.c linked-list.c

##Compilateur C
CC = gcc

##Editeur de liens
LD = gcc

AR = ar -r

RM = rm

##Repertoire des fichiers .c
SRC_DIR = ./src

##Repertoire des bibliotheques
LIB_DIR = ./lib

##Repertoire des fichiers .h
INCLUDE_DIR = ./include

##Options du compilateur
CFLAGS = -Wall -I$(INCLUDE_DIR)

##Options de l'editeur de liens
LDFLAGS = -c

LIB_FILES = liblinked_list.a

## Nom de l'executable
EXEC_NAME = test_exe

## Target liblinked-list-utils.a
## archive linked-list.o into library liblinked-list-utils.a
$(LIB_DIR)/$(LIB_FILES) : linked-list.o
	$(AR) $@ linked-list.o


## Target main.o
## compile main.c to produce an object file (main.o)
main.o: $(SRC_DIR)/main.c
	$(CC) $(LDFLAGS) $(CFLAGS) $<


## Target linked-list.o
## compile linked-list.c to produce an object file (linked-list.o)
linked-list.o: $(SRC_DIR)/linked-list.c
	$(CC) $(LDFLAGS) $(CFLAGS) $<

## Target test_make.exe
## link liblinked-list-utils.a and main.o to produce the executable (linked-list-exe)
$(EXEC_NAME): main.o $(LIB_DIR)/$(LIB_FILES)
	$(LD) $^ -o $(EXEC_NAME)


## Target all: Useful? Where should be put in the makefile?
all: $(EXEC_NAME)


## Target clean
clean:
	$(RM) *.o $(LIB_DIR)/*.a $(EXEC_NAME) depend

## Gestion des dependances

depend:
	$(CC) $(CFLAGS) -MM $(SRC_DIR)/main.c > depend
	$(CC) $(CFLAGS) -MM $(SRC_DIR)/linked-list.c > depend
