#LIB_NAME=list
CC=gcc
CFLAGS=-I/home/chuck/.local/lib/chuck/dbg -L/home/chuck/.local/lib/chuck/dbg -ldbg -Wall

SO_TARGET=lib$(LIB_NAME).so
LIB=$(LIB_NAME).c

all: $(SO_TARGET)

$(SO_TARGET): $(LIB)
	$(CC) $(CFLAGS) -shared -fPIC -o $@ $(LIB)

clean:
	rm *.so
