#include "ofApp.h"

void ofApp::setup(){
	ofBackground(0, 0, 0);

    // 指定したIPアドレスとポート番号でサーバーに接続
    //OSCメッセージの送信者 ofxOscSender sender;
	sender.setup(HOST,PORT);
    //#define HOST "127.0.0.1" // 受信側のIPアドレス
    //#define PORT 8000 // 受信側のポート番号
}

void ofApp::update(){
}

void ofApp::draw(){
    //現在のマウスの場所に円を描画
    ofSetColor(255, 255, 255);
    ofCircle(mouseX, mouseY, 10);
}

//マウスを座標(480, 240)に動かした場合
//‣/mouse/position 480 240
void ofApp::mouseMoved(int x, int y){
	ofxOscMessage m;//OSCメッセージの準備
	m.setAddress("/mouse/position");//OSCアドレスの指定
	m.addIntArg(x);//OSC引数として、現在のマウスの座標(x, y)を送信
	m.addIntArg(y);
	sender.sendMessage(m);//メッセージを送信
}

void ofApp::mouseDragged(int x, int y, int button){
	ofxOscMessage m;//OSCメッセージの準備
	m.setAddress("/mouse/position");//OSCアドレスの指定
	m.addIntArg(x);//OSC引数として、現在のマウスの座標(x, y)を送信
	m.addIntArg(y);
	sender.sendMessage(m);//メッセージを送信
}

//マウスボタンを押した瞬間
//‣ /mouse/button “down”
void ofApp::mousePressed(int x, int y, int button){
	ofxOscMessage m;//OSCメッセージの準備
	m.setAddress("/mouse/button");//OSCアドレスの指定
	m.addStringArg("down");//OSC引数として、マウス状態"down"を送信
	sender.sendMessage(m); //メッセージを送信
}

void ofApp::mouseReleased(int x, int y, int button){
    
	ofxOscMessage m;//OSCメッセージの準備
	m.setAddress("/mouse/button");//OSCアドレスの指定
	m.addStringArg("up");//OSC引数として、マウス状態"up"を送信
	sender.sendMessage( m );//メッセージを送信
}