void each_square(){
  unsigned char index[5]={0B11111000,0B11111000,0B11111000,0B11111000,0B11111000};
  int count=10;
  
 
  for(int i=0;i<5;i++){
    for(int n=0;n<5;n++){
      index[i]=index[i]>>n;
       for(int t=0;t<count;t++){
        for(int k=0;k<5;k++){
            digitalWrite(latch_pin, LOW);
            
            shiftOut(data_pin, clock_pin,LSBFIRST, ~index[4]);
            shiftOut(data_pin, clock_pin,LSBFIRST, ~index[3]);
            shiftOut(data_pin, clock_pin,LSBFIRST, ~index[2]);
            shiftOut(data_pin, clock_pin,LSBFIRST, ~index[1]);
            shiftOut(data_pin, clock_pin,LSBFIRST, ~index[0]);
            shiftOut(data_pin, clock_pin,MSBFIRST, row[k]);
          
            digitalWrite(latch_pin, HIGH);
            delay(1);
        }
      }
    }
  }

 for(int i=0;i<5;i++){
  index[i]=0B00000000;
 }

  for(int i=4;i>=0;i--){
    for(int n=0;n<5;n++){
     bitWrite(index[i],n+3,1);
       for(int t=0;t<count;t++){
        for(int k=0;k<5;k++){
            digitalWrite(latch_pin, LOW);
            
            shiftOut(data_pin, clock_pin,LSBFIRST, ~index[4]);
            shiftOut(data_pin, clock_pin,LSBFIRST, ~index[3]);
            shiftOut(data_pin, clock_pin,LSBFIRST, ~index[2]);
            shiftOut(data_pin, clock_pin,LSBFIRST, ~index[1]);
            shiftOut(data_pin, clock_pin,LSBFIRST, ~index[0]);
            shiftOut(data_pin, clock_pin,MSBFIRST, row[k]);
          
            digitalWrite(latch_pin, HIGH);
            delay(1);
        }
      }
    }
  }
}
