
INCDIR = include/
SRCDIR = src/
OBJDIR = obj/
BINDIR = bin/

INC_RAPIDJSON = $(INCDIR)rapidjson/
INC_RESOURCES = $(INCDIR)resources/

SRC_RESOURCES = $(SRCDIR)resources/

CC = g++

CFLAGS = -O2 -W -Wall -Wno-unused-parameter -Wno-unused-variable
LIBS = -lpistache -lssl -lcrypto -lpthread
INCS = -I$(INCDIR) -I$(INC_RAPIDJSON) -I$(INC_RESOURCES)

OBJS_RESOURCES = chart_endpoint.o details_endpoint.o table_endpoint.o
OBJS = $(addprefix $(OBJDIR), api.o $(OBJS_RESOURCES))

EXEC = $(BINDIR)api

RM = rm -fv

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LIBS)

rebuild:
	make clean
	make

$(OBJDIR)api.o: $(SRCDIR)api.cc
	$(CC) -c $(SRCDIR)api.cc -o $(OBJDIR)api.o $(INCS) $(CFLAGS) 
	

$(OBJDIR)chart_endpoint.o: $(SRC_RESOURCES)chart_endpoint.cc
	$(CC) -c $(SRC_RESOURCES)chart_endpoint.cc -o $(OBJDIR)chart_endpoint.o $(INCS) $(CFLAGS)
	
$(OBJDIR)details_endpoint.o: $(SRC_RESOURCES)details_endpoint.cc
	$(CC) -c $(SRC_RESOURCES)details_endpoint.cc -o $(OBJDIR)details_endpoint.o $(INCS) $(CFLAGS) 
	
$(OBJDIR)table_endpoint.o: $(SRC_RESOURCES)table_endpoint.cc
	$(CC) -c $(SRC_RESOURCES)table_endpoint.cc -o $(OBJDIR)table_endpoint.o $(INCS) $(CFLAGS)

clean:
	$(RM) $(OBJS) $(EXEC)
