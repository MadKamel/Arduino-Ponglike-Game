// Code written by MadKamel, crystal oscillator personified. Hello!
int AUDIO = 13;		// pin for speaker
int L0 = 11;		// Lights 0 through 7
int L1 = 10;
int L2 = 9;
int L3 = 8;
int L4 = 7;
int L5 = 6;
int L6 = 5;
int L7 = 4;

int gamespeed = 75;

void setup() {
	pinMode(AUDIO, OUTPUT);
	pinMode(L0, OUTPUT);
	pinMode(L1, OUTPUT);
	pinMode(L2, OUTPUT);
	pinMode(L3, OUTPUT);
	pinMode(L4, OUTPUT);
	pinMode(L5, OUTPUT);
	pinMode(L6, OUTPUT);
	pinMode(L7, OUTPUT);
	beep_audio(AUDIO, 4);
	beep_audio(AUDIO, 3);
	beep_audio(AUDIO, 2);
	beep_audio(AUDIO, 1);
	beep_audio(AUDIO, 8);
	beep_audio(AUDIO, 5);
	beep_audio(AUDIO, 1);
}

void flash_light(int pin, int duration) {
	digitalWrite(pin, HIGH);
	delay(duration);
	digitalWrite(pin, LOW);
}

void beep_audio(int pin, int speed) {
	int length = 64/speed;
	while(length > 0) {
		digitalWrite(pin, HIGH);
		delay(speed);
		digitalWrite(pin, LOW);
		delay(speed);
		length = length - 1;
	}
}

void blip_audio(int pin, int speed, int speedmod) {
	int length = speedmod/speed;
	while(length > 0) {
		digitalWrite(pin, HIGH);
		delay(speed);
		digitalWrite(pin, LOW);
		delay(speed);
		length = length - 1;
	}
}

void endgame() {
	digitalWrite(L0, HIGH);
	digitalWrite(L7, HIGH);
	digitalWrite(L1, LOW);
	digitalWrite(L2, LOW);
	digitalWrite(L3, LOW);
	digitalWrite(L4, LOW);
	digitalWrite(L5, LOW);
	digitalWrite(L6, LOW);
	beep_audio(AUDIO, 8);
	beep_audio(AUDIO, 6);
	beep_audio(AUDIO, 4);
	beep_audio(AUDIO, 2);
	beep_audio(AUDIO, 4);
	beep_audio(AUDIO, 2);
	delay(500);
	beep_audio(AUDIO, 4);
	beep_audio(AUDIO, 3);
	beep_audio(AUDIO, 2);
	beep_audio(AUDIO, 1);
	beep_audio(AUDIO, 8);
	beep_audio(AUDIO, 5);
	beep_audio(AUDIO, 1);
	digitalWrite(L0, LOW);
	digitalWrite(L1, LOW);
	digitalWrite(L2, LOW);
	digitalWrite(L3, LOW);
	digitalWrite(L4, LOW);
	digitalWrite(L5, LOW);
	digitalWrite(L6, LOW);
	digitalWrite(L7, LOW);
}

// mainloop function- flashes each LED, going back and forth.
void loop() {
	blip_audio(AUDIO, 1, 16);
	flash_light(L0, gamespeed);
	flash_light(L1, gamespeed);
	flash_light(L2, gamespeed);
	flash_light(L3, gamespeed);
	flash_light(L4, gamespeed);
	flash_light(L5, gamespeed);
	flash_light(L6, gamespeed);
	blip_audio(AUDIO, 1, 16);
	flash_light(L7, gamespeed);
	flash_light(L6, gamespeed);
	flash_light(L5, gamespeed);
	flash_light(L4, gamespeed);
	flash_light(L3, gamespeed);
	flash_light(L2, gamespeed);
	flash_light(L1, gamespeed);
	gamespeed = gamespeed - 1;
	if(gamespeed < 10) {
		endgame();
		gamespeed = 75;
	}
}
