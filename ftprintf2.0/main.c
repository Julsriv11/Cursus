/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <jarias-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:48:54 by jarias-i          #+#    #+#             */
/*   Updated: 2024/03/21 10:09:22 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//para comprobar el proyecto

#include "ft_printf.h"

/* int	main(void)
{
	int		x;
	int		y;
	int 	num = 21;
	char	*str = "Wingardium leviosa";
	void	*ptr = malloc(10);
	unsigned int	z = 40000;

	x = ft_printf("Hola %d o %u o %s o %p\n", num, z, str, ptr);
	y = printf("Hola %d o %u o %s o %p\n", num, z, str, ptr);
	free(ptr);
	printf("Longitud de mi print %d y el original %d", x, y);
	return 0;
} */

/* int	main(void)
{
	int	x;
	int	y;
	char *s = "testeo";

	x = ft_printf("Hola %s \n", s);
	y = printf("Hola %s \n", s);
	return 0;
} */
/* 
int	main(void)
{
	int	size;

	char	c = 'D';
	printf("\nCARACTER (c):\n");
	size = printf("Printf: %c\n", c);
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %c\n", c);
	printf("Size ft_printf: %d\n", size);

	int		n = -123;
	printf("\nNÚMERO ENTERO (i):\n");
	size = printf("Printf: %i\n", n);
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %i\n", n);
	printf("Size ft_printf: %d\n", size);

	printf("\nNÚMERO ENTERO (d):\n");
	size = printf("Printf: %d\n", n);
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %d\n", n);
	printf("Size ft_printf: %d\n", size);

	unsigned int	ui = 42;
	printf("\nUNSIGNED INT (u):\n");
	size = printf("Printf: %u\n", ui);
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %u\n", ui);
	printf("Size ft_printf: %d\n", size);

	printf("\nPORCENTAJE (%%):\n");
	size = printf("Printf: %%\n");
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %%\n");
	printf("Size ft_printf: %d\n", size);

	char	*s = "Hola Mundo!";
	printf("\nSTRING (s):\n");
	size = printf("Printf: %s\n", s);
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %s\n", s);
	printf("Size ft_printf: %d\n", size);

	//char	*sn = NULL;
	printf("\nSTRING NULL (s):\n");
	size = printf("%s\n", (char *)NULL);
	printf("Size Printf: %d\n", size);
	size = ft_printf("%s\n", (char *)NULL);
	printf("Size ft_printf: %d\n", size);

	int *p = &n;
	printf("\nPUNTEROS (p):\n");
	size = printf("Printf: %p\n", (void *)p);
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %p\n", (void *)p);
	printf("Size ft_printf: %d\n", size);

	printf("\n>>PUNTERO VACÍO(p):\n");
	size = printf("Printf: %p\n", "");
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %p\n", "");
	printf("Size ft_printf: %d\n", size);

	unsigned int	x = -1;
	printf("\nHEXADECIMAL EN MINÚSCULAS (x):\n");
	size = printf("Printf: %x\n", x);
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %x\n", x);
	printf("Size ft_printf: %d\n", size);

	unsigned int	xx = -1;
	printf("\nHEXADECIMAL EN MAYÚSCULAS (X):\n");
	size = printf("Printf: %X\n", xx);
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %X\n", xx);
	printf("Size ft_printf: %d\n", size);

	printf("\nVACÍO:\n");
	size = printf("");
	printf("Size Printf: %d\n", size);
	size = ft_printf("");
	printf("Size ft_printf: %d\n", size);

	printf("\nCONVERSIÓN ERRONEA:\n");
	// size = printf("Printf: %r\n", n);
	// printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: %r\n", n);
	printf("Size ft_printf: %d\n", size);

	printf("\nNO IMPRIMIBLES:\n");
	size = printf("Printf: \001\002\007\v\010\f\r\n");
	printf("Size Printf: %d\n", size);
	size = ft_printf("ft_printf: \001\002\007\v\010\f\r\n");
	printf("Size ft_printf: %d\n", size);

	return (0);
} */