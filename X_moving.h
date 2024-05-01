void X_moving(){
  unsigned char X[5][5]={
    {0B10001000,0B01010000,0B00100000,0B01010000,0B10001000},
    {0B10001000,0B01010000,0B00100000,0B01010000,0B10001000},
    {0B10001000,0B01010000,0B00100000,0B01010000,0B10001000},
    {0B10001000,0B01010000,0B00100000,0B01010000,0B10001000},
    {0B10001000,0B01010000,0B00100000,0B01010000,0B10001000},
  };

  unsigned char plus[5][5]={
    {0B00100000,0B00100000,0B11111000,0B00100000,0B00100000},
    {0B00100000,0B00100000,0B11111000,0B00100000,0B00100000},
    {0B00100000,0B00100000,0B11111000,0B00100000,0B00100000},
    {0B00100000,0B00100000,0B11111000,0B00100000,0B00100000},
    {0B00100000,0B00100000,0B11111000,0B00100000,0B00100000},
  };
  
  int count=25;

   for(int t=0;t<count;t++){
      for(int k=0;k<5;k++){  
        digitalWrite(latch_pin, LOW);
        
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(X[k][4]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(X[k][3]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(X[k][2]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(X[k][1]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(X[k][0]));
        shiftOut(data_pin, clock_pin,MSBFIRST, row[k]);
      
        digitalWrite(latch_pin, HIGH);
        delay(1);
    }
   }

   for(int t=0;t<count;t++){
      for(int k=0;k<5;k++){  
        digitalWrite(latch_pin, LOW);
        
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(plus[k][4]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(plus[k][3]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(plus[k][2]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(plus[k][1]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(plus[k][0]));
        shiftOut(data_pin, clock_pin,MSBFIRST, row[k]);
      
        digitalWrite(latch_pin, HIGH);
        delay(1);
    }
   }
}
