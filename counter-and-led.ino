int lzPin = 13;
int lzState = 0;    

   //设置阴极接口
int a = 1;
int b = 2;
int c = 3;
int d = 4;
int e = 5;
int f = 6;
int g = 7;
int p = 8;
//设置阳极接口
int d4 = 9;
int d3 = 10;
int d2 = 11;
int d1 = 12;

int step =0;//thw number of every step
byte segs[7] = { a, b, c, d, e, f, g };

byte seven_seg_digits[10][7] = { { 0,0,0,0,0,0,1 },  // = 0
                                 { 1,0,0,1,1,1,1 },  // = 1
                                 { 0,0,1,0,0,1,0 },  // = 2
                                 { 0,0,0,0,1,1,0 },  // = 3
                                 { 1,0,0,1,1,0,0 },  // = 4
                                 { 0,1,0,0,1,0,0 },  // = 5
                                 { 0,1,0,0,0,0,0 },  // = 6
                                 { 0,0,0,1,1,1,1 },  // = 7
                                 { 0,0,0,0,0,0,0 },  // = 8
                                 { 0,0,0,0,1,0,0 }   // = 9
                             }; 
                             
void setup() {    
      pinMode(lzPin, INPUT); 

      pinMode(d1, OUTPUT);
      pinMode(d2, OUTPUT);
      pinMode(d3, OUTPUT);
      pinMode(d4, OUTPUT);
      pinMode(a, OUTPUT);
      pinMode(b, OUTPUT);
      pinMode(c, OUTPUT);
      pinMode(d, OUTPUT);
      pinMode(e, OUTPUT);
      pinMode(f, OUTPUT);
      pinMode(g, OUTPUT);
      pinMode(p, OUTPUT);
}

void loop()
{
   lzState = digitalRead(lzPin);
   if (lzState == LOW)
      {   
       step++;
       screen(step);
       delay(1000);
      }
   else
      {
      }
}

void pickDigit(int x)  //定义pickDigit(x),其作用是开启dx端口
{
  digitalWrite(d1, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(d3, LOW);
  digitalWrite(d4, LOW);

  switch(x)
  {
  case 1: 
    digitalWrite(d1, HIGH); 
    break;
  case 2: 
    digitalWrite(d2, HIGH); 
    break;
  case 3: 
    digitalWrite(d3, HIGH); 
    break;
  default: 
    digitalWrite(d4, HIGH); 
    break;
  }
}

void clearLEDs()  //清屏
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(p, HIGH);
}

// 点亮对应数字的数码管
void lightSegments(int x) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segs[i], seven_seg_digits[x][i]);
  }
}

void screen(int n)
{
  clearLEDs();
  pickDigit(1);
  lightSegments((n/1000)%10);
  clearLEDs();
  pickDigit(2);
  lightSegments((n/100)%10);
  clearLEDs();
  pickDigit(3);
  lightSegments((n/10)%10);
  clearLEDs();
  lightSegments(4);
  lightSegments(n%10);
}
