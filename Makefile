# Based on libvita2d's Makefile by xerpi

TARGET_LIB = libvitagui.a
OBJS = src/gui.o src/pane.o src/label.o src/list.o src/menu.o src/vec2.o
INCLUDES   = include

PREFIX  = $(VITASDK)/bin/arm-vita-eabi
CC      = $(PREFIX)-gcc
CXX	= $(PREFIX)-g++
AR      = $(PREFIX)-ar
CFLAGS  = -Wall -I$(INCLUDES) -I$(VITASDK)/include
CXXFLAGS = $(CFLAGS) -fno-exceptions -std=c++11

all: $(TARGET_LIB)

debug: CFLAGS += -DDEBUG_BUILD
debug: all

$(TARGET_LIB): $(OBJS)
	$(AR) -rc $@ $^

clean:
	@rm -rf $(TARGET_LIB) $(OBJS)

install: $(TARGET_LIB)
	@cp $(TARGET_LIB) $(VITASDK)/lib
	@rm $(VITASDK)/include/gui -rf
	@cp -r include/gui $(VITASDK)/include/
	@cp include/gui.h $(VITASDK)/include/
	@echo "Installed!"
