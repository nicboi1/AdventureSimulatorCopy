#ifndef __ATTRIBUTE_HPP__
#define __ATTRIBUTE_HPP__

#include <string>

using namespace std;


class att {

protected:

        int att_id;
        int roll_mod;
        bool reroll;
        int dam_mod;

public: 

	att(){}
	virtual ~att() {} 


	virtual int getID(){ return att_id; }
	virtual int getRollMod() { return roll_mod; }
	virtual bool getReroll() { return reroll; }
	virtual int getDamMod() { return dam_mod; }

};

class att_elf : public att {

public:

	att_elf() : att() {

		att_id = 1;
		roll_mod = 0; 
		reroll = true;
		dam_mod = 3;

	};


};


class att_dwarf : public att {

public:

	att_dwarf() : att() {

                att_id = 2;
                roll_mod = 0;
                reroll = true;
                dam_mod = 1;

	
	}

};


class att_human : public att {

public:

	att_human() : att() {

		att_id = 3;
                roll_mod = 1;
                reroll = true;
                dam_mod = 1;

	}


};


class att_halfling : public att {

public:

	att_halfling() : att() {

		att_id = 4;
                roll_mod = 2;
                reroll = true;
                dam_mod = -1;

	}

};




#endif
