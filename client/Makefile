MACRO=DEBUGALL
CFLAGS+=-g -w -D$(MACRO) -lpthread
SRCPATH=.
INCLUDEPATH=.
INCLUDEPATH+=../thread ../task ../log ../config ../util
TARGET=test
SOURCES=$(wildcard $(SRCPATH)/*.cpp)
ALIAS_OBJS=../thread/thread.o \
	../task/task_mgr.o \
	../log/sub_log.o \
	../config/config.o

#OBJS := $(patsubst %.cpp, %.o,$(SOURCES))
OBJS=$(SOURCES:.cpp=.o)
CFLAGS+=$(foreach dir, $(INCLUDEPATH), -I$(dir))

all: build
	@cd ../task
	@echo "Build Done!"
	@echo $(CFLAGS)
clean:
	$(RM) $(OBJS) $(TARGET)

build:
	g++ -c ${CFLAGS} ${SOURCES} 
	g++ ${CFLAGS} -o ${TARGET} ${OBJS} ${ALIAS_OBJS}
