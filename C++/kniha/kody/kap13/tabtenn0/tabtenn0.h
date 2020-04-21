// tabtenn0.h -- základní tøída stolního tenisu
#ifndef TABTENN0_H_
#define TABTENN0_H_
// jednoduchá základí tøída
class TableTennisPlayer
{
private:
	enum {LIM = 20};
	char firstname[LIM];
	char lastname[LIM];
	bool hasTable;
public:
	TableTennisPlayer (const char * fn = "zadny",
									const char * ln = "zadny", bool ht = false);
	void Name() const;
	bool HasTable() const { return hasTable; };
	void ResetTable(bool v) { hasTable = v; };
};
#endif

