#include "sample_lwip_comm.h"
#include "atk2ext_common.h"
#include "include/lwip/sockets.h"

/********************************************
 * test scenario
 ********************************************/

#define SAMPLE_LWIP_SCENE3_SEND_DATA	"sample lwip scene3\n"

void sample_lwip_scene3(void)
{
	int err;
	int sended_length = 0;
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
		syslog(LOG_ERROR, " %s %s() line=%d : scene3 connection", __FILE__, __FUNCTION__, __LINE__);
		return;
	}

	//do
	//send
	err = sample_lwip_send(&sample_lwip_client, SAMPLE_LWIP_SCENE3_SEND_DATA, sizeof(SAMPLE_LWIP_SCENE3_SEND_DATA), &sended_length);
	if (err != 0) {
		syslog(LOG_ERROR, " %s %s() line=%d : scene3 send", __FILE__, __FUNCTION__, __LINE__);
	}

	tslp_tsk(100);

	//done
	sample_lwip_disconnection(&sample_lwip_socket);
	if (err != 0) {
		syslog(LOG_ERROR, " %s %s() line=%d : scene3 done", __FILE__, __FUNCTION__, __LINE__);
	}

	syslog(LOG_INFO, " %s %s() line=%d : scene3 success", __FILE__, __FUNCTION__, __LINE__);

	return;
}




