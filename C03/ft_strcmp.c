int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    // This loop does all the work. It stops at the end of s1 OR at the first difference.
    while (s1[i] != '\0' && s1[i] == s2[i])
    {
        i++;
    }

    // After the loop, return the difference at the stopping point.
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
int main()
{
  ft_strcmp("heKlo", "hello");

  return 0;
}