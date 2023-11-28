int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
int An0 = 9;
int An1 = 10;
int p = 11;
char A , B , C , D ; 
int C1 = 0, C2 = 0;
String apuntadorMemoria="";
int apuntadorMemoriaNum=-1;
String res = "";
char nums [2][2];
double memory[4]={0.0,0.0,0.0,0.0};
bool guarda=false;


void setup()
{
    
    pinMode(a, OUTPUT);
    pinMode(b, OUTPUT);
    pinMode(c, OUTPUT);
    pinMode(d, OUTPUT);
    pinMode(e, OUTPUT);
    pinMode(f, OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(An0, OUTPUT);
    pinMode(p, OUTPUT);
    pinMode(An1, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
  //sintaxys de entrada = <Operacion>: D1D2,D3D4
  if (Serial.available()) {
    String s = Serial.readStringUntil('\n');
    s.trim();
    res ="";
    if(s.charAt(0)=='m'){
      String registro = s.substring(8);
      if(registro =="G1"){Serial.print("Registro G1:");Serial.println(memory[0]);}
      if(registro =="G2"){Serial.print("Registro G2:");Serial.println(memory[1]);}
      if(registro =="G3"){Serial.print("Registro G3:");Serial.println(memory[2]);}
      if(registro =="G4"){Serial.print("Registro G4:");Serial.println(memory[3]);}

    }else{
      for (int i = 0; i < s.length(); i++) {
        if(s.charAt(i)==' '){
        
          String a = s.substring(i+1);
          int igual = a.indexOf('=');
          if(igual<0){
            getNumbers(a);
            apuntadorMemoria="";
            apuntadorMemoriaNum=-1;
            guarda=false;

          }else if(a.substring(0,igual).indexOf('G')<0){

            getNumbers(a.substring(0,igual));
            apuntadorMemoria=a.substring(a.length()-2);
            //Serial.print(apuntadorMemoria);
            if(apuntadorMemoria=="G1"){apuntadorMemoriaNum=0;}
            else if(apuntadorMemoria=="G2"){apuntadorMemoriaNum=1;}
            else if(apuntadorMemoria=="G3"){apuntadorMemoriaNum=2;}
            else if(apuntadorMemoria=="G4"){apuntadorMemoriaNum=3;}

            guarda=true;
          }else if(a.substring(0,igual).indexOf('G')>-1){
            Serial.println("ENTRA");
            double numEsp1=0.0;
            double numEsp2=0.0;
            String SnumEsp1 =  a.substring(0,2);
            String SnumEsp2 =  a.substring(3,5);
            Serial.println(SnumEsp2);
            if(SnumEsp1[0] != 'G'){
              numEsp1 = binarioToDouble(SnumEsp1);
            }else{
              numEsp1=memory[getApuntador(SnumEsp1)];
            }
            if(SnumEsp2[0] != 'G'){
              numEsp2 = binarioToDouble(SnumEsp2);
            }else{
              numEsp2=memory[getApuntador(SnumEsp2)];
            }
            Serial.println(numEsp1);
            Serial.println(numEsp2);

            String operacion = s.substring(0,i);
            if(operacion.equals("suma")){
              Serial.print("suma: ");Serial.println(numEsp1+numEsp2);
            }
            if(operacion.equals("resta")){
              Serial.print("resta: ");Serial.println(numEsp1-numEsp2);
            }
            if(operacion.equals("multiplicacion")){
              Serial.print("multiplicacion: ");Serial.println(numEsp1*numEsp2);
            }
            if(operacion.equals("division")){
              Serial.print("division: ");Serial.println(numEsp1/numEsp2);
            }


          }
          
          res = s.substring(0,i);
        }
      }
    }

    
    //Serial.println(res);


  	if(nums[0][0] == '0' && nums[0][1] == '0'){
      C1 = 0;
      
    }
    if(nums[0][0] == '0' && nums[0][1] == '1'){
      C1 = 1;
      
    }
    if(nums[0][0] == '1' && nums[0][1] == '0'){
      C1 = 2;
      
    }
    if(nums[0][0] == '1' && nums[0][1] == '1'){
      C1 = 3;
      
    }

    if(nums[1][0] == '0' && nums[1][1] == '0'){
      C2 = 0;
      
    }
    if(nums[1][0] == '0' && nums[1][1] == '1'){
      C2 = 1;
      
    }
    if(nums[1][0] == '1' && nums[1][1] == '0'){
      C2 = 2;
      
    }
    if(nums[1][0] == '1' && nums[1][1] == '1'){
      C2 = 3;
      
    }

    

  
  
  }
  if(res=="suma"){
    if(apuntadorMemoria!=""){
      memory[apuntadorMemoriaNum]=C1+C2;
    }
    /*Serial.println("Resultado:");
    Serial.println(C1+C2);*/
    Sal(C1+C2); 

  }else
  if(res=="resta"){
    if(apuntadorMemoria!=""){
      memory[apuntadorMemoriaNum]=C1-C2;
    }
    //Serial.println("Resultado:");
    Sal(C1-C2);
  }else
  if(res=="multiplicacion"){
    if(apuntadorMemoria!=""){
      memory[apuntadorMemoriaNum]=C1*C2;
    }
    //Serial.println("Resultado:");
    Sal(C1*C2);
  }else
  if(res=="division"){
    if(apuntadorMemoria!=""){
      memory[apuntadorMemoriaNum]=C1/C2;
    }
    //Serial.println("Resultado:");
    if(C1 == 0 && C2 == 0){
      Sal(333);
    }else if(C2 == 0){
      Sal(111);
    }else if(C1 == 1 && C2 == 3){
      Sal(33);
    }else if(C1 == 1 && C2 == 2){
      Sal(50);
    }else if(C1 == 2 && C2 == 3){
      Sal(66);
    }else if(C1 == 3 && C2 == 2){
      Sal(105);
    }
    else{
      Sal( (int) C1/C2 );  
    }
  }else
  if(res=="and"){
    //Serial.println("Resultado:");
    if(A == '1'&& C == '1' && B == '1' && D == '1'){
      Sal(3);
    }else if(A == '1' && C == '1'){
      Sal(2);
    }else if(B == '1' && D == '1'){
      Sal(1);
    }else{
      Sal(0);
    }
  }else
  if(res=="or"){
    //Serial.println("Resultado:");
    if((A == '1' || C == '1') && (B == '1' || D == '1')){
      Sal(3);
    }else
    if(A == '1' || C == '1'){
      Sal(2);
    }else
    if(B == '1' || D == '1'){
      Sal(1);
    }else{
      Sal(0);
    }
  }else
  if(res=="xor"){
    //Serial.println("Resultado:");
    if(A == '1' ^ C == '1' && B == '1' ^ D == '1'){
      Sal(3);
    }else
    if(A == '1' ^ C == '1'){
      Sal(2);
    }else
    if(B == '1' ^ D == '1'){
      Sal(1);
    }else{
      Sal(0);
    }
    	
  }


}




void Sal (int n){
  switch(n){
    case -3:
      //Serial.println("-3");
      digitalWrite(An1, 1);
      digitalWrite(a, 0);
      digitalWrite(b, 0);
      digitalWrite(c, 0);
      digitalWrite(d, 0);
      digitalWrite(e, 0);
      digitalWrite(f, 0);
      digitalWrite(g, 1);
      digitalWrite(p, 0);
      digitalWrite(An0, 0);
      delay(10);

      digitalWrite(An0, 1);
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 0);
      digitalWrite(f, 0);
      digitalWrite(g, 1);
      digitalWrite(An1, 0);
      delay(10);
      
    break;
    case -2:
      //Serial.println("-2");
      digitalWrite(An1, 1);
      digitalWrite(a, 0);
      digitalWrite(b, 0);
      digitalWrite(c, 0);
      digitalWrite(d, 0);
      digitalWrite(e, 0);
      digitalWrite(f, 0);
      digitalWrite(g, 1);
      digitalWrite(p, 0);
      digitalWrite(An0, 0);
      delay(10);
      

      digitalWrite(An0, 1);
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 0);
      digitalWrite(d, 1);
      digitalWrite(e, 1);
      digitalWrite(f, 0);
      digitalWrite(g, 1);
      digitalWrite(An1, 0);
      delay(10);
      
      
    break;
    case -1:
      //Serial.println("-1");
      digitalWrite(An1, 1);
      digitalWrite(a, 0);
      digitalWrite(b, 0);
      digitalWrite(c, 0);
      digitalWrite(d, 0);
      digitalWrite(e, 0);
      digitalWrite(f, 0);
      digitalWrite(g, 1);
      digitalWrite(p, 0);
      digitalWrite(An0, 0);
      delay(10);
      

      digitalWrite(An0, 1);
      digitalWrite(a, 0);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 0);
      digitalWrite(e, 0);
      digitalWrite(f, 0);
      digitalWrite(g, 0);
      digitalWrite(p, 1);
      digitalWrite(An1, 0);
      delay(10);
      
      
    break;
    case 0:
      //Serial.println("0");
      digitalWrite(An1, 1);
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 1);
      digitalWrite(f, 1);
      digitalWrite(g, 0);
      digitalWrite(p, 1);
      digitalWrite(An0, 0);
      delay(10);
      
      
      digitalWrite(An0, 1);
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 1);
      digitalWrite(f, 1);
      digitalWrite(g, 0);
      digitalWrite(An1, 0);
      delay(10);
      

    break;
    case 33:
      //Serial.println("0.3");
      digitalWrite(An1, 1);
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 1);
      digitalWrite(f, 1);
      digitalWrite(g, 0);
      digitalWrite(p, 1);
      digitalWrite(An0, 0);
      delay(10);
      
      
      digitalWrite(An0, 1);
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 0);
      digitalWrite(f, 0);
      digitalWrite(g, 1);
      digitalWrite(An1, 0);
      delay(10);
      
    break;
    case 50:
      //Serial.println("0.5");
      digitalWrite(An1, 1);
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 1);
      digitalWrite(f, 1);
      digitalWrite(g, 0);
      digitalWrite(p, 1);
      digitalWrite(An0, 0);
      delay(10);

      
      digitalWrite(An0, 1);
      digitalWrite(a, 1);
      digitalWrite(b, 0);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 0);
      digitalWrite(f, 1);
      digitalWrite(g, 1);
      digitalWrite(An1, 0);
      delay(10);

    break;
    case 66:
      //Serial.println("0.6");
      digitalWrite(An1, 1);
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 1);
      digitalWrite(f, 1);
      digitalWrite(g, 0);
      digitalWrite(p, 1);
      digitalWrite(An0, 0);
      delay(10);
      
      digitalWrite(An0, 1);
      digitalWrite(a, 1);
      digitalWrite(b, 0);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 1);
      digitalWrite(f, 1);
      digitalWrite(g, 1);
      digitalWrite(An1, 0);
      delay(10);
    break;
    case 1:
      //Serial.println("1");
      
      digitalWrite(An1, 1);
      digitalWrite(a, 0);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 0);
      digitalWrite(e, 0);
      digitalWrite(f, 0);
      digitalWrite(g, 0);
      digitalWrite(p, 1);
      digitalWrite(An0, 0);
      delay(10);

      digitalWrite(An0, 1);
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 1);
      digitalWrite(f, 1);
      digitalWrite(g, 0);
      digitalWrite(An1, 0);
      delay(10);
      

    break;
    case 105:
    //Serial.println("1.5");
      
      digitalWrite(An1, 1);
      digitalWrite(a, 0);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 0);
      digitalWrite(e, 0);
      digitalWrite(f, 0);
      digitalWrite(g, 0);
      digitalWrite(p, 1);
      digitalWrite(An0, 0);
      delay(10);
    
      digitalWrite(An0, 1);
      digitalWrite(a, 1);
      digitalWrite(b, 0);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 0);
      digitalWrite(f, 1);
      digitalWrite(g, 1);
      digitalWrite(An1, 0);
      delay(10);
    break;
    case 2:
      //Serial.println("2");
      digitalWrite(An1, 1);
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 0);
      digitalWrite(d, 1);
      digitalWrite(e, 1);
      digitalWrite(f, 0);
      digitalWrite(g, 1);
      digitalWrite(p, 1);
      digitalWrite(An0, 0);
      delay(10);
      

      digitalWrite(An0, 1);
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 1);
      digitalWrite(f, 1);
      digitalWrite(g, 0);
      digitalWrite(An1, 0);
      delay(10);
      
    break;
    case 3:
      //Serial.println("3");
      digitalWrite(An1, 1);
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 0);
      digitalWrite(f, 0);
      digitalWrite(g, 1);
      digitalWrite(p, 1);
      digitalWrite(An0, 0);
      delay(10);


      digitalWrite(An0, 1);
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 1);
      digitalWrite(f, 1);
      digitalWrite(g, 0);
      digitalWrite(An1, 0);
      delay(10);

    break;
    case 4:
      //Serial.println("4");
      digitalWrite(An1, 1);
      digitalWrite(a, 0);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 0);
      digitalWrite(e, 0);
      digitalWrite(f, 1);
      digitalWrite(g, 1);
      digitalWrite(p, 1);
      digitalWrite(An0, 0);
      delay(10);

      digitalWrite(An0, 1);
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 1);
      digitalWrite(f, 1);
      digitalWrite(g, 0);
      digitalWrite(An1, 0);
      delay(10);
      
    break;
    case 5:
      //Serial.println("5");
      digitalWrite(An1, 1);
      digitalWrite(a, 1);
      digitalWrite(b, 0);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 0);
      digitalWrite(f, 1);
      digitalWrite(g, 1);
      digitalWrite(p, 1);
      digitalWrite(An0, 0);
      delay(10);
      

      digitalWrite(An0, 1);
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 1);
      digitalWrite(f, 1);
      digitalWrite(g, 0);
      digitalWrite(An1, 0);
      delay(10);
      
    break;
    case 6:
      //Serial.println("6");
      digitalWrite(An1, 1);
      digitalWrite(a, 1);
      digitalWrite(b, 0);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 1);
      digitalWrite(f, 1);
      digitalWrite(g, 1);
      digitalWrite(p, 1);
      digitalWrite(An0, 0);
      delay(10);

      digitalWrite(An0, 1);
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 1);
      digitalWrite(f, 1);
      digitalWrite(g, 0);
      digitalWrite(An1, 0);
      delay(10);
      
    break;
    case 7:
      //Serial.println("7");
      digitalWrite(An1, 1);
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 0);
      digitalWrite(e, 0);
      digitalWrite(f, 0);
      digitalWrite(g, 0);
      digitalWrite(p, 1);
      digitalWrite(An0, 0);
      delay(10);
      

      digitalWrite(An0, 1);
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 1);
      digitalWrite(f, 1);
      digitalWrite(g, 0);
      digitalWrite(An1, 0);
      delay(10);
      
    break;
    case 8:
      //Serial.println("8");
      digitalWrite(An1, 1);
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 1);
      digitalWrite(f, 1);
      digitalWrite(g, 1);
      digitalWrite(p, 1);
      digitalWrite(An0, 0);
      delay(10);
      

      digitalWrite(An0, 1);
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 1);
      digitalWrite(f, 1);
      digitalWrite(g, 0);
      digitalWrite(An1, 0);
      delay(10);
      
    break;
    case 9:
      //Serial.println("9");
      digitalWrite(An1, 1);
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 0);
      digitalWrite(e, 0);
      digitalWrite(f, 1);
      digitalWrite(g, 1);
      digitalWrite(p, 1);
      digitalWrite(An0, 0);
      delay(10);
      

      digitalWrite(An0, 1);
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 1);
      digitalWrite(f, 1);
      digitalWrite(g, 0);
      digitalWrite(An1, 0);
      delay(10);
      
    break;
    
    break;
    case 111:
      //Serial.println("Infinito");
      digitalWrite(p,0);
      digitalWrite(An0, 0);
      digitalWrite(An1, 0);
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 0);
      digitalWrite(d, 0);
      digitalWrite(e, 0);
      digitalWrite(f, 1);
      digitalWrite(g, 1);
    delay(10);
    break;
    case 333:
      //Serial.println("Er");
      digitalWrite(p,0);
      
      digitalWrite(An1, 1); 
      

      digitalWrite(a, 1);
      digitalWrite(b, 0);
      digitalWrite(c, 0);
      digitalWrite(d, 1);
      digitalWrite(e, 1);
      digitalWrite(f, 1);
      digitalWrite(g, 1);
      digitalWrite(An0, 0);
      delay(10);
      

      digitalWrite(An0, 1);
      
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 0);
      digitalWrite(d, 0);
      digitalWrite(e, 1);
      digitalWrite(f, 1);
      digitalWrite(g, 0);
      digitalWrite(An1, 0);
      delay(10);
      
    break;
    case 355:
      digitalWrite(An0, 1);
      digitalWrite(An1, 1);
      digitalWrite(a, 0);
      digitalWrite(b, 0);
      digitalWrite(c, 0);
      digitalWrite(d, 0);
      digitalWrite(e, 0);
      digitalWrite(f, 0);
      digitalWrite(g, 0);
      //Serial.println("Nada");
    break;
    default:
      //Serial.println("error");
      //Serial.println(n);
      digitalWrite(An0, 0);
      digitalWrite(An1, 0);
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 1);
      digitalWrite(f, 1);
      digitalWrite(g, 1);
      digitalWrite(p, 1);

      delay(1000);
      
      digitalWrite(An0, 1);
      digitalWrite(An1, 1);

      delay(500);
      
    break;
  }
}

int getApuntador(String cadena ){
  if(cadena=="G1"){
    return 0;
  }
  if(cadena=="G2"){
    return 1;
  }
  if(cadena=="G3"){
    return 2;
  }
  if(cadena=="G4"){
    return 3;
  }

}
double binarioToDouble(String binario) {
  double resultado = 0.0;

  for (int i = 0; i < binario.length(); i++) {
    char digito = binario.charAt(i);

    if (digito == '1') {
      resultado = resultado * 2 + 1;
    } else if (digito == '0') {
      resultado = resultado * 2;
    } else {
      // Manejar un carácter no válido (opcional)
      Serial.println("Error: La cadena contiene caracteres no binarios.");
      return 0.0;
    }
  }

  return resultado;
}
void getNumbers(String cadena){
  //Serial.println(cadena);
  int salto =0;
  int apuntador =0;
  for(int i = 0; i < cadena.length(); i++){
    if(cadena.charAt(i)!= ','){
      nums[salto][apuntador]=cadena.charAt(i);
      apuntador++;
    }else{
      salto++;
      apuntador=0;
    }
  }
}