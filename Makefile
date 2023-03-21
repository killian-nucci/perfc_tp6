DEBUG?=no
DEBUG_CVH_CLEANING?=no

CC=gcc
BUILD_DIR=build
SRC_DIR=src
INCLUDE=-Iinclude
CFLAGS=-fdiagnostics-color=always -Wall -pedantic -std=c17 -g -g3
SOURCES=$(wildcard $(SRC_DIR)/*.c)
OBJECTS=$(SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

ifeq ($(DEBUG), yes)
	CFLAGS += -g
endif
ifeq ($(DEBUG_CVH_CLEANING), yes)
	CFLAGS += -DDEBUG_CVH_CLEANING
endif

all: main

# Cible par défaut : l'exécutable main
main: $(OBJECTS)
	$(CC) $(INCLUDE) $(CFLAGS) $^ -o $(BUILD_DIR)/$@ $(LIBS)

# Création des fichiers objets à partir des fichiers sources
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir --parents $(BUILD_DIR)
	$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/main

.PHONY: clean all