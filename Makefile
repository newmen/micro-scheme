NAME		:= micro-scheme

GCC_PATH	:= /usr
CXX		:= $(GCC_PATH)/bin/g++
FLAGS		:= -std=c++11 -fPIC -Wall

SRC_DIR		:= lang
OBJS_DIR	:= obj
TESTS_DIR	:= tests

SOURCE_DIRS	:= $(shell find $(SRC_DIR) -type d)
OBJECTS_DIRS	:= $(SOURCE_DIRS:$(SRC_DIR)%=$(OBJS_DIR)%)

SOURCE_FILES	:= $(wildcard $(addsuffix /*.cpp, $(SOURCE_DIRS)))
SOURCE_OBJECTS	:= $(patsubst $(SRC_DIR)/%, $(OBJS_DIR)/%, $(SOURCE_FILES:%.cpp=%.o))
MD_FILES	:= $(SOURCE_OBJECTS:%.o=%.d)

.PHONY: all dirs clean test

all:	$(NAME)
$(NAME):	dirs $(MD_FILES) $(SOURCE_OBJECTS)

test: all
	$(MAKE) -C $(TESTS_DIR) 

dirs:
	mkdir -p $(OBJECTS_DIRS)

$(OBJS_DIR)/%.d: $(SRC_DIR)/%.cpp
	$(CXX) $(FLAGS) -MM -MF $@ $<

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) -c $(FLAGS) -o $@ $<

clean:
	rm -rf $(OBJS_DIR)

include $(wildcard $(addsuffix /*.d, $(OBJECTS_DIRS)))
