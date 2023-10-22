#Samriddha Kharel 1001918169 Coding Assignment 7

SRC1 = DrawTool.c
SRC2 = ListLib.c
SRC3 = FileLib.c
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
OBJ3 = $(SRC3:.c=.o)

EXE = $(SRC1:.c=.e)

CFLAGS = -g

all : $(EXE)
 
$(EXE): $(OBJ1) $(OBJ2) $(OBJ3)
	gcc $(CFLAGS) $(OBJ1) $(OBJ2) $(OBJ3)-o $(EXE) 

$(OBJ1) : $(SRC1)
	gcc -c $(CFLAGS) $(SRC1)
$(OBJ2) : $(SRC2)
	gcc -c $(CFLAGS) $(SRC2)
$(OBJ3) : $(SRC3)
	gcc -c $(CFLAGS) $(SRC3)