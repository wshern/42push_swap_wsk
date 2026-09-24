#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

static void test_strlen(void)
{
	char *a = "test123";
	char *b = "";
	char *c = "This is a very long string that totals at 44";

	if (ft_strlen(a) != strlen(a))
	{
		printf("ft_strlen FAIL - short\n");
		return;
	}
	else if (ft_strlen(b) != strlen(b))
	{
		printf("ft_strlen FAIL - empty\n");
		return;
	}
	else if (ft_strlen(c) != strlen(c))
	{
		printf("ft_strlen FAIL - long\n");
		return;
	}
	else
		printf("ft_strlen OK!\n");
}

static void	test_isalpha(void)
{
	int	i;

	i = -10;
	while (i < 300)
	{
		if (!!ft_isalpha(i) != !!isalpha(i))
		{
			printf("ft_isalpha FAIL at %d\n", i);
			return ;
		}
		i++;
	}
	printf("ft_isalpha OK!\n");
}

static void	test_isdigit(void)
{
	int	i;

	i = -10;
	while (i < 300)
	{
		if (!!ft_isdigit(i) != !!isdigit(i))
		{
			printf("ft_isdigit FAIL at %d\n", i);
			return ;
		}
		i++;
	}
	printf("ft_isdigit OK!\n");
}

static void	test_isalnum(void)
{
	int	i;

	i = -10;
	while (i < 300)
	{
		if (!!ft_isalnum(i) != !!isalnum(i))
		{
			printf("ft_isalnum FAIL at %d\n", i);
			return ;
		}
		i++;
	}
	printf("ft_isalnum OK!\n");
}

static void	test_isascii(void)
{
	int	i;

	i = -10;
	while (i < 300)
	{
		if (!!ft_isascii(i) != !!isascii(i))
		{
			printf("ft_isascii FAIL at %d\n", i);
			return ;
		}
		i++;
	}
	printf("ft_isascii OK!\n");
}

static void	test_isprint(void)
{
	int	i;

	i = -10;
	while (i < 300)
	{
		if (!!ft_isprint(i) != !!isprint(i))
		{
			printf("ft_isprint FAIL at %d\n", i);
			return ;
		}
		i++;
	}
	printf("ft_isprint OK!\n");
}

static void test_memset(void)
{
	char ctrl[20];
	char test[20];

	memset(ctrl, 'X', 20);
	if (ft_memset(test, 'X', 20) != test)
		printf("ft_memset FAIL - return value!\n");
	else if (memcmp(ctrl, test, 20) != 0)
		printf("ft_memset FAIL - content!\n");
	memset(ctrl, 'A', 20);
	memset(test, 'A', 20);
	ft_memset(test, 'Z', 0);
	if (memcmp(ctrl, test, 20) != 0)
		printf("ft_memset FAIL: n=0\n");
	memset(ctrl, 200, 10);
	ft_memset(test, 200, 10);
	if (memcmp(ctrl, test, 10) != 0)
		printf("ft_memset FAIL: value > 127\n");
	else
		printf("ft_memset OK!\n");
}

static void test_bzero(void)
{
	char ctrl[20];
	char test[20];

	memset(ctrl, 'a', 20);
	memset(test, 'a', 20);
	bzero(ctrl, 20);
	ft_bzero(test, 20);
	if (memcmp(ctrl, test, 20) != 0)
		printf("ft_bzero FAIL: content!\n");
	else
		printf("ft_bzero OK!\n");
}

static void test_memcpy(void)
{
	char ctrl[20];
	char test[20];
	char src[] = "abc\0de";

	memcpy(ctrl, src, 7);
	if (ft_memcpy(test, src, 7) != test)
	{
		printf("ft_memcpy FAIL - return value!\n");
		return;
	}
	else if (memcmp(ctrl, test, 7) != 0)
	{
		printf("ft_memcpy FAIL - content!\n");
		return;
	}
	memset(ctrl, 'A', 20);
	memset(test, 'A', 20);
	ft_memcpy(test, src, 0);
	if (memcmp(ctrl, test, 20) != 0)
		printf("ft_memcpy FAIL - wrote when n=0\n");
	else
		printf("ft_memcpy OK!\n");
}

