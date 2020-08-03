#include <stdio.h>
#include <unistd.h>

struct superblocktype {
unsigned short isize;
int fsize;
char name[20];
}

main(){

int i,fd;
struct superblocktype s1,s2;
char my_name[20]="Hello World";

s1.isize=20;
s1.fsize=1320000;
for (i=0;i<sizeof(my_name);i++) s1.name[i]=my_name[i];

// make sure test.data exists. If not, use touch command to create an empty file called test.data

fd=open("test.data",2);

lseek(fd,100,SEEK_SET);
//start next read/write from 100th byte of the file. Not from the beginning.

write(fd,&s1.isize,sizeof(s1));

lseek(fd,0,SEEK_SET);

// next read is from the beginning of the file. Nothing was written; so you should not see any value after reading

read(fd,&s2.isize,sizeof(s2));
printf("s2 components: isize = %d, fsize = %d, name = %s\n",s2.isize, s2.fsize,s2.name);

// now, see to the 100th byte
lseek(fd,100,SEEK_SET);
read(fd,&s2.isize,sizeof(s2));
printf("s2 components: isize = %d, fsize = %d, name = %s\n",s2.isize, s2.fsize,s2.name);

}
