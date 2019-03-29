/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accept.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:58:59 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/29 10:13:25 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.h"

int accept_new_connexion(t_socket *socket)
{
	t_sock_inter *server;
	t_sock_inter *empty_inter;
	socklen_t len;

	if (socket->enable != ENABLE_SOCKET)
		return 0;
	len = sizeof(t_sockaddr_in);
	server = &socket->server;
	if (socket->nb_client >= MAX_CLIENT_SOCKET)
	{
		errno = ENOMEM;
		perror("cannot accept more connexion");
		return -1;
	}
	DEBUG_SOCKET_CO &&ft_dprintf(2, SOCKET_NEW_CO);
	empty_inter = socket->clients + socket->nb_client;
	empty_inter->sock =
		accept(server->sock, (t_sockaddr *)&empty_inter->inter, &len);
	if (empty_inter->sock < 0)
		perror("accept()");
	else
		socket->nb_client++;
	return empty_inter->sock;
}
