#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main () {
    struct sockaddr_in server, client;
    char buf[256];
    
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(9999);
    server.sin_family = AF_INET;

    bind(sock, (struct sockaddr *)&server, sizeof(server));

    for (;;) {
        int len = sizeof(client);
        recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr *)&client, &len);
        printf("%s\n", buf);
    }
    close(sock);

    return 0;
}
