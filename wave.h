void wave(){
   unsigned int index_first[5][5]={
   {0B00000000,0B00000000,0B00000000,0B00000000,0B00000000},
   {0B00000000,0B00000000,0B00000000,0B11111000,0B00000000},
   {0B11111000,0B00000000,0B11111000,0B00000000,0B11111000},
   {0B00000000,0B11111000,0B00000000,0B00000000,0B00000000},
   {0B00000000,0B00000000,0B00000000,0B00000000,0B00000000},
  };

  unsigned index[5][5];
  
  for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
        index[i][j]=index_first[i][j];
      }
    }
    
  for(int n=0;n<=3;n++){
    
    for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
        if(j==4){
          index[i][j]=index[i][0];
        }else{
          index[i][j]=index[i][j+1];
        }
      }
    }
    
    for(int t=0;t<19;t++){
    for(int k=0;k<5;k++){
        digitalWrite(latch_pin, LOW);
        
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(index[k][4]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(index[k][3]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(index[k][2]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(index[k][1]));
        shiftOut(data_pin, clock_pin,LSBFIRST, ~(index[k][0]));
        shiftOut(data_pin, clock_pin,MSBFIRST, row[k]);
      
        digitalWrite(latch_pin, HIGH);
        delay(1);
    
  }
  }
  }
  
 
}
