CC = g++
FLAGS = -std=gnu++2b -Wall -Wextra #-Werror
BUILD = ../build
OBJECT = ../obj

TARGET_NAME = test
TARGET = $(BUILD)/$(TARGET_NAME)

all: build
build: $(TARGET)
rebuild: clean build

run: #$(TARGET)
	clear
	./$(TARGET)

$(TARGET): $(OBJECT)/$(TARGET_NAME).o class_task.cpp
	$(CC) $(FLAGS) $^ -o $(TARGET)
#------------------------OBJECT
$(OBJECT)/%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@
#------------------------CLEAN
clean:
	rm -rf $(OBJECT)/*
clean_build:
	rm -rf $(BUILD)/*
clean_all: clean clean_build

#------------------------CLANG
style: clang_i
clang_n: *.cpp
	cp ../materials/linters/.clang-format .
	clang-format -n -style=file *.cpp *.h
	rm .clang-format
clang_i: *.cpp
	cp ../materials/linters/.clang-format .
	clang-format -i -style=file *.cpp *.h
	rm .clang-format