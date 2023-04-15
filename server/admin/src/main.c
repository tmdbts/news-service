#include "main.h"

int main(int argc, char *argv[]) {
    int server_socket, port_number;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port_number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    server_socket = socket(AF_INET, SOCK_DGRAM, 0);

    if (server_socket < 0) {
        perror(SOCKET_ERROR_MESSAGE);
        exit(EXIT_FAILURE);
    }

    bzero((char *) &server_address, sizeof(server_address));
    port_number = atoi(argv[1]);

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port_number);

    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror(BIND_ERROR_MESSAGE);
        exit(EXIT_FAILURE);
    }

    while (1) {
        client_address_length = sizeof(client_address);
        char buffer[MAX_MSG_LEN];

        ssize_t n = recvfrom(server_socket, buffer, MAX_MSG_LEN, 0, (struct sockaddr *) &client_address,
                             &client_address_length);

        if (n < 0) {
            perror(RECEIVE_ERROR_MESSAGE);
            exit(EXIT_FAILURE);
        }

        printf("Received message: %s\n", buffer);

        char *okStr = "I got your message \n";

        n = sendto(server_socket, okStr, strlen(okStr), 0,
                   (struct sockaddr *) &client_address, client_address_length);

        if (n < 0) {
            perror(WRITE_ERROR_MESSAGE);
            exit(EXIT_FAILURE);
        }
    }
}
