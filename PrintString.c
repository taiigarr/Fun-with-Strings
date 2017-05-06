int PrintString(string s)
{
	while (!EmptyString(s))
	{
		printf ("%c", s->letter);
		s = s->rightlink;
	}
	printf("\n");
	return 1;
}
