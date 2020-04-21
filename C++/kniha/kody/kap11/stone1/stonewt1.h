// stonewt1.h -- upravená definice tøídy Stonewt
#ifndef STONEWT1_H_
#define STONEWT1_H_
class Stonewt
{
private:
	enum {Lbs_per_stn = 14};				// poèet liber na kámen
	int stone; 										// poèet celých kamenù
	double pds_left; 							// zbytek váhy v librách
	double pounds; 								// celková váha v librách
public:
	Stonewt(double lbs); 						// konstruktor pro libry
	Stonewt(int stn, double lbs); 		// konstruktor pro kameny
	Stonewt(); 										// implicitní konstruktor
	~Stonewt();
	void show_lbs() const; 					// zobrazení váhy v librách
	void show_stn() const; 					// zobrazení váhy v kamenech
// konverzní funkce
	operator int() const;
	operator double() const;
}; ;
#endif
