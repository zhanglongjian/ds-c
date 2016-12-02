//#include <iostream.h>
//using namespace std;
#ifndef List2
#define List2
template<class ElemType>
class List{
public:
virtual int GetLen()=0;/*�����Ա���*/
virtual ElemType &GetElem(int i)=0;/*ȡ��i��Ԫ��,i=1~n*/
ElemType &operator[](int i){return GetElem(i);}//�±�����
virtual int Locate(ElemType x)=0;
virtual int InsElem(int i,ElemType x)=0;
virtual int DelElem(int i)=0;
virtual void DispList(char c=',',char c2='\n')=0;
};
#endif

#ifndef sq_List2
#define sq_List2

template<typename ElemType>
class sqList:public List<ElemType>{
ElemType *data,X;   //����洢����Ԫ�ص�����
int Length,MaxLen;  //���Ա��ʵ�ʳ���
public://���캯����ʼ��˳���
sqList(int n=100):MaxLen(n),Length(0),X(0){data=new ElemType[n];}
int GetLen(){return Length;}//�����Ա���

ElemType &GetElem(int i)//ȡ��i��Ԫ��ֵ,i=1~n
{if(i<1||i>Length)return X;//���������
 return data[i-1];}
//ElemType &operator[](int i){return GetElem(i);}//�±�����

int Locate(ElemType x)//����ֵΪxԪ�ص�λ��,û�ҵ�����a0
{int i;
for(i=0;i<Length;i++)if(!(data[i]!=x))return i+1;
return 0;}

int InsElem(int i,ElemType x)//��iλ�ò�����x,i=1~n
{int j;
 if(Length==MaxLen)return 0;//������ 
 if(i<1||i>Length+1)return 0;//����λ�ó���
 for(j=Length;j>=i;j--)data[j]=data[j-1];//����Ԫ�غ��� 
 data[i-1]=x;Length++;  //����x,���ȼ�1 
 return 1;}

int DelElem(int i)//ɾ�����Ա��е�i��λ���ϵ�Ԫ�� 
{int j;
 if(i<1||i>Length)return 0;//���ձ�ɾ��λ�õĺϷ���
 for(j=i;j<=Length-1;j++)data[j-1]=data[j];//��ǰ�ƶ�Ԫ��
 Length--;return 1;}

void DispList(char c=',',char c2='\n')//������Ա���ÿ��Ԫ��ֵ
{int i;
if(Length==0){cout<<"�ձ�";if(c2)if(c2=='\n')cout<<endl;else cout<<c2;return;}
for(i=0;i<Length;i++){cout<<data[i];if(c)cout<<c;}
if(c2)if(c2=='\n')cout<<endl;else cout<<c2;
}

};

#endif