static void test_memmove(void)
{
	char ctrl_src[] = "Test string";
	char ctrl_dest[12];
	char test_src[] = "Test string";
	char test_dest[12];

	memmove(ctrl_dest, ctrl_src, 5);
	ft_memmove(test_dest, test_src, 5);
	if (memcmp(ctrl_dest, test_dest, 5) != 0)
	{
		printf("ft_memmove FAIL - content\n");
		return;
	}

	char ctrl[] = "Test string";
	char test[] = "Test string";

	memmove(ctrl + 2, ctrl, 5);
	ft_memmove(test + 2, test, 5);
	if (memcmp(ctrl, test, 12) != 0)
	{
		printf("ft_memmove FAIL - overlap (dest > src)!\n");
		return ;
	}
	char ctrl2[] = "Test string";
	char test2[] = "Test string";

	memmove(ctrl2, ctrl2 + 2, 5);
	ft_memmove(test2, test2 + 2, 5);
	if (memcmp(ctrl2, test2, 12) != 0)
		printf("ft_memmove FAIL - overlap (dest < src)!\n");
	else
		printf("ft_memmove OK!\n");
}

static void test_memchr(void)
{
	char s[] = "Hello world";

	if (memchr(s, 'w', 12) != ft_memchr(s, 'w', 12))
		printf("ft_memchr FAIL - found error!\n");
	else if (memchr(s, 'z', 12) != ft_memchr(s, 'z', 12))
		printf("ft_memchr FAIL - not found error!\n");
	else if (memchr(s, 0, 12) != ft_memchr(s, 0, 12))
		printf("ft_memchr FAIL - null byte should be found!\n");
	else if (memchr(s, 'w', 3) != ft_memchr(s, 'w', 3))
		printf("ft_memchr FAIL - n too small!\n");
	else if (memchr(s, 200, 12) != ft_memchr(s, 200, 12))
		printf("ft_memchr FAIL - byte > 127!\n");
	else
		printf("ft_memchr OK!\n");
}

// for memcmp and strncmp
int sign(int n)
{
	if (n > 0)
		return (1);
	if (n < 0)
		return (-1);
	return (0);
}
// for memcmp and strncmp

static void test_memcmp(void)
{
	char *s1 = "Test 12345";
	char *s2 = "Test 12a45";
	char *a = "\200";
	char *b = "\0";

	if (sign(memcmp(s1, s2, 11)) != sign(ft_memcmp(s1, s2, 11)))
		printf("ft_memcmp FAIL - differ\n");
	else if (sign(memcmp(s1, s1, 11)) != sign(ft_memcmp(s1, s1, 11)))
		printf("ft_memcmp FAIL - identical\n");
	else if (sign(memcmp(s1, s2, 0)) != sign(ft_memcmp(s1, s2, 0)))
		printf("ft_memcmp FAIL - n=0\n");
	else if (sign(memcmp(a, b, 1)) != sign(ft_memcmp(a, b, 1)))
		printf("ft_memcmp FAIL - byte > 127\n");
	else
		printf("ft_memcmp OK\n");
}

static void test_strlcpy(void)
{
	char *src = "HelloWorld";
	char dest1[11];
	char dest2[11];

	if (strlcpy(dest1, src, 11) != ft_strlcpy(dest2, src, 11))
		printf("ft_strlcpy FAIL - result error!\n");
	else if (memcmp(dest1, dest2, 11) != 0)
		printf("ft_strlcpy FAIL - content error!\n");
	else if (strlcpy(dest1, src, 7) != ft_strlcpy(dest2, src, 7))
		printf("ft_strlcpy FAIL - size different!\n");
	else if (memcmp(dest1, dest2, 7) != 0)
		printf("ft_strlcpy FAIL - content different\n");
	else if (strlcpy(dest1, src, 0) != ft_strlcpy(dest2, src, 0))
		printf("ft_strlcpy FAIL - must write nothing!\n");
	else if (strlcpy(dest1, src, 1) != ft_strlcpy(dest2, src, 1))
		printf("ft_strlcpy FAIL - more than NULL error!\n");
	else if (memcmp(dest1, dest2, 1) != 0)
		printf("ft_strlcpy FAIL - null not copied!\n");
	else
		printf("ft_strlcpy OK!\n");
}

