# tool macros
CC := gcc
CFLAGS := -g -Wall -Wpedantic -Werror -Wextra -std=c11
CCOBJFLAGS := $(CFLAGS) -c

# path macros
BIN_PATH := bin
OBJ_PATH := obj
BLD_PATH := src
SRC_PATH := test/src

# compile macros
TARGET_NAME := dll
# ---- No need to edit below this line ----
TARGET := $(BIN_PATH)/$(TARGET_NAME)

# src files & obj files
BLD := $(foreach x, $(BLD_PATH), $(wildcard $(addprefix $(x)/*,.c*)))
SRC := $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/*,.c*)))
OBJ := $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRC))) $(notdir $(basename $(BLD)))))

# clean files list
DISTCLEAN_LIST := $(OBJ)

CLEAN_LIST := $(TARGET) \
			  $(DISTCLEAN_LIST) \
			  $(BIN_PATH) \
			  $(OBJ_PATH)

# default rule
default: makedir all

# non-phony targets
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

$(OBJ_PATH)/%.o: $(BLD_PATH)/%.c*
	$(CC) $(CCOBJFLAGS) -o $@ $<

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c*
	$(CC) $(CCOBJFLAGS) -o $@ $<

$(DBG_PATH)/%.o: $(BLD_PATH)/%.c* $(SRC_PATH)/%.c*
	$(CC) $(CCOBJFLAGS) $(DBGFLAGS) -o $@ $<

# phony rules
.PHONY: makedir
makedir:
	@mkdir -p $(BIN_PATH) $(OBJ_PATH) $(DBG_PATH)

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	@echo CLEAN $(CLEAN_LIST)
	@rm -rf $(CLEAN_LIST)

debug: CFLAGS += -ggdb3
debug: default $(TARGET)

good: clean debug
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(TARGET)

test: clean default
	./$(TARGET)
	
.PHONY: distclean
distclean:
	@echo CLEAN $(DISTCLEAN_LIST)
	@rm -f $(DISTCLEAN_LIST)