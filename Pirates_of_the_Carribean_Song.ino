#include <LiquidCrystal.h> //screen setup
LiquidCrystal lcd(8, 7, 6, 5, 4, 3); //screen ports

const int speakerPin = 2;
const int tempo = 240; //bpm, roughly, may change or may have multiple, 

const int red = 9; //red port
const int green = 10; //green port
const int blue = 11; //blue port

//char songNotes [] = {'g', 'a', 'c', 'a', 'e', 'e', 'd', //if using character songNotes list, it can only be a character, G# (gsharp), Bb (bflat)
                     //'g', 'a', 'c', 'a', 'd', 'd', 'c', 
                     //'g', 'a', 'c', 'a', 'c', 'd', ' ', 'a', 'g', ' ', 'g', 'd', 'c'}; //array or list of character values, array - data structure that stores multiple values

String stringSongNotes[] = {"A", "C", "D", "D", "D", "E", "F", "F", 
                            "F", "G", "E", "E", "D", "C", "C", "D",
                            "A", "C", "D", "D", "D", "E", "F", "F",
                            "F", "G", "E", "E", "D", "C", "D",
                            "A", "C", "D", "D", "D", "F", "G", "G",  
                            "G", "A", "A#", "A#", "A", "G", "A", "D", 
                            "D", "E", "F", "F", "G", "A", "D", 
                            "D", "F", "E", "E", "F", "D", "E"};
                            //"h", "j", "l", "l", "l", "m", "n", "n", 
                            //"n", "o", "m"};//"h"}; //"l", "k", "k", "l",
                            //"h", "j", "k", "k", "k", "m", "n", "n"};
                          

int beats[] = {16, 16, 8, 8, 16, 16, 8, 8, //beats and tempo correlate, beats determine length of time a not plays, if you want a decimal it can't be an integer
               16, 16, 8, 8, 16, 16, 8, 8, 
               16, 16, 8, 8, 16, 16, 8, 8,
               16, 16, 8, 8, 16, 16, 4,
               16, 16, 8, 8, 16, 16, 8, 8,
               16, 16, 8, 8, 16, 16, 8, 8, 
               16, 16, 8, 8, 16, 16, 4,
               16, 16, 8, 8, 16, 16, 4,};
               //16, 16, 8, 8, 16, 16, 8, 8,
               //16, 16, 8}; //16, 16, 8, 8,
               //16, 16, 8, 8, 16, 16, 8, 8};

//float halfBeats[] = {5, .5, 6.7};

String lyrics[] = {"A", "C", "D", "D", "D", "E", "F", "F", 
                            "F", "G", "E", "E", "D", "C", "C", "D",
                            "A", "C", "D", "D", "D", "E", "F", "F",
                            "F", "G", "E", "E", "D", "C", "D",
                            "A", "C", "D", "D", "D", "F", "G", "G",  
                            "G", "A", "A#", "A#", "A", "G", "A", "D", 
                            "D", "E", "F", "F", "G", "A", "D", 
                            "D", "F", "E", "E", "F", "D", "E"};
                            //"h", "j", "l", "l", "l", "m", "n", "n", 
                            //"n", "o", "m"};//"h"}; //"l", "k", "k", "l",
                            //"h", "j", "k", "k", "k", "m", "n", "n"};


int colors [] = {9, 10, 11, 9, 10, 11, 9, 10,
                11, 9, 10, 11, 9, 10, 11, 9,
                10, 11, 9, 10, 11, 9, 10, 11, 
                9, 10, 11, 9, 10, 11, 9,
                10, 11, 9, 10, 11, 9, 10, 11, 
                9, 10, 11, 9, 10, 11, 9, 10, 
                11, 9, 10, 11, 9, 10, 11, 
                9, 10, 11, 9, 10, 11, 9};
                          
void setup() {
Serial.begin(9600);
lcd.begin(16,2);
pinMode(speakerPin, OUTPUT);
pinMode(red, OUTPUT);
pinMode(green, OUTPUT);
pinMode(blue, OUTPUT);
}

void loop() {
 for(int i = 0; i < 61; i++ ){ //songnotes is length of notes given, maybe change to i > 35 notes for example, number of notes, everytime we wrk through the for loop, i changes
   int duration = 1500/beats[i]; //cannot int if using float values for your beat

   int frequency = getFrequency(stringSongNotes[i]); 
   int color = colors[i];
   digitalWrite(red, LOW);
   digitalWrite(blue, LOW);
   digitalWrite(green, LOW);
   digitalWrite(color, HIGH);

   if(frequency > 0){
     tone(speakerPin, frequency, duration);
    
   }
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(lyrics[i]);
    delay(20);
     delay(duration * 1.1);
     noTone(speakerPin);


  }
 delay(2000);
}

int getFrequency(String note){ 
  if (note == "A") return 220;
  if (note == "A#") return 233;
  if (note == "B") return 247;
  if (note == "C") return 262;
  if (note == "D") return 294;
  if (note == "E") return 330;
  if (note == "F") return 349;
  if (note == "G") return 392; 
  if (note == "h") return 440; //works
  if (note == "i") return 466;
  if (note == "j") return 494; //works
  if (note == "k") return 523;
  if (note == "l") return 587; //works (fix value)
  if (note == "m") return 659; //works
  if (note == "n") return 784; //works
  if (note == "o") return 698; //works
  return 0; //must have a return statement, once it returns any value, the function's call ends, function can only return one time
}
//defining a function that returns an integer, non-void function, with char note as a parameter (input that our function accepts)