#include<stdio.h>
int main()
{
	char s[81], v[31], V[31];
	int i, j, n;
	V[0] = 'A', V[26] = 'A',V[27] = 'B',V[28] = 'C', V[29] = 'D', V[30] = 'E';
	for (i = 1; i < 26; i++)
	V[i] = V[0] + i;
	v[0] = 'a', v[26] = 'a',v[27] = 'b',v[28] = 'c', v[29] = 'd',v[30] = 'e';
	for (i = 1; i < 26; i++)
	v[i] = v[0] + i;
	while (gets(s) != NULL)
	{
		n = strlen(s);
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < 26; j++)
			{
				if (s[i] == v[j])
				{
					s[i] = v[j + 5];
			    	break;
				}
			}
			for (j = 0; j < 26; j++)
			{
				if (s[i] == V[j])
				{
					s[i] = V[j + 5];
			    	break;
				}
			}
		}
		puts(s);
	}
	return 0;
}