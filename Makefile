all: myapp.exe

OBJS=Nhom_6.o sub.o

myapp.exe: $(OBJS)
	gcc $(OBJS) -lstdc++ -o $@

# ./%.o: %.c
# 	g++ -o $@ -c $<

./%.o: %.cpp
	g++ -o $@ -c $<