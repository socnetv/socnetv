/***************************************************************************
 SocNetV: Social Networks Visualiser 
 version: 0.6
 Written in Qt 4.4
 
                         parser.h  -  description
                             -------------------
    copyright            : (C) 2005-2009 by Dimitris B. Kalamaras
    email                : dimitris.kalamaras@gmail.com
 ***************************************************************************/

/*******************************************************************************
*     This program is free software: you can redistribute it and/or modify     *
*     it under the terms of the GNU General Public License as published by     *
*     the Free Software Foundation, either version 3 of the License, or        *
*     (at your option) any later version.                                      *
*                                                                              *
*     This program is distributed in the hope that it will be useful,          *
*     but WITHOUT ANY WARRANTY; without even the implied warranty of           *
*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
*     GNU General Public License for more details.                             *
*                                                                              *
*     You should have received a copy of the GNU General Public License        *
*     along with this program.  If not, see <http://www.gnu.org/licenses/>.    *
********************************************************************************/

#ifndef PARSER_H
#define PARSER_H

using namespace std;

#include <QThread>
#include <QPointF>
#include <QMutex>
#include <QObject>
#include <QtXml>	


/** 	
	Main class for network file parsing and loading
	Currently, it supports Pajek, Adjacency, Graphviz, GraphML
*/
class Parser :  public QThread {
	Q_OBJECT
public:
	void load(QString fileName, int, QString, QString, QString, bool, int w, int h);
	
	int loadPajek();
	int loadAdjacency();
	int loadDot();
	int loadGraphML();
	int loadGML();
	int loadGW();
	int loadDL();

	void dotProperties(QString str, int &nValue, QString &label, QString &shape, QString &color, QString &fontName, QString &fontColor );
	void readGraphML (QXmlStreamReader &);
	void readGraphMLGraphElement(QXmlStreamReader &);
	void readGraphMLNodeElement (QXmlStreamReader &);
	void endGraphMLNodeElement (QXmlStreamReader &);
	void readGraphMLEdgeElement (QXmlStreamReader &);
	void readGraphMLDataElement (QXmlStreamReader &);
	void readGraphMLUnknownElement (QXmlStreamReader &);
	void readGraphMLKeys(QXmlStreamReader &);
signals:
	void createNode(int,int,QString, QString, QString, QPointF, QString, bool);
	void createEdge (int, int, float, QString, bool, bool, bool);
	void fileType(int, QString, int, int);
	void removeDummyNode (int);
protected:
	void run();
private: 
	QMutex mutex;
	QMap<QString, int> nodeNumber;
	QMap<QString, QString> keyFor, keyName, keyType, keyDefaultValue ;
	QXmlStreamReader *xml;
	QString fileName, networkName, initNodeColor, initLinkColor, initNodeShape;
  
	int gwWidth, gwHeight, totalLinks, aNodes, initNodeSize, source, target;
	bool initShowLabels;
	bool undirected, arrows, bezier;
	double randX, randY;
};


#endif
