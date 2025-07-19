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

size_t	fetch_from_signs(size_t *index, const char *str, va_list args)
{
	size_t		i;

	i = 0;
	*index += 1;
	if (str[i] == 'c')
		return (get_char(va_arg(args, int)));
	else if (str[i] == 's')
		return (get_string(va_arg(args, char *)));
	else if (str[i] == 'p')
		return (get_pointer(va_arg(args, unsigned long int)));
	else if (str[i] == 'd' || str[i] == 'i')
		return (get_integer(va_arg(args, long int)));
	else if (str[i] == 'u')
		return (get_uinteger(va_arg(args, unsigned int)));
	else if (str[i] == 'x')
		return (get_lower_hexa(va_arg(args, unsigned long int)));
	else if (str[i] == 'X')
		return (get_upper_hexa(va_arg(args, unsigned long int)));
	else if (str[i] == '%')
		return (get_char((int) '%'));
	return (0);
}

size_t	printf_buffer(const char *str, size_t len, va_list args)
{
	size_t		i;
	size_t		size;

	i = 0;
	size = 0;
	while (i < len && str[i])
	{
		if (str[i] == '%')
			size += fetch_from_signs(&i, str + i + 1, args);
		else
			size += get_char(str[i]);
		i += 1;
	}
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	size_t		size;

	if (!str)
		return (-1);
	va_start(args, str);
	size = printf_buffer(str, ft_strlen(str), args);
	va_end(args);
	return (size);
}
