
#include "Serial_Com.h"
int COM_flag = 0;
int win_reloy(char buf[])
{
	static HANDLE hcom;
	if (!COM_flag)
	{
	hcom = CreateFile(("COM2"), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING
		, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hcom == INVALID_HANDLE_VALUE)
	{
		printf("�򿪴���ʧ�ܣ�\n");
		//exit(0);
	}
	else
	{
		printf("�򿪴��ڳɹ���\n");
	}

		SetupComm(hcom, 1024, 1024);
		DCB dcb;
		GetCommState(hcom, &dcb);
		dcb.BaudRate = 9600;//����������
		dcb.ByteSize = 8;//����λ
		dcb.Parity = 0;
		dcb.StopBits = 1;//ֹͣλ
		SetCommState(hcom, &dcb);
		COM_flag = 1;
	}
	char data[] = "yangmin";
	char data1[] = "5678";

	DWORD dwWrittenLen = 0;
	if (!WriteFile(hcom, buf, 46, &dwWrittenLen, NULL))
	{
		//  fprintf(stderr, "��������ʧ�ܣ�\n");
		printf("��������ʧ�ܣ�\n");
		return 0;
	}
	//Sleep(3000);
	//WriteFile(hcom, buf, sizeof(buf), &dwWrittenLen, NULL);
	return 1;
}



#if __linux
int linux_reloy(char buf[])
{
	int x, y, z = 10;
	int fd;
	fd = open("/dev/ttyAMA0", O_RDWR);
	if (fd == -1)
	{
		perror("serialport error\n");
	}
	else {
	}
	struct termios Opt;
	int status;
	tcgetattr(fd, &Opt);
	cfsetispeed(&Opt, B9600);
	cfsetospeed(&Opt, B9600);
	Opt.c_cflag &= ~CSIZE;
	Opt.c_cflag |= CS8;
	Opt.c_cflag &= ~PARENB;
	Opt.c_iflag &= ~INPCK;
	Opt.c_cflag &= ~CSTOPB;
	tcsetattr(fd, TCSANOW, &Opt);
	status = tcsetattr(fd, TCSANOW, &Opt);
	if (status != 0)

	{
		perror("tcsetattr fd1");
	}
	char buff[20];
	sprintf(buff, ":%d,%d,%d.", x, y, z);
	int length = 0;
	for (int i = 0; i<20; i++)
	{
		if (buff[i] == '\0')
		{
			length = i;
			break;
		}
	}
	write(fd, &buf, length);
	close(fd);
	printf("%d     %d    %d\n", x, y, z);

}
#endif
