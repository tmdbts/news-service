#ifndef ADMIN_MAIN_H
#define ADMIN_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

const char *SOCKET_ERROR_MESSAGE = "ERROR opening socket";
const char *BIND_ERROR_MESSAGE = "ERROR on binding";
const char *RECEIVE_ERROR_MESSAGE = "ERROR receiving from socket";
const char *WRITE_ERROR_MESSAGE = "ERROR writing to socket";

const char *USAGE_FMT = "%s <ip> <port>";
const char *DEFAULT_PROGRAM_NAME = "admin";
const int MAX_MSG_LEN = 1024;

#endif //ADMIN_MAIN_H
