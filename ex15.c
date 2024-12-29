#include <stdio.h>

void print_array(int *arr,int size);

int main(int argc,char *argv[]){
	//create two arrays we care about
	int ages[] = {23,43,12,89,2};
	char *names[] = {
		"Alan","Frank","Mary","John","Lisa"};

	//safely get the size of ages
	int count = sizeof(ages)/sizeof(int);
	int i = 0;

	//first way using indexing
	for(i = 0; i < count; i++){
		printf("%s has %d years alive.\n",names[i],ages[i]);
	}

	printf("---\n");

	//setup the pointers to the start of the arrays
	int *cur_age = (int*)ages;
	char **cur_name = names;

	//second way using pointers
	for(int i=0;i<count;i++){
		printf("%s is %d years old.\n",cur_name[i],cur_age[i]);
	}

	printf("---\n");

	//third way, pointers are just arrays
	for(i=0;i<count;i++){
		printf("%s is %d years old again.\n",cur_name[i],cur_age[i]);
	}

	printf("---\n");

	//fourth way with pointers in a stupid complex way
	for(cur_name = names,cur_age = ages;(cur_age-ages)<count;cur_name++,cur_age++){
		printf("%s lived %d years so far.\n",cur_name[0],cur_age[0]);
	}

	printf("---\n");

	//使用指针来处理命令行参数，就像处理names那样
	char** arg_ptr = argv;
	
	for(i=0;i<argc;i++){
		printf("Argument %d: %s\n", i,*arg_ptr);
		arg_ptr++;
	}	

	printf("---\n");

	//add address
	for(i=0;i<argc;i++){
		printf("Argument %d: %s\naddress:%p\n", i, argv[i], (void*)argv[i]);
	}	

	printf("---\n");
	
	//调用函数
	print_array(ages,5);


	return 0;
}

void print_array(int *arr,int size){
	for(int i=0;i<size;i++){
		printf("Element %d : %d\n",i,*arr);
		arr++;
	}
}
