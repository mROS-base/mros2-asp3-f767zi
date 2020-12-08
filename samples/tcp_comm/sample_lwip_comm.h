#ifndef _SAMPLE_LWIP_COMM_H_
#define _SAMPLE_LWIP_COMM_H_

#include "atk2ext_common.h"
#include "include/lwip/sockets.h"

#define SAMPLE_LWIP_COMM_TIMEOUT	100
#define SAMPLE_LWIP_SELECT_TIMEOUT_SEC	10
#define SAMPLE_LWIP_SELECT_TIMEOUT_USEC	10000000

#define SAMPLE_LWIP_SERVER_PORT			54001
#define SAMPLE_LWIP_SERVER_IPADDR		"0.0.0.0"

#define SAMPLE_LWIP_CLIENT_PORT			54002
#define SAMPLE_LWIP_CLIENT_IPADDR		"192.168.11.4"

#define SAMPLE_LWIP_LISTENBACKLOG	1

typedef struct {
	int		sockfd;
	int		timeout;
	bool_t	blocking;
	int		comm_type;
}SampleLwipSocketType;

typedef struct {
	int sockfd;
	struct sockaddr_in addr;
	bool_t	connected;
}SampleLwipTcpClientType;

extern int sample_lwip_connection_tcp_server(SampleLwipSocketType* server_socket, SampleLwipSocketType* client_socket, struct sockaddr_in* server);
extern int sample_lwip_disconnection(SampleLwipSocketType* socket);

extern int sample_lwip_connection_tcp_client(SampleLwipSocketType* server_socket, struct sockaddr_in* server);

extern int sample_lwip_send(SampleLwipSocketType* socket, char* data, int data_size, int* res);


#endif /*_SAMPLE_LWIP_COMM_H_*/
