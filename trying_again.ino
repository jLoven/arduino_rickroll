
int pin = 7;
int songLength = 3;
int notes[] = {440, 659, 440};
float durations[] = {1.0, 5.0, 1.0};
int bpm = 180;

void playSong(int notes[], float durations[], int bpm, int songLength) {
 //  It's gonna take an array of notes, an array of durations, 
 //  and a beatsPerminute.
 
 //  notes[] means just a pointer to notes, it has no idea what's in notes.
 
 float bps = (60.0 / bpm) * 1000.0; // Beats per second in milliseconds for arduino
 
 Serial.begin(9600);
 
 for (int i = 0; i < songLength; i ++) {
   tone(pin, notes[i], (long) (durations[i] * bps) - 10);
   delay((long) (durations[i] * bps));
   Serial.print("note: ");
   Serial.print(notes[i]);
   Serial.print("duration: ");
   Serial.println(durations[i] * bps - 10);
   //  Play each note for this long, buffer of 10 to distinguish notes
 }
}

void setup() {
  pinMode(pin, OUTPUT);
}

void loop() {
  playSong(notes, durations, bpm, songLength);
}
