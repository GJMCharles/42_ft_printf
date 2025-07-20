/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 23:04:41 by grcharle          #+#    #+#             */
/*   Updated: 2025/06/30 06:26:43 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
#include <stddef.h>
# include "libft/libft.h"

# define BASE_LOWER_X "0123456789abcdef"
# define BASE_UPPER_X "0123456789ABCDEF"

int		ft_printf(const char *str, ...);
size_t	printf_buffer(const char *str, size_t len, va_list args);
size_t	fetch_from_signs(size_t *index, const char *str, va_list args);
size_t	print_data(char *data);
size_t	print_string(const char *str);
size_t	print_integer(int nb, short int abs);
size_t	print_pointer(unsigned long int nb);
size_t	print_hexadecimal(unsigned long int nb, int uppercase);

// size_t	print_data(void *ptr, char type);
// char	*get_string(const char *str);
// char	*get_integer(int nb, int abs);

/*
size_t	get_pointer(unsigned long int nb);
char	*get_hex(unsigned long int nb, unsigned short base, int uppercase);
char	*get_string(const char *str);



size_t get_hexadecimal(unsigned long int nb, int uppercase);
*/

#endif // FT_PRINTF_H
