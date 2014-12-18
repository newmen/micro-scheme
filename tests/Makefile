NAME		:= micro-scheme-tests

GCC_PATH	:= /usr
CXX		:= $(GCC_PATH)/bin/g++
FLAGS		:= -std=c++11 -fPIC -Wall

HELPERS_DIR	:= ../helpers
OBJS_DIR	:= obj

HELPER_FILES	:= $(wildcard $(addsuffix /*.cpp, $(HELPERS_DIR)))
HELPER_OBJECTS	:= $(patsubst $(HELPERS_DIR)/%, $(OBJS_DIR)/%, $(HELPER_FILES:%.cpp=%.o))
MD_FILES	:= $(HELPER_OBJECTS:%.o=%.d)

SOURCE_OBJ_DIRS	:= $(shell find ../obj -type d)
SOURCE_OBJECTS  := $(wildcard $(addsuffix /*.o, $(SOURCE_OBJ_DIRS)))
TEST_FILES	:= $(wildcard *.cpp)

.PHONY: all dirs clean

all:	$(NAME)
$(NAME):	dirs $(MD_FILES) $(HELPER_OBJECTS)
	$(CXX) $(FLAGS) $(SOURCE_OBJECTS) $(HELPER_OBJECTS) $(TEST_FILES) -o $(NAME) -lgtest -lgtest_main
	./$(NAME)
	rm $(NAME)

dirs:
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.d: $(HELPERS_DIR)/%.cpp
	$(CXX) -c $(FLAGS) -MM -MF $@ $<

$(OBJS_DIR)/%.o: $(HELPERS_DIR)/%.cpp
	$(CXX) -c $(FLAGS) -o $@ $<

clean:
	rm -f $(NAME)
	rm -rf $(OBJS_DIR)

include $(wildcard $(addsuffix /*.d, $(OBJS_DIR)))
