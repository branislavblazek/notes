// tv.h -- tøídy Tv a Remote
#ifndef TV_H_
#define TV_H_

class Tv
{
public:
	friend class Remote; // tøída Remote má pøístup k soukr. èástem Tv
	enum {Off, On};
	enum {MinVal,MaxVal = 20};
	enum {Antenna, Cable};
	enum {TV, VCR};

	Tv(int s = Off, int mc = 100) : state(s), volume(5),
		maxchannel(mc), channel(2), mode(Cable), input(TV) {}
	void onoff() {state = (state == On)? Off : On;}
	bool ison() const {return state == On;}
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() {mode = (mode == Antenna)? Cable : Antenna;}
	void set_input() {input = (input == TV)? VCR : TV;}
	void settings() const; // výpis všech nastavení
private:
	int state; 			// zapnuto nebo vypnuto
	int volume; 		// bude digitalizována 
	int maxchannel; 	// maximální poèet programù
	int channel; 		// aktuální nastavení programù
	int mode; 			// z antény nebo kabelem
	int input; 			// TV nebo VCR
};

class Remote
{
private:
	int mode; // ovládání TV nebo VCR
public:
	Remote(int m = Tv::TV) : mode(m) {}
	bool volup(Tv & t) { return t.volup();}
	bool voldown(Tv & t) { return t.voldown();}
	void onoff(Tv & t) { t.onoff(); }
	void chanup(Tv & t) {t.chanup();}
	void chandown(Tv & t) {t.chandown();}
	void set_chan(Tv & t, int c) {t.channel = c;}
	void set_mode(Tv & t) {t.set_mode();}
	void set_input(Tv & t) {t.set_input();}
};
#endif
