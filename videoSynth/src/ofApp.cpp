#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	//Show GUI
	showGui = true;

	//Window setup and parameters
	ofSetWindowTitle( "Video Synth" );
	ofSetWindowShape( 1280, 720 );
	ofSetFrameRate ( 60 );
	ofBackground( ofColor::white );
	ofSetFullscreen( true );
	
	//GUI setup and parameters	
	gui.setup ( "Parameters", "settings.xml" );
	gui.add( countx.setup( "countx", 50, 0, 200 ) );
	gui.add( stepx.setup( "stepx", 20, 0, 200 ) );
	gui.add( twistx.setup( "twistx", 5, -45, 45) );
	
	//Primitive group setup and parameters
	primGroup.setup ( "Primitive" );
	primGroup.add( shiftY.setup( "shiftY", 0.0, -1000.0, 1000.0 ) );
	primGroup.add( rotate.setup( "rotate", 0.0, -180.0, 180.0 ) );
	primGroup.add( size.setup( "size", 
				ofVec2f(6, 6),//have a look at Vec clas definition
				ofVec2f(0, 0), 
				ofVec2f(20, 20) ) );
	primGroup.add( color.setup( "color", 
				ofColor::black, 
				ofColor(0, 0, 0, 0),
				ofColor::white ) );
	primGroup.add( filled.setup( "filled", false ) );
	primGroup.add( type.setup( "type", false ) );
	gui.add( &primGroup );
	gui.loadFromFile( "settings.xml" );
	
	//Global setup and parameters
	globalGroup.setup( "Global" );
	globalGroup.add( Scale.setup( "Scale", 1, 0.0, 1 ) );
	globalGroup.add( Rotate.setup( "Rotate", 0, -180, 180 ) );
	globalGroup.add( Background.setup( "Background", 255, 0, 255) );
	gui.add( &globalGroup );
}
//--------------------------------------------------------------
void ofApp::exit() {
	gui.saveToFile( "settings.xml" );
}
//--------------------------------------------------------------
void ofApp::update(){

}
//--------------------------------------------------------------

void ofApp::stripePattern() {
	ofSetColor( color );
	ofSetLineWidth ( 1 );
	if ( filled ) ofFill(); else ofNoFill();
	for (int i=-countx; i < countx; i++) {
	ofPushMatrix();
	ofTranslate( i * stepx, 0 );
	ofRotate( i * twistx );
	
	ofTranslate( 0, shiftY );
	ofRotate ( rotate );
	ofScale( size->x, size->y );
	if ( type ) ofRect( -50, -50, 100, 100 );
	else ofTriangle( 0, 0, -50, 100, 50, 100);
	
	ofPopMatrix();
	}
	//ofScale( 6, 3 );
	//ofTriangle( 0, 0, -50, 100, 50, 100 );
}
//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground( Background ); 	//sets background to a grey color
	ofPushMatrix();
	ofTranslate( ofGetWidth() / 2, ofGetHeight() / 2 );
	
	// drawing code goes in here-----
	float Scl = pow( Scale, 4.0f );  //raises Scale's slider to the 4th
	ofScale( Scl, Scl );
	ofRotate( Rotate );
	stripePattern();
	
	//-----
	
	ofPopMatrix();
	if ( showGui ) gui.draw();
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if ( key == 'z' ) showGui = !showGui;		//hide gui on 'z' key
	if ( key == OF_KEY_RETURN ) ofSaveScreen( "screenshot" + ofToString(ofRandom(0, 1000), 0) + ".png" );		//saves randomscreenshot 0 - 999
	
	//Saving and loading files
	if ( key == 's' ) {
	ofFileDialogResult res;
	res = ofSystemSaveDialog( "preset.xml", "Saving Preset" );
	if ( res.bSuccess ) gui.saveToFile( res.filePath );
	}
	
	if ( key == 'l' ) {
	ofFileDialogResult res;
	res = ofSystemLoadDialog( "Loading Preset" );
	if ( res.bSuccess ) gui.loadFromFile( res.filePath );
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
//--------------------------------------------------------------

