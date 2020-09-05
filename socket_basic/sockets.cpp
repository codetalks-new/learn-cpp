#include <sys/socket.h>

#include <optional>
using std::optional;

class SockAddr {
 public:
  SockAddr() {
    bzero(&storage, sizeof(sockaddr_storage));
  }
  SockAddr(sockaddr* addr) {
    storage = *(sockaddr_storage*)addr;
  }

 private:
  sockaddr_storage storage;
};