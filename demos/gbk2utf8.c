#include <iconv.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const* argv[]) {
  const char* const gbk_file_name = "gbk.txt";
  FILE* gbk_fp = fopen(gbk_file_name, "rb");
  if (!gbk_fp) {
    perror("打开 gbk.txt 失败\n");
    return -1;
  }
  char gbk_buf[BUFSIZ] = {'\0'};
  const size_t fsize = fread(gbk_buf, sizeof(char), BUFSIZ - 1, gbk_fp);
  if (ferror(gbk_fp)) {
    perror("读取 gbk.txt 出错\n");
    return -1;
  }

  char utf8_buf[BUFSIZ] = {'\0'};

  iconv_t gbk2utf8 = iconv_open(/*tocode*/ "UTF-8", /*fromcode*/ "GBK");
  if (gbk2utf8 == -1) {
    perror("当前系统不支持 GBK到 UTF-8的转码\n");
    return -1;
  }
  size_t in_size = strlen(gbk_buf);
  size_t out_size = BUFSIZ;
  char* in_buf = gbk_buf;
  char* out_buf = utf8_buf;
  size_t cvted = iconv(gbk2utf8, &in_buf, &in_size, &out_buf, &out_size);
  if (cvted == -1) {
    perror("转换失败\n");
    return -1;
  }
  printf("转换结果如下:\n");
  printf("%s\n", utf8_buf);
  iconv_close(gbk2utf8);
  return 0;
}
//编译命令: clang -std=c11 -liconv -o bin/demo gbk2utf8.c
