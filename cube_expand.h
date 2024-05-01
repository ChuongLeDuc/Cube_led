void cube_expand(){
  unsigned char index[5][5]={
    {0B00000000,0B00000000,0B00000000,0B00000000,0B00000000},
    {0B00000000,0B00000000,0B00000000,0B00000000,0B00000000},
    {0B00000000,0B00000000,0B00000000,0B00000000,0B00000000},
    {0B00000000,0B00000000,0B00000000,0B00000000,0B00000000},
    {0B00000000,0B00000000,0B00000000,0B00000000,0B00000000},
  };

  int count=10;
  
  for(int y=1;y<=3;y++){
    switch(y){
      case 1:
        index[2][2]=0B00100000;
        break;
      case 2:
        index[1][1]=0B01110000;
        index[1][2]=0B01110000;
        index[1][3]=0B01110000;

        index[2][1]=0B01110000;
        index[2][3]=0B01110000;

        index[3][1]=0B01110000;
        index[3][2]=0B01110000;
        index[3][3]=0B01110000;

        break;

      default:
        for(int i=0;i<5;i++){
          for(int j=0;j<5;j++){
            index[i][j]=0B11111000;
          }
        }
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
  
 for(int y=3;y>=1;y--){
    switch(y){
      case 1:
        index[2][2]=0B00000000;
        break;
      case 2:
        for(int i=0;i<5;i++){
          for(int j=0;j<5;j++){
            index[i][j]=0B00000000;
          }
        }
        index[2][2]=0B00100000;

      break;

      default:
      for(int e=0;e<5;e++){
        index[0][e]=0B00000000;
        index[4][e]=0B00000000;
        index[e][0]=0B00000000;
        index[e][4]=0B00000000;

        for(int f=1;f<4;f++){
          index[e][f]=0B01110000;
        }
     } 
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
