EXE_NAME  = monHttpClient
INC = -I../include
SRC = ../
vpath %.cpp ../source
EXE_PATH = $(DESTDIR)/$(EXE_NAME)/

OBJS = main.o \
	mongoose.o

CC = g++ -g
CFLAGS = -O0 -fPIC $(INC) -D_DEBUG -DEXENAME='"$(EXE_NAME)"' -DMG_ENABLE_SSL=1

$(EXE_NAME):$(OBJS)
	$(CC) $(OBJS) -o ../$(EXE_NAME) -lz -lm -lpthread -lssl

%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm *.o ../$(EXE_NAME)

install:
	mkdir -p $(EXE_PATH)
	cp ../$(EXE_NAME) $(EXE_PATH)
	cp -rf ../config $(EXE_PATH)
	cp -rf ../log $(EXE_PATH)
