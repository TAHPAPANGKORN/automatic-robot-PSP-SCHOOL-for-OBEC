
#include<pop7.h>
int sp = 90; // speed
int i = 2;
int state = 1;

int Set_Cm = 700;
int TimeDelayflag = 5;

int TimeChaiYo =  5* TimeDelayflag;
void setup() {
  setTextSize(2);
  setTextColor(GLCD_RED);
  glcdMode(1);
  glcd(0,3,"PSP ROBOT  "); 
  Serial.begin(9600);
}

void loop() {
  int But = digitalRead(31);
  
  if (But == 0){
      state = 2;
    }
  switch (state) {
   case (2) :     
   Robot_start();
   cross_rightbeforechop();
   cross_longward();
   Flag();
   stop_();
   
   case (1) :
   Robot_start();
     cross_left();
     cross_left();
     cross_right();
     cross_dot();   
     go_green1();
     cross_right(); 
     cross_rightbeforechop();
     cross_longward();
     Flag();
     stop_();
   }
}

void cross_dot() {
  while(i>1) {
    int left = digitalRead(27); 
    int right = digitalRead(28);
    int out_left = digitalRead(29);
    int out_right = digitalRead(26);

    if(left==0 && right==0 && out_left ==0 && out_right ==0) //go forward
    {
      fd(sp);
    }
    
    if(left==1 && right==0 ) //turn  left
    {
      sl(sp);
    }
    if(out_left==1 && right==0 )
    {
      sl(sp);
    }
    if(left==0 && right==1  ) //turn  right
    {
      sr(sp);
    }
    if(left==0 && out_right==1 )
    {
      sr(sp);
    }
    if(left==1 && right==1 && out_left == 1 && out_right == 1 )
    {
      fd(sp);
      sleep(400);
      break;
    }   
    
  }
}

void cross_left() { //found the cross  and turn left
    while(i>1)
  {
      int left = digitalRead(27); 
      int right = digitalRead(28);
      int out_left = digitalRead(29);
      int out_right = digitalRead(26);
      
    if(left==0 && right==0) //go forward
    {
      fd(sp);
    }
    
    if(left==1 && right==0 ) //turn  left
    {
      sl(sp);
    }
    if(out_left==1 && right==0 )
    {
      sl(sp);
    }
    if(left==0 && right==1  ) //turn  right
    {
      sr(sp);
    }
    if(left==0 && out_right==1 )
    {
      sr(sp);
    }
    
    if(left==1 && right==1 && out_left == 1 && out_right == 1 ) //found the black cross 
    {
      fd(sp);
      sleep(400);
      sl(sp);
      while(digitalRead(29)==0);
      while(digitalRead(27)==0);
      while(digitalRead(29)==1);
      while(digitalRead(27)==1); 
      sl(sp);
      while(digitalRead(26)==0);
      while(digitalRead(26)==1);
//      delay(180);
//      ao();
//      sleep(200);
      break;
    } 
  }
}
void cross_rightbeforechop() { //found the cross  and turn right
  while(i>1)
  {
      int left = digitalRead(27); 
      int right = digitalRead(28);
      int out_left = digitalRead(29);
      int out_right = digitalRead(26);
      
    if(left==0 && right==0 || out_left== 0 && out_right== 0) //go forward
    {
      fd(sp);
    }
    
    if(left==1 && right==0 ) //turn  left
    {
      sl(sp);
    }
    if(out_left==1 && right==0 )
    {
      sl(sp);
    }
    if(left==0 && right==1  ) //turn  right
    {
      sr(sp);
    }
    if(left==0 && out_right==1 )
    {
      sr(sp);
    }
    if(left==1 && right==1 && out_left == 1 && out_right == 1 || out_left == 1 && out_right == 1 )
    {
      fd(sp);
      sleep(500);
      sr(sp); 
      while(digitalRead(26)==0);
      while(digitalRead(28)==0);
      while(digitalRead(26)==1);
      while(digitalRead(28)==1);
      sr(sp);
      while(digitalRead(27)==0);    
//      delay(150);
//      ao();
//      sleep(200);
      break;
    } 
  }
}

void cross_right() { //found the cross  and turn right
  while(i>1)
  {
      int left = digitalRead(27); 
      int right = digitalRead(28);
      int out_left = digitalRead(29);
      int out_right = digitalRead(26);
      
    if(left==0 && right==0 || out_left== 0 && out_right== 0) //go forward
    {
      fd(sp);
    }
    
    if(left==1 && right==0 ) //turn  left
    {
      sl(sp);
    }
    if(out_left==1 && right==0 )
    {
      sl(sp);
    }
    if(left==0 && right==1  ) //turn  right
    {
      sr(sp);
    }
    if(left==0 && out_right==1 )
    {
      sr(sp);
    }
    if(left==1 && right==1 && out_left == 1 && out_right == 1 || out_left == 1 && out_right == 1  )
    {
      fd(sp);
      sleep(360);
      sr(sp); 
      while(digitalRead(26)==0);
      while(digitalRead(28)==0);
      while(digitalRead(26)==1);
      while(digitalRead(28)==1);
      sr(sp);
      while(digitalRead(27)==0);
      while(digitalRead(27)==1);
      ao();
      sleep(200);
      break;
    } 
  }
}


