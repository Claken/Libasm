/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testasm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:59:01 by sachouam          #+#    #+#             */
/*   Updated: 2021/05/07 16:09:20 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

# include "libasm.h"

void
	test_strlen(void)
{
	printf("===== TEST STRLEN =====\n");
	char str[] = "chaine";
	printf("str : %s\n", str);
	printf("le vrai strlen : %ld\n", strlen(str));
	printf("libasm  strlen : %d\n", ft_strlen(str));
	printf("\n");
	char str2[] = "";
	printf("str : %s\n(c'est-à-dire \"\")\n", str2);
	printf("le vrai strlen : %ld\n", strlen(str2));
	printf("libasm  strlen : %d\n", ft_strlen(str2));
	printf("\n");
	char str3[] = "asdfasdf''///##!!@";
	printf("str : %s\n", str3);
	printf("le vrai strlen : %ld\n", strlen(str3));
	printf("libasm  strlen : %d\n", ft_strlen(str3));
	printf("\n");
	char str4[] = "the\0hidden";
	printf("str : %s\n(c'est-à-dire \"the\\0hidden\")\n", str4);
	printf("le vrai strlen : %ld\n", strlen(str4));
	printf("libasm  strlen : %d\n", ft_strlen(str4));
	printf("\n");
	char str5[] = "Lorem ipsum dolor sit amet, consectetur adipiscingelit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquambibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Crasvolutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisifelis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellusac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posueretortor, sit amet consequat amet.";
	printf("str : %s\n", str5);
	printf("le vrai strlen : %ld\n", strlen(str5));
	printf("libasm  strlen : %d\n", ft_strlen(str5));
	printf("\n");
}

void
	test_strcpy(void)
{
	printf("===== TEST STRCPY =====\n");
	char src[] = "chaine";
	char dst[10];
	char dst2[10];
	printf("src : %s\n", src);
	strcpy(dst, src);
	printf("le vrai strcpy = %s\n", dst);
	ft_strcpy(dst2, src);
	printf("libasm  strcpy = %s\n", dst2);
	printf("\n");
	char sc[] = "";
	char dt[10];
	char dt2[10];
	printf("src : %s\n(c'est-à-dire \"\")\n", sc);
	strcpy(dt, sc);
	printf("le vrai strcpy = %s\n", dt);
	ft_strcpy(dt2, sc);
	printf("libasm  strcpy = %s\n", dt2);
	printf("\n");
	char str4[] = "the\0hidden";
	printf("str : %s\n(c'est-à-dire \"the\\0hidden\")\n", str4);
	char dd[1000];
	char dd2[1000];
	strcpy(dd, str4);
	ft_strcpy(dd2, str4);
	printf("le vrai strcpy = %s\n", dd);
	printf("libasm  strcpy = %s\n", dd2);
	printf("\n");
	char str5[] = "Lorem ipsum dolor sit amet, consectetur adipiscingelit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquambibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Crasvolutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisifelis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellusac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posueretortor, sit amet consequat amet.";
	char d[10000];
	char d2[10000];
	printf("src : %s\n", str5);
	strcpy(d, str5);
	ft_strcpy(d2, str5);
	printf("le vrai strcpy = %s\n", d);
	printf("libasm  strcpy = %s\n", d2);
	printf("\n");
	char str6[] = "\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0b\x0c\x0d\x0e\x0f";
	printf("src : %s\nc'est-à-dire : ", str6);
	printf("\\x01\\x02\\x03\\x04\\x05\\x06\\x07\\x08\\x09\\x0b\\x0c\\x0d\\x0e\\x0f\n");
	char ddd[1000];
	char ddd2[1000];
	strcpy(ddd, str6);
	ft_strcpy(ddd2, str6);
	printf("le vrai strcpy = %s(endofstr)\n", ddd);
	printf("libasm  strcpy = %s(endofstr)\n", ddd2);
	printf("\n");

}

void
	test_strcmp(void)
{
	printf("===== TEST STRCMP =====\n");
	char str1[] = "";
	char str2[] = "";
	printf("chaines : \"\" et \"\"\n");
	printf("vrai   strcmp : %d\n", strcmp(str1, str2));
	printf("libasm strcmp : %d\n", ft_strcmp(str1, str2));
	printf("\n");
	char s1[] = "";
	char s2[] = "dzd";
	printf("chaines : \"\" et %s\n", s2);
	printf("vrai   strcmp : %d\n", strcmp(s1, s2));
//	strcmp(s1, s2) < 0 ? -1 : strcmp(s1, s2));
	printf("libasm strcmp : %d\n", ft_strcmp(s1, s2));
	printf("\n");
	char st1[] = "bon";
	char st2[] = "bo";
	printf("chaines : %s et %s\n", st1, st2);
	printf("vrai   strcmp : %d\n", strcmp(st1, st2));
//	strcmp(st1, st2) > 0 ? 1 : strcmp(st1, st2));
	printf("libasm strcmp : %d\n", ft_strcmp(st1, st2));
	printf("\n");
	printf("chaines : %s et %s\n", st2, st1);
	printf("vrai   strcmp : %d\n", strcmp(st2, st1));
	printf("libasm strcmp : %d\n", ft_strcmp(st2, st1));
	printf("\n");
	char src1[] = "\xff\xff";
	char src2[] = "\xff";
	printf("chaines : \\xff\\xff et \\xff\n");
	printf("vrai   strcmp : %d\n", strcmp(src1, src2));
//	strcmp(src1, src2) > 0 ? 1 : strcmp(src1, src2));
	printf("libasm strcmp : %d\n", ft_strcmp(src1, src2));
	printf("\n");
}

void
	test_strdup(void)
{
	printf("===== TEST STRDUP =====\n");
	char *s1 = NULL;
	char *s2 = NULL;
	printf("chaine : unechaine\n");
	s1 = strdup("unechaine");
	s2 = ft_strdup("unechaine");
	printf("vrai   strdup = %s\n", s1);
	printf("libasm strdup = %s\n", s2);
	printf("\n");
	free(s1);
	free(s2);
	char str5[] = "Lorem ipsum dolor sit amet, consectetur adipiscingelit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquambibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Crasvolutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisifelis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellusac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posueretortor, sit amet consequat amet.";
	s1 = strdup(str5);
	s2 = ft_strdup(str5);
	printf("chaine : %s\n\n", str5);
	printf("vrai   strdup = %s\n\n", s1);
	printf("libasm strdup = %s\n", s2);
	free(s1);
	free(s2);
	printf("\n");
	char str4[] = "the\0hidden";
	printf("chaine : the\\0hidden\n");
	s1 = strdup(str4);
	s2 = ft_strdup(str4);
	printf("vrai   strdup = %s\n", s1);
	printf("libasm strdup = %s\n", s2);
	free(s1);
	free(s2);
	printf("\n");
	printf("chaine : \"\"\n");
	s1 = strdup("");
	s2 = ft_strdup("");
	printf("vrai   strdup = %s\n", s1);
	printf("libasm strdup = %s\n", s2);
	free(s1);
	free(s2);
	printf("\n");
	char str6[] = "\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0b\x0c\x0d\x0e\x0f";
	printf("chaine : \\x01\\x02\\x03\\x04\\x05\\x06\\x07\\x08\\x09\\x0b\\x0c\\x0d\\x0e\\x0f\n");
	s1 = strdup(str6);
	s2 = ft_strdup(str6);
	printf("vrai   strdup = %s.\n", s1);
	printf("libasm strdup = %s.\n", s2);
	free(s1);
	free(s2);
	printf("\n");
}

void
	test_write(void)
{
	printf("===== TEST WRITE  =====\n");
	printf("vrai write :\n");
	write(1, "c\n", 2);
	printf("asm  write :\n");
	ft_write(1, "c\n", 2);
	printf("\n");
	printf("vrai write :\n");
	write(1, "string\n", 7);
	printf("asm  write :\n");
	ft_write(1, "string\n", 7);
	printf("\n");
	printf("vrai write :\n");
	write(1, "the\0hidden\n", 11);
	printf("asm  write :\n");
	ft_write(1, "the\0hidden\n", 11);
	printf("\n");
	printf("vrai write :\n");
	write(2, "std = 2\n", 8);
	printf("asm  write :\n");
	ft_write(2, "std = 2\n", 8);
	printf("\n");
	printf("vrai write :\n");
	write(1, "pas assez de places", 16);
	printf("\n");
	printf("asm  write :\n");
	ft_write(1, "pas assez de places", 16);
	printf("\n");
	printf("\n");
	printf("vrai write :\n");
	write(1, "#c#s#p#x#X#e#f#g\n", 18);
	printf("asm  write :\n");
	ft_write(1, "#c#s#p#x#X#e#f#g\n", 18);
	printf("\n");
	char str6[] = "\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0b\x0c\x0d\x0e\x0f";
	printf("vrai write :\n");
	write(1, str6, 50);
	printf("\n");
	printf("asm  write :\n");
	ft_write(1, str6, 50);
	printf("\n");
	printf("\n");
	printf("(quand std = -1)\n");
	printf("vrai write :\n");
	printf("return value = %ld\n", write(-1, "bonjour", 7));
	printf("errno        = %d\n", errno);
	errno = 0;
	printf("asm  write :\n");
	printf("return value = %ld\n", ft_write(-1, "bonjour", 7));
	printf("errno        = %d\n", errno);
	printf("\n");
	printf("(quand std = 3 et chaine = \"\")\n");
	printf("vrai write :\n");
	printf("return value = %ld\n", write(3, "", 0));
	printf("errno        = %d\n", errno);
	errno = 0;
	printf("asm  write :\n");
	printf("return value = %ld\n", ft_write(3, "", 0));
	printf("errno        = %d\n", errno);
	printf("\n");
}

void
	test_read(char *av)
{
	printf("=====  TEST READ  =====\n");
	char buffer[1000];
	char fd;

	fd = open(av, O_RDONLY);
	printf("vrai read : \n");
	printf("return value : %ld\n", read(fd, buffer, 15));
	printf("buffer : %s\n", buffer);
	close(fd);
	fd = open(av, O_RDONLY);
	bzero(buffer, 1000);
	printf("asm  read : \n");
	printf("return value : %ld\n", ft_read(fd, buffer, 15));
	printf("buffer : %s\n", buffer);
	bzero(buffer, 1000);
	close(fd);
	fd = open(av, O_RDONLY);
	printf("\n");

	fd = open(av, O_RDONLY);
	printf("quand size = 1000\n");
	printf("vrai read : \n");
	printf("return value : %ld\n", read(fd, buffer, 1000));
	printf("buffer : %s\n", buffer);
	close(fd);
	fd = open(av, O_RDONLY);
	bzero(buffer, 1000);
	printf("asm  read : \n");
	printf("return value : %ld\n", ft_read(fd, buffer, 1000));
	printf("buffer : %s\n", buffer);
	bzero(buffer, 1000);
	close(fd);
	fd = open(av, O_RDONLY);
	printf("\n");

	printf("(quand size = 0)\n");
	printf("vrai read : \n");
	printf("return value : %ld\n", read(fd, buffer, 0));
	printf("buffer : %s\n", buffer);
	close(fd);
	fd = open(av, O_RDONLY);
	printf("asm  read : \n");
	printf("return value : %ld\n", ft_read(fd, buffer, 0));
	printf("buffer : %s\n", buffer);
	close(fd);
	fd = open(av, O_RDONLY);
	printf("\n");

	printf("(quand size = -1)\n");
	printf("vrai read : \n");
	printf("return value : %ld\n", read(fd, buffer, -1));
	printf("errno        = %d\n", errno);
	errno = 0;
	close(fd);
	fd = open(av, O_RDONLY);
	printf("asm  read : \n");
	printf("return value : %ld\n", ft_read(fd, buffer, -1));
	printf("errno        = %d\n", errno);
	errno = 0;
	close(fd);
	fd = open(av, O_RDONLY);
	printf("\n");

	printf("(quand fd = -1)\n");
	printf("vrai read :\n");
	printf("return value = %ld\n", read(-1, buffer, 7));
	printf("errno        = %d\n", errno);
	errno = 0;
	printf("asm  read :\n");
	printf("return value = %ld\n", ft_read(-1, buffer, 7));
	printf("errno        = %d\n", errno);
	printf("\n");

	printf("(quand buffer = NULL)\n");
	printf("vrai read :\n");
	printf("return value = %ld\n", read(fd, NULL, 7));
	printf("errno        = %d\n", errno);
	errno = 0;
	close(fd);
	fd = open(av, O_RDONLY);
	printf("asm  read :\n");
	printf("return value = %ld\n", ft_read(fd, NULL, 7));
	printf("errno        = %d\n", errno);
	printf("\n");
	close(fd);
}

int
	main(int ac, char **av)
{
	if (ac < 2)
	{
		printf("not enough arguments\n");
		return (0);
	}
	if (atoi(av[1]) == 1)
		test_strlen();
	else if (atoi(av[1]) == 2)
		test_strcpy();
	else if (atoi(av[1]) == 3)
		test_strcmp();
	else if (atoi(av[1]) == 4)
		test_write();
	else if (atoi(av[1]) == 5 && ac > 2)
		test_read(av[2]);
	else if (atoi(av[1]) == 6)
		test_strdup();
	else
	{
		if (atoi(av[1]) == 5 && ac <= 2)
			printf("put a file .txt in second argument for read (5)\n");
		else
			printf("put a number between 1 and 6\n");
	}
	return (0);
}
