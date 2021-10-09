#include<iostream>

char c;

int main() {

	printf("Nhap vao chu cai dau cua ten: ");
	scanf("%c", &c);
	int d;
	printf("Nhap vao thu tu cua chu cai %c trong bang chu cai tieng Viet: ", c);
	scanf("%d", &d);
	printf("------------------------------------------------------------------\n");
	printf("Chu cai %c dung sau %d chu cai trong bang chu cai tieng Viet!!!", c, 29-d);

 return 0;    
}