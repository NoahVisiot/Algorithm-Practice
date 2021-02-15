ifndef LOCAL_HOST
  LOCAL_HOST:=$(shell uname)

  ifeq (Cygwin, $(LOCAL_HOST))
    LOCAL_HOST:=window
  endif

  ifeq (GNU/Linux, $(LOCAL_HOST))
    LOCAL_HOST:=linux
  endif
  
  ifeq (Darwin, $(LOCAL_HOST))
    LOCAL_HOST:=mac
  endif

endif

ifeq (linux, $(LOCAL_HOST))
CC = gcc
AR = ar
CXX = g++
endif

CFLAG = -Wall

ifeq (window, $(LOCAL_HOST))
CC = gcc
CXX = g++
AR = ar
endif

ifeq (mac, $(LOCAL_HOST))
CC = gcc
AR = ar
CXX = g++
endif