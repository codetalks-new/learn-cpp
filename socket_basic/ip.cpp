
#include <arpa/inet.h>
#include <assert.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/un.h>

#include <string>
using std::string;

TEST(IpAddrTestSuite, IpV4TestCase) {
  const char* ip = "192.168.1.101";
  in_addr_t v1 = inet_addr(ip);
  in_addr_t v2 = inet_network(ip);
  EXPECT_EQ(v1, htonl(v2));
  struct in_addr ipv4_addr;
  int ret = inet_aton(ip, &ipv4_addr);
  EXPECT_EQ(v1, ipv4_addr.s_addr);
  const char* ip2 = inet_ntoa(ipv4_addr);
  EXPECT_STREQ(ip2, ip);
}
TEST(IpAddrTestSuite, IpV6TestCase) {
  // 1) 测试 inet_pton 转换 IPv4 的地址
  const char* ip = "192.168.1.101";
  struct in_addr v4_addr1;
  inet_pton(AF_INET, ip, &v4_addr1);
  struct in_addr v4_addr2;
  inet_aton(ip, &v4_addr2);
  EXPECT_EQ(v4_addr1.s_addr, v4_addr2.s_addr);

  // 2) 测试 inet_ntop 转换 IPv4 地址
  char ip2[INET_ADDRSTRLEN] = {'\0'};
  inet_ntop(AF_INET, &v4_addr1, ip2, INET_ADDRSTRLEN);
  EXPECT_STREQ(ip, ip2);
  // 3) 测试 IPv6 的网络二进制表和字符串表示的互相转换
  const char* v6_localhost = "::1";  // IPv6 版的 127.0.0.1 即 localhost
  struct in6_addr v6_addr1;
  inet_pton(AF_INET6, v6_localhost, &v6_addr1);
  char v6_ip2[INET6_ADDRSTRLEN] = {'\0'};
  inet_ntop(AF_INET6, &v6_addr1, v6_ip2, INET6_ADDRSTRLEN);
  EXPECT_STREQ(v6_localhost, v6_ip2);
}

TEST(SocketAddrTestSuite, IPv4TestCase) {
  struct sockaddr_in addr4;
  struct sockaddr_in6 addr6;
  struct sockaddr_storage st;
  struct sockaddr_un un;
  in6addr_loopback;
  int size = offsetof(struct sockaddr_un, sun_path) + strlen(un.sun_path);
  printf("offset:%d", size);
  printf("offset:%d", SUN_LEN(&un));
}

GTEST_API_ int main(int argc, char* argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}
