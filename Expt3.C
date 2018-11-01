#include<stdio.h>
#include<graphics.h>

void bresenham(int x1, int y1, int x2, int y2)
{
    float dy=y2-y1, dx=x2-x1, d;
    float m;
    m=dy/dx;
    printf("\n%f",m);

       if(m<0&&m>=-1){

        d=2*dy-dx;
        while(x1<=x2){
            putpixel(x1,y1,BLUE);
            d=d+2*dy;
            x1++;
            y1--;
            if(d>=0){
                y1--;
                d=d+2*dx;
            }
            delay(10);
        }
    }

    if((m<=1)&&(m>=0)){


        d=2*dy-dx;
        while(x1<=x2){
            putpixel(x1,y1,GREEN);
            d=d+2*dy;
            x1++;
            if(d>=0){
                y1++;
                d=d-2*dx;
            }
            delay(10);
        }
    }


    if(m>1){


        d=2*dx-dy;
        while(y1<=y2){
            putpixel(x1,y1,YELLOW);
            d=d+2*dx;
            y1++;
            if(d>=0){
                x1++;
                d=d-2*dy;
            }
            delay(10);
            }
        }

        if(m<-1){


        d=2*dx-dy;
        while(y1>=y2){
            putpixel(x1,y1,RED);
            d=d+2*dx;

            y1--;
            if(d>=0){
                    y1--;
                x1++;
                d=d-2*dy;
            }
            delay(10);
            }
    }


}



int main()
{
  int gd = DETECT, gm;
  float x1,y1,x2,y2,p1,q1,p2,q2,r1,s1,r2,s2,u1,v1,u2,v2;

    printf("[RED] Enter the value of x1 and y1: ");
    scanf("%f%f",&x1,&y1);
    printf("[RED] Enter the value of x2 and y2: ");
    scanf("%f%f",&x2,&y2);
    printf("\n[BLUE] Enter the value of p1 and q1: ");
    scanf("%f%f",&p1,&q1);
    printf("[BLUE] Enter the value of p2 and q2: ");
    scanf("%f%f",&p2,&q2);
    printf("\n[GREEN] Enter the value of r1 and s1: ");
    scanf("%f%f",&r1,&s1);
    printf("[GREEN] Enter the value of r2 and s2: ");
    scanf("%f%f",&r2,&s2);
    printf("\n[YELLOW] Enter the value of u1 and v1: ");
    scanf("%f%f",&u1,&v1);
    printf("[YELLOW] Enter the value of u2 and v2: ");
    scanf("%f%f",&u2,&v2);

  initgraph (&gd, &gm, "c:\\tc\\bgi");

  bresenham(x1, y1, x2, y2);
  bresenham(p1, q1, p2, q2);
  bresenham(r1, s1, r2, s2);
  bresenham(u1, v1, u2, v2);

  getch();
  return 0;
}

