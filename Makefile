CC=g++
INCLUDEDIR=-I/usr/local/include
INCLUDEDIRS=$(INCLUDEDIR)
#LIBDIR=-L/usr/local/lib -lgtest
LIBDIR=-lgtest
LDFLAGS=$(LIBDIR)
CFLAGS=-g -Wall -std=c++11 $(INCLUDEDIRS) $(LDFLAGS)
TARGET=a.out
OBJS=rvalue_reference.o main.o
TARGET_OPTION=-f
#LDFLAGS=link option
#LDLIBS=a list of link library
#$@: 현재 Target 이름
#$^: 현재 Target이 의존하는 대상들의 전체 목록
#$?: 현재 Target이 의존하는 대상들 중 변경된 것들의 목록
#$%: 대상의 이름 (해당 규칙 대상이 아카이브 인 경우)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

rvalue_reference.o : rvalue_reference.cpp
	$(CC) -c -o rvalue_reference.o rvalue_reference.cpp

main.o : main.cpp
	$(CC) -c -o main.o main.cpp

clean:
	rm $(TARGET_OPTION) $(TARGET)
	rm $(TARGET_OPTION) *.o
 
all: $(TARGET)
 
