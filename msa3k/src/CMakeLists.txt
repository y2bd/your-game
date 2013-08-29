# MSA3K/src

include_directories(${MSA3K_SOURCE_DIR}/src)
link_directories(${MSA3K_BINARY_DIR}/src)

set(SRC audio.cpp entity.cpp game.cpp gamestate.cpp init.cpp input.cpp msa3k.cpp render.cpp)

set(LIBERRY allegro-static allegro_image-static allegro_audio-static allegro_acodec-static -lpng -lz -ljpeg -lallegro_acodec-static -lFLAC -ldumb -lvorbisfile -lvorbis -logg -lallegro_audio-static -lpulse-simple -lpulse -lasound -lopenal -lallegro-static -lm -lpthread -lSM -lICE -lX11 -lXext -lXcursor -lXinerama -lXrandr -lGL -lGLU)

add_executable(../msa3k.out ${SRC})
target_link_libraries(../msa3k.out ${LIBERRY})
