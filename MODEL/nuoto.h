#ifndef NUOTO_H
#define NUOTO_H
#include <workout.h>

class Nuoto : virtual public Workout {
private:
    unsigned int VascheRana;
    unsigned int VascheDorso;
    unsigned int VascheLibero;
    static unsigned int constRana;
    static unsigned int constDorso;
    static unsigned int constLibero;
    static unsigned int constGrassi;
public:
    Nuoto(unsigned int =0, unsigned int =0, unsigned int =0, unsigned int =0);
    virtual unsigned int calorie() const;
    virtual unsigned int GrassiBruc() const;

    unsigned int getVascheLibero() const;
    unsigned int getVascheRana() const;
    unsigned int getVascheDorso() const;

    void set_VascheLibero(unsigned int);
    void set_VascheRana(unsigned int);
    void set_VascheDorso(unsigned int);

    virtual bool operator==(const Workout& ) const;
    virtual bool operator<=(const  Workout& ) const;
    virtual bool operator>=(const  Workout& ) const;
};


#endif // NUOTO_H
