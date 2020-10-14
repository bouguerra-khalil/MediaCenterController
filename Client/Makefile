
PROG = Interface

SOURCES = Interface.java  Client.java 

JC = javac

JFLAGS = -g
 
all: classes

run: all
	java ${PROG}

classes: $(SOURCES:.java=.class)

clean:
	-@$(RM) *.class 1>/dev/null 2>&1
tar:
	tar cvf ${PROG}.tar.gz ${SOURCES}

.SUFFIXES: .java .class

.java.class:
	$(JC) $(JFLAGS) $*.java