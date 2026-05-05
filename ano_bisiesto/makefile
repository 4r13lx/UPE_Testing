# Compiler
CC = gcc

# Flags base
CFLAGS = -Wall -Wextra -I./src
LDFLAGS =

# Coverage
COVERAGE_FLAGS = --coverage

# Directories
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = bin

# Sources
SRC = $(wildcard $(SRC_DIR)/*.c)
TESTS = $(wildcard $(TEST_DIR)/*.c)

# -- Rules --

# Binaries
TEST_BIN = $(BUILD_DIR)/runTests

# Default
all: test

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Tests
$(TEST_BIN): $(SRC) $(TESTS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Build
build: $(TEST_BIN)

# Run tests
test: $(TEST_BIN)
	@echo "Running tests..."
	@$(TEST_BIN)

# Coverage
coverage: CFLAGS += $(COVERAGE_FLAGS)
coverage: LDFLAGS += $(COVERAGE_FLAGS)
coverage: clean $(TEST_BIN)
	@echo "Running tests with coverage..."
	@$(TEST_BIN)

# Generate coverage report
coverage-report: coverage
	lcov --capture --directory . --output-file coverage.info
	lcov --remove coverage.info '/usr/*' --output-file coverage.info --ignore-errors unused
	genhtml coverage.info --output-directory coverage-report

# Clean
clean:
	rm -rf $(BUILD_DIR) *.gcda *.gcno *.info coverage-report

# Declare phony targets
.PHONY: all build test coverage coverage-report clean