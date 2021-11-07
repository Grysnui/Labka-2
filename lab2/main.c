#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

void info(double I,double Mistake,int n )//���� ��������� �� �������, Mistake - �������
{
    printf("I = %lf\n",I);
    printf("Mistake= %lf\n",Mistake);
    printf("Amount of steps = %d\n",n);
    printf("Maladets, PC ne vzorvalsya\n\n");
}

double Calc(double x)//������� ���������� ���������
{
    /* Var 13 ��� (-1;1)
    func= 1/(1.1+x)^2
    */
    return (1/pow(1.1+x,2));
}

double Rectangles(int n,double A, double B)//������� ���������� ��������� �� ��������� ������ ������������

{
    double h,I,x;
    h=(B-A)/n;
    for(x = A; x <= B ;x = x + h)
   {
    I=I+Calc(x);
   }
    I=I*h;
    return I;
}
double Trapezium (int n,double A, double B)//������� �������������� ��������� �� ��������� ������ ��������
{
    double h,I=0,x;//�=0 ��� �������� � �������
     h=(B-A)/n;
     I=Calc(A)+Calc(B);
     for(x = A; x <= B ;x = x + h)
     {
        I=I+Calc(x);
     }
     I=I*h;
     return I;
}
double Simpson(int n,double A, double B)//������� ���������� ��������� �� ��������� ������ ѳ�����
{
    double h,I=0,x,II=0;//II - ������ ��������
    int i=0;
    h=((B-A)/n);
    for(i=0;i<=n;i++)
    {
        if(i%2 != 0)
        {
            I=I+Calc(A+h*i);
        }
         if(i%2 == 0)
         {
               II=II+Calc(A+h*i);
         }
    }
    I=((B-A)/(3*n))*(Calc(A)+4*I+2*II+Calc(B));
     return I;
}
int main()
{
    setlocale(LC_ALL, "Rus");
    int v,i,j=1,g,n;
    double h,d,x,I=0.0,II=0.0,A,B;
    for(g=0;g<3;g++)//����, ��� ������������ ��� ������
   {
    printf("Hello, Dear Katin(�������)\n\n");
    printf("1 - Rectangles\n2 - Trapezium\n3 - Simpson\n");
    printf("Choose your method: ");
    scanf("%d",&v);
    switch("%d",v)
    {
    case 1://Rectangles
        printf("Amount of steps:");
        scanf("%d",&n);
        printf("\nlower limit: ");
        scanf("%lf",&A);
        printf("\nupper border: ");
        scanf("%lf",&B);
        for (j;j<=2;j++)
        {
            if(j==1)
            {
                I=Rectangles(n,A,B);
                n=n+2;
            }
            II=Rectangles(n,A,B);
            if(fabs(I-II)>0.00001 && fabs(I-II)<0.001)//�������� �� ����������� �������
            {
                II=fabs(I-II);
                info(I,II,n);
                break;
            }
            else
                {
                    j=0;//� ������� ����������� ����� ������ ���� �� �������
                }
        }
        break;
        case 2://Trapezium
            printf("Amount of steps:");
            scanf("%d",&n);
            printf("\nlower limit: ");
            scanf("%lf",&A);
            printf("\nupper border: ");
            scanf("%lf",&B);
            for(j; j<=2;j++)
        {
            if(j==1)
              {
               I = Trapezium(n,A,B);
               n=n+2;
              }
            II = Trapezium(n,A,B);
            if(fabs(I-II)>0.00001 && fabs(I-II)<0.001)
            {
                II = fabs(I-II);
                info(I,II,n);
                break;
            }
            else
            {
                j=0;
            }
        }
        break;
        case 3://Simpson
        do
        {
            printf("Number of intervals must be even(������) \n");
            printf("Amount of steps:");
            scanf("%d",&n);

        }
        while(n%2!=0);
        printf("\nlower limit:");
        scanf("%lf",&A);
        printf("\nupper border:");
        scanf("%lf",&B);
for(j; j<=2;j++)
        {
              if(j==1)
              {
               I = Simpson(n,A,B);
               n=n+2;
              }
            II = Simpson(n,A,B);
            if(fabs(I-II)>0.00001 && fabs(I-II)<0.001)
            {
                II = fabs(I-II);
                info(I,II,n);
                break;
            }
            else
            {
                j=0;
            }
        }
        break;
    default:
        printf("Wrong variant\n");//���� ���������� �� ������ ������� � �������
        break;
    }
 }
 return 0;
}
