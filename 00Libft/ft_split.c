#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t  ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

static int count_w(/* whatever parameter you need */)
{
   /* find and return the number of words in the string */
}

static void ft_free(/* whatever argument you need */)
{
   /* free EVERYTHING you allocated */
   /* each element of the array as well as the array */
}

static char *space_word(/* whatever argument you need */)
{
   /* allocate enough room for the word */
   /* copy the word into the memory you allocated above */
   /* return the allocated word */
}

char    **ft_split(char const *s, char c)
{
    size_t  size;

    size = ft_strlen(s);

    if (!s)
        return (NULL);
    /* allocate an array big enough to hold all the words in s */
   /* loop over the string and find the start of the word */
    /* find the end of the word */
   /* copy the world at the first free index in our words array */
   /* return our words array */     
}

int main()
{
    char    *str = "Viento en popa, a toda vela, no corta el mar, sino vuela";
}