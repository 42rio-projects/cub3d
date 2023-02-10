#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*ola;

	ola = malloc(10);
	ola = "hi\n";
	printf("%s\n", ola);
	free(ola);
}
