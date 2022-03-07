/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:15:45 by ayghazal          #+#    #+#             */
/*   Updated: 2019/11/10 15:35:36 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*temp;
	char		*res;
	int			ls1;
	int			ls2;

	ls1 = 0;
	ls2 = 0;
	if (!s1)
		return (NULL);
	while (s1[ls1++])
		;
	while (s2[ls2++])
		;
	temp = (char *)malloc(ls1 + ls2 - 1);
	if (temp == NULL)
		return (NULL);
	res = temp;
	while (*s1 != '\0')
		*temp++ = *s1++;
	while (*s2 != '\0')
		*temp++ = *s2++;
	*temp = '\0';
	return (res);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*temp;
	int		i;

	i = 0;
	if (!s || s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	str = (char *)s;
	temp = (char *)malloc(len + 1);
	if (temp == NULL)
		return (NULL);
	while (str[start] != '\0' && len > 0)
	{
		temp[i] = str[start];
		i++;
		start++;
		len--;
	}
	temp[i] = '\0';
	return (temp);
}

char		*ft_strdup(const char *s1)
{
	char		*ptr;
	int			len;

	len = ft_strlen(s1);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, len);
	ptr[len] = '\0';
	return (ptr);
}

size_t		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *temp1;
	char *temp2;

	temp1 = (char *)src;
	temp2 = (char *)dst;
	if (dst == src)
		return (dst);
	while (n--)
	{
		*temp2++ = *temp1++;
	}
	return (dst);
}
