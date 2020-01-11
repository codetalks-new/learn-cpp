#include <iconv.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::ios;
using std::string;
using std::vector;

static vector<char> read_binary_file(const string& file_name) {
  ifstream fs(file_name, ios::binary);
  fs.unsetf(ios::skipws);
  fs.seekg(0, ios::end);
  auto file_size = fs.tellg();
  fs.seekg(0, ios::beg);
  vector<char> v;
  v.reserve(file_size);
  v.insert(v.begin(), std::istream_iterator<char>(fs),
           std::istream_iterator<char>());
  return v;
}

int main(int argc, char const* argv[]) {
  auto v_gbk = read_binary_file("gbk.txt");
  cout << "v_gbk.size()=" << v_gbk.size() << endl;
  // 如果GBK 两个字节,那么一般 utf-8 最多两个字节
  size_t in_size = v_gbk.size();
  size_t out_size = in_size * 1.5 + 1;
  char utf8_buf[out_size];
  memset(&utf8_buf, '\0', out_size);
  char* in_buf = v_gbk.data();
  char* out_buf = utf8_buf;
  auto gbk2utf8 = iconv_open(/*tocode*/ "UTF-8", /*fromcode*/ "GBK");
  if (gbk2utf8 == (iconv_t*)-1) {
    perror("当前系统不支持 GBK到 UTF-8的转码\n");
    return -1;
  }

  size_t cvted = iconv(gbk2utf8, &in_buf, &in_size, &out_buf, &out_size);
  if (cvted == -1) {
    perror("转换失败\n");
    return -1;
  }
  cout << "转换结果如下:" << endl;
  cout << utf8_buf << endl;
  iconv_close(gbk2utf8);
  return 0;
}