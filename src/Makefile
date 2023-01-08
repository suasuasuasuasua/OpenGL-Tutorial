.PHONY: all run execute clean clearscr
CXX = g++
LD = g++
CXXFLAGS = -std=c++17
LDFLAGS = -std=c++17
ARGS = 

TARGET = main
OBJ_FILES = $(TARGET).o glad.o
INC_FILES = $(TARGET).h glad.h

UNAME := $(shell uname)

LIBRARIES = 
ifeq ($(UNAME), Linux)
	LIBRARIES += -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl
endif
ifeq ($(UNAME), Darwin)
	LIBRARIES += -lglfw -framework CoreVideo -framework OpenGL -framework IOKit -framework Cocoa -framework Carbon
endif

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(LD) $(LDFLAGS) $(OBJ_FILES) -o $@ $(LIBRARIES)

%.o : %.c $(INC_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $<

run: | clearscr all execute clean

execute: $(TARGET)
	@echo "Running $(TARGET)\n"

	@./$(TARGET) $(ARGS)
clean:
	@rm -rf core $(TARGET) $(OBJ_FILES)

clearscr:
	@clear
