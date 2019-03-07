# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lroux <lroux@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 13:27:44 by lroux             #+#    #+#              #
#    Updated: 2019/03/07 15:30:08 by lroux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SUBDIR	:= projects
SUBS	:= vm assembly

LIBDIR	:= $(SUBDIR)/libs

# Include core
include $(LIBDIR)/multi.mk
