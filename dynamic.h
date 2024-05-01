void dynamic(){
 unsigned char index[5][5]={
    {0B00000000,0B00000000,0B00000000,0B00000000,0B00000000},
    {0B00000000,0B00000000,0B00000000,0B00000000,0B00000000},
    {0B00000000,0B00000000,0B00000000,0B00000000,0B00000000},
    {0B00000000,0B00000000,0B00000000,0B00000000,0B00000000},
    {0B00000000,0B00000000,0B00000000,0B00000000,0B00000000},
    };

 int count=10;

 for(int i=0;i<5;i++){
  switch(i){
    case 0:
      index[i][2]=0B00100000;
    break;
      
    case 1:
      index[i][1]=0B01110000;
      index[i][2]=0B01110000;
      index[i][3]=0B01110000;
     break;
     
     case 2:
      index[i][1]=0B01110000;
      index[i][2]=0B01110000;
      index[i][3]=0B01110000;
     break;
     
     case 3:
      index[i][0]=0B11111000;
      index[i][1]=0B11111000;
      index[i][2]=0B11111000;
      index[i][3]=0B11111000;
      index[i][4]=0B11111000;
     break;
     
     default:
      index[i][0]=0B11111000;
      index[i][1]=0B11111000;
      index[i][2]=0B11111000;
      index[i][3]=0B11111000;
      index[i][4]=0B11111000;
     break;
  }
   
  for(int t=0;t<count;t++){
   for(int i=0;i<5;i++){
   
        digitalWrite(latch_pin, LOW);
        
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(index[i][4]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(index[i][3]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(index[i][2]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(index[i][1]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(index[i][0]));
        shiftOut(data_pin, clock_pin,MSBFIRST, row[i]);
      
        digitalWrite(latch_pin, HIGH);
        delay(1);
    }
  }
 }


 for(int i=4;i>=0;i--){
  switch(i){
    case 0:
      index[i][2]=0B00000000;
    break;
      
    case 1:
      index[i][1]=0B00000000;
      index[i][2]=0B00000000;
      index[i][3]=0B00000000;
     break;
     
     case 2:
      index[i][1]=0B00000000;
      index[i][2]=0B00000000;
      index[i][3]=0B00000000;
     break;
     
     case 3:
      index[i][0]=0B00000000;
      index[i][1]=0B00000000;
      index[i][2]=0B00000000;
      index[i][3]=0B00000000;
      index[i][4]=0B00000000;
     break;
     
     default:
      index[i][0]=0B00000000;
      index[i][1]=0B00000000;
      index[i][2]=0B00000000;
      index[i][3]=0B00000000;
      index[i][4]=0B00000000;
     break;
  }
   
  for(int t=0;t<count;t++){
   for(int i=0;i<5;i++){
   
        digitalWrite(latch_pin, LOW);
        
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(index[i][4]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(index[i][3]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(index[i][2]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(index[i][1]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(index[i][0]));
        shiftOut(data_pin, clock_pin,MSBFIRST, row[i]);
      
        digitalWrite(latch_pin, HIGH);
        delay(1);
    }
  }
 }
}
