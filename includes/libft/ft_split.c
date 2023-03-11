/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:35:39 by vsergio           #+#    #+#             */
/*   Updated: 2023/03/11 13:13:10 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_splits(char *s, char c);
static int	sub_len(char *s, char c);
static void	ft_free(char **final, int offset);

char	**ft_split(char const *s, char c)
{
	char	**final;
	int		splits;
	int		offset;
	int		substring;

	offset = 0;
	splits = count_splits((char *)s, c);
	final = malloc(sizeof(char *) * (splits + 1));
	if (final == NULL)
		return (NULL);
	final[splits] = NULL;
	while (offset < splits)
	{
		substring = sub_len((char *)s, c);
		final[offset] = ft_substr(s, 0, substring);
		if (!final[offset++])
		{
			ft_free(final, offset);
			return (NULL);
		}
		s += substring;
	}
	return (final);
}

static void	ft_free(char **final, int offset)
{
	while (offset-- > 0)
		free(final[offset]);
	free(final);
}

static int	count_splits(char *str, char c)
{
	int	splitnum;

	splitnum = 1;
	while (*str)
	{
		if (*str == c)
			splitnum++;
		str++;
	}
	return (splitnum);
}

static int	sub_len(char *str, char c)
{
	int	len;

	len = 0;
	while (str[len])
	{
		if (str[len] == c)
			return (len + 1);
		len++;
	}
	return (len);
}
