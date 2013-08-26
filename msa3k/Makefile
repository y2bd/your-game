BUILD = build/
SOURCE = source/
OBJS := $(patsubst $(SOURCE)%.cpp,$(BUILD)%.o,$(wildcard $(SOURCE)*.cpp))

CC = g++
OPTS = -Wall -g -ansi -std=c++11
LIBS = `pkg-config --libs --static allegro-static-5 allegro_image-static-5\
 allegro_audio-static-5 allegro_acodec-static-5`
#LIBS = -lallegro -lallegro_image -lallegro_audio -lallegro_acodec

msa3k.out: $(OBJS)
	$(CC) -o $@ $(OBJS) $(OPTS) $(LIBS)

$(BUILD)msa3k.o: $(patsubst %,$(SOURCE)%, msa3k.cpp init.h constants.h game.h\
render.h audio.h)
	$(CC) -o $@ -c $(LIBS) $(OPTS) $<
$(BUILD)init.o: $(patsubst %,$(SOURCE)%,init.cpp init.h constants.h)
	$(CC) -o $@ -c $(LIBS) $(OPTS) $<
$(BUILD)game.o: $(patsubst %,$(SOURCE)%,game.cpp game.h gamestate.h)
	$(CC) -o $@ -c $(LIBS) $(OPTS) $<
$(BUILD)render.o: $(patsubst %,$(SOURCE)%,render.cpp render.h constants.h)
	$(CC) -o $@ -c $(LIBS) $(OPTS) $<
$(BUILD)audio.o: $(patsubst %,$(SOURCE)%,audio.cpp audio.h)
	$(CC) -o $@ -c $(LIBS) $(OPTS) $<
$(BUILD)gamestate.o: $(patsubst %,$(SOURCE)%,gamestate.cpp gamestate.h)
	$(CC) -o $@ -c $(LIBS) $(OPTS) $<
$(BUILD)input.o: $(patsubst %,$(SOURCE)%,input.cpp input.h constants.h)
	$(CC) -o $@ -c $(LIBS) $(OPTS) $<
$(BUILD)entity.o: $(patsubst %,$(SOURCE)%,entity.cpp entity.h)
	$(CC) -o $@ -c $(LIBS) $(OPTS) $<

.PHONY: clean

clean:
	rm -rf $(OBJS)
