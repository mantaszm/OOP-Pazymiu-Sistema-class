.PHONY: all configure build run test docs clean

BUILD_DIR := build

all: build

configure:
	cmake -S . -B $(BUILD_DIR)

build: configure
	cmake --build $(BUILD_DIR)

run: build
	./$(BUILD_DIR)/programa

test: build
	ctest --test-dir $(BUILD_DIR) --output-on-failure

docs:
	doxygen Doxyfile
	$(MAKE) -C docs/latex

clean:
	rm -rf $(BUILD_DIR)
	rm -f programa unit_tests *.o
	rm -f test_generated.txt test_input.txt test_input_no_nd.txt
