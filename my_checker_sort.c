#include "sorted.h"
#include <string.h>

char	*ft_join(char *inst, char buff)
{
	int	i;
	char	*iinst;

	i = strlen(inst);
	iinst = calloc (i + 2, 1);
	if (!iinst)
		return (NULL);
	iinst[++i] = buff;
	while (i-- > 0)
		iinst[i] = inst[i];
	free (inst);
	return (iinst);
}

int main()
{
	char	*buff;
	char	*inst;

	buff = calloc(2, 1);
	if (!buff)
		return (0);
	while (read(0, buff, 1 ))
		inst = ft_join(inst, buff[0]);
	printf("%s",inst);
	free (inst);
	free (buff);
	return (0);
}
