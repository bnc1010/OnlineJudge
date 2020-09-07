#include<iostream>
#include<cmath>
using namespace std;

int n;   //�ʺ���Ŀ
int a[8][8]; //����
int white[8],black[8];  //white�׻ʺ�λ�ã�black�ڻʺ�λ�� 
int c=0;  //��ͬ�����������

void blackq(int pos)   //��ɫ�ʺ����
{
	for(int i=0;i<pos-1;i++){ 
		int judge = black[pos-1] - black[i];  // ��һ��λ����֮ǰ����λ�õ���֮������ж�
		if(judge==0 || abs(judge)==(pos-1-i))  // ��ͬһ�У����С���֮�����ֵ���
		    return; 
	} 
	
	if(pos==n){
		c++;
		return;
	}
	
	for(int i=0;i<n;i++){
		if(a[pos][i] && white[pos]!=i){  // �жϴ�λ���Ƿ��ܷŻʺ��Ҵ�λ���Ƿ��ѷŰ׻ʺ� 
			black[pos] = i;
	    	blackq(pos+1); //�жϴ�λ���ܷ�Żʺ���������ݹ飬���򷵻أ����ݲ���һ�� 
		}
		
	}
}

void whiteq(int pos) //��ɫ�ʺ���ã���pos�У�Ҳ���ǵ�pos+1���׻ʺ� 
{
	for(int i=0;i<pos-1;i++){
		int judge = white[pos-1] - white[i];  // ��һ��λ����֮ǰ����λ�õ���֮������ж�
		if(judge==0 || abs(judge)==(pos-1-i))  // ��ͬһ�У����С���֮�����ֵ���
		    return; 
	} 
	
	if(pos==n){  //���ź����а׻ʺ󣬿�ʼ�źڻʺ� 
		blackq(0);
		return;
	}
	
	for(int i=0;i<n;i++){  // i ��Ӧ��i�� 
		if(a[pos][i]){   // �жϴ�λ���Ƿ��ܷŻʺ�
			white[pos] = i;
		    whiteq(pos+1); //�жϴ�λ���ܷ�Żʺ���������ݹ飬���򷵻أ����ݲ���һ��
		}	 
	}
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	whiteq(0);
	cout<<c<<endl;
	system("pause");
	return 0;
}