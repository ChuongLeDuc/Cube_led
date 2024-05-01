void mini_cube(){
  unsigned char index[5][5]={
    {0B11000000,0B11000000,0B00000000,0B00011000,0B00011000},
    {0B11000000,0B11000000,0B00000000,0B00011000,0B00011000},
    {0B00000000,0B00000000,0B00000000,0B00000000,0B00000000},
    {0B00011000,0B00011000,0B00000000,0B11000000,0B11000000},
    {0B00011000,0B00011000,0B00000000,0B11000000,0B11000000},
  };
  
 int count=15;
 
 for(int g=0;g<=1;g++){
  for(int n=0;n<=3;n++){
    if(n!=0){
      for(int i=0;i<5;i++){
        if(i==2){
          continue;
        }else{
          if(g==0){
            if(i==0|| i==1 ){
              index[i][0]=index[i][0]>>1;
              index[i][1]=index[i][1]>>1;
      
              index[i][3]=index[i][3]<<1;
              index[i][4]=index[i][4]<<1;
            }else{
              index[i][0]=index[i][0]<<1;
              index[i][1]=index[i][1]<<1;
      
              index[i][3]=index[i][3]>>1;
              index[i][4]=index[i][4]>>1;
            }
          }else{
             if(i==0|| i==1 ){
              index[i][0]=index[i][0]<<1;
              index[i][1]=index[i][1]<<1;
      
              index[i][3]=index[i][3]>>1;
              index[i][4]=index[i][4]>>1;
            }else{
              index[i][0]=index[i][0]>>1;
              index[i][1]=index[i][1]>>1;
    
              index[i][3]=index[i][3]<<1;
              index[i][4]=index[i][4]<<1;
            }
          }
        }
      }
    }
    for(int t=0;t<count;t++){
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
 }
