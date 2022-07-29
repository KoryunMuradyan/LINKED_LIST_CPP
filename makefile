export EXECUTABLE := my_proj

.PHONY: default
default: $(EXECUTABLE)

export DEBUG_FLAGS := -o3
export SOURCE_FILES := $(wildcard *.cpp)
export OBJ_FILES := $(patsubst %.cpp, %.o, $(SOURCE_FILES))
export DEP_FILES := $(patsubst %.cpp, %.dep, $(SOURCE_FILES))
export TEMP_FILES := $(OBJ_FILES) $(DEP_FILES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJ_FILES)
	@echo "Linking the executable"
	@gcc $(DEBUG_FLAGS) $^ /usr/lib/gcc/x86_64-linux-gnu/9/libstdc++.a -o $@

%.o:
	@echo "Compiling $<"
	gcc $(DEBUG_FLAGS) -c $< -o $@

%.dep : %.cpp
	@echo "Generating depdendencies for $<"
	@gcc -MM $< -o $@

.PHONY: clean
clean:
	@echo "Cleaning the temprorary files"
	@-rm $(TEMP_FILES)

.PHONY: test
test: $(EXECUTABLE)
	@echo "Running the tests"
	@time ./$(EXECUTABLE)

.PHONY: debug
debug: clean
	@echo "Building the release version"
	@$(MAKE) DEBUG_FLAGS="-g"
	@echo "Running GDB"
	@gdb ./$(EXECUTABLE)

.PHONY: release
release: clean
	@echo "Building the release version"
	@$(MAKE) DEBUG_FLAGS="-03"

.PHONY: profile
profile: clean
	@echo "Building the release version"
	@$(MAKE) DEBUG_FLAGS="-03"

include $(DEP_FILES)
