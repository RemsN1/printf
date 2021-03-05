#include "ft_printf.h"

int main()
{
	int a = 0;
	printf("%0*.%\n", 2);
	ft_printf("%0*.%\n", 2); //-135 -12 -1 0 1 13 198
}
