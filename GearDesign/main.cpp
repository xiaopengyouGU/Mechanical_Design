#include "mechanicaldesign.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //GearDesignUI w;
    //KeyDesignUI w;
    //BearingDesignUI w;
    //AxleDesignUI w;
    MechanicalDesign w;
    w.show();


    return a.exec();
}
