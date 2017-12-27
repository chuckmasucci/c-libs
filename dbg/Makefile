# LIB_NAME=dgb
CC=gcc

SO_TARGET=lib$(LIB_NAME).so
LIB=$(LIB_NAME).c

all: $(SO_TARGET)

$(SO_TARGET): $(LIB)
	$(CC) -shared -fPIC -o $@ $(LIB)

clean:
	rm *.o, *.so
