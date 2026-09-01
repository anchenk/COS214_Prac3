CXX      := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -Iinclude
BUILD_DIR:= build
TARGET   := eventflow
ZIP_NAME := submission.zip
FLAT_DIR := flat_src
ROOT_FILES := README.md Doxyfile visualParadigm resources/COS214\ -\ Practical\ 3.pdf Makefile

# Find main.cpp and all src/ cpp files
SRCS     := $(shell find src -type f -name '*.cpp')

# Map main.cpp -> build/main.o and src/path/file.cpp -> build/src/path/file.o
OBJS     := $(patsubst src/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

all: $(TARGET)
	./$(TARGET)

# Link object files into final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each .cpp into a .o file inside build/
$(BUILD_DIR)/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

# Zip Makefile, source trees, and explicitly add all ROOT_FILES without extension filtering
zip:
	zip -r $(ZIP_NAME) Makefile $(ROOT_FILES) src include -i '*.cpp' '*.h' '*.hpp'
	zip -u -r $(ZIP_NAME) Makefile $(ROOT_FILES)
	if [ -d resources ]; then zip -j $(ZIP_NAME) resources/*; fi

# Generate flat zip: handle individual files and directories separately with cp -r
flat-zip:
	@rm -rf $(FLAT_DIR) $(ZIP_NAME)
	@mkdir -p $(FLAT_DIR)
	@cp Makefile $(FLAT_DIR)/
	@# Copy files or flatten directory contents listed in ROOT_FILES
	@for item in $(ROOT_FILES); do \
		if [ -d "$$item" ]; then \
			cp -r "$$item"/* $(FLAT_DIR)/ 2>/dev/null || true; \
		elif [ -f "$$item" ]; then \
			cp "$$item" $(FLAT_DIR)/; \
		fi; \
	done
	@# Copy C++ sources/headers, excluding build and temp dirs
	@find . -type f \( -name '*.cpp' -o -name '*.h' -o -name '*.hpp' \) ! -path "./$(BUILD_DIR)/*" ! -path "./$(FLAT_DIR)/*" -exec cp {} $(FLAT_DIR)/ \;
	@if [ -d resources ]; then cp -r resources/* $(FLAT_DIR)/ 2>/dev/null || true; fi
	@# Patch include directives
	@for f in $(FLAT_DIR)/*; do \
		[ -f "$$f" ] && sed -i -E 's/#include "([^"]*\/)?([^"\/]+)"/#include "\2"/g' "$$f"; \
	done
	cd $(FLAT_DIR) && zip -j ../$(ZIP_NAME) *
	@rm -rf $(FLAT_DIR)

# Clean build output
clean:
	rm -rf $(BUILD_DIR) $(TARGET) *.o $(ZIP_NAME) $(FLAT_DIR)

.PHONY: all clean zip flat-zip