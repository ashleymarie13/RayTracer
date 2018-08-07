CC = g++
CFLAGS = -Wall
DEPS = vec3.h ray.h hitable.h hitable_list.h main.cpp
OBJ = main.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

run: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean: 
	rm -rf *o run