static void test_strlcat(void)
{
	char *src = "Hello World";
	char dest1[30] = "Test World";
	char dest2[30] = "Test World";

	if (strlcat(dest1, src, 22) != ft_strlcat(dest2, src, 22))
	{
		printf("ft_strlcat FAIL - result ERROR!\n");
		return;
	}
	else if (memcmp(dest1, dest2, 22) != 0)
	{
		printf("ft_strlcat FAIL - content ERROR!\n");
		return;
	}
	strcpy(dest1, "Test World");
	strcpy(dest2, "Test World");
	if (strlcat(dest1, src, 17) != ft_strlcat(dest2, src, 17))
	{
		printf("ft_strlcat FAIL - TRUNCATION result EERROR!\n");
		return;
	}
	else if (memcmp(dest1, dest2, 17) != 0)
	{
		printf("ft_strlcat FAIL - TRUNCATION content ERROR!\n");
		return;
	}
	strcpy(dest1, "Test World");
	strcpy(dest2, "Test World");
	if (strlcat(dest1, src, 5) != ft_strlcat(dest2, src, 5))
	{
		printf("ft_strlcat FAIL - dstsize < dst return ERROR\n");
		return;
	}
	strcpy(dest1, "Test World");
	strcpy(dest2, "Test World");	
	if (strlcat(dest1, src, 0) != ft_strlcat(dest2, src, 0))
			printf("ft_strlcat FAIL - n=0\n");
	else printf("ft_strlcat OK!\n");
}

static void test_toupper_tolower(void)
{
	int i;
	int result = 1;

	i = -10;
	while (i < 300)
	{
		if (toupper(i) != ft_toupper(i))
			result = 0;
		i++;
	}
	if (result == 1)
		printf("ft_toupper OK!\n");
	else
		printf("ft_toupper FAIL!\n");
	i = -10;
	while (i < 300)
	{
		if (tolower(i) != ft_tolower(i))
			result = 0;
		i++;
	}
	if (result == 1)
		printf("ft_tolower OK!\n");
	else
		printf("ft_tolower FAIL!\n");
}

static void test_strchr_strrchr(void)
{
	char *str = "Hello World";

	if (strchr(str, 'l') != ft_strchr(str, 'l'))
		printf("ft_strchr FAIL - return ERROR!\n");
	else if (strchr(str, 'z') != ft_strchr(str, 'z'))
		printf("ft_strchr FAIL - not found ERROR!\n");
	else if (strchr(str, '\0') != ft_strchr(str, '\0'))
		printf("ft_strchr FAIL - null ERROR!\n");
	else if (strrchr(str, 'l') != ft_strrchr(str, 'l'))
		printf("ft_strchr FAIL - REVERSE return ERROR!\n");
	else if (strrchr(str, 'z') != ft_strrchr(str, 'z'))
		printf("ft_strrchr FAIL - REVERSE not found ERROR!\n");
	else if (strrchr(str, '\0') != ft_strrchr(str, '\0'))
		printf("ft_strrchr FAIL - REVERSE null ERROR!\n");
	else
		printf("ft_strchr OK!\nft_strrchr OK!\n");
}

static void test_strncmp(void)
{
	char *s1 = "Test 12345";
	char *s2 = "Test 12a45";
	char *a = "\200";
	char *b = "\0";

	if (sign(strncmp(s1, s2, 11)) != sign(ft_strncmp(s1, s2, 11)))
		printf("ft_strncmp FAIL - differ\n");
	else if (sign(strncmp(s1, s1, 11)) != sign(ft_strncmp(s1, s1, 11)))
		printf("ft_strncmp FAIL - identical\n");
	else if (sign(strncmp(s1, s2, 0)) != sign(ft_strncmp(s1, s2, 0)))
		printf("ft_strncmp FAIL - n=0\n");
	else if (sign(strncmp(a, b, 1)) != sign(ft_strncmp(a, b, 1)))
		printf("ft_strncmp FAIL - byte > 127\n");
	else if (sign(strncmp("abc", "abcd", 5)) != sign(ft_strncmp("abc", "abcd", 5)))
		printf("ft_strncmp FAIL - diff str length error!\n");
	else if (sign(strncmp(s1, s2, 3)) != sign(ft_strncmp(s1, s2, 3)))
		printf("ft_strncmp FAIL - comparison error!\n");
	else
		printf("ft_strncmp OK!\n");
}

