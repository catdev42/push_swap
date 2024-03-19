/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:21:22 by myakoven          #+#    #+#             */
/*   Updated: 2024/03/19 21:53:27 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// char	**makearray(int argc, char **argv)
// {
// 	char	**argv_replace;
// 	int		i;

// 	i = 0;
// 	argv_replace = malloc(sizeof(char *) * argc);
// 	if (!argv_replace)
// 		return (NULL);
// 	while (i < argc - 1)
// 	{
// 		argv_replace[i] = ft_strdup(argv[i + 1]);
// 		if (!argv_replace[i])
// 			return (free_array(argv_replace));
// 		i++;
// 	}
// 	argv_replace[i] = NULL;
// 	return (argv_replace);
// }

char	**ft_split_ps(char const *s, char c)
{
	char	**arr;
	size_t	arr_counter;
	size_t	word_len;

	arr = malloc((ft_wordcount_ps(s, c) + 2) * sizeof(char *));
	if (!arr || !s)
		return (NULL);
	arr_counter = 1;
	arr[0] = ft_strdup("");
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		if (!ft_strchr(s, c))
			word_len = ft_strlen(s);
		else
			word_len = ft_strchr(s, c) - s;
		arr[arr_counter++] = ft_substr(s, 0, word_len);
		if (!arr[arr_counter - 1])
			return (ft_free_split_ps(arr, (arr_counter - 2)));
		s += word_len;
	}
	arr[arr_counter] = NULL;
	return (arr);
}

size_t	ft_wordcount_ps(char const *s, char c)
{
	size_t	count;

	count = 0;
	if (!*s)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}


