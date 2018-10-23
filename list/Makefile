LIB_NAME=list
CC=gcc
CFLAGS=-I/home/chuck/.local/include -L/home/chuck/.local/lib -ldbg -Wall

SO_TARGET=lib$(LIB_NAME).so
LIB=$(LIB_NAME).c

all: $(SO_TARGET)

$(SO_TARGET): $(LIB)
	$(CC) $(CFLAGS) -shared -fPIC -o $@ $(LIB)

install:
	cp liblist.so /home/chuck/.local/lib
clean:
	rm *.so