void cross_forward() { //found the cross  and go forward
  while(i>1)
  {
      int left = digitalRead(27); 
      int right = digitalRead(28);
      int out_left = digitalRead(29);
      int out_right = digitalRead(26);
      
    if(left==0 && right==0 ) //go forward
    {
      fd(100);
    }
    if(left==1 && right==0 ) //turn  left
    {
      sl(sp);
    }
    if(out_left==1 && right==0 )
    {
      sl(sp);
    }
    if(left==0 && right==1  ) //turn  right
    {
      sr(sp);
    }
    if(left==0 && out_right==1 )
    {
     sr(sp);
    }
    
    if(left==1 && right==1 && out_left == 1 && out_right == 1)
    {
      fd(sp);
      sleep(400);
      break;
    } 
  }
}

void go_green() {
  while (i>1) {
    int dis = digitalRead(24);
    
    if (dis == 0) {  // x = ค่าระยะเส้นใน y = ค่าระยะเส้นนอก
        motor(1,80);  //1 left motor
        motor(2,50); //2 right motor
      }
      if (dis == 1 ) {
        motor(1,50);
        motor(2,80);
      }
   }   
  }

void FrowardCorlorGreen(int Time)
{
  int value = 0; 
  glcd(1,0,"%d",value);
  while (i>i)
  {
    go_green();
    if (value < Time)
    {
      go_green();
      value++;
      delay(3);
    }
    else
    {
      AO();
      break;
    }

  }
  value = 0;
}


void cross_button() { //found the cross  and go forward
  while(i>1)
  {
      int left = digitalRead(27); 
      int right = digitalRead(28);
      int out_left = digitalRead(29);
      int out_right = digitalRead(26);
 
   if(left==0 && right==0 && out_left ==0 && out_right ==0) //go forward
    {
      fd(sp);
    }
    
    if(left==1 && right==0 ) //turn  left
    {
      sl(sp);
    }
    if(out_left==1 && right==0 )
    {
      sl(sp);
    }
    if(left==0 && right==1  ) //turn  right
    {
      sr(sp);
    }
    if(left==0 && out_right==1 )
    {
      sr(sp);
    }
    
    if(left==1 && right==1 && out_left == 1 && out_right == 1)
    {
      fd(60);
      sleep(400);
      fd(sp);
      while (digitalRead(31)==1);
      ao();
      break;
    }
  }
}

void button() {
  while(i>1){
  if(digitalRead(31)== 0)
      { 
        ao();
        delay(1000);
        servo(1,90);
        delay(2000);
        servo(2,20);
        delay(2000);
        motor(3,-10);
        delay(2000);
        servo(1,110);
        delay(2000);
        servo(2,10);
        delay(2000);
        ao();
        break;
      }
  }
}

void stop_ () {  //found the cross  and stop 
  while(i>1)
  {
    ao();
    while (digitalRead(31)==0);
  }
}
void Robot_start() {
  while(i>1) {
    int backsensor = digitalRead(25);
    ao();
    if (backsensor == 0) {
      Serial.println(backsensor);
      ao();
      }
    else {
      delay(1000);
      motor(3,50);
      break;
      }
  }
}
void Flag ()
{
  while (i>1)
        {
          servo(3, 90);
          delay(200);
          servo(3, 60);
          delay(200);
        } 
}

void go_green1() {   
  while (i>1) {
   int dis = analogRead(30); 
   int left = digitalRead(27); 
   int right = digitalRead(28);
   int out_left = digitalRead(29);
   int out_right = digitalRead(26);
   int ultra = (dis*100)/1023;
   
    if (ultra < 6 ) {  // x = ค่าระยะเส้นใน y = ค่าระยะเส้นนอก
        motor(1,100);  //1 left motor
        motor(2,60); //2 right motor
      }
    else if (ultra > 6 )
      {
        motor(1,60);
        motor(2,100);
      }
      
    if (left==1 && right==1 && out_left == 1 && out_right == 1 || out_left == 1 && out_right == 1 || left==1 && right==1 ) {
      fd(sp);
      sleep(400);
      break;
   }
 }
}
void cross_longward() { //go long
  while(i>1)
  {
      int left = digitalRead(27);
      int right = digitalRead(28);
      int out_left = digitalRead(29);
      int out_right = digitalRead(26);
      
    if(left==0 && right==0 ) //go forward
    {
      fd(100);
    }
    if(left==1 && right==0 ) //turn  left
    {
      sl(100);
//      motor(1,30);
//      motor(2,100);
    }
    if(out_left==1 && right==0 )
    {
      sl(100);
//      motor(1,30);
//      motor(2,100);
    }
    if(left==0 && right==1  ) //turn  right
    {
      sr(100);
//      motor(1,100);
//      motor(2,30);
    }
    if(left==0 && out_right==1 )
    {
      sr(100);
//      motor(1,100);
//      motor(2,30);
    }
    
    if(left==1 && right==1 && out_left == 1 && out_right == 1)
    {
     fd(sp);
    } 
    if(digitalRead(31)== 0)
      { 
        ao();
        delay(1000);
        servo(1,110);
        delay(1000);
        servo(2,35);
        delay(800);
        motor(3,-10);
        delay(1000);
        servo(2,10);
        delay(500);
        ao();
        break;
      }
  }
}
