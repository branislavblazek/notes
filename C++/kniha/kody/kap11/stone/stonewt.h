// stonewt.h -- definice tøídy Stonewt
#ifndef STONEWT_H_
#define STONEWT_H_
class Stonewt
{
private:
	enum {Lbs_per_stn = 14}; 			// poèet liber na jeden kámen
	int stone; 									// váha v celých kamenech
	double pds_left; 						// zbytek váhy v librách
	double pounds; 							// celková váha v librách
public:
	Stonewt(double lbs); 					// konstruktor typu double pro libry
	Stonewt(int stn, double lbs); 	// konstruktor pro kameny, libry
	Stonewt(); 									// implicitní konstruktor
	~Stonewt();
	void show_lbs() const; 				// zobrazení váhy v librách
	void show_stn() const; 				// zobrazení váhy v kamenech
};
#endif
