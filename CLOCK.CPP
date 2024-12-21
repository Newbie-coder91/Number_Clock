/*Special Clock
Created By Newbie-coder91 Aka Atul Agrawal*/
#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include <dos.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159265358979

void main()
{
  int a=DETECT, b;
  clrscr();
  initgraph(&a,&b,"");

  double sec_x, sec_y;
  double min_x, min_y;
  double hour_x, hour_y;
  double hour_step =  (2*PI)/12;
  double step =  (2*PI)/60;
  int sec_r, min_r, hour_r;
  char sec_ch[3], min_ch[3], hour_ch[3];

  time_t rawtime;
  struct tm *current_time;
  time(&rawtime);
  current_time = localtime(&rawtime);

  int i;
  int sec = current_time->tm_sec;
  int min = current_time->tm_min;
  int hour = current_time->tm_hour;
  if(hour>12) hour -= 12;


  double sec_angle = -PI/2 + sec * step;
  double min_angle = -PI/2 + min * step;
  double hour_angle = -PI/2+ hour + hour_step + (min/60.0)*hour_step;
  while(kbhit()==0){
    outtextxy(175,20,"This Clock is Created By Atul Agrawal");
    circle(325,242,140);
    circle(325,242,5);
    sec_r = 20;
    min_r = 20;
    hour_r = 20;
    sprintf(sec_ch,"%d",sec);
    sprintf(min_ch,"%d",min);
    sprintf(hour_ch,"%d",hour);
    for(i = 1; i <= 6; i++) {
      sec_x = 320 + sec_r*cos(sec_angle);
      sec_y = 240 + sec_r*sin(sec_angle);
      outtextxy(sec_x,sec_y,sec_ch);
      sec_r += 20;
      if(i > 1){
      min_x = 320 + min_r*cos(min_angle);
      min_y = 240 + min_r*sin(min_angle);
      outtextxy(min_x,min_y,min_ch);
      min_r += 20;
      }
      if(i>2){
      hour_x = 320 + hour_r*cos(hour_angle);
      hour_y = 240 + hour_r*sin(hour_angle);
      outtextxy(hour_x,hour_y,hour_ch);
      hour_r += 20;
      }
    }
    delay(1000);
    sec_angle += step;
    sec++;
    //-----------------------------
    if(sec == 61){
      sec = 1;
      min_angle += step;
      min++;
    }
    if(sec_angle < -2*PI){
      sec_angle += 2*PI;
    }
    //-----------------------------
    if(min == 61){
      min = 1;
      hour_angle += hour_step;
      hour++;
    }
    if(min_angle < -2*PI){
      min_angle += 2*PI;
    }
    //-----------------------------
    if(hour == 13){
      hour = 1;
    }
    if(hour_angle < -2*PI){
      hour_angle += 2*PI;
    }
    cleardevice();
  }

  getch();
}
