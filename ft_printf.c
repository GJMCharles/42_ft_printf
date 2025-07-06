/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 11:21:15 by grcharle          #+#    #+#             */
/*   Updated: 2025/06/30 06:28:01 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_fetch_sign(const char *str, va_list args)
{
	(void) str;
	(void) args;
	// char flags[10] = "cspdiuxX%";

	size_t i;
	// size_t length;

	i = 0;
	// length = 0;
	if (str[i] == 'c') return get_char((char) va_arg(args, int));
	else if (str[i] == 's') return get_string(va_arg(args, char *));
	else if (str[i] == 'p') return get_pointer((unsigned long int) va_arg(args, unsigned long int));
	// else if (str[i] == 'd' || str[i] == 'i') {}
	// else if (str[i] == 'u') {}
	// else if (str[i] == 'x') {}
	// else if (str[i] == 'X') {}
	// else if (str[i] == '%') {}
	return (0);
}

char	*printf_buffer(const char *str, size_t len, va_list args)
{
	size_t	i;
	char	*data;
	char	*tmp1;
	char	*tmp2;

	i = 0;
	data = ft_strdup("");
	if (!data) return (0);
	while (i < len && str[i])
	{
		tmp1 = ft_strdup(data);
		free(data);
		if (str[i] == '%')
		{
            i += 1;
            tmp2 = check_fetch_sign(str + i, args);
		}
		else tmp2 = get_char((int) str[i]);
		data = ft_strjoin(tmp1, tmp2);
		free(tmp1);
		free(tmp2);
		i += 1;
	}
	return (data);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	size_t len;
	char *data;

	if (!str)
		return (-1);
    va_start(args, str);
    data = printf_buffer(str, ft_strlen(str), args);
    va_end(args);
    ft_putstr_fd(data, 1);
	len = ft_strlen(data);
    free(data);
	return (len);
}
