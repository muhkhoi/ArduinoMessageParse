int buf_data[30];
int flag = 0;
int ccc = 0;
int mode;
int data1, data2, data3;
char cData1[4],cData2[4],cData3[4];

void setup() {
  Serial.begin(9600);
  char c;
}

void loop() {

  //Contoh Format : #123,456,789!
  //Sehingga Data1:123, Data2:456, Data3, 789
  
  if (Serial.available())
  {
    char baca = Serial.read();
    if (baca == '#')  
    {
      flag = 1;
      ccc = 0;
    }
    else
    {
      ccc++;
      buf_data[ccc] = baca;
      if (flag == 1 && baca == '!')
      {

        cData1[0] = buf_data[1];      //Array Data1 ke 1,2,3
        cData1[1] = buf_data[2];
        cData1[2] = buf_data[3];
                                      //Array Char ke 5 "Koma"
        cData2[0] = buf_data[5];      //Array Data2 ke 1,2,3
        cData2[1] = buf_data[6];
        cData2[2] = buf_data[7];
                                      //Array Char ke 8 "Koma"
        cData3[0] = buf_data[9];      //Array Data2 ke 1,2,3
        cData3[1] = buf_data[10];
        cData3[2] = buf_data[11];


        flag = 0; ccc = 0;

        data1 = atoi(cData1);
        data2 = atoi(cData2);
        data3 = atoi(cData3);
      }


    }

  }

  Serial.print("Data 1 :");
  Serial.println(data1);
  Serial.print("Data 2 :");
  Serial.println(data2);
  Serial.print("Data 3 :");
  Serial.println(data3);
  
}
