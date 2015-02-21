int pin = 7;

//  Example song
int songLength = 3;
int notes[] = {440, 659, 440};
float durations[] = {1.0, 5.0, 1.0};
int bpm = 180;

// Example midi song
//  define lengthOfMidi 3
int lengthOfMidi = 3;
int midi[] = {50, 60, 70};
int hertz[] = {0, 0, 0};

// RICK ROLL
int lengthOfRickRoll = 27;
int midiRick[] = {65, 67, 70, 67, 74, 74, 72, 65, 67, 70, 67, 72, 72, 70, 69, 67, 65, 67, 70, 67, 70, 72, 69, 65, 65, 72, 70};
float durationsRick[] = {0.25, 0.25, 0.25, 0.25, 0.75, 0.75, 1.5, 0.25, 0.25, 0.25, 0.25, 0.75, 0.75, 0.75, 0.25, 0.5, 0.25, 0.25, 0.25, 0.25, 1.0, 0.5, 0.75, 0.25, 1.0, 0.5, 1.0, 2.0};
int bpmRick = 120;
//  Empty hertz for Rick Rolling.
int hertzRick[27] = {};

void playSong(int notes[], float durations[], int bpm, int songLength) {
 //  It's gonna take an array of notes, an array of durations, 
 //  and a beatsPerminute.
 
 //  notes[] means just a pointer to notes, it has no idea what's in notes.
 
 float bps = (60.0 / bpm) * 1000.0; // Beats per second in milliseconds for arduino
 
 Serial.begin(9600);
 
 for (int i = 0; i < songLength; i ++) {
   tone(pin, notes[i], (long) (durations[i] * bps) - 10); //  Tone takes a pin number, an int note, and a long duration.
   //  The 10 seconds is so consecutive same notes are distinguishable.
   
   delay((long) (durations[i] * bps)); //  DELAY OR THIS DOESN'T WORK! Tone is asynchronous- it has effects while the program is running
   //  even if tone() already returned a value. You gotta leave it time to finish having those effects - i.e. a tone length.
 }
}

void midiToHertz(int midi[], int hertz[], int lengthOfMidi) {
  for (int i = 0; i < lengthOfMidi; i ++) {
    //  To convert midi to hertz equation: hertz = (2^(midi - 69)/12) * 440
    hertz[i] = (int) (pow(2.0, ((midi[i] - 69.0) / 12.0)) * 440);
  }
  
  for (int i = 0; i < lengthOfMidi; i ++) {
    Serial.println(hertz[i]);
  }
}

void setup() {
  pinMode(pin, OUTPUT);
}

void loop() {
  midiToHertz(midiRick, hertzRick, lengthOfRickRoll);
  playSong(hertzRick, durationsRick, bpmRick, lengthOfRickRoll);
}