static void test_strnstr(void)
{
	char *str = "Test Stri3ng";
	char *find = "st Stri";

	if (strnstr(str, find, 13) != ft_strnstr(str, find, 13))
	{
		printf("ft_strnstr FAIL - 'found' ERROR!\n");
		return;
	}
	if (strnstr(str, find, 5) != ft_strnstr(str, find, 5))
	{
		printf("ft_strnstr FAIL - (n < needle) ERROR!\n");
		return;
	}
	if (strnstr(str, find, 0) != ft_strnstr(str, find, 0))
	{
		printf("ft_strnstr FAIL - n=0 ERROR!\n");
		return;
	}
	find = "z";
	if (strnstr(str, find, 13) != ft_strnstr(str, find, 13))
	{	
		printf("ft_strnstr FAIL - 'not found' ERROR!\n");
		return;
	}
	find = "";
	if (strnstr(str, find, 13) != ft_strnstr(str, find, 13))
	{
		printf("ft_strnstr FAIL - empty needle ERROR!\n");
		return;
	}
	str = "Test";
	find = "Testt";
	if (strnstr(str, find, 6) != ft_strnstr(str, find, 6))
	{
		printf("ft_strnstr FAIL - (needle > haystack) ERROR!\n");
		return;
	}
	else
		printf("ft_strnstr OK!\n");
}

static void	test_atoi(void)
{
	char	*cases[] = {"42", "-42", "+42", "   \t\n42", "42abc",
		"abc", "", "--42", "-", "2147483647", "-2147483648", "0", "-0"};
	int		i;
	int		n;

	n = sizeof(cases) / sizeof(cases[0]);
	i = 0;
	while (i < n)
	{
		if (ft_atoi(cases[i]) != atoi(cases[i]))
		{
			printf("atoi FAIL on \"%s\"\n", cases[i]);
			return ;
		}
		i++;
	}
	printf("ft_atoi OK!\n");
}

static void test_calloc(void)
{
	char	*ptr;
	char	*ptr1;
	char	*ptr2;

	ptr = ft_calloc(0, 0);
	if (ptr == NULL)
	{
		printf("ft_calloc FAIL - not non-NULL\n");
		free(ptr);
		return;
	}
	ptr1 = ft_calloc(10, sizeof(char));
	ptr2 = calloc(10, sizeof(char));
	if (ptr1 == NULL)
		printf("ft_calloc FAIL - NULL\n");
	else if (memcmp(ptr1, ptr2, 10) != 0)
		printf("ft_calloc FAIL -not zeroed!\n");
	else
		printf("ft_calloc OK!\n");
	free(ptr);
	free(ptr1);
	free(ptr2);
}

static void test_strdup(void)
{
	char *str = "Test string";
	char *ptr1;
	char *ptr2;

	ptr1 = strdup(str);
	ptr2 = ft_strdup(str);
	if (ptr2 == NULL)
		printf("ft_strdup FAIL - returned NULL!\n");
	else if (strcmp(ptr1, ptr2) != 0)
		printf("ft_strdup FAIL - content!\n");
	else if (ptr2 == str)
		printf("ft_strdup FAIL - same address!\n");
	free(ptr1);
	free(ptr2);
	str = "";
	ptr1 = strdup(str);
	ptr2 = ft_strdup(str);
	if (strcmp(ptr1, ptr2) != 0)
		printf("ft_strdup FAIL - duplicate not empty!\n");
	else
		printf("ft_strdup OK!\n");
	free(ptr1);
	free(ptr2);
}

static void test_ftsplit(void)
{
	char *s = "xxtestx xxxwordxxx";
	char c = 'x';
	char **arr;

	arr = ft_split(s, c);
	if (arr == NULL)
		printf("st_split FAIL - NULL returned!\n");
	else
		printf("ft_split OK!\n");
}

int	main(void)
{
	test_strlen();
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();
	test_memchr();
	test_memcmp();
	test_strlcpy();
	test_strlcat();
	test_toupper_tolower();
	test_strchr_strrchr();
	test_strncmp();
	test_strnstr();
	test_atoi();
	test_calloc();
	test_strdup();

	test_ftsplit();
	return (0);
}