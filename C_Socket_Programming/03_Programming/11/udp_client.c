#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// https://www.yokoweb.net/dokuwiki/programing/linux-programing/network-programing/msys2-winsock-network-programing

int main () {
    struct sockaddr_in server;
    char buf[256];

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(9999);
    server.sin_family = AF_INET;

    strcpy(buf, "hello");
    sendto(sock, buf, sizeof(buf), 0, (struct sockaddr *)&server, sizeof(server));

    close(sock);

    return 0;
}