#ifndef TROUT_H
#define TROUT_H

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/un.h>
#include <stdarg.h>
#include <syslog.h>
#include "util.h"
#include "trout.h"

typedef struct rec{
  u_short seq;
} Rec;

typedef struct timeval Timeval;
typedef struct sockaddr Sockaddr;

int max_ttl;
int nprobes;

int seq;

char recvbuf[BUFSIZE];
char sendbuf[BUFSIZE];
Rec *rec;

int sendfd, recvfd;
int pipefd[2];

Sockaddr *sasend;
Sockaddr *sarecv;
Sockaddr *salast;
Sockaddr *sabind;

socklen_t salen;
int datalen;

u_short sport;
u_short dport;

Timeval sendtv[1];
Timeval recvtv[1];
Timeval difftv[1];


void sig_alrm (int signo);
int process_ip (struct ip *ip, int len);
int recv_dgram ();
void sub_tv (Timeval *plus, Timeval *minus, Timeval *res);
double time_to_double (Timeval *time);
void print_report ();
void send_dgram (int ttl);
int send_probes (int ttl);
void loop_ttl ();

#endif
