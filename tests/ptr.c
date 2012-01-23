
#include <stdio.h>

struct st {
	int j;
	int *i;
	int k;
};

int ptr(int *a)
{
	*a = 12;
	return 0;
}

int ptr_st(struct st *s)
{
	//printf("%d\n", *s->i);
	//ptr(s->i);
	printf("\nPTR\n");
	printf("ctx addr: %x\n", s);
	printf("ctx.clen addr: %x\n", &(s->i));
	ptr( &(s->i) );
	//ptr(s->i);
	return 0;
}

int test()
{
	struct st s;
	s.i = 10;

	printf("ctx addr: %x\n", &s);
	printf("ctx.clen addr: %x\n", &s.i);
	printf("ctx.clen lval: %d\n", s.i);

	ptr_st(&s);
	printf("%d\n", s.i);

/*
	int a = 10;
	ptr(&a);
	printf("%d\n", a);
*/
	return 0;
}

int main(int argc, char const* argv[])
{
	test();
	/*
	struct st s;
	s.i = 10;
	ptr_st(&s);
	printf("%d\n", s.i);
	*/
/*
	int a = 10;
	ptr(&a);
	printf("%d\n", a);
*/
	return 0;
}
