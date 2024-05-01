void display_text(){
  unsigned int I[5][5]={
   {0B10000000,0B10000000,0B10000000,0B10000000,0B10000000},
   {0B00000000,0B00000000,0B10000000,0B00000000,0B00000000},
   {0B00000000,0B00000000,0B10000000,0B00000000,0B00000000},
   {0B00000000,0B00000000,0B10000000,0B00000000,0B00000000},
   {0B10000000,0B10000000,0B10000000,0B10000000,0B10000000},
  };

  unsigned int heart[5][5]={
   {0B00000000,0B10000000,0B00000000,0B10000000,0B00000000},
   {0B10000000,0B00000000,0B10000000,0B00000000,0B10000000},
   {0B10000000,0B00000000,0B00000000,0B00000000,0B10000000},
   {0B00000000,0B10000000,0B00000000,0B10000000,0B00000000},
   {0B00000000,0B00000000,0B10000000,0B00000000,0B00000000},
  };


  unsigned int U[5][5]={
   {0B10000000,0B00000000,0B00000000,0B00000000,0B10000000},
   {0B10000000,0B00000000,0B00000000,0B00000000,0B10000000},
   {0B10000000,0B00000000,0B00000000,0B00000000,0B10000000},
   {0B10000000,0B00000000,0B00000000,0B00000000,0B10000000},
   {0B00000000,0B10000000,0B10000000,0B10000000,0B00000000},
  };

  int count=10;
  
for(int character=1;character<=3;character++){
 for(int n=0;n<5;n++){
  for(int t=0;t<count;t++){
  switch(character){
    case 1:
      for(int k=0;k<5;k++){
        digitalWrite(latch_pin, LOW);
        
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(I[k][4]>>n));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(I[k][3]>>n));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(I[k][2]>>n));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(I[k][1]>>n));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(I[k][0]>>n));
        shiftOut(data_pin, clock_pin,MSBFIRST, row[k]);
      
        digitalWrite(latch_pin, HIGH);
        delay(1);
      }
    break;

    case 2:
       for(int k=0;k<5;k++){
        digitalWrite(latch_pin, LOW);
        
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(heart[k][4]>>n));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(heart[k][3]>>n));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(heart[k][2]>>n));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(heart[k][1]>>n));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(heart[k][0]>>n));
        shiftOut(data_pin, clock_pin,MSBFIRST, row[k]);
      
        digitalWrite(latch_pin, HIGH);
        delay(1);
      }
    break;

    default:
       for(int k=0;k<5;k++){
        digitalWrite(latch_pin, LOW);
        
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(U[k][4]>>n));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(U[k][3]>>n));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(U[k][2]>>n));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(U[k][1]>>n));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(U[k][0]>>n));
        shiftOut(data_pin, clock_pin,MSBFIRST, row[k]);
      
        digitalWrite(latch_pin, HIGH);
        delay(1);
      }
    };
   }
  }


for(int i=0;i<5;i++){
  for(int j=0;j<5;j++){
    I[i][j]=I[i][j]>>4;
    heart[i][j]=heart[i][j]>>4;
    U[i][j]=U[i][j]>>4;
   
  }
}



 for(int n=0;n<5;n++){
  for(int t=0;t<count;t++){
  switch(character){
    case 1:
      for(int k=0;k<5;k++){
        digitalWrite(latch_pin, LOW);
        
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(I[k][4]<<n));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(I[k][3]<<n));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(I[k][2]<<n));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(I[k][1]<<n));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(I[k][0]<<n));
        shiftOut(data_pin, clock_pin,MSBFIRST, row[k]);
      
        digitalWrite(latch_pin, HIGH);
        delay(1);
      }
    break;

    case 2:
       for(int k=0;k<5;k++){
        digitalWrite(latch_pin, LOW);
        
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(heart[k][4]<<n));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(heart[k][3]<<n));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(heart[k][2]<<n));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(heart[k][1]<<n));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(heart[k][0]<<n));
        shiftOut(data_pin, clock_pin,MSBFIRST, row[k]);
      
        digitalWrite(latch_pin, HIGH);
        delay(1);
      }
    break;

    default:
       for(int k=0;k<5;k++){
        digitalWrite(latch_pin, LOW);
        
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(U[k][4]<<n));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(U[k][3]<<n));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(U[k][2]<<n));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(U[k][1]<<n));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(U[k][0]<<n));
        shiftOut(data_pin, clock_pin,MSBFIRST, row[k]);
      
        digitalWrite(latch_pin, HIGH);
        delay(1);
      }
    
    
  };
   
   }
 }

 for(int i=0;i<5;i++){
  for(int j=0;j<5;j++){
    I[i][j]=I[i][j]<<4;
    heart[i][j]=heart[i][j]<<4;
    U[i][j]=U[i][j]<<4;
   
  }
}
}
}
