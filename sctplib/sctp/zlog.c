#include "zlog.h"

void zlog_data(const uint8_t* data, int data_len)
{
	int i;
	printf("%04x| ", 0);
	int line = 16;
	for(i = 1; i <= data_len; i++)
	{
		printf("%02x", data[i - 1]);
		if(i % 8 == 0 && i % 16 != 0)printf(" - ");
		if(i % 16 == 0)
		{
			if(i != data_len)
			{
				printf("\n%04x| ", line);
				line += 16;
			}
		}
		if(i % 8 !=0 && i % 16 != 0)printf(" ");
	}
	printf("\n");
}

void zlog_eth(const struct rte_ether_hdr *eth)
{
	printf("(SMAC：%02x:%02x:%02x:%02x:%02x:%02x,DMAC：%02x:%02x:%02x:%02x:%02x:%02x)\n",
			eth->s_addr.addr_bytes[0],
			eth->s_addr.addr_bytes[1],
			eth->s_addr.addr_bytes[2],
			eth->s_addr.addr_bytes[3],
			eth->s_addr.addr_bytes[4],
			eth->s_addr.addr_bytes[5],
			eth->d_addr.addr_bytes[0],
			eth->d_addr.addr_bytes[1],
			eth->d_addr.addr_bytes[2],
			eth->d_addr.addr_bytes[3],
			eth->d_addr.addr_bytes[4],
			eth->d_addr.addr_bytes[5]);
}

void zlog_ip(const struct iphdr* ip)
{
	char s_ip[20];
	char d_ip[20];

	//d_ip
	struct in_addr in;
	in.s_addr = ip->daddr;
	strcpy(d_ip, inet_ntoa(in)); //32位网络字节顺序转化成点分十进制串

	//s_ip
	struct in_addr in1;
	in1.s_addr = ip->saddr;
	strcpy(s_ip, inet_ntoa(in1));
	printf("(s_ip = %s, d_ip = %s)\n", s_ip, d_ip);
}


void zlog_affinity(void)
{
	// 查看cpu 亲和性(affinity)
	//cpu_set_t get;
	//CPU_ZERO(&get);
	//if (pthread_getaffinity_np(pthread_self(), sizeof(get), &get) < 0) {
	//	fprintf(stderr, "get thread affinity failed\n");
	//}
	//// 查看当前线程所运行的所有cpu
	//int cpus = sysconf(_SC_NPROCESSORS_CONF);
	//int i;
	//for (i = 0; i < cpus; i++) {
	//	if (CPU_ISSET(i, &get)) {
	//		printf("this thread %ld is running in processor %d\n", (long int)pthread_self(), i);
	//	}
	//}
}
