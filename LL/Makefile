# app: main.o node.o linked_list.o
# 	clang++ ./build/main.o ./build/node.o ./build/linked_list.o -o app

# main.o:
# 	clang++ -c main.cpp

# node.o:
# 	clang++ -c node.cpp

# linked_list.o:
# 	clang++ -c linked_list.cpp

BUILD_DIR = build
SRC_DIR = src

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

app: $(OBJS)
	clang++ $(OBJS) -o $(BUILD_DIR)/app

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	clang++ -I ./include -c $< -o $@

clean:
	rm -rf ./build/*.o app

run:
	./build/app