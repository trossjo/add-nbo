#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i = argc;
	if (argc == 3 ) {
        	FILE *fp1, *fp2;
		uint32_t f1;
		uint32_t f2;
		uint32_t sum;

	        fp1 = fopen(argv[1],"rb");
		fp2 = fopen(argv[2],"rb");
		fread(&f1, sizeof(uint32_t), 1, fp1);
		fread(&f2, sizeof(uint32_t), 1, fp2);

		sum = ntohl(f1)+ntohl(f2);

		printf("%d(0x%X) + ",ntohl(f1), ntohl(f1));
		printf("%d(0x%X) = ",ntohl(f2), ntohl(f2));
		printf("%d(ox%X)", ntohl(f1)+ntohl(f2),ntohl(f1)+ntohl(f2));
		printf("\n");
		fclose(fp1);
		fclose(fp2);
		return 0;
	}
	else {
		printf("Usage : %s <filename1> <filename2>\n", argv[0]);
		return 0;
	}
}
