#include "sample_lwip_comm.h"
#include "autosar_os_ext_common.h"
#include "include/lwip/sockets.h"

/********************************************
 * test scenario
 ********************************************/

void sample_lwip_scene7(void)
{
	int err;
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
		syslog(LOG_ERROR, " %s %s() line=%d : scene7 connection", __FILE__, __FUNCTION__, __LINE__);
		return;
	}

	err = sample_lwip_disconnection(&sample_lwip_client);
	if (err != 0) {
		syslog(LOG_ERROR, " %s %s() line=%d : scene7 disconneciton", __FILE__, __FUNCTION__, __LINE__);
		return;
	}

	//do
	err = sample_lwip_reconnection_tcp_server(&sample_lwip_socket, &sample_lwip_client, &sample_lwip_server);
	if (err != 0) {
		syslog(LOG_ERROR, " %s %s() line=%d : scene7 reconnection", __FILE__, __FUNCTION__, __LINE__);
		return;
	}

	//done
	err = sample_lwip_disconnection(&sample_lwip_client);
	if (err != 0) {
		syslog(LOG_ERROR, " %s %s() line=%d : scene7 done", __FILE__, __FUNCTION__, __LINE__);
		return;
	}

	syslog(LOG_INFO, " %s %s() line=%d : scene7 success", __FILE__, __FUNCTION__, __LINE__);


	return;
}




