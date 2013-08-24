BUILD = build/
SOURCE = source/
OBJS := $(patsubst $(SOURCE)%.cpp,$(BUILD)%.o,$(wildcard $(SOURCE)*.cpp))

CC = g++
OPTS =  -Wall -g -ansi -std=c++11
LIBS = -lallegro -lallegro_image

msa3k.out: $(OBJS)
	$(CC) -o $@ $(OBJS) $(OPTS) $(LIBS)

$(BUILD)msa3k.o: $(patsubst %,$(SOURCE)%, msa3k.cpp init.h constants.h game.h\
render.h gamestate.h)
	$(CC) -o $@ -c $(LIBS) $(OPTS) $<
$(BUILD)init.o: $(patsubst %,$(SOURCE)%,init.cpp init.h constants.h)
	$(CC) -o $@ -c $(LIBS) $(OPTS) $<
$(BUILD)game.o: $(patsubst %,$(SOURCE)%,game.cpp game.h gamestate.h)
	$(CC) -o $@ -c $(LIBS) $(OPTS) $<
$(BUILD)render.o: $(patsubst %,$(SOURCE)%,render.cpp render.h)
	$(CC) -o $@ -c $(LIBS) $(OPTS) $<
$(BUILD)gamestate.o: $(patsubst %,$(SOURCE)%,gamestate.cpp gamestate.h)
	$(CC) -o $@ -c $(LIBS) $(OPTS) $<

.PHONY: clean

clean:
	rm -rf $(OBJS)
