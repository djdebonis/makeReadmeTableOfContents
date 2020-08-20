#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

/*****
 * assumes we do not have hashtags besides title hashtags in the first four characters
 * takes as many arguments as are passed after the execution file is called
 * - each argument is a file that needs to have a table of contents created for
 *****/

string makeHeaderOne(string origString);

string makeHeaderTwo(string lowString);


int main(int argc, char *argv[]) {

    //string programName = argv[0];
    //int numArguments = argc;

    for (int i = 1; i < argc; i++) { // i has to be set to 1 because you don't
        // want to output whatever information is in argument 1, cause that is relating
        // to arg cc
        string infileName = argv[i]; // select the file

        //string infileName = "test.txt";
        string outfileName = "tableOfContents" + to_string(i) + ".txt";
        ofstream outfile;
        outfile.open(outfileName);
        cout << "The file name is document " << i << " is " << infileName << endl;
        string yesNo;
        cout << "Is this correct? (y/n): ";
        cin >> yesNo;
        ifstream infile;
        vector<string> fullDoc;
        if ((yesNo == "y") || (yesNo == "yes") || (yesNo == "1")) {
            infile.open(infileName);
        } else {
            string tempFile;
            cout << "Please enter the file's name: ";
            cin >> tempFile;
            infile.open(tempFile);
        }
        if (infile.is_open()) {
            string tempLine;
            //typedef char *cstr;
            //cstr tempLine;
            while (getline(infile, tempLine)) {
                // string line = tempLine;
                if ((tempLine == "") || (tempLine == "\n")) {
                    continue;
                } else {
                    string origString = tempLine;
                    fullDoc.push_back(origString); // push the whole line back into the vector
                    //cout << origString << endl; // so everything is functioning up to this point
                    char headerChar = tempLine[0];
                    //cout << headerChar << endl;

                    if (headerChar == '#') {
                        string search = "#";
                        int counter = 0;
                        int max = 4; // assuring we are not collecting hashtags from further in the string
                        size_t found = -1;
                        do {
                            found = tempLine.find(search, found + 1);
                            if ((found != string::npos) && (found <= max)) {
                                counter++;
                                //cout << counter << endl;
                            } else {
                                continue;
                            }
                        } while ((found != string::npos) && (counter <= max));

                        string tableOfContentsLine;

                        // create header one, which is in brackets [] and is the text displayed to user
                        string headerOne = makeHeaderOne(origString);
                        //cout << headerOne << endl;

                        // create header two, which is in parentheses () and is the anchored link to header
                        transform(origString.begin(), origString.end(), origString.begin(), ::tolower);
                        string headerTwo = makeHeaderTwo(origString);
                        //cout << headerTwo << endl;

                        if (counter == 1) { // now write these accordingly

                            outfile << headerOne << headerTwo << "\n";
                            //outfile.close();
                        } else if (counter == 2) {
                            //outfile.open(outfileName);
                            outfile << "- " << headerOne << headerTwo << "\n";
                            //outfile.close();
                        } else if (counter == 3) {
                            //outfile.open(outfileName);
                            outfile << "\t* " << headerOne << headerTwo << "\n";
                            //outfile.close();
                        } else if (counter == 4) {
                            //outfile.open(outfileName);
                            outfile << "\t\t* " << headerOne << headerTwo << "\n";
                            //outfile.close();
                        } else {
                            //outfile.open(outfileName);
                            outfile << "\t\t\t* " << headerOne << headerTwo << "\n";
                            //outfile.close();
                        }
                    }
                }
            }

        } else {
            cout << "The file could not be found." << endl;
        }


        infile.close();
        outfile.close();
    }

    return 0;
}

string makeHeaderTwo(string lowString){ // make the header with the hyperlink

    vector<string> tokens;
    istringstream iss(lowString);

    string word;
    while(iss >> word) {
        tokens.push_back(word);
    }

    string header = "(#";

    for(int i = 1; i < tokens.size(); i++){ // loop begins at one to avoid grabbing header
        if (i < ((tokens.size()) - 1)){
            string word = tokens[i];
            header = header +  word + "-";
        }
        else{
            string word = tokens[i];
            header = header + word + ")";
        }
    }
    return(header);
}

string makeHeaderOne(string origString){ // make the header with the displayed txt
    vector<string> tokens;
    istringstream iss(origString);

    string word;
    while(iss >> word) {
        tokens.push_back(word);
    }

    string header = "[";

    for(int i = 1; i < tokens.size(); i++){ // loop begins at one to avoid grabbing header
        if (i < ((tokens.size()) - 1)){
            string word = tokens[i];
            header = header +  word + " ";
        }
        else{
            string word = tokens[i];
            header = header + word + "]";
        }
    }
    return(header);
}
