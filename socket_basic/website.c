#include <arpa/inet.h>  /* for inet_ntoa */
#include <netinet/in.h> /* for IPv4 addr */
#include <stdbool.h>
#include <stdio.h>
#include <string.h>     /* for strerror */
#include <sys/errno.h>  /* for errno */
#include <sys/socket.h> /* for socket,bind,listen,accept etc*/
#include <unistd.h>     /* for write  read*/
#define CHECK_FAIL(ret)                                       \
  ({                                                          \
    bool fail = ret == -1;                                    \
    errno_t __save_errno = errno;                             \
    if (fail) {                                               \
      fprintf(stderr, "%s:error:%d,%s\n", __func__, __LINE__, \
              strerror(__save_errno));                        \
    }                                                         \
    errno = __save_errno;                                     \
    fail;                                                     \
  })

int main(int argc, char const *argv[]) {
  int serverfd = socket(AF_INET, SOCK_STREAM, 0);
  if (CHECK_FAIL(serverfd)) {
    return -1;
  }
  size_t addr_len = sizeof(struct sockaddr_in);
  in_port_t port = 4321;
  struct sockaddr_in addr4 = {
      .sin_family = AF_INET,
      .sin_port = htons(port),
  };
  addr4.sin_addr.s_addr = htonl(INADDR_ANY);
  int ret = -1;
  int option = 1;

  ret = setsockopt(serverfd, SOL_SOCKET, SO_REUSEPORT, &option, sizeof(option));
  if (CHECK_FAIL(ret)) {
    return -1;
  }
  ret = bind(serverfd, (struct sockaddr *)&addr4, sizeof(addr4));
  if (CHECK_FAIL(ret)) {
    return -1;
  }
  int backlog = 128;
  ret = listen(serverfd, backlog);
  if (CHECK_FAIL(ret)) {
    return -1;
  }
  printf("Serving at: http://0.0.0.0:%d\n", port);
  // struct sockaddr_storage addr_storage; // the right choice
  struct sockaddr_in client_addr;  // simple
  socklen_t client_addr_len = 0;
  const char body[] =
      "<h1 style=\"color:red;\">欢迎来到代码会说话的编程世界!</h1>\r\n";
  const char headers[] =
      "HTTP/1.1 200 OK\r\n"
      "Content-Type:text/html;charset=utf-8\r\n"
      "Content-Length:75\r\n"
      "Connection: close\r\n"
      "\r\n";
  while (true) {
    int clientfd =
        accept(serverfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (CHECK_FAIL(clientfd)) {
      return -1;
    }
    char *client_ip = inet_ntoa(client_addr.sin_addr);
    printf("client connected: %s:%d\n", client_ip, ntohs(client_addr.sin_port));
    ssize_t send_cnt = -1;
    send_cnt = write(clientfd, headers, sizeof(headers));
    if (CHECK_FAIL(send_cnt)) {
      continue;
    }
    send_cnt = write(clientfd, body, sizeof(body));
    if (CHECK_FAIL(send_cnt)) {
      continue;
    }
    ret = close(clientfd);
    CHECK_FAIL(ret);
  }

  return 0;
}
