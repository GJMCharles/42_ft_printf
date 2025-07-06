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
# include <stddef.h>
# include "libft/libft.h"

# define BASE_X "0123456789abcdef"

int		ft_printf(const char *str, ...);
char	*printf_buffer(const char *str, size_t len, va_list args);
char	*check_fetch_sign(const char *str, va_list args);

char	*get_char(char c);
char	*get_string(const char *str);
char	*get_pointer(unsigned long int nb);

int		get_nbr_hex(unsigned long int nb, unsigned short base, int uppercase);

#endif // FT_PRINTF_H
