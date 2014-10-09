#include <stdio.h>
#include <stdlib.h>

#ifndef X
#error X is not defined
#endif

void str_to_tale(int *t, char *str)
{
        int i;

        for(i=0; i<X*X; i++)
                t[i]=(int)strtol(str, &str, 10);

        return;
}

void output_count(unsigned long long int count[X*X])
{
	int i;

	fputs("#elem,on-bit count\n", stdout);
	for(i=0; i<X*X; i++)
		printf("%d,%llu\n", i+1, count[i]);

	return;
}

int main()
{
	unsigned long long int count[X*X]={0};
	int tale[X*X];
	int i;
	char str[0xffff];

	while(!feof(stdin)){
		fgets(str, 0xffff, stdin);
		str_to_tale(tale, str);
		for(i=0; i<X*X; i++)
			if(tale[i])
				count[i]++;
	}

	output_count(count);

	return 0;
}
