#Source files
OBJS = *.cpp

#Compiler
CC = g++

#Compiler Flags
COMP_FLAG = -w

#Linker Flags
LINK_FLAG =

#Name
NAME = build/tankcoder

#Targets
all : $(OBJS)
	$(CC) $(OBJS) $(COMP_FLAG) $(LINK_FLAG) -o $(NAME)
