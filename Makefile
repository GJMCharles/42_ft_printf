# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/31 22:56:16 by grcharle          #+#    #+#              #
#    Updated: 2025/06/30 06:23:13 by grcharle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Set default rule when 'make all'
.DEFAULT_GOAL := all

# Hide message 'Entering directory' & 'Leaving directory'
MAKEFLAGS += --no-print-directory

# Delete files & empty directories
RM := rm -fr
RM_DIR := rmdir -p

NAME := libftprintf.a

MODULES := ./modules
LIBRARY := ./includes
SOURCES := ./sources

AR := ar
CC := cc
CFLAGS := \
	-Wall -Wextra -Werror -Wpedantic \
	-Wformat -Wformat-security -Wfatal-errors \
	-Wstack-protector -Wconversion -Wstrict-overflow \
	-fstack-protector-strong

# Project Libft (+GetNextLine)
LIBFT := $(addprefix $(MODULES)/, libft)

CPPFLAGS := \
	-I $(LIBRARY) \
	-I $(LIBFT)

# Specifies options for the linker:
# example: -L/usr/local/lib
LDFLAGS := \
	-L $(LIBFT)

# Lists libraries to link with:
# example: -lm -lpthread
LDLIBS := \
	-lft

RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
BLUE := \033[0;34m
MAGENTA := \033[0;35m
CYAN := \033[0;36m
WHITE := \033[0;37m
BG_B := \033[40m
BG_W := \033[47m
NC := \033[0m

define compile
	echo -e "convert 🌀 '$(1)' => '$(CYAN)$(BG_B)$(2)$(NC)'"
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $(1) -o $(2)
endef

SOURCES_MANDATORY := \
	ft_printf.c

SOURCES_DIR := sources
OBJECTS_DIR := .objects

$(OBJECTS_DIR):
	echo -e "📂 Directory created: '$(GREEN)$(OBJECTS_DIR)$(NC)'"
	mkdir -p $@

$(OBJECTS_DIR)/%.o:$(SOURCES_DIR)/%.c | $(OBJECTS_DIR)
	$(call compile,$<,$@)

OBJECTS_MANDATORY := $(patsubst $(SOURCES_DIR)/%.c,$(OBJECTS_DIR)/%.o,$(SOURCES_DIR)/$(SOURCES_MANDATORY))

$(NAME): $(OBJECTS_MANDATORY)
	$(MAKE) -C $(LIBFT) all
	$(AR) -crs tmp_$@ $^
	@echo "CREATE $@" > $@.mri
	@echo "ADDLIB $(LIBFT)/libft.a" >> $@.mri
	@echo "ADDLIB ./tmp_$@" >> $@.mri
	@echo "SAVE" >> $@.mri
	@echo "END" >> $@.mri
	$(AR) -M < $@.mri
	$(RM) tmp_$@
	$(RM) $@.mri
	ranlib $@
	@if [ -f "${@}" ]; then \
		echo -e "✅ Archived library created: 🗃 '$(YELLOW)$(BG_B)$(NAME)$(NC)'"; \
	fi

all: $(NAME)

-include $(SOURCES_MANDATORY:.c=.d)

clean:
	$(MAKE) -C $(LIBFT) clean
	$(RM) $(OBJECTS_MANDATORY)
	@if [ -d  "${OBJECTS_DIR}" ]; then \
		$(RM_DIR) $(OBJECTS_DIR); \
		echo -e "🧼 Directory removed: '$(GREEN)$(OBJECTS_DIR)$(NC)'"; \
	fi

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	@if [ -f  "${NAME}" ]; then \
		$(RM) $(NAME); \
		echo -e "🧹 Archived library removed : 🗃 '$(YELLOW)$(BG_B)$(NAME)$(NC)'"; \
	fi

re: fclean all
	@echo -e "🔄 Rebuilt! 🚀 "

norm:
	norminette --use-gitignore -R 2 $(SOURCES_MANDATORY) ./includes/ft_printf.h

info:
	echo -e "- make [all] : compile objects to generate library '$(NAME)'"
	echo -e "- make clean : remove objects '*.o' files inside '$(OBJECTS_DIR)'"
	echo -e "- make fclean : execute 'make clean' then remove library '$(NAME)'"
	echo -e "- make re : recompile the entire project"
	echo -e "- make norm : execute 'norminette' validation"

.PHONY: all clean fclean re norm info

.PRECIOUS:

.SECONDARY:

.SILENT:
