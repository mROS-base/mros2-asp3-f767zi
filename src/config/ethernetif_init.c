#include "ethernetif.h"
#include "ethernetif_init.h"

err_t rtps_ethernetif_init(struct netif *netif)
{

  return ethernetif_init(netif);

}
