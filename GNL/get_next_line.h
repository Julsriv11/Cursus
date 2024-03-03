

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
void    *ft_calloc(size_t count, size_t size);
void    *ft_memset(void *b, int c, size_t len);
char    *join_and_free(char *static_lines, char *buffer);
char    *go_next_line(char *static_lines);
char    *returned_line(char *static_lines);
char    *get_next_line(int fd);

#endif