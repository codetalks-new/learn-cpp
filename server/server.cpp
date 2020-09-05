#include <errno.h>
#include <netinet/ip.h>
#include <string.h>     /* for memset */
#include <sys/socket.h> /* for socket,bind*/
#include <unistd.h>     /* getpid */

#include <cstdint>
#include <cstdio>  /* for perror */
#include <cstdlib> /* for exist */
#include <string>
namespace sock {
/// 连接类型
enum class SocketType : int { TCP = SOCK_STREAM, UDP = SOCK_DGRAM };
/// 地址类型
enum class AddressFamily : int { IPV4 = AF_INET };
using ProtocolFamily = AddressFamily;
struct SyscallResult {
  bool ok;
  union {
    errno_t err_code;
    int value;
  };
  operator bool() {
    return ok;
  }
};
inline bool is_syscall_ok(int ret) {
  return ret == 0;
}
inline SyscallResult mkSyscallResult(int ret) {
  const bool ok = is_syscall_ok(ret);
  return {.ok = ok, .err_code = ok ? 0 : errno};
}

inline int check_errno(int ret) {
  if (ret == -1) {
    perror(__FILE__);
    std::exit(ret);
  }
  return ret;
}

struct SocketFd {
  int fd;
  operator int() {
    return fd;
  }
};
using socket_fd_t = int;
inline socket_fd_t createSocket(AddressFamily af, SocketType type) {
  int ret =
      ::socket(static_cast<int>(af), static_cast<int>(type), /*protocol*/ 0);
  return check_errno(ret);
}
inline socket_fd_t createTCPSocket() {
  return createSocket(AddressFamily::IPV4, SocketType::TCP);
}
inline socket_fd_t createUDPSocket() {
  return createSocket(AddressFamily::IPV4, SocketType::UDP);
}
using ip_port_t = uint16_t;
struct SocketAddr {
  uint32_t ip;
  ip_port_t port;
};

sockaddr_in mkIPv4ServerAddr(in_port_t port) {
  in_addr ipv4_addr = {.s_addr = INADDR_ANY};
  return {.sin_len = sizeof(sockaddr_in),
          .sin_family = AF_INET,
          .sin_port = htons(port),
          .sin_addr = ipv4_addr};
}

socket_fd_t createTCPServerSocket(ip_port_t port) {
  socket_fd_t fd = createTCPSocket();
  sockaddr_in addr = mkIPv4ServerAddr(port);
  check_errno(::bind(fd, (sockaddr *)&addr, sizeof(sockaddr_in)));
  check_errno(::listen(fd, 0));
  return fd;
}
}  // namespace sock

const char *queryAI(char *query) {
  std::string str(query);
  std::string qmark("吗");
  return str.c_str();
}
int main(int argc, char const *argv[]) {
  printf("PID = %d\n", getpid());
  in_port_t port = 4321;
  sock::socket_fd_t server_fd = sock::createTCPServerSocket(port);
  printf("serving at: 0.0.0.0:%d\n", port);
  sockaddr_in client_addr;
  socklen_t ipv4_addr_len = 0;
  char buf[BUFSIZ];
  char gretting[] = ">Welcome!\n";
  while (true) {
    sock::socket_fd_t client_fd = sock::check_errno(
        ::accept(server_fd, (sockaddr *)&client_addr, &ipv4_addr_len));
    printf("%u:%d is connected!\n", client_addr.sin_addr.s_addr,
           client_addr.sin_port);
    fflush(stdout);
    while (true) {
      size_t read_cnt = read(client_fd, &buf, BUFSIZ - 1);
      sock::check_errno(read_cnt);
      buf[read_cnt] = '\0';
      size_t write_cnt = write(client_fd, gretting, sizeof(gretting));
      sock::check_errno(write_cnt);
    }
  }

  return 0;
}
