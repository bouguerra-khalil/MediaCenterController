
PROG = myprog

SOURCES = Media.cpp main.cpp tcpserver.cpp cppsocket.cpp 

OBJETS = ${SOURCES:%.cpp=%.o}

CXX = c++

CXXFLAGS = -std=c++11 -Wall -g

LDFLAGS = 

LDLIBS= -lpthread
 
all: ${PROG}

run: ${PROG}
	./${PROG}

${PROG}: depend-${PROG} ${OBJETS}
	${CXX} -o $@ ${CXXFLAGS} ${LDFLAGS} ${OBJETS} ${LDLIBS}

clean:
	-@$(RM) *.o depend-${PROG} core 1>/dev/null 2>&1

clean-all: clean
	-@$(RM) ${PROG} 1>/dev/null 2>&1
tar:
	tar cvf ${PROG}.tar.gz ${SOURCES}

depend-${PROG}:
	${CXX} ${CXXFLAGS} -MM ${SOURCES} > depend-${PROG}

.SUFFIXES: .cpp .cxx .c

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.c.o:
	$(CC) -c (CFLAGS) $(INCPATH) -o $@ $<

-include depend-${PROG}
