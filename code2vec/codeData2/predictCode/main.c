#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10001
int min(int x,int y){
  if(x<y) return x;
  return y;
}
struct node{
  int u,e,w;//u��ʼ��e�յ㣬wǮ
}edge[900010],temp;//��ʾ·
int book[100100];//��ʾ����ͷ��Ǯ������ΪMAX�ɴ����޷�����ͷ
int pre[100100];
int flag=0;
void init(int n){
  int i;
  for(i=0;i<=n;i++){
    pre[i]=i;
  }//����ѵ��������ڵ�һ�������ڣ���ʱ��������·����ͨͼ��������ڵ㣬������Ҫ��ͷ���룬���û����ڵ�������ͨ����������ͷ����
}
int find(int x){
  if(pre[x]==x) return x;
  else return pre[x]=find(pre[x]);//һ·���ϣ�Ѱ�Ҹ��ڵ㣬������������ͼ�Ƿ���ͨ
}
int f_first(int n,int m){//����ͷ����
  init(n);
  int sum=0;//�ܼ۸����
  flag=0;
  for(int i=0;i<m;i++){
    if(edge[i].w==MAX) continue;
    int t1=find(edge[i].u);
    int t2=find(edge[i].e);
    if(t1!=t2||edge[i].w<0){//�������յ㻹û����ͨ������������ͨ���Ѿ���ͨ������·׬Ǯ�����ްײ���
    pre[t1]=t2;//��������ͨ
    sum+=edge[i].w;
    if(edge[i].u==0) flag++;//�������������ڵ㣬˵��������ͷ
    }
  }
  return sum;
}
int f_second(int n,int m){//û����ͷ����
  init(n);  
  int sum=0;  
  for(int i=0; i<m; i++){    
    if(edge[i].u==0) continue;    
    int t1=find(edge[i].u);    
    int t2=find(edge[i].e);    
    if(t1!=t2||edge[i].w<0){      
      pre[t1]=t2;    
      sum+=edge[i].w;
    }
  }
  return sum;
}
int main(){
  int m,n;
  scanf("%d%d",&m,&n);
  int i,j;
  for(i=0;i<m;i++){
    scanf("%d%d%d",&edge[i].u,&edge[i].e,&edge[i].w);
  }
  for(i=1;i<=n;i++){
    scanf("%d",&book[i]);
  }
  for(i=1;i<=n;i++){
    edge[m].u=0;
    edge[m].e=i;
    if(book[i]==-1) edge[m].w=MAX;
    else edge[m].w=book[i];
    m++;//����ͷ���·�����Һ͵�0��"����"�Ľڵ���ͨ
  }
  for(i=0;i<m-1;i++){
    for(j=i+1;j<m;j++){
      if(edge[i].w>edge[j].w){
        temp=edge[i];
        edge[i]=edge[j];
        edge[j]=temp;
      }
    }
  }//Ȼ���·��������������Ϳ�������ȡ���·�����г��н�����
  int a1=f_first(n,m);
  if(flag==1){//ֻ����һ����ͷ����ô˵������ڵ������Ժ�ͼ������ȫ��ͨ
    int a2=f_second(n,m);
    printf("%d",a2);
  }
  else printf("%d",min(a1,f_second(n,m)));
  return 0;
}