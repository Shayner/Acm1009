#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
 int m,n,k;
 int j[1010],f[1010];
 double each[1010]={0};
 while(scanf("%d%d",&m,&n)!=EOF&&m!=-1&&n!=-1){
	 int t,temp[1010]={0};
	 double min=0.0;
	 double sum=0.0;
	 for(k=0;k<n;k++)
	 {
		 scanf("%d%d",&j[k],&f[k]); 
		 if(f[k]!=0)each[k]=j[k]*1.0/f[k];
		 else temp[k]=j[k];
	 }
	 //�Ƚ������Ǹ�each
	 while(m!=0){
		 //n=n-1;
		 min=0;
		 for(k=0;k<n;k++){
			 if(min<each[k]&&each[k]!=0) 
				 {
					 min=each[k];
					 t=k;
			 }
	 }
		 // printf("��ǰ��each%.3lf\n",min);
	 each[t]=0;
	 for(k=0;k<n;k++){
		 if(temp[k]!=0){
			 sum+=temp[k];
			 temp[k]=0;
		 }
	 }
	 //printf("��ǰ��m��%d\n",m);
	 //printf("��ǰ�ĺͣ�%.3lf\n",sum);
	 if(m>=f[t]){
		 sum=sum+f[t]*min;
		 m=m-f[t];
		 
	 }
	 else{ 
		 printf("%d  ",m);
		 sum+=m*min;
		 m=0;
	 } 
	 //printf("%d  ",n);
	// printf("��ǰ��m��%d\n",m);
	 }
	// printf("����m��%d\n",m);
	 printf("%.3lf\n",sum);
 }
	return 0;
}
