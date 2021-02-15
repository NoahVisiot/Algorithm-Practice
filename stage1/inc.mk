ifeq ($(OS),Windows_NT)
    CCFLAGS += -D WIN32
    ifeq ($(PROCESSOR_ARCHITEW6432),AMD64)
        CCFLAGS += -D AMD64
    else
        ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
            CCFLAGS += -D AMD64
        endif
        ifeq ($(PROCESSOR_ARCHITECTURE),x86)
            CCFLAGS += -D IA32
        endif
    endif
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        CCFLAGS += -D LINUX
         LOCAL_HOST:=linux
    endif
    ifeq ($(UNAME_S),Darwin)
        CCFLAGS += -D OSX
        LOCAL_HOST:=mac
    endif
    UNAME_P := $(shell uname -p)
    ifeq ($(UNAME_P),x86_64)
        CCFLAGS += -D AMD64
    endif
    ifneq ($(filter %86,$(UNAME_P)),)
        CCFLAGS += -D IA32
    endif
    ifneq ($(filter arm%,$(UNAME_P)),)
        CCFLAGS += -D ARM
    endif
endif

ifeq (linux, $(LOCAL_HOST))
CC = gcc
AR = ar
CXX = g++
else ifeq (window, $(LOCAL_HOST))
CC = gcc
CXX = g++
AR = ar
else ifeq (mac, $(LOCAL_HOST))
CC = gcc
AR = ar
CXX = g++
endif