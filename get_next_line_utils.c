/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:00:00 by cvidon            #+#    #+#             */
/*   Updated: 2022/08/15 18:00:00 by cvidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 ** @brief      Find length of string.
 **
 ** "The strlen() function computes the length of the string s.  The strnlen()
 ** function attempts to compute the length of s, but never scans beyond the **
 ** first maxlen bytes of s."
 **
 ** @see        STRLEN(3) <string.h>
 */

size_t	ft_strlen(const char *str)
{
	const char	*ptr;

	ptr = str;
	while (*ptr)
		++ptr;
	return ((size_t)(ptr - str));
}

/*
 ** @brief      Save a copy of a string.
 **
 ** XXX PROTECTED VERSION
 **
 ** "The strdup() function allocates sufficient memory for a copy of the string
 ** s1, does the copy, and returns a pointer to it.  The pointer may
 ** subsequently be used as an argument to the function free(3)."
 **
 ** @see        STRDUP(3) <string.h>
 */

char	*ft_strdup(const char *str)
{
	char	*dup;
	char	*ptr;

	if (!str)
		return (NULL);
	dup = malloc (sizeof (char) * (ft_strlen(str) + 1));
	if (!dup)
		return (NULL);
	ptr = dup;
	while (*str)
		*ptr++ = *str++;
	return (*ptr = 0, dup);
}

/*
 ** @brief      Concatenate two strings into a new string (with malloc).
 **
 ** XXX PROTECTED VERSION
 **
 ** @param[in]  s1 the first string (will be free).
 ** @param[in]  s2 the second string.
 ** @return     A string made of s1 + s2 or NULL if malloc fail.
 */

char	*ft_strjoin_free_s1(char *s1, const char *s2)
{
	char	*s3;
	char	*p3;
	char	*p1;

	if (!s1 && s2)
		return (ft_strdup (s2));
	if (s1 && !s2)
		return (ft_strdup (s1));
	if (!s1 && !s2)
		return (ft_strdup (""));
	s3 = malloc (sizeof (char) * (ft_strlen (s1) + ft_strlen (s2) + 1));
	if (!s3)
		return (free (s1), NULL);
	p3 = s3;
	p1 = s1;
	while (*p1)
		*p3++ = *p1++;
	while (*s2)
		*p3++ = *s2++;
	return (*p3 = 0, free (s1), s3);
}

/*
 ** @brief      Extract substring from string.
 **
 ** "Allocates (with malloc(3)) and returns a substring from the string s.
 ** The substring begins at index start and is of maximum size len."
 **
 ** XXX PROTECTED
 ** XXX MODIFIED: return NULL instead of ft_strdup("") l.6
 **
 ** @param[in]  str the string that contain the cherished substring.
 ** @param[in]  start the beginning of the substring.
 ** @param[in]  size the length of the substring.
 ** @return     The cherished substring or NULL if malloc fail.
 */

char	*ft_substr(const char *str, unsigned int start, size_t size)
{
	size_t	len;
	char	*sub;

	if (!str)
		return (NULL);
	len = ft_strlen (str);
	if (start >= len)
		return (NULL);
	if (len - start < size)
		size = len - start;
	sub = malloc (sizeof (char) * (size + 1));
	if (!sub)
		return (NULL);
	sub[size] = 0;
	while (size--)
		sub[size] = str[start + size];
	return (sub);
}
