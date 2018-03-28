//#include <iostream>
//#include <algorithm>
//#include <map>
//
//using namespace std;
//
//int main() {
//
//    int n, m;
//    cin >> n >> m;
//
//    map<string, string> json;
//
//    string line;
//    string all_data;
//    while (n--) {
//        getline(cin, line);
//        all_data += line;
//    }
//
//    bool isKey = false;
//    bool inStr = false;
//    int inObj = 0;
//    string key;
//    string value;
//    string baseKey;
//    for (int i = 0; i < all_data.size(); ++i) {
//        if (all_data[i] == ' ') {
//            continue;
//        }
//
//        if (all_data[i] == '{') {
//            isKey = true;
//            if (!inObj) {
//                inObj = 1;
//                continue;
//            }
//            else {
//                ++inObj;
//                json[baseKey + key] = "OBJECT";
//                baseKey += key + '.';
//                continue;
//            }
//        }
//
//        if (all_data[i] == '"') {
//            if (inStr) {
//                inStr = false;
//                continue;
//            }
//
//            inStr = true;
//            int j = i+1;
//            while (j < all_data.size()) {
//                if (all_data[j] == '\\') {
//                    if (all_data[j+1] == '\\') {
//                        if (isKey) {
//                            key += '\\';
//                        }
//                        else {
//                            value += '\\';
//                        }
//                    }
//                    else if (all_data[j+1] == '"') {
//                        if (isKey) {
//                            key += '"';
//                        }
//                        else {
//                            value += '"';
//                        }
//                    }
//                    j += 2;
//                    continue;
//                }
//
//                if (all_data[j] == '"') {
//                    break;
//                }
//
//                if (isKey) {
//                    key += all_data[j];
//                }
//                else {
//                    value += all_data[j];
//                }
//                ++j;
//            }
//
//            i = j - 1;
//            continue;
//        }
//
//        if (all_data[i] == ':') {
//            isKey = false;
//            continue;
//        }
//
//        if (all_data[i] == '}') {
//            json[baseKey + key] = value;
//
//            // remove to last baseKey
//            int k;
//            for (k = baseKey.size()-1; k >= 0; --k) {
//                if (baseKey[k] == '.') {
//                    break;
//                }
//            }
//
//            if (k < 0) {
//                baseKey = "";
//            }
//            else {
//                baseKey = baseKey.substr(0, k);
//            }
//        }
//
//        if (all_data[i] == ',') {
//            json[baseKey + key] = value;
//            isKey = true;
//            key = "";
//            value = "";
//        }
//    }
//
//    while (m--) {
//        getline(cin, line);
//        if (json.find(line) == json.end()) {
//            cout << "NOTEXIST" << endl;
//        }
//        else {
//            cout << json[line] << endl;
//        }
//    }
//}