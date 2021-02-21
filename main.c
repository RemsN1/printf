#include "printf.h"

int main(int ac, char **av)
{
	unsigned long long x = 0xFFFFF;
	printf("%-10.*d\n",0,0);
	printf("%*.*s\n", 10, 0, "trql");
	printf("%.20p", &x);
}
