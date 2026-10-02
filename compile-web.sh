mkdir -p bin

em++ src/*.cpp \
/home/ethancubes/Projects/Programming/libraries/raylib-web/src/libraylib.web.a \
-I/home/ethancubes/Projects/Programming/libraries/raylib-web/src \
-I./src \
-DPLATFORM_WEB \
-o bin/index.html \
-s USE_GLFW=3 \
-s ASYNCIFY \
-s ASYNCIFY_STACK_SIZE=65536 \
--preload-file assets
