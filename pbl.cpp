#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define MAX 1000

//Ten sinh vien 1: Tran Vu Lam
//Ten sinh vien 2: Ngo Van Danh
//De tai: 902

void setcolor(), hn(), hoocner_tq(), outf(), enter(), readFile(), xuatmang(), menu1(), menu2(), menu3();
double calc();

double calc(double c[], int n, double k){
	double res=c[0];
	for(int i=1; i<=n; i++) res=res*k+c[i];
	return res;
}

void setcolor(int color){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,color);
}

void hn(double a[], int n, double k){
	for(int i=0; i<=n; i++) printf("%12.2lf",a[i]);
	double res=a[0];
	printf("\n            ");
	for(int i=1; i<=n; i++){
		printf("%12.2lf",res*k);
		res=res*k+a[i];
	}
	printf("\n       -----------------------------------------------------------------------------\n");
	printf("%12.2lf",a[0]);
	res=a[0];
	for(int i=1; i<=n; i++){
		res=res*k+a[i];
		if(i<n) printf("%12.2lf",res);
	}
	setcolor(FOREGROUND_RED);
    printf("%12.2lf",res);
    setcolor(FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    printf("\n\n");
}
void hoocner_tq(double a[], double b[], double c, int n){
	for(int i=0; i<=n; i++) b[i]=a[i];
	for(int i=0; i<=n; i++) printf("%12.2lf",b[i]);
	printf("\n             ");
	while(n>=1){
		for(int i=1; i<=n; i++){
			b[i]=b[i-1]*c+b[i];
			printf("%12.2lf",b[i-1]*c);
		}
		printf("\n");
		for(int i=0; i<=n; i++) printf("------------");
		printf("\n\n");
		for(int i=0; i<=n; i++){
			if(n>1 && i<n) printf("%12.2lf",b[i]);
			else{
				setcolor(FOREGROUND_RED);
    			printf("%12.2lf",b[i]);
    			setcolor(FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
			}
		}
		printf("\n            ");
		n--;
	}
}

void outf(double a[], double b[], double c, int n, FILE *f){
	for(int i=0; i<=n; i++) b[i]=a[i];
	for(int i=0; i<=n; i++) fprintf(f,"%12.2lf",b[i]);
	fprintf(f,"\n             ");
	while(n>=1){
		for(int i=1; i<=n; i++){
			b[i]=b[i-1]*c+b[i];
			fprintf(f,"%12.2lf",b[i-1]*c);
		}
		fprintf(f,"\n");
		for(int i=0; i<=n; i++) fprintf(f,"------------");
		fprintf(f,"\n\n");
		for(int i=0; i<=n; i++) fprintf(f,"%12.2lf",b[i]);
		fprintf(f,"\n            ");
		n--;
	}
}

void enter(char s[], FILE **f){
	printf("\nNhap ten file dau vao: ");
	do{
		scanf("%s",s);
		strcat(s,".txt");
		*f=fopen(s,"r");
		if(*f==NULL) printf("File khong ton tai, vui long nhap lai ten file: ");
	}while(*f==NULL);
	printf("\nNhap file thanh cong!\n\n");
	printf("Nhan Enter de tiep tuc ... ");
	getch(); system("cls");
}

void readFile(double c[], int n, FILE **f){
	for(int i=0; i<=n; i++) fscanf(*f,"%lf",&c[i]);
}

void xuatmang(double a[],int n) {
	for(int i=0; i<=n; i++) printf("%3.lf   ",a[i]);
	printf("\n");
}

void menu1(){
	printf("\n------------------------------------------CHUONG TRINH TINH TOAN TREN DA THUC------------------------------------------\n");
	printf("1. Nhap va doc du lieu tu file.\n");
	printf("2. Xuat du lieu vua nhap ra man hinh.\n");
	printf("3. Thuc hien tinh toan.\n");
	printf("4. Xuat ket qua ra man hinh.\n");
	printf("5. Xuat ket qua ra file .\n");
	printf("0. Ket thuc chuong trinh.\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	printf("Xin moi nhap lua chon: ");
}

void menu2(){
	printf("\n----------------------------------------------3. THUC HIEN TINH TOAN----------------------------------------------\n");
	printf("1. Tinh re1 = p(z) + q(z).\n");
	printf("2. Tinh re2 = q(z) + q(t).\n");
	printf("3. Tinh re3 = p(z) + q(t).\n");
	printf("4. Tinh re4 = p(1) + p(2) + ... + p(m).\n");
	printf("5. Tinh re5 = p(x1) + p(x2) + ... + p(xm).\n");
	printf("6. Tinh re1, res2, res3, res4, res5.\n");
	printf("7. Bien doi da thuc p(x+m).\n");
	printf("8. Nhap v va bien doi da thuc p(x+v).\n");
	printf("0. Thoat chuc nang 3.\n");
	printf("------------------------------------------------------------------------------------------------------------------\n");
	printf("Xin moi nhap lua chon: ");
	
}

void menu3(){
	printf("\n----------------------------------------------------4. XUAT KET QUA----------------------------------------------------\n");
	printf("1. Xuat re1 = p(z) + q(z).\n");
	printf("2. Xuat re2 = q(z) + q(t).\n");
	printf("3. Xuat re3 = p(z) + q(t).\n");
	printf("4. Xuat re4 = p(1) + p(2) +... + p(m).\n");
	printf("5. Xuat re5 = p(x1) + p(x2) + ... + p(xm).\n");
	printf("6. Xuat res1, res2, res3, res4, res5.\n");
	printf("7. Xuat da thuc p(x+m).\n");	
	printf("8. Xuat da thuc p(x+v).\n");
	printf("0. Thoat chuc nang 4.\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("Xin moi nhap lua chon: ");
}

main(){
	int n, m, l1=1, l2=1, l3=1, l4=1, l5=1, l7=1, l8=1;
	double v, z, t, res1, res2, res3, res4=0, res5=0;
	FILE *f, *fp;
	char s[MAX];
	double x[MAX], a[MAX], b[MAX], d[MAX], e[MAX];
	int lc, check=1;
	do{
		menu1();
		scanf("%d",&lc);
		if(lc<0 || lc>5){
			system("cls");
			printf("Vui long nhap lai!\n");
		}
		switch(lc){
			case 1: 
				enter(s,&f);
				fscanf(f,"%d%d%lf%lf",&n,&m,&z,&t);
				readFile(x,m-1,&f);
				readFile(a,n,&f);
				readFile(b,m,&f);
				check=0;
				system("cls");
				break;
			case 2:
				if(check) printf("Vui long nhap du lieu truoc khi su dung tinh nang nay!");
				else{
					system("cls");
					printf("n=%d	m=%d	z=%.3f    t=%.3f\n\n",n,m,z,t);
					printf("Mang X:\t"); xuatmang(x,m-1);
					printf("Mang A:\t"); xuatmang(a,n);
					printf("Mang B:\t"); xuatmang(b,m);
				}
				printf("\n\nNhan Enter de tiep tuc ... ");
				getch(); system("cls");
				break;
			case 3:
				system("cls");
				if(check) printf("Vui long nhap du lieu truoc khi su dung tinh nang nay!");
				else{
					int k;
					do{
						menu2();
						scanf("%d",&k);
						system("cls");
						if(k<0 || k>8) printf("Vui long nhap lai!\n");
						switch(k){
							case 1:
								l1=0;
								res1=calc(a,n,z) + calc(b,m,z);
								printf("Da tinh toan xong res1!\n\n");
								printf("Nhan Enter de tiep tuc ... ");
								getch(); system("cls");
								break;
							case 2:
								l2=0;
								res2=calc(b,m,z) + calc(b,m,t);
								printf("Da tinh toan xong res2!\n\n");
								printf("Nhan Enter de tiep tuc ... ");
								getch(); system("cls");
								break;
							case 3:
								l3=0;
								res3=calc(a,n,z) + calc(b,m,t);
								printf("Da tinh toan xong res3!\n\n");
								printf("Nhan Enter de tiep tuc ... ");
								getch(); system("cls");
								break;
							case 4:
								l4=0;
								for(int i=1; i<=m; i++) res4+=calc(a,n,i);
								printf("Da tinh toan xong res4!\n\n");
								printf("Nhan Enter de tiep tuc ... ");
								getch(); system("cls");
								break;
							case 5:
								l5=0;
								for(int i=0; i<m; i++) res5+=calc(a,n,x[i]);
								printf("Da tinh toan xong res5!\n\n");
								printf("Nhan Enter de tiep tuc ... ");
								getch(); system("cls");
								break;
							case 6:
								l1=0; l2=0; l3=0; l4=0; l5=0;
								res1=calc(a,n,z) + calc(b,m,z);
								res2=calc(b,m,z) + calc(b,m,t);
								res3=calc(a,n,z) + calc(b,m,t);
								for(int i=1; i<=m; i++) res4+=calc(a,n,i);
								for(int i=0; i<m; i++) res5+=calc(a,n,x[i]);
								printf("Da tinh toan xong res1, res2, res3, res4, res5!\n\n");
								printf("Nhan Enter de tiep tuc ... ");
								getch(); system("cls");
								break;
							case 7:
								l7=0;
								printf("Da bien doi xong da thuc p(x+m)!\n\n");
								printf("Nhan Enter de tiep tuc ... ");
								getch(); system("cls");
								break;
							case 8 :
								l8=0;
								printf("Nhap gia tri v can tinh p(x+v): ");
								scanf("%lf",&v);
								printf("\nDa bien doi xong da thuc p(x+v) voi v = %.2lf\n\n", v);
								printf("Nhan Enter de tiep tuc ... ");
								getch(); system("cls");
							default: break;
						}
					}while(k!=0);
				}
				break;
		 	case 4:
				system("cls");
				int k;
				if(check) printf("Vui long nhap du lieu truoc khi su dung tinh nang nay!");
				else{
					do{	
						menu3();
						scanf("%d",&k);
						system("cls");
					 	if(k<0 || k>8) printf("Vui long nhap lai!\n");
						switch(k){
							case 1:
								if(l1) printf("Chua tinh toan res1!");
								else{
									hn(a,n,z);
									hn(b,m,z);
									printf("res1 = p(z) + q(z) = %.3lf + %.3lf = %.3lf",calc(a,n,z), calc(b,m,z), res1);
								}
								printf("\n\nNhan Enter de tiep tuc ... ");
								getch(); system("cls");
								break;
							case 2:
								if(l2) printf("Chua tinh toan res2!");
								else{
									hn(b,m,z);
									hn(b,m,t);
									printf("res2 = q(z) + q(t) = %.3lf + %.3lf = %.3lf",calc(b,m,z), calc(b,m,t), res2);
								}
								printf("\n\nNhan Enter de tiep tuc ... ");
								getch(); system("cls");
								break;
							case 3:
								if(l3) printf("Chua tinh toan res3!");
								else{
									hn(a,n,z);
									hn(b,m,t);
									printf("res3 = p(z) + q(t) = %.3lf + %.3lf = %.3lf",calc(a,n,z), calc(b,m,t), res3);
								}
								printf("\n\nNhan Enter de tiep tuc ... ");
								getch(); system("cls");
								break;
							case 4:
								if(l4)printf("Chua tinh toan res4!");
								else{
									for(int i=1; i<=m; i++) hn(a,n,i);
									printf("res4 = p(1) + p(2) + ... + p(m) = %.3lf",res4);
								}
								printf("\n\nNhan Enter de tiep tuc ... ");
								getch(); system("cls");
								break;
							case 5:
								if(l5) printf("Chua tinh toan res5!");
								else{
									for(int i=0; i<m; i++) hn(a,n,x[i]);
									printf("res5 = p(x1) + p(x2) + ... + p(xm) = %.3lf",res5);
								}
								printf("\n\nNhan Enter de tiep tuc ... ");
								getch(); system("cls");
								break;
							case 6:
								if(l1 || l2 || l3 || l4 || l5) printf("Chua tinh toan day du cac ket qua!");
								else printf("res1 = %3.3lf\nres2 = %3.3lf\nres3 = %3.3lf\nres4 = %3.3lf\nres5 = %3.3lf",res1,res2,res3,res4,res5);
								printf("\n\nNhan Enter de tiep tuc ... ");
								getch(); system("cls");
								break;	
							case 7:
								if(l7) printf("Chua bien doi da thuc p(x+m)!");
								else{
									hoocner_tq(a,d,m,n);
									printf("\nHe so cua da thuc p(x+m): ");
									for(int i=0; i<=n; i++) printf("%.3lf    ",d[i]);
								}
								printf("\n\nNhan Enter de tiep tuc ... ");
								getch(); system("cls");
								break;
							case 8:
								if(l8) printf("Chua co du lieu de bien doi da thuc p(x+v)!");
								else{
									hoocner_tq(a,e,v,n);
									printf("\nHe so cua da thuc p(x+v) voi v = %.2lf: ", v);
									for(int i=0; i<=n; i++) printf("%.3lf    ",e[i]);
								}
								printf("\n\nNhan Enter de tiep tuc ... ");
								getch(); system("cls");
								break;
							default: break;
						}
					}while(k!=0);
				}
				break;
			case 5:
				system("cls");
				if(check) printf("Vui long nhap du lieu truoc khi su dung tinh nang nay!");
				else{
					if(l1 || l2 || l3 || l4 || l5 || l7) printf("Chua co day du du lieu de xuat ra file!");
					else{
						char ss[100];
						printf("Nhap ten file muon xuat ket qua: ");
						scanf("%s",&ss);
						strcat(ss,".txt");
						fp=fopen(ss,"w");
	    				fprintf(fp,"res1 : %lf\n", res1);
	    				fprintf(fp,"res2 : %lf\n", res2);		    	
	    				fprintf(fp,"res3 : %lf\n", res3);	
						fprintf(fp,"res4 : %lf\n", res4);
						fprintf(fp,"res5 : %lf\n", res5);	
						fprintf(fp,"\n");
						fprintf(fp,"So do Hoocne tong quat cua da thuc p(x+m): \n\n");
						outf(a,d,m,n,fp);
						fprintf(fp,"\nHe so cua da thuc p(x+m):	");
						for(int i=0; i<=n; i++) fprintf(fp,"%.3lf 	",d[i]);
						fprintf(fp,"\n\n");
						if(l8==0){
							fprintf(fp,"So do Hoocne tong quat cua da thuc p(x+v) voi v = %lf: \n\n", v);
							outf(a,e,v,n,fp);
							fprintf(fp,"\n\nHe so cua da thuc p(x+v) voi v = %lf:	", v);
							for(int i=0; i<=n; i++) fprintf(fp,"%.3lf 	",e[i]);
						}
	    				fclose(fp);
	    				printf("\nDa xuat thanh cong ket qua ra file %s!",ss);
	    				printf("\n\nNhan Enter de tiep tuc ... ");
	    			}
				}
				getch(); system("cls");
				break;
			default: break;
		}
	}while(lc!=0);
}	
				
				

