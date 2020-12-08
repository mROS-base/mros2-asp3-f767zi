#include "sample_lwip_comm.h"
#include "atk2ext_common.h"
#include "include/lwip/sockets.h"

static int sample_lwip_socket_select(SampleLwipSocketType* socket, bool_t read, bool_t write)
{
	int ret;

	fd_set sample_lwip_fd_set;
	struct timeval sample_lwip_timeval;
	fd_set* r_set = NULL;
	fd_set* w_set = NULL;

	FD_ZERO(&sample_lwip_fd_set);
	FD_SET(socket->sockfd, &sample_lwip_fd_set);

	if (read == true) {
		r_set = &sample_lwip_fd_set;
	}
	if (write == true) {
		w_set = &sample_lwip_fd_set;
	}

	sample_lwip_timeval.tv_sec =SAMPLE_LWIP_SELECT_TIMEOUT_SEC;
	sample_lwip_timeval.tv_usec =SAMPLE_LWIP_SELECT_TIMEOUT_USEC;


	ret = lwip_select(FD_SETSIZE, r_set, w_set, NULL, &sample_lwip_timeval);
	if (ret < 0) {
		syslog(LOG_ERROR, " %s %s() line=%d select err", __FILE__, __FUNCTION__, __LINE__);
		return -1;
	}
	if ((ret == 0 || !FD_ISSET(socket->sockfd, &sample_lwip_fd_set))) {
		syslog(LOG_INFO, " %s %s() line=%d select timeout", __FILE__, __FUNCTION__, __LINE__);
		return -1;
	}

	return 0;
}


int sample_lwip_connection_tcp_server(SampleLwipSocketType* server_socket, SampleLwipSocketType* client_socket, struct sockaddr_in* server)
{
	int err;

	//socket create
	server_socket->sockfd = lwip_socket(AF_INET, server_socket->comm_type, 0);
	if (server_socket->sockfd < 0) {
		syslog(LOG_ERROR, " %s %s() line=%d socket err", __FILE__, __FUNCTION__, __LINE__);
		return -1;
	}

	//socket bind
	err = lwip_bind(server_socket->sockfd, (const struct sockaddr *)server, sizeof(struct sockaddr));
	if (err != 0) {
		syslog(LOG_ERROR, " %s %s() line=%d bind err:%d", __FILE__, __FUNCTION__, __LINE__, err);
		return err;
	}

	//listen
	err = lwip_listen(server_socket->sockfd, SAMPLE_LWIP_LISTENBACKLOG);
	if (err != 0) {
		syslog(LOG_ERROR, " %s %s() line=%d listen err:%d", __FILE__, __FUNCTION__, __LINE__, err);
		return err;
	}

	//accept
	while (1) {
		err = sample_lwip_socket_select(server_socket->sockfd, true, false);
		if (err != 0) {
			continue;
		}

		client_socket->sockfd = lwip_accept(server_socket->sockfd, (struct sockaddr*)server, sizeof(struct sockaddr));
		if (client_socket->sockfd < 0) {
			syslog(LOG_ERROR, " %s %s() line=%d accept err:%d", __FILE__, __FUNCTION__, __LINE__, err);
			continue;
		}
		else {
			break;
		}
	}

	return 0;
}

int sample_lwip_disconnection(SampleLwipSocketType* socket)
{
	int err;
	err = lwip_close(socket->sockfd);
	if (err != 0) {
		syslog(LOG_ERROR, " %s %s() line=%d close err:%d", __FILE__, __FUNCTION__, __LINE__, err);
		return err;
	}

	return 0;
}

int sample_lwip_connection_tcp_client(SampleLwipSocketType* server_socket, struct sockaddr_in* server)
{

	int err;

	//socket create
	server_socket->sockfd = lwip_socket(AF_INET, server_socket->comm_type, 0);
	if (server_socket->sockfd < 0) {
		syslog(LOG_ERROR, " %s %s() line=%d socket err", __FILE__, __FUNCTION__, __LINE__, err);
		return -1;
	}

	//connect
	err = lwip_connect(server_socket->sockfd, server, sizeof(struct sockaddr));
	if (err != 0) {
		syslog(LOG_ERROR, " %s %s() line=%d connect err:%d", __FILE__, __FUNCTION__, __LINE__, err);
		return err;
	}

	return 0;
}

static void sample_lwip_connection_udp_server(void)
{



	return;
}

int sample_lwip_send(SampleLwipSocketType* socket, char* data, int data_size, int* res)
{
	int err;
	int send_size;

	//guard
	if (socket->sockfd < 0) {
		syslog(LOG_ERROR, " %s %s() line=%d send sockfd err:%d", __FILE__, __FUNCTION__, __LINE__, err);
		return -1;
	}

	// send
	while(1) {
		err = sample_lwip_socket_select(socket->sockfd, false, true);
		if (err != 0) {
			continue;
		}
	}

	send_size = lwip_send(socket->sockfd, data, data_size, 0);
	if (send_size == 0) {
		syslog(LOG_ERROR, " %s %s() line=%d send err:%d", __FILE__, __FUNCTION__, __LINE__, err);
	}
	*res = send_size;

	return 0;
}

static void sample_lwip_sendto(void)
{

	return;
}

static void sample_lwip_recv(void)
{

	return;
}

static void sample_lwip_fromrecv(void)
{

	return;
}
