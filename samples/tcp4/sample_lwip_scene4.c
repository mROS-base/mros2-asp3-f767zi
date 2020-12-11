#include "sample_lwip_comm.h"
#include "atk2ext_common.h"
#include "include/lwip/sockets.h"

/********************************************
 * test scenario
 ********************************************/
#define SAMPLE_LWIP_SCENE4_RECV_DATA_SIZE		50
static char sample_lwip_scene4_recv_data[SAMPLE_LWIP_SCENE4_RECV_DATA_SIZE];

void sample_lwip_scene4(void)
{
	int err;
	int recv_size = 0;
	SampleLwipSocketType sample_lwip_socket;
	struct sockaddr_in sample_lwip_server;
	SampleLwipSocketType sample_lwip_client;

	//pre
	sample_lwip_socket.comm_type = SOCK_STREAM;
	sample_lwip_socket.blocking = true;
	sample_lwip_socket.timeout = SAMPLE_LWIP_COMM_TIMEOUT;

	sample_lwip_server.sin_family = AF_INET;
	sample_lwip_server.sin_port =  htons(SAMPLE_LWIP_SERVER_PORT);
	sample_lwip_server.sin_addr.s_addr = INADDR_ANY;

	err = sample_lwip_connection_tcp_server(&sample_lwip_socket, &sample_lwip_client, &sample_lwip_server);
	if (err != 0) {
		syslog(LOG_ERROR, " %s %s() line=%d : scene4 connection", __FILE__, __FUNCTION__, __LINE__);
		return;
	}

	//do
	//send
	err = sample_lwip_recv(&sample_lwip_client, sample_lwip_scene4_recv_data, (SAMPLE_LWIP_SCENE4_RECV_DATA_SIZE - 1U), &recv_size);
	if (err != 0) {
		syslog(LOG_ERROR, " %s %s() line=%d : scene4 recv", __FILE__, __FUNCTION__, __LINE__);
	}

	//done
	err = sample_lwip_disconnection(&sample_lwip_socket);
	if (err != 0) {
		syslog(LOG_ERROR, " %s %s() line=%d : scene4 done", __FILE__, __FUNCTION__, __LINE__);
		return;
	}

	sample_lwip_scene4_recv_data[(recv_size + 1U)] = '\0';
	syslog(LOG_INFO, " %s %s() line=%d : scene4 success", __FILE__, __FUNCTION__, __LINE__);
	syslog(LOG_INFO, " recv size:%d , recv data:%s", recv_size, sample_lwip_scene4_recv_data);

	return;
}






