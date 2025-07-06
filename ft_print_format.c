/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:34:36 by grcharle          #+#    #+#             */
/*   Updated: 2025/06/30 18:34:38 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int get_nb_length(unsigned long int nb) {
	int len;

	len = 1;
	while (nb > 9)
	{
		nb /= 10;
		len += 1;
	}
	return (len);
}

char *get_char(char c)
{
	char *data;
	data = (char *) ft_calloc(sizeof(char), 2);
	if (!data)
		return (0);
	data[0] = c;
	return (data);
}

char	*get_string(const char *str)
{
	char *data;

    if (!str)
		data = ft_strdup("(null)");
    else
		data = ft_strdup(str);
	if (!data)
		return (0);
    return (data);
}

char	*get_pointer(unsigned long int nb)
{
	char	*data;

	data = ft_strjoin("0x", ft_itoa(get_nbr_hex(nb, 16, 0)));
	if (!data)
		return (0);
	return (data);
}

int	get_nbr_hex(unsigned long int nb, unsigned short base, int uppercase) {
	int result;
	if (nb >= base)
	{
		result = get_nbr_hex(nb / base, base, uppercase);
		result += BASE_X[nb % base];
	}
	else
		result = BASE_X[nb];
	// printf(">>%i<<", result);
	return (result);
}
//6c8
// size_t  display_format_s(va_list args)
// {
// 	len = ft_strlen(ptr);
// 	ft_putstr_fd(ptr, 1);
// 	free(ptr);
//     return (len);
// }
// size_t  display_format_c(va_list args)
// {
//     char	ptr;
// 	ptr = (int) va_arg(args, int);
// 	ft_putchar_fd(ptr, 1);
//     return (1);
// }
// size_t  display_format_i(va_list args)
// {
//     int	    ptr;
// 	ptr = (int) va_arg(args, int);
// 	ft_putnbr_fd(ptr, 1);
//     return (1);
// }
