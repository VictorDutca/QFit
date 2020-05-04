#include "xmlhandler.h"
#include <QFile>
#include <QJsonDocument>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

XMLHandler::XMLHandler(){}

void XMLHandler::FileReader(QString work) {
    QFile FileWorkout(work);
    if(FileWorkout.open(QIODevice::ReadOnly | QIODevice::Text)){
        try{
            XMLRead.setDevice(&FileWorkout);
            XMLRead.readNext();
            while(!XMLRead.atEnd() && !XMLRead.hasError()){
                XMLRead.readNext();
                if(XMLRead.isStartDocument())
                    continue;
                if(XMLRead.isStartElement()){
                    if(XMLRead.name() == "Workout")
                        continue;
                    QString work1 = XMLRead.name().toString();
                    Workout* w = WorkoutExplode(work1);
                    //FINIRE QUA
                }
            }
        }
    }
}
Workout* XMLHandler::WorkoutExplode(QString work){
    Workout* w = nullptr;
    XMLRead.readNextStartElement();
    if(XMLRead.isStartElement()){
        if(work == "swimming"){
            int freestyle, frog, backstroke, length;
            XMLRead.readNextStartElement();
            length = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            backstroke = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            frog = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            freestyle = XMLRead.readElementText().toInt();
            w = new Nuoto(static_cast<unsigned int>(length),
                          static_cast<unsigned int>(frog),
                          static_cast<unsigned int>(backstroke),
                          static_cast<unsigned int>(freestyle));
        }
        else if(work == "running"){
            int length, plain,downhill,uphill,distance;
            XMLRead.readNextStartElement();
            length = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            plain = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            downhill = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            uphill = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            distance = XMLRead.readElementText().toInt();
            w = new Corsa(static_cast<unsigned int>(length),
                          static_cast<unsigned int>(distance),
                          static_cast<unsigned int>(plain),
                          static_cast<unsigned int>(uphill),
                          static_cast<unsigned int>(downhill));
        }
        else if(work == "cycling"){
            int length, plain,downhill,uphill,distance;
            XMLRead.readNextStartElement();
            length = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            plain = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            downhill = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            uphill = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            distance = XMLRead.readElementText().toInt();
            w = new Ciclismo(static_cast<unsigned int>(length),
                          static_cast<unsigned int>(distance),
                          static_cast<unsigned int>(plain),
                          static_cast<unsigned int>(uphill),
                          static_cast<unsigned int>(downhill));
        }
        else if(work == "triathlon"){
            int plainCo,downhillCo,uphillCo,distanceCo,lengthCo,plainCi,downhillCi,uphillCi,distanceCi,lengthCi,freestyle, frog, backstroke, lengthN;
            XMLRead.readNextStartElement();
            lengthN = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            backstroke = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            frog = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            freestyle = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            lengthCo = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            plainCo = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            downhillCo = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            uphillCo = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            distanceCo = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            lengthCi = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            plainCi = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            downhillCi = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            uphillCi = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            distanceCi = XMLRead.readElementText().toInt();
            w = new Triathlon(static_cast<unsigned int>(lengthCo),
                          static_cast<unsigned int>(distanceCo),
                          static_cast<unsigned int>(plainCo),
                          static_cast<unsigned int>(uphillCo),
                          static_cast<unsigned int>(downhillCo),
                          static_cast<unsigned int>(lengthCi),
                          static_cast<unsigned int>(distanceCi),
                          static_cast<unsigned int>(plainCi),
                          static_cast<unsigned int>(uphillCi),
                          static_cast<unsigned int>(downhillCi),
                          static_cast<unsigned int>(lengthN),
                          static_cast<unsigned int>(frog),
                          static_cast<unsigned int>(backstroke),
                          static_cast<unsigned int>(freestyle));
        }
        XMLRead.readNext();
    }
    return w;
}

