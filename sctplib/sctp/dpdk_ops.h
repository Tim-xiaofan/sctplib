/*dpdk_ops.h*/
#ifndef _DPDK_OPS_H
#define _DPDK_OPS_H

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <syslog.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <sys/types.h>
#include <sys/queue.h>
#include <netinet/in.h>
#include <setjmp.h>
#include <stdarg.h>
#include <ctype.h>
#include <errno.h>
#include <getopt.h>
#include <signal.h>
#include <stdbool.h>

#include <rte_common.h>
#include <rte_log.h>
#include <rte_malloc.h>
#include <rte_memory.h>
#include <rte_memcpy.h>
#include <rte_eal.h>
#include <rte_launch.h>
#include <rte_atomic.h>
#include <rte_cycles.h>
#include <rte_prefetch.h>
#include <rte_lcore.h>
#include <rte_per_lcore.h>
#include <rte_branch_prediction.h>
#include <rte_interrupts.h>
#include <rte_random.h>
#include <rte_debug.h>
#include <rte_ether.h>
#include <rte_ethdev.h>
#include <rte_mempool.h>
#include <rte_mbuf.h>
#include <rte_ring.h>
#include <rte_log.h>
#include <rte_lcore.h>
#include <rte_errno.h>

extern const char *_MSG_POOL;
extern const char *_MSFW_2_DPDK;
extern const char *_DPDK_2_MSFW;
extern const char *_MSFW_2_DPDK1;
extern const char *_DPDK_2_MSFW1;
extern struct rte_ring *send_ring, *recv_ring, *send_ring1, *recv_ring1;
extern struct rte_mempool *message_pool;
int dpdk_ops(int argc, char *argv[]);

#endif //!!!_DPDK_OPS_H

