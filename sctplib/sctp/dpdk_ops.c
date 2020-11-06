/*dpdk_ops.cpp*/
#include "dpdk_ops.h"
#include <stdio.h>
const char *_MSG_POOL = "MSG_POOL";
const char *_MSFW_2_DPDK = "MSFW_2_DPDK";
const char *_DPDK_2_MSFW = "DPDK_2_MSFW";
const char *_MSFW_2_DPDK1 = "MSFW_2_DPDK1";
const char *_DPDK_2_MSFW1 = "DPDK_2_MSFW1";
struct rte_ring *send_ring, *recv_ring, *send_ring1, *recv_ring1;
struct rte_mempool *message_pool;
volatile bool force_quit;

int dpdk_ops(int argc, char *argv[])
{
	/*dpdk eal init*/
	int ret = 0;
	int i;
	if(argv == NULL)
	{
		printf("argv == NULL");
		return -1;
	}
	for(i=0; i < argc; i++)
		printf("%s\n", argv[i]);
	ret = rte_eal_init(argc, argv);
	if (ret < 0)
		rte_exit(EXIT_FAILURE, "Cannot init EAL\n");

	recv_ring = rte_ring_lookup(_DPDK_2_MSFW);
	if (recv_ring == NULL)
		rte_exit(EXIT_FAILURE, "Problem getting recv_ring\n");
	send_ring = rte_ring_lookup(_MSFW_2_DPDK);
	if (send_ring == NULL)
		rte_exit(EXIT_FAILURE, "Problem getting send_ring\n");
	recv_ring1 = rte_ring_lookup(_DPDK_2_MSFW1);
	if (recv_ring1 == NULL)
		rte_exit(EXIT_FAILURE, "Problem getting recv_ring1\n");
	send_ring1 = rte_ring_lookup(_MSFW_2_DPDK1);
	if (send_ring1 == NULL)
		rte_exit(EXIT_FAILURE, "Problem getting send_ring1\n");
	message_pool = rte_mempool_lookup(_MSG_POOL);
	if (message_pool == NULL)
		rte_exit(EXIT_FAILURE, "Problem getting message pool\n");

	printf("Finished Process EAL Init.\n");
	return ret;
}
