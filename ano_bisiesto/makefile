# Compiler
CC = gcc

# Flags base
CFLAGS = -Wall -Wextra -I./src
LDFLAGS =

# Coverage
COVERAGE_FLAGS = --coverage

# Directorios
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build

# Archivos
SRC = $(wildcard $(SRC_DIR)/*.c)
TESTS = $(wildcard $(TEST_DIR)/*.c)

# Binarios
TEST_BIN = $(BUILD_DIR)/runTests

# Default
all: test

# Crear carpeta build
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Tests
$(TEST_BIN): $(SRC) $(TESTS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Alias para compatibilidad
build: $(TEST_BIN)

# Ejecutar tests
test: $(TEST_BIN)
	@echo "Running tests..."
	@$(TEST_BIN)

# Coverage
coverage: CFLAGS += $(COVERAGE_FLAGS)
coverage: LDFLAGS += $(COVERAGE_FLAGS)
coverage: clean $(TEST_BIN)
	@echo "Running tests with coverage..."
	@$(TEST_BIN)

# Reporte coverage
coverage-report: coverage
	lcov --capture --directory . --output-file coverage.info
	lcov --remove coverage.info '/usr/*' --output-file coverage.info
	genhtml coverage.info --output-directory coverage-report

# Limpieza
clean:
	rm -rf $(BUILD_DIR) *.gcda *.gcno *.info coverage-report

.PHONY: all build test coverage coverage-report clean