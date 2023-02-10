#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*ola;

	ola = malloc(10);
	ola = "esta vazando\n";
	printf("%s\n", ola);
}
