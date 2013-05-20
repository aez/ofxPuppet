#include "ofApp.h"

void ofApp::setup(){
	ofSetVerticalSync(true);
	ofRectangle square(50,50,600,600);
	int nHoriz = 10, nVert = 10;
	
	ofMesh mesh;
	mesh.setMode(OF_PRIMITIVE_TRIANGLES);
	for (int j = 0; j < nVert; j++){
    for (int i = 0; i < nHoriz; i++){
			float x = ofMap(i, 0, nHoriz-1, square.x, square.x + square.width);
			float y = ofMap(j, 0, nVert-1, square.y, square.y + square.height);
			mesh.addVertex(ofPoint(x,y));
		}
	}
	for ( unsigned int y = 0; y < (nVert-1); y++ ) {
		for ( unsigned int x = 0; x < nHoriz-1; x++ ) {
			unsigned int nRow1 = y * nHoriz;
			unsigned int nRow2 = (y+1) * nHoriz;
			mesh.addIndex(nRow1 + x);
			mesh.addIndex(nRow2 + x + 1);
			mesh.addIndex(nRow1 + x + 1);
			mesh.addIndex(nRow1 + x);
			mesh.addIndex(nRow2 + x);
			mesh.addIndex(nRow2 + x + 1);
		}
	}
	
	puppet.setMesh(mesh);
}

void ofApp::update(){
	puppet.update();
}

void ofApp::draw(){
	ofBackground(0);
	ofSetColor(255);
	puppet.drawWireframe();
}

void  ofApp::mouseDragged(int x, int y, int button){
	puppet.mouseDragged(x, y, button);
}

void  ofApp::mousePressed(int x, int y, int button){
	puppet.mousePressed(x, y, button);
}

void  ofApp::mouseReleased(int x, int y, int button){
	puppet.mouseReleased(x, y, button);
}











