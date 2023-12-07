#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(0);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	auto radius = 100;
	vector<glm::vec2> base_location;
	base_location.push_back(glm::vec2(-200, -200));
	base_location.push_back(glm::vec2(200, -200));
	base_location.push_back(glm::vec2(200, 200));
	base_location.push_back(glm::vec2(-200, 200));

	
	for (int i = 0; i < base_location.size(); i++) {

		auto deg_param = ofMap(ofNoise(base_location[i].x, base_location[i].y, ofGetFrameNum() * 0.0085), 0, 1, -360, 360);
		auto next_deg_param = ofMap(ofNoise(
			base_location[(i + 1) % base_location.size()].x, base_location[(i + 1) % base_location.size()].y, ofGetFrameNum() * 0.0085), 0, 1, -360, 360);

		for (int deg = 0; deg < 45; deg += 5) {

			auto location_1 = base_location[i] + glm::vec2(radius * cos((deg + deg_param) * DEG_TO_RAD), radius * sin((deg + deg_param) * DEG_TO_RAD));
			auto location_2 = base_location[(i + 1) % base_location.size()] + glm::vec2(radius * cos((deg + next_deg_param) * DEG_TO_RAD), radius * sin((deg + next_deg_param) * DEG_TO_RAD));

			ofDrawCircle(location_1, 2.5);
			ofDrawCircle(location_2, 2.5);
			ofDrawLine(location_1, location_2);
		}

		for (int deg = 120; deg < 165; deg += 5) {

			auto location_1 = base_location[i] + glm::vec2(radius * cos((deg + deg_param) * DEG_TO_RAD), radius * sin((deg + deg_param) * DEG_TO_RAD));
			auto location_2 = base_location[(i + 1) % base_location.size()] + glm::vec2(radius * cos((deg + next_deg_param) * DEG_TO_RAD), radius * sin((deg + next_deg_param) * DEG_TO_RAD));

			ofDrawCircle(location_1, 2.5);
			ofDrawCircle(location_2, 2.5);
			ofDrawLine(location_1, location_2);
		}

		for (int deg = 240; deg < 285; deg += 5) {

			auto location_1 = base_location[i] + glm::vec2(radius * cos((deg + deg_param) * DEG_TO_RAD), radius * sin((deg + deg_param) * DEG_TO_RAD));
			auto location_2 = base_location[(i + 1) % base_location.size()] + glm::vec2(radius * cos((deg + next_deg_param) * DEG_TO_RAD), radius * sin((deg + next_deg_param) * DEG_TO_RAD));

			ofDrawCircle(location_1, 2.5);
			ofDrawCircle(location_2, 2.5);
			ofDrawLine(location_1, location_2);
		}
	}

	int start = 150;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}