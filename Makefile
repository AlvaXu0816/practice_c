#CFLAGS=-Wall -g

#all: ex-1 ex-3

#ex-1: ex1.c
	#cc $(CFLAGS) ex-1.c -o ex1

#ex-3: ex3.c
	#cc $(CFLAGS) ex-3.c -o ex3

#clean:
	#rm -f ex-1 ex-3

CFLAGS=-Wall -g

# 新增目标：编译生成双向链表库
LIBRARY=liblcthw.a

# 默认目标，编译两个示例文件和库
all: ex-1 ex-3 $(LIBRARY)

# 编译示例1
ex-1: ex1.c
	cc $(CFLAGS) ex-1.c -o ex1

# 编译示例3
ex-3: ex3.c
	cc $(CFLAGS) ex-3.c -o ex3

# 生成库文件
$(LIBRARY): src/lcthw/list.o
	ar rcs $(LIBRARY) src/lcthw/list.o

# 编译链表实现文件
src/lcthw/list.o: src/lcthw/list.c src/lcthw/list.h
	cc $(CFLAGS) -c src/lcthw/list.c -o src/lcthw/list.o

# 清理目标
clean:
	rm -f ex-1 ex-3 $(LIBRARY)
	rm -f src/lcthw/*.o
	rm -rf build tests/libex29_tests
	rm -f tests/tests.log
	find . -name "*.gc*" -exec rm {} \;
	rm -rf `find . -name "*.dSYM" -print`

# 运行测试
test: $(LIBRARY)
	./tests/runtests.sh




