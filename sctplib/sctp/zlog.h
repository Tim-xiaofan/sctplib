#ifndef ZLOG_H
#define ZLOG_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>

#include <rte_ether.h>
#include <rte_ip.h>
void zlog_data(const uint8_t* data, int data_len);
void zlog_eth(const struct rte_ether_hdr *eth);
void zlog_ip(const struct iphdr* ip);
void zlog_affinity(void);
#endif //ZLOG_H
