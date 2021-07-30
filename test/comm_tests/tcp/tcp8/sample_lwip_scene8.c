#include "sample_lwip_comm.h"
#include "autosar_os_ext_common.h"
#include "include/lwip/sockets.h"

/********************************************
 * test scenario
 ********************************************/

void sample_lwip_scene8(void)
{
	int err;
	SampleLwipSocketType sample_lwip_socket;
	struct sockaddr_in sample_lwip_server;

	//pre
	sample_lwip_socket.comm_type = SOCK_STREAM;
	sample_lwip_socket.blocking = true;
	sample_lwip_socket.timeout = SAMPLE_LWIP_COMM_TIMEOUT;

	sample_lwip_server.sin_family = AF_INET;
	sample_lwip_server.sin_port =  htons(SAMPLE_LWIP_CLIENT_PORT);
	sample_lwip_server.sin_addr.s_addr = ipaddr_addr(SAMPLE_LWIP_CLIENT_IPADDR);

	//do
	//connection
	err = sample_lwip_connection_tcp_client(&sample_lwip_socket, &sample_lwip_server);
	if (err != 0) {
		syslog(LOG_ERROR, " %s %s() line=%d : scene8 connection", __FILE__, __FUNCTION__, __LINE__);
		return;
	}

	err = sample_lwip_disconnection(&sample_lwip_socket);
	if (err != 0) {
		syslog(LOG_ERROR, " %s %s() line=%d : scene8 disconnection", __FILE__, __FUNCTION__, __LINE__);
		return;
	}

	//do
	//connection
	err = sample_lwip_connection_tcp_client(&sample_lwip_socket, &sample_lwip_server);
	if (err != 0) {
		syslog(LOG_ERROR, " %s %s() line=%d : scene8 connection", __FILE__, __FUNCTION__, __LINE__);
		return;
	}


	//done
	err = sample_lwip_disconnection(&sample_lwip_socket);
	if (err != 0) {
		syslog(LOG_ERROR, " %s %s() line=%d : scene8 done", __FILE__, __FUNCTION__, __LINE__);
		return;
	}

	syslog(LOG_INFO, " %s %s() line=%d : scene8 success", __FILE__, __FUNCTION__, __LINE__);


	return;
}




