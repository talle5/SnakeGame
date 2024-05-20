TARGET=index.html
CC=emcc
WARN=-Wall -Wno-missing-braces -Wunused-result
STD=-std=c++17
OPT=-D_DEFAULT_SOURCE -O3 $(STD)
CCFLAGS=$(OPT) $(WARN)

all: build 

build: 
	$(CC) -o $(TARGET) src/main.cpp -Wall -std=c++17 -D_DEFAULT_SOURCE -Wno-missing-braces -Wunused-result -Os -I raylib/include -s USE_GLFW=3 -s ASYNCIFY -s TOTAL_MEMORY=67108864 --shell-file raylib/shell.html raylib/lib/libraylib.a -DPLATFORM_WEB -s 'EXPORTED_FUNCTIONS=["_free","_malloc","_main"]' -s EXPORTED_RUNTIME_METHODS=ccall

