#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
int fd;
char write_buf[] = "Hello, I/O System Call in C\n";
char read_buf[50];
fd = open("sample.txt", O_CREAT | O_RDWR, 0644);
if (fd < 0) {
printf("File open failed\n");
return 1;
}
write(fd, write_buf, sizeof(write_buf));
lseek(fd, 0, SEEK_SET);
read(fd, read_buf, sizeof(read_buf));
printf("Data read from file:\n%s", read_buf);
close(fd);
return 0;